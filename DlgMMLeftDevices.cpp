// DlgMMLeftDevices.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLeftDevices.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftDevices dialog
#define MMLD_TOOL_HEIGHT 23
#define MMLD_PANEL_TREE 1
#define MMLD_PANEL_GROUP 2
#define MMLD_BK_COLOR RGB(0x28,0x2B,0x32)
CDlgMMLeftDevices::CDlgMMLeftDevices(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLeftDevices::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLeftDevices)
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_nCurrPanel = 0;
	m_bkBrush.CreateSolidBrush(MMLD_BK_COLOR);
}


void CDlgMMLeftDevices::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLeftDevices)
	DDX_Control(pDX, IDC_BTN_LIST, m_btnList);
	DDX_Control(pDX, IDC_BTN_GROUP, m_btnGroup);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLeftDevices, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLeftDevices)
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_LIST, OnBtnList)
	ON_BN_CLICKED(IDC_BTN_GROUP, OnBtnGroup)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftDevices message handlers

BOOL CDlgMMLeftDevices::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_DeviceTree.Create(IDD_MMLD_TREE,this);
	m_DeviceGroup.Create(IDD_MMLD_GROUP,this);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top = MMLD_TOOL_HEIGHT;
	m_DeviceTree.MoveWindow(&rect2);
	m_DeviceTree.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLD_PANEL_TREE;
	
	m_btnList.SetSkin(IDB_TAB_BACK22,IDB_TAB_BACK21);
	m_btnGroup.SetSkin(IDB_TAB_BACK22,IDB_TAB_BACK21);
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("List",tStr))
		m_btnList.SetText(tStr,10);
	else
		m_btnList.SetText("List",10);
	if(g_GetLanguage("Group",tStr))
		m_btnGroup.SetText(tStr,10);
	else
		m_btnGroup.SetText("Group",10);
	m_btnList.SetDown();
	m_bInitDialog = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDlgMMLeftDevices::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgMMLeftDevices::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLD_TOOL_HEIGHT;
	if(m_nCurrPanel == MMLD_PANEL_TREE)
		m_DeviceTree.MoveWindow(&rect2);
	else
		m_DeviceGroup.MoveWindow(&rect2);
}

void CDlgMMLeftDevices::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CDlgMMLeftDevices::SetMultiWinPtr(void *pMultiWin)
{
	m_DeviceTree.SetMultiWinPtr(pMultiWin);
}
void CDlgMMLeftDevices::TabButtonsUp()
{
	m_btnList.SetUp();
	m_btnGroup.SetUp();
}
void CDlgMMLeftDevices::OnBtnList() 
{
	if(m_nCurrPanel == MMLD_PANEL_TREE)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLD_TOOL_HEIGHT;
	m_DeviceGroup.ShowWindow(SW_HIDE);
	m_DeviceTree.MoveWindow(&rect2);
	m_DeviceTree.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLD_PANEL_TREE;
	TabButtonsUp();
	m_btnList.SetDown();
}

void CDlgMMLeftDevices::OnBtnGroup() 
{
	if(m_nCurrPanel == MMLD_PANEL_GROUP)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLD_TOOL_HEIGHT;
	m_DeviceTree.ShowWindow(SW_HIDE);
	m_DeviceGroup.MoveWindow(&rect2);
	m_DeviceGroup.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLD_PANEL_GROUP;
	TabButtonsUp();
	m_btnGroup.SetDown();
}

