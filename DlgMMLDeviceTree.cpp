// DlgMMLDeviceTree.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLDeviceTree.h"
#include "tinyxml.h"

#include <string>
#include <vector>
#include <queue>
#include <list>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLDeviceTree dialog


CDlgMMLDeviceTree::CDlgMMLDeviceTree(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLDeviceTree::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLDeviceTree)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_pMultiWin = NULL;
}


void CDlgMMLDeviceTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLDeviceTree)
	DDX_Control(pDX, IDC_TREE_DEVICE, m_TreeCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLDeviceTree, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLDeviceTree)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_DEVICE, OnDblclkTreeDevice)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLDeviceTree message handlers

void CDlgMMLDeviceTree::SetMultiWinPtr(void *pMultiWin)
{
	m_pMultiWin = (CMultiWindow*)pMultiWin;
	m_pMultiWin->SetPanelPtr(PANEL_TYPE_TREE, this);
}

BOOL CDlgMMLDeviceTree::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_bInitDialog = true;

	if(!GetDeviceList())
		return FALSE;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMMLDeviceTree::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top = 1;
	m_TreeCtrl.MoveWindow(&rect2);
}

void CDlgMMLDeviceTree::OnDestroy() 
{
	CDialog::OnDestroy();
	ReleaseDataForTreeCtrl();	
}

void CDlgMMLDeviceTree::OnDblclkTreeDevice(NMHDR* pNMHDR, LRESULT* pResult) 
{
	if(m_pMultiWin == NULL) return;
	HTREEITEM hItem = m_TreeCtrl.GetSelectedItem();
	DWORD IData = m_TreeCtrl.GetItemData(hItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType == NODE_TYPE_AREA)
		return;
	else if(pNodeData->nType == NODE_TYPE_ENCODER)
	{
		hItem = m_TreeCtrl.GetChildItem(hItem);
		IData = m_TreeCtrl.GetItemData(hItem);
		pNodeData = (TREE_NODE_DATA*)IData;
		if(pNodeData->nType != NODE_TYPE_CHANNEL)
			return;
		m_pMultiWin->ConnectEncoder(pNodeData->id);
	}
	else if(pNodeData->nType == NODE_TYPE_CHANNEL)
		m_pMultiWin->ConnectEncoder(pNodeData->id);
	*pResult = 0;
}

BOOL CDlgMMLDeviceTree::GetDeviceList()
{
	TiXmlDocument *xmlDocument = new TiXmlDocument();
	BOOL bRet = HD_GetDeviceList(xmlDocument);
	if( !bRet )
	{
		delete xmlDocument;
		return FALSE;
	}

	TiXmlElement *RootElement = xmlDocument->RootElement();
	if(RootElement == NULL)
	{
		delete xmlDocument;
		return FALSE;
	}
	
	int n = 0;
	string sType,sId,sName;
	TiXmlElement* pXmlElement = RootElement->FirstChildElement();
	if(pXmlElement == NULL)
	{
		delete xmlDocument;
		return FALSE;
	}
	TiXmlAttribute *pAttribute = pXmlElement->FirstAttribute();
	if(pAttribute == NULL)
	{
		delete xmlDocument;
		return FALSE;
	}
	sType = pAttribute->Value();
	int nType = atoi(sType.c_str());
	if(nType != NODE_TYPE_AREA)
	{
		delete xmlDocument;
		return FALSE;
	}
	pAttribute = pAttribute->Next();
	sId = pAttribute->Value();					//区域ID
	pAttribute = pXmlElement->LastAttribute();  //GetAttribute("name");
	sName = pAttribute->Value();
	
	queue<TiXmlElement*> queueXml;
	queueXml.push(pXmlElement);
	
	TREE_NODE_DATA *pData = new TREE_NODE_DATA;
	pData->nType = NODE_TYPE_AREA;
	pData->id = atoi(sId.c_str());
	TVINSERTSTRUCT vtins;
	memset(&vtins,0,sizeof(vtins));
	vtins.hParent = NULL;
	vtins.hInsertAfter = TVI_LAST;
	vtins.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_HANDLE;
	vtins.item.pszText = (LPSTR)sName.c_str();
	vtins.item.cchTextMax = strlen(vtins.item.pszText);
	vtins.item.lParam = (long)pData;
	HTREEITEM hTreeItem = m_TreeCtrl.InsertItem(&vtins);
	queue<HTREEITEM> queueTree;	//保存树的父节点
	queueTree.push(hTreeItem);
	TiXmlNode* pXmlNode = NULL;
	while(!queueXml.empty())
	{
		pXmlElement = queueXml.front();
		queueXml.pop();
		hTreeItem = queueTree.front();
		queueTree.pop();
		pXmlNode = pXmlElement->FirstChild();
		while(pXmlNode != NULL)
		{
			pXmlElement = pXmlNode->ToElement();
			queueXml.push(pXmlElement);
			pAttribute = pXmlElement->FirstAttribute();
			sType = pAttribute->Value();
			pAttribute = pAttribute->Next();
			sId = pAttribute->Value();
			pAttribute = pAttribute->Next();
			sName = pAttribute->Value();
			TREE_NODE_DATA *pData = new TREE_NODE_DATA;
			if(atoi(sType.c_str()) == NODE_TYPE_AREA)
			{
				pData->nType = NODE_TYPE_AREA;
				pData->id = atoi(sId.c_str());
			}
			else if(atoi(sType.c_str()) == NODE_TYPE_ENCODER)
			{
				pData->nType = NODE_TYPE_ENCODER;
				pData->id = atoi(sId.c_str());
			}
			else if(atoi(sType.c_str()) == NODE_TYPE_CHANNEL)
			{
				pData->nType = NODE_TYPE_CHANNEL;
				pData->id = atoi(sId.c_str());
			}
			memset(&vtins,0,sizeof(vtins));
			vtins.hParent = hTreeItem;
			vtins.hInsertAfter = TVI_LAST;
			vtins.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_HANDLE;
			vtins.item.pszText = (LPSTR)sName.c_str();
			vtins.item.cchTextMax = strlen(vtins.item.pszText);
			vtins.item.lParam = (long)pData;
			HTREEITEM hItem = m_TreeCtrl.InsertItem(&vtins);
			queueTree.push(hItem);
			pXmlNode = pXmlElement->NextSibling();
		}
	}
	delete xmlDocument;
	return TRUE;
}
BOOL CDlgMMLDeviceTree::ReleaseDataForTreeCtrl()
{
	HTREEITEM hriRoot = m_TreeCtrl.GetRootItem();
	if(hriRoot == NULL)	return FALSE;
	
	queue<HTREEITEM> htQueue;
	htQueue.push(hriRoot);
	HTREEITEM ht = NULL;
	
	while(!htQueue.empty())
	{
		ht = htQueue.front();
		htQueue.pop();	
		
		TVITEM vitrm;
		vitrm.mask =TVIF_PARAM | TVIF_HANDLE;
		vitrm.hItem = ht;
		BOOL bRet = m_TreeCtrl.GetItem(&vitrm); //TreeView_GetItem(hwndTV,&vitrm);
		
		TREE_NODE_DATA* pItemData = NULL;
		pItemData=(TREE_NODE_DATA *) vitrm.lParam;
		if(pItemData)
		{
			delete pItemData;
			pItemData = NULL;
		}
		
		if(vitrm.cChildren != 0 && bRet)
		{
			HTREEITEM hChild = m_TreeCtrl.GetChildItem(ht);
			while(hChild)
			{
				htQueue.push(hChild);
				hChild=m_TreeCtrl.GetNextSiblingItem(hChild);
			}
		}
	}
	return TRUE;
}