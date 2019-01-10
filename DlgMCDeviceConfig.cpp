// DlgMCDeviceConfig.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMCDeviceConfig.h"
#include "tinyxml.h"
#include <string>
#include <queue>
using namespace std;
#include "DlgMCDAddArea.h"
#include "DlgMCDAddEncoder.h"
#include "DlgMCDModiChannel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDeviceConfig dialog
#define MCD_TIPS_TOP 30

CDlgMCDeviceConfig::CDlgMCDeviceConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMCDeviceConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMCDeviceConfig)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_hSelItem = NULL;
	m_pReloadTreeThread = NULL;
}


void CDlgMCDeviceConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMCDeviceConfig)
	DDX_Control(pDX, IDC_TREE_DEVICE, m_TreeCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMCDeviceConfig, CDialog)
	//{{AFX_MSG_MAP(CDlgMCDeviceConfig)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_COMMAND(IDM_CD_ADD_AREA, OnAddArea)
	ON_COMMAND(IDM_CD_ADD_DEVICE, OnAddDevice)
	ON_COMMAND(IDM_CD_DEL_NODE, OnDelNode)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_DEVICE, OnDblclkTreeDevice)
	ON_NOTIFY(NM_RCLICK, IDC_TREE_DEVICE, OnRclickTreeDevice)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDeviceConfig message handlers
BOOL CDlgMCDeviceConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("ConfigDeviceTips1",tStr))
	GetDlgItem(IDC_STATIC_INFO)->SetWindowText(tStr);
	VERIFY(m_MenuPop.LoadMenu(IDR_MENU_CONF_DEVI));
	CMenu* pPopup = m_MenuPop.GetSubMenu(0);
	ASSERT(pPopup != NULL);
	
	UINT ID = pPopup->GetMenuItemID(0);	
	if(g_GetLanguage("AddArea",tStr))
		pPopup->ModifyMenu(ID,MF_STRING,IDM_CD_ADD_AREA,tStr);
	
	ID = pPopup->GetMenuItemID(1);
	if(g_GetLanguage("AddDevice",tStr))
		pPopup->ModifyMenu(ID,MF_STRING,IDM_CD_ADD_DEVICE,tStr);
	
	ID = pPopup->GetMenuItemID(2);
	if(g_GetLanguage("DelNode",tStr))
		pPopup->ModifyMenu(ID,MF_STRING,IDM_CD_DEL_NODE,tStr);
	
	m_bInitDialog = true;
	return TRUE;
}
void CDlgMCDeviceConfig::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	if(!bShow)
		return;
	if(!GetDeviceList())
		return ;
}
void CDlgMCDeviceConfig::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top = MCD_TIPS_TOP;
	rect2.right = rect2.right/2;
	m_TreeCtrl.MoveWindow(&rect2);
}

void CDlgMCDeviceConfig::OnDestroy() 
{
	CDialog::OnDestroy();
	ReleaseDataForTreeCtrl();	
}

void CDlgMCDeviceConfig::OnAddArea()	//菜单项
{	
	if(m_hSelItem==NULL) return;
	DWORD IData = m_TreeCtrl.GetItemData(m_hSelItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType != NODE_TYPE_AREA)
		return;
	//弹出设备输入框
	CDlgMCDAddArea DlgAddArea;
	DlgAddArea.m_nUpAreaId = pNodeData->id;
	DlgAddArea.m_strUPName = m_TreeCtrl.GetItemText(m_hSelItem);
	DlgAddArea.m_nType = 0;
	if(DlgAddArea.DoModal() != IDOK)
		return;

	if(!HD_AddArea(DlgAddArea.m_nUpAreaId, DlgAddArea.m_strName))
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("AddFail", tStr))
			MessageBox(tStr);
		else
			MessageBox("Add fail.");
		return;
	}
	//重新加载设备树
	ReloadTree();
}

