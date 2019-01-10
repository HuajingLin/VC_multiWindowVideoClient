// DlgMMonitorRight.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMonitorRight.h"
#include "DlgModuleMonitor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMonitorRight dialog
#define MMR_TOOL_HEIGHT 25
#define MMR_LIST_HEIGHT 100
#define MMR_BK_COLOR RGB(0x0,0x0,0x0)

CDlgMMonitorRight::CDlgMMonitorRight(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMonitorRight::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMonitorRight)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_bkBrush.CreateSolidBrush(MMR_BK_COLOR);
}


void CDlgMMonitorRight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMonitorRight)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMonitorRight, CDialog)
	//{{AFX_MSG_MAP(CDlgMMonitorRight)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMonitorRight message handlers

BOOL CDlgMMonitorRight::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_PanelTool.Create(IDD_MMR_TOOL,this);
	m_PanelList.Create(IDD_MMR_LIST,this);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.bottom = MMR_TOOL_HEIGHT;
	m_PanelTool.MoveWindow(&rect2);
	m_PanelTool.ShowWindow(SW_SHOW);
	
	rect2 = rect;
	rect2.top = MMR_TOOL_HEIGHT;
	rect2.bottom = rect.bottom - MMR_LIST_HEIGHT;
	m_MultiWindow.Create(NULL,NULL,WS_VISIBLE|WS_CHILD|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, rect2, this, IDC_MULTI_WIN);
	m_MultiWindow.SplitWindow(4);
	m_PanelTool.SetMVideoPtr(&m_MultiWindow);

	rect2 = rect;
	rect2.top = rect.bottom - MMR_LIST_HEIGHT;
	m_PanelList.MoveWindow(&rect2);
	m_PanelList.ShowWindow(SW_SHOW);
	CDlgModuleMonitor* pMonitor = (CDlgModuleMonitor*)GetParent();
	pMonitor->SetMultiWinPtr(&m_MultiWindow);
	m_bInitDialog = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
HBRUSH CDlgMMonitorRight::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
void CDlgMMonitorRight::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog) return;
	RECT rect;
	GetClientRect(&rect);
	rect.left = 1;
	rect.right -= 1;
	RECT rect2 = rect;
	rect2.bottom = MMR_TOOL_HEIGHT;
	m_PanelTool.MoveWindow(&rect2);
	m_PanelTool.ShowWindow(SW_SHOW);
	
	rect2 = rect;
	rect2.top = MMR_TOOL_HEIGHT;
	rect2.bottom = rect.bottom - MMR_LIST_HEIGHT;
	m_MultiWindow.MoveWindow(&rect2);
	
	rect2 = rect;
	rect2.top = rect.bottom - MMR_LIST_HEIGHT;
	m_PanelList.MoveWindow(&rect2);
	m_PanelList.ShowWindow(SW_SHOW);
}
