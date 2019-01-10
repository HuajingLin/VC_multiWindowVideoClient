// DlgMMLeftOperate.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLeftOperate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MMLO_TOOL_HEIGHT	23
#define MMLO_PANEL_PTZ		1
#define MMLO_PANEL_PRSET	2
#define MMLO_PANEL_CRUISE	3
#define MMLO_PANEL_VIDEO	4
#define MMLO_BK_COLOR RGB(0x28,0x2B,0x32)
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftOperate dialog


CDlgMMLeftOperate::CDlgMMLeftOperate(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLeftOperate::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLeftOperate)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_nCurrPanel = 0;
	m_bkBrush.CreateSolidBrush(MMLO_BK_COLOR);
}


void CDlgMMLeftOperate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLeftOperate)
	DDX_Control(pDX, IDC_BTN_VPARAM, m_btnVParam);
	DDX_Control(pDX, IDC_BTN_PTZ, m_btnPtz);
	DDX_Control(pDX, IDC_BTN_PRESET, m_btnPreset);
	DDX_Control(pDX, IDC_BTN_CRUISE, m_btnCruise);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLeftOperate, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLeftOperate)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_PTZ, OnBtnPtz)
	ON_BN_CLICKED(IDC_BTN_PRESET, OnBtnPreset)
	ON_BN_CLICKED(IDC_BTN_CRUISE, OnBtnCruise)
	ON_BN_CLICKED(IDC_BTN_VPARAM, OnBtnVParam)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftOperate message handlers

void CDlgMMLeftOperate::SetMultiWinPtr(void *pMultiWin)
{
	m_PanelPtz.SetMultiWinPtr(pMultiWin);
}

BOOL CDlgMMLeftOperate::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_btnPtz.SetSkin(IDB_TAB_BACK12,IDB_TAB_BACK11);
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("PTZ",tStr))
		m_btnPtz.SetText(tStr,5);
	else
		m_btnPtz.SetText("PTZ",5);
	m_btnPtz.SetDown();

	m_btnPreset.SetSkin(IDB_TAB_BACK12,IDB_TAB_BACK11);
	if(g_GetLanguage("Preset",tStr))
		m_btnPreset.SetText(tStr,3);
	else
		m_btnPreset.SetText("Preset",5);

	m_btnCruise.SetSkin(IDB_TAB_BACK12,IDB_TAB_BACK11);
	if(g_GetLanguage("Cruise",tStr))
		m_btnCruise.SetText(tStr,5);
	else
		m_btnCruise.SetText("Cruise",5);
	m_btnVParam.SetSkin(IDB_TAB_BACK12,IDB_TAB_BACK11);
	if(g_GetLanguage("Video",tStr))
		m_btnVParam.SetText(tStr,5);
	else
		m_btnVParam.SetText("Video",5);

	m_PanelPtz.Create(IDD_MMLO_PTZ,this);	
	m_PanelPreset.Create(IDD_MMLO_PRESET,this);
	m_PanelCruise.Create(IDD_MMLO_CRUISE,this);
	m_PanelVParam.Create(IDD_MMLO_VIDEO_PARAM,this);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top = MMLO_TOOL_HEIGHT;
	m_PanelPtz.MoveWindow(&rect2);
	m_PanelPtz.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLO_PANEL_PTZ;
	m_bInitDialog = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDlgMMLeftOperate::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
void CDlgMMLeftOperate::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog)
		return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLO_TOOL_HEIGHT;
	if(m_nCurrPanel == MMLO_PANEL_PTZ)
		m_PanelPtz.MoveWindow(&rect2);
	//
}
void CDlgMMLeftOperate::TabButtonsUp()
{
	m_btnVParam.SetUp();
	m_btnPtz.SetUp();
	m_btnPreset.SetUp();
	m_btnCruise.SetUp();
}
void CDlgMMLeftOperate::OnBtnPtz() 
{
	if(m_nCurrPanel == MMLO_PANEL_PTZ)
		return;
	m_PanelPreset.ShowWindow(SW_HIDE);
	m_PanelCruise.ShowWindow(SW_HIDE);
	m_PanelVParam.ShowWindow(SW_HIDE);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLO_TOOL_HEIGHT;
	m_PanelPtz.MoveWindow(&rect2);
	m_PanelPtz.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLO_PANEL_PTZ;
	TabButtonsUp();
	m_btnPtz.SetDown();
}

void CDlgMMLeftOperate::OnBtnPreset() 
{
	if(m_nCurrPanel == MMLO_PANEL_PRSET)
		return;
	m_PanelPtz.ShowWindow(SW_HIDE);
	m_PanelCruise.ShowWindow(SW_HIDE);
	m_PanelVParam.ShowWindow(SW_HIDE);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLO_TOOL_HEIGHT;
	m_PanelPreset.MoveWindow(&rect2);
	m_PanelPreset.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLO_PANEL_PRSET;
	TabButtonsUp();
	m_btnPreset.SetDown();
}

void CDlgMMLeftOperate::OnBtnCruise() 
{
	if(m_nCurrPanel == MMLO_PANEL_CRUISE)
		return;
	m_PanelPtz.ShowWindow(SW_HIDE);
	m_PanelPreset.ShowWindow(SW_HIDE);
	m_PanelVParam.ShowWindow(SW_HIDE);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLO_TOOL_HEIGHT;
	m_PanelCruise.MoveWindow(&rect2);
	m_PanelCruise.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLO_PANEL_CRUISE;
	TabButtonsUp();
	m_btnCruise.SetDown();
}

void CDlgMMLeftOperate::OnBtnVParam() 
{
	if(m_nCurrPanel == MMLO_PANEL_VIDEO)
		return;
	m_PanelPtz.ShowWindow(SW_HIDE);
	m_PanelPreset.ShowWindow(SW_HIDE);
	m_PanelCruise.ShowWindow(SW_HIDE);
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.left = 2;
	rect2.right -= 2;
	rect2.top = MMLO_TOOL_HEIGHT;
	m_PanelVParam.MoveWindow(&rect2);
	m_PanelVParam.ShowWindow(SW_SHOW);
	m_nCurrPanel = MMLO_PANEL_VIDEO;
	TabButtonsUp();
	m_btnVParam.SetDown();
}
