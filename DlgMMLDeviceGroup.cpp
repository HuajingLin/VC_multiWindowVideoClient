// DlgMMLDeviceGroup.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLDeviceGroup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLDeviceGroup dialog


CDlgMMLDeviceGroup::CDlgMMLDeviceGroup(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLDeviceGroup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLDeviceGroup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_pMultiWin = NULL;
}


void CDlgMMLDeviceGroup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLDeviceGroup)
	DDX_Control(pDX, IDC_TREE_DEVICE, m_treeGroup);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLDeviceGroup, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLDeviceGroup)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLDeviceGroup message handlers
void CDlgMMLDeviceGroup::SetMultiWinPtr(void *pMultiWin)
{
	m_pMultiWin = (CMultiWindow*)pMultiWin;
	m_pMultiWin->SetPanelPtr(PANEL_TYPE_TREE, this);
}
BOOL CDlgMMLDeviceGroup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_bInitDialog = true;

	//if(!GetDeviceList())
	//	return FALSE;
	TVINSERTSTRUCT vtins;
	memset(&vtins,0,sizeof(vtins));
	vtins.hParent = NULL;
	vtins.hInsertAfter = TVI_LAST;
	vtins.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_HANDLE;
	vtins.item.pszText = "默认分组";//(LPSTR)sName.c_str();
	vtins.item.cchTextMax = strlen(vtins.item.pszText);
	vtins.item.lParam = 1;//分组ID
	HTREEITEM hTreeItem = m_treeGroup.InsertItem(&vtins);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMMLDeviceGroup::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top = 1;
	GetDlgItem(IDC_TREE_DEVICE)->MoveWindow(&rect2);

	
	
}