void CDlgMCDeviceConfig::OnAddDevice()  //菜单项
{
	if(m_hSelItem==NULL) return;
	DWORD IData = m_TreeCtrl.GetItemData(m_hSelItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType != NODE_TYPE_AREA)
		return;
	//弹出设备输入框
	CDlgMCDAddEncoder DlgAddEncoder;
	DlgAddEncoder.m_nType = 0;
	DlgAddEncoder.m_strAreaName = m_TreeCtrl.GetItemText(m_hSelItem);
	DlgAddEncoder.m_nAreaId = pNodeData->id;
	if(DlgAddEncoder.DoModal() != IDOK)
		return;
	CString strName = DlgAddEncoder.m_strDeviName;
	BYTE	nIPMode = DlgAddEncoder.m_nIPMode;
	CString strIP = DlgAddEncoder.m_strIP;
	WORD	nPort = DlgAddEncoder.m_nPort;
	CString strUser = DlgAddEncoder.m_strUser;
	CString strPwd = DlgAddEncoder.m_strPwd;
	BYTE	nChannel = DlgAddEncoder.m_nChannel;
	CString strDeviId = DlgAddEncoder.m_strDeviId;
	CString strDNS = DlgAddEncoder.m_strDnsIP;
	CString strMulti = DlgAddEncoder.m_strMulticastIP;
	int nAreaId = pNodeData->id;
	if(HD_AddEncoder(1,strName.GetBuffer(0),nIPMode, strIP.GetBuffer(0),nPort,strUser.GetBuffer(0),strPwd.GetBuffer(0),nChannel,
		strDNS.GetBuffer(0),strMulti.GetBuffer(0),strDeviId.GetBuffer(0),nAreaId) <= 0)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("AddFail", tStr))
			MessageBox(tStr);
		else
			MessageBox("Add fail.");
		return;
	}
	//重新加载设备树
	ReloadTree();
}

void CDlgMCDeviceConfig::OnDelNode()  //菜单项
{
	if(m_hSelItem==NULL) return;
	DWORD IData = m_TreeCtrl.GetItemData(m_hSelItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType == NODE_TYPE_AREA)	//删除区域
	{
		if(!HD_DeleteArea(pNodeData->id))
		{
			TCHAR tStr[STR_LEN];
			if(g_GetLanguage("DeleteFail",tStr))
				MessageBox(tStr);
			else
				MessageBox("Delete fail.");
			return;
		}
	}
	else if(pNodeData->nType == NODE_TYPE_ENCODER)	//删除设备
	{
		if(!HD_DeleteEncoder(pNodeData->id))
		{
			TCHAR tStr[STR_LEN];
			if(g_GetLanguage("DeleteFail",tStr))
				MessageBox(tStr);
			else
				MessageBox("Delete fail.");
			return;
		}
	}
	else
		return;
	//重新加载设备树
	ReloadTree();
}

void CDlgMCDeviceConfig::OnDblclkTreeDevice(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CPoint pt;
	UINT nFlags;
	::GetCursorPos(&pt);
	::ScreenToClient(m_TreeCtrl.m_hWnd, &pt);
	m_hSelItem = m_TreeCtrl.HitTest(pt,&nFlags);
	if(m_hSelItem==NULL) return;
	DWORD IData = m_TreeCtrl.GetItemData(m_hSelItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType == NODE_TYPE_AREA)	//修改区域
	{		
		//弹出设备输入框
		CDlgMCDAddArea DlgAddArea;
		DlgAddArea.m_nType = 1;
		DlgAddArea.m_nAreaId = pNodeData->id;
		DlgAddArea.m_strName = m_TreeCtrl.GetItemText(m_hSelItem);
		HTREEITEM hTreeItem = m_TreeCtrl.GetParentItem(m_hSelItem);
		DlgAddArea.m_strUPName = m_TreeCtrl.GetItemText(hTreeItem);
		if(DlgAddArea.DoModal() != IDOK)
			return;
		if(!HD_ModifyArea(DlgAddArea.m_nAreaId, DlgAddArea.m_strName))
		{
			TCHAR tStr[STR_LEN];
			if(g_GetLanguage("ModiFail",tStr))
				MessageBox(tStr);
			else
				MessageBox("Modify fail.");
			return;
		}
	}
	else if(pNodeData->nType == NODE_TYPE_ENCODER)	//修改设备
	{
		//弹出设备输入框
		CDlgMCDAddEncoder DlgAddEncoder;
		DlgAddEncoder.m_nType = 1;
		HTREEITEM hTreeItem = m_TreeCtrl.GetParentItem(m_hSelItem);
		DlgAddEncoder.m_strAreaName = m_TreeCtrl.GetItemText(hTreeItem);
		DlgAddEncoder.m_EncoderID = pNodeData->id;
		int EncoderID = pNodeData->id;
		if(EncoderID <= 0) return;
		if(DlgAddEncoder.DoModal() != IDOK)
			return;
		CString strName = DlgAddEncoder.m_strDeviName;
		BYTE	nIPMode = DlgAddEncoder.m_nIPMode;
		CString strIP = DlgAddEncoder.m_strIP;
		WORD	nPort = DlgAddEncoder.m_nPort;
		CString strUser = DlgAddEncoder.m_strUser;
		CString strPwd = DlgAddEncoder.m_strPwd;
		BYTE	nChannel = DlgAddEncoder.m_nChannel;
		CString strDeviId = DlgAddEncoder.m_strDeviId;
		CString strDNS = DlgAddEncoder.m_strDnsIP;
		CString strMulti = DlgAddEncoder.m_strMulticastIP;		
		if(!HD_ModifyEncoder(EncoderID,strName.GetBuffer(0),nIPMode, strIP.GetBuffer(0),nPort,strUser.GetBuffer(0),strPwd.GetBuffer(0),nChannel,
			strDNS.GetBuffer(0),strMulti.GetBuffer(0)))
		{
			TCHAR tStr[STR_LEN];
			if(g_GetLanguage("ModiFail", tStr))
				MessageBox(tStr);
			else
				MessageBox("Modify fail.");
			return;
		}
	}
	else if(pNodeData->nType == NODE_TYPE_CHANNEL)	//修改通道
	{
		CDlgMCDModiChannel DlgChannel;
		DlgChannel.m_nChannelID = pNodeData->id;
		DlgChannel.m_strChannelName =  m_TreeCtrl.GetItemText(m_hSelItem);
		HTREEITEM hTreeItem = m_TreeCtrl.GetParentItem(m_hSelItem);
		DlgChannel.m_strDeviName = m_TreeCtrl.GetItemText(hTreeItem);
		DWORD IData = m_TreeCtrl.GetItemData(hTreeItem);
		TREE_NODE_DATA* pChannelData = (TREE_NODE_DATA*)IData;
		DlgChannel.m_nEncoderID = pChannelData->id;
		if(pChannelData->id <= 0) return;
		if(DlgChannel.DoModal() != IDOK)
			return;
		if(!HD_ModifyEncChannel(pChannelData->id, DlgChannel.m_strChannelName.GetBuffer(0), DlgChannel.m_nStream))
		{
			TCHAR tStr[STR_LEN];
			if(g_GetLanguage("ModiFail", tStr))
				MessageBox(tStr);
			else
				MessageBox("Modify fail.");
			return;
		}
	}
	//重新加载设备树
	m_pReloadTreeThread = AfxBeginThread(ReloadTreeThread, this);
	*pResult = 0;
}
UINT CDlgMCDeviceConfig::ReloadTreeThread(LPVOID lpParam)
{
	CDlgMCDeviceConfig* pDlg=(CDlgMCDeviceConfig*)lpParam;
	pDlg->ReloadTree();
	return 0;
}
void CDlgMCDeviceConfig::ReloadTree()
{
	ReleaseDataForTreeCtrl();
	m_TreeCtrl.DeleteAllItems();
	GetDeviceList();
}
void CDlgMCDeviceConfig::OnRclickTreeDevice(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMenu* pPopup = m_MenuPop.GetSubMenu(0);
	ASSERT(pPopup != NULL);
	pPopup->EnableMenuItem(0, MF_BYPOSITION|MF_ENABLED);
	pPopup->EnableMenuItem(1, MF_BYPOSITION|MF_ENABLED);
	pPopup->EnableMenuItem(2, MF_BYPOSITION|MF_ENABLED);

	CPoint pt;
	UINT nFlags;
	::GetCursorPos(&pt);
	::ScreenToClient(m_TreeCtrl.m_hWnd, &pt);
	m_hSelItem = m_TreeCtrl.HitTest(pt,&nFlags);
	if(m_hSelItem==NULL) return;
	DWORD IData = m_TreeCtrl.GetItemData(m_hSelItem);
	TREE_NODE_DATA* pNodeData = (TREE_NODE_DATA*)IData;
	if(pNodeData->nType == NODE_TYPE_AREA && pNodeData->id==1)
		pPopup->EnableMenuItem(2, MF_BYPOSITION|MF_GRAYED); //不能删除根节点
	else if(pNodeData->nType == NODE_TYPE_ENCODER)
	{
		pPopup->EnableMenuItem(0, MF_BYPOSITION|MF_GRAYED);	//设备下不能添加区域
		pPopup->EnableMenuItem(1, MF_BYPOSITION|MF_GRAYED);	//设备下不能添加设备
	}
	else if(pNodeData->nType == NODE_TYPE_CHANNEL)
		return;

	tagPOINT point;
	GetCursorPos(&point);
	pPopup = m_MenuPop.GetSubMenu(0);
	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_LEFTBUTTON, point.x, point.y, this);
	*pResult = 0;
}

BOOL CDlgMCDeviceConfig::GetDeviceList()
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
BOOL CDlgMCDeviceConfig::ReleaseDataForTreeCtrl()
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
