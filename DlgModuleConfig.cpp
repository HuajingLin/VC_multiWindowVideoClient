// DlgModuleConfig.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgModuleConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgModuleConfig dialog
#define MCD_TOOL_WIDTH 103
#define MCD_PANEL_DEVICE 1
#define MCD_PANEL_LOCAL	2
#define MCD_PANEL_USER	3

CDlgModuleConfig::CDlgModuleConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgModuleConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgModuleConfig)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_nCurrPanel = 0;
}


void CDlgModuleConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgModuleConfig)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgModuleConfig, CDialog)
	//{{AFX_MSG_MAP(CDlgModuleConfig)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_CONFIG_DEVI, OnBtnConfigDevice)
	ON_BN_CLICKED(IDC_BTN_CONFIG_LOCAL, OnBtnConfigLocal)
	ON_BN_CLICKED(IDC_BTN_CONFIG_USER, OnBtnConfigUser)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgModuleConfig message handlers
BOOL CDlgModuleConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_DeviceConfig.Create(IDD_MC_DEVICE, this);
	m_LocalConfig.Create(IDD_MC_LOCAL, this);
	m_UserConfig.Create(IDD_MC_USER, this);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = MCD_TOOL_WIDTH;
	m_DeviceConfig.MoveWindow(&rect2);
	m_DeviceConfig.ShowWindow(SW_SHOW);
	m_nCurrPanel = MCD_PANEL_DEVICE;
	
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("DeviceConfig",tStr))
		GetDlgItem(IDC_BTN_CONFIG_DEVI)->SetWindowText(tStr);
	if(g_GetLanguage("LocalConfig",tStr))
		GetDlgItem(IDC_BTN_CONFIG_LOCAL)->SetWindowText(tStr);
	if(g_GetLanguage("UserConfig",tStr))
		GetDlgItem(IDC_BTN_CONFIG_USER)->SetWindowText(tStr);
	m_bInitDialog = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgModuleConfig::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = MCD_TOOL_WIDTH;
	if(m_nCurrPanel == MCD_PANEL_DEVICE)
	{
		m_DeviceConfig.MoveWindow(&rect2);
	}
	else if(m_nCurrPanel == MCD_PANEL_LOCAL)
	{
		m_LocalConfig.MoveWindow(&rect2);
	}
	else if(m_nCurrPanel == MCD_PANEL_DEVICE)
	{
		m_UserConfig.MoveWindow(&rect2);
	}
}
void CDlgModuleConfig::OnBtnConfigDevice()
{
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = MCD_TOOL_WIDTH;
	m_LocalConfig.ShowWindow(SW_HIDE);
	m_UserConfig.ShowWindow(SW_HIDE);
	m_DeviceConfig.MoveWindow(&rect2);
	m_DeviceConfig.ShowWindow(SW_SHOW);
	m_nCurrPanel = MCD_PANEL_DEVICE;
}
void CDlgModuleConfig::OnBtnConfigLocal()
{
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = MCD_TOOL_WIDTH;
	m_DeviceConfig.ShowWindow(SW_HIDE);
	m_UserConfig.ShowWindow(SW_HIDE);
	m_LocalConfig.MoveWindow(&rect2);
	m_LocalConfig.ShowWindow(SW_SHOW);
	m_nCurrPanel = MCD_PANEL_LOCAL;
}
void CDlgModuleConfig::OnBtnConfigUser()
{
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = MCD_TOOL_WIDTH;
	m_DeviceConfig.ShowWindow(SW_HIDE);
	m_LocalConfig.ShowWindow(SW_HIDE);
	m_UserConfig.MoveWindow(&rect2);
	m_UserConfig.ShowWindow(SW_SHOW);
	m_nCurrPanel = MCD_PANEL_USER;
}