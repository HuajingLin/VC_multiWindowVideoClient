// DlgMMonitorLeft.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMonitorLeft.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMonitorLeft dialog
#define MM_OPERATE_PANEL_HEIGHT 223		//模块监控操作面板高
#define MML_BK_COLOR RGB(0x28,0x2B,0x32)
CDlgMMonitorLeft::CDlgMMonitorLeft(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMonitorLeft::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMonitorLeft)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_bkBrush.CreateSolidBrush(MML_BK_COLOR);
}


void CDlgMMonitorLeft::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMonitorLeft)
	//
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMonitorLeft, CDialog)
	//{{AFX_MSG_MAP(CDlgMMonitorLeft)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMonitorLeft message handlers

BOOL CDlgMMonitorLeft::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_PanelOperate.Create(IDD_MML_OPERATE,this);
	m_PanelPlay.Create(IDD_MML_PLAY,this);
	m_PanelDevices.Create(IDD_MML_DEVICES,this);	
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.bottom = MM_OPERATE_PANEL_HEIGHT;
	m_PanelOperate.MoveWindow(&rect2);
	m_PanelOperate.ShowWindow(SW_SHOW);
	rect2 = rect;
	rect2.top = MM_OPERATE_PANEL_HEIGHT+2;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.bottom = rect2.top + 97;
	m_PanelPlay.MoveWindow(&rect2);
	m_PanelPlay.ShowWindow(SW_SHOW);	
	rect2 = rect;
	rect2.top = MM_OPERATE_PANEL_HEIGHT+99;
	m_PanelDevices.MoveWindow(&rect2);
	m_PanelDevices.ShowWindow(SW_SHOW);	
	m_bInitDialog = true;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDlgMMonitorLeft::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgMMonitorLeft::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog) return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.bottom = MM_OPERATE_PANEL_HEIGHT;
	m_PanelOperate.MoveWindow(&rect2);
	m_PanelOperate.ShowWindow(SW_SHOW);
	rect2 = rect;
	rect2.top = MM_OPERATE_PANEL_HEIGHT+2;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.bottom = rect2.top + 97;
	m_PanelPlay.MoveWindow(&rect2);
	m_PanelPlay.ShowWindow(SW_SHOW);	
	rect2 = rect;
	rect2.top = MM_OPERATE_PANEL_HEIGHT+99;
	m_PanelDevices.MoveWindow(&rect2);
	m_PanelDevices.ShowWindow(SW_SHOW);	
}

void CDlgMMonitorLeft::SetMultiWinPtr(void *pMultiWin)
{
	m_PanelOperate.SetMultiWinPtr(pMultiWin);
	m_PanelDevices.SetMultiWinPtr(pMultiWin);
}
