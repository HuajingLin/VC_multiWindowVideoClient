// DlgModuleMonitor.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgModuleMonitor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgModuleMonitor dialog
#define MM_LEFT_PANEL_WIDTH 223		//Ä£¿é¼à¿Ø×óÃæ°å¿í

CDlgModuleMonitor::CDlgModuleMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgModuleMonitor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgModuleMonitor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
}


void CDlgModuleMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgModuleMonitor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgModuleMonitor, CDialog)
	//{{AFX_MSG_MAP(CDlgModuleMonitor)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgModuleMonitor message handlers

BOOL CDlgModuleMonitor::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_MonitorLeft.Create(IDD_MM_LEFT,this);
	m_MonitorRight.Create(IDD_MM_RIGHT,this);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.right = MM_LEFT_PANEL_WIDTH;
	m_MonitorLeft.MoveWindow(&rect2);
	m_MonitorLeft.ShowWindow(SW_SHOW);
	rect2 = rect;
	rect2.left = MM_LEFT_PANEL_WIDTH;
	m_MonitorRight.MoveWindow(&rect2);
	m_MonitorRight.ShowWindow(SW_SHOW);
	m_bInitDialog = true;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgModuleMonitor::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.right = MM_LEFT_PANEL_WIDTH;
	m_MonitorLeft.MoveWindow(&rect2);
	rect2 = rect;
	rect2.left = MM_LEFT_PANEL_WIDTH;
	m_MonitorRight.MoveWindow(&rect2);
}
void CDlgModuleMonitor::SetMultiWinPtr(void* pMultiWin)
{
	m_MonitorLeft.SetMultiWinPtr(pMultiWin);
}