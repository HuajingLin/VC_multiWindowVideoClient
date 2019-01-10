// DlgMMRightTool.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMRightTool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMRightTool dialog


CDlgMMRightTool::CDlgMMRightTool(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMRightTool::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMRightTool)
	//}}AFX_DATA_INIT
	m_bInitDlg = false;
	m_pMVideo = NULL;
}


void CDlgMMRightTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMRightTool)
	DDX_Control(pDX, IDC_BTN_PREVI, m_btnPrevi);
	DDX_Control(pDX, IDC_BTN_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BTN_FULLSCREEN, m_btnFullscreen);
	DDX_Control(pDX, IDC_BTN_PANE4, m_btnPane4);
	DDX_Control(pDX, IDC_BTN_PANE9, m_btnPane9);
	DDX_Control(pDX, IDC_BTN_PANE64, m_btnPane64);
	DDX_Control(pDX, IDC_BTN_PANE6, m_btnPane6);
	DDX_Control(pDX, IDC_BTN_PANE36, m_btnPane36);
	DDX_Control(pDX, IDC_BTN_PANE16, m_btnPane16);
	DDX_Control(pDX, IDC_BTN_PANE13, m_btnPane13);
	DDX_Control(pDX, IDC_BTN_PANE10, m_btnPane10);
	DDX_Control(pDX, IDC_BTN_PANE1, m_btnPane1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMRightTool, CDialog)
	//{{AFX_MSG_MAP(CDlgMMRightTool)
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_PANE1, OnBtnPane1)
	ON_BN_CLICKED(IDC_BTN_PANE4, OnBtnPane4)
	ON_BN_CLICKED(IDC_BTN_PANE6, OnBtnPane6)
	ON_BN_CLICKED(IDC_BTN_PANE9, OnBtnPane9)
	ON_BN_CLICKED(IDC_BTN_PANE10, OnBtnPane10)
	ON_BN_CLICKED(IDC_BTN_PANE13, OnBtnPane13)
	ON_BN_CLICKED(IDC_BTN_PANE16, OnBtnPane16)
	ON_BN_CLICKED(IDC_BTN_PANE36, OnBtnPane36)
	ON_BN_CLICKED(IDC_BTN_PANE64, OnBtnPane64)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMRightTool message handlers

BOOL CDlgMMRightTool::OnInitDialog() 
{
	CDialog::OnInitDialog();
	TCHAR tStr[STR_LEN];
	m_btnFullscreen.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnFullscreen.LoadBitmaps (IDB_BTN_FULL,IDB_BTN_FULL_D,IDB_BTN_FULL_O,0,IDC_BTN_FULLSCREEN);
	m_btnFullscreen.SizeToContent();
	m_btnFullscreen.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("FullScreen",tStr))
		m_btnFullscreen.SetTooltipText(tStr);
	else
		m_btnFullscreen.SetTooltipText("Full Screen");

	m_btnPrevi.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnPrevi.LoadBitmaps (IDB_BTN_PREVI,IDB_BTN_PREVI_D,IDB_BTN_PREVI_O,0,IDC_BTN_PREVI);
	m_btnPrevi.SizeToContent();
	m_btnPrevi.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("FrontPage",tStr))
		m_btnPrevi.SetTooltipText(tStr);
	else
		m_btnPrevi.SetTooltipText("Front Page");

	m_btnNext.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnNext.LoadBitmaps (IDB_BTN_NEXT,IDB_BTN_NEXT_D,IDB_BTN_NEXT_O,0,IDC_BTN_NEXT);
	m_btnNext.SizeToContent();
	m_btnNext.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("BackPage",tStr))
		m_btnNext.SetTooltipText(tStr);
	else
		m_btnNext.SetTooltipText("Back Page");

	m_btnPane1.SetSkin(IDB_BTN_01PANE,IDB_BTN_01PANE_D,IDB_BTN_01PANE_O);
	m_btnPane1.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane4.SetSkin(IDB_BTN_04PANE,IDB_BTN_04PANE_D,IDB_BTN_04PANE_O);
	m_btnPane4.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane4.SetDown();
	m_btnPane6.SetSkin(IDB_BTN_06PANE,IDB_BTN_06PANE_D,IDB_BTN_06PANE_O);
	m_btnPane6.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane9.SetSkin(IDB_BTN_09PANE,IDB_BTN_09PANE_D,IDB_BTN_09PANE_O);
	m_btnPane9.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane10.SetSkin(IDB_BTN_10PANE,IDB_BTN_10PANE_D,IDB_BTN_10PANE_O);
	m_btnPane10.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane13.SetSkin(IDB_BTN_13PANE,IDB_BTN_13PANE_D,IDB_BTN_13PANE_O);
	m_btnPane13.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane16.SetSkin(IDB_BTN_16PANE,IDB_BTN_16PANE_D,IDB_BTN_16PANE_O);
	m_btnPane16.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane36.SetSkin(IDB_BTN_36PANE,IDB_BTN_36PANE_D,IDB_BTN_36PANE_O);
	m_btnPane36.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_btnPane64.SetSkin(IDB_BTN_64PANE,IDB_BTN_64PANE_D,IDB_BTN_64PANE_O);
	m_btnPane64.SetWindowPos(&wndTop, 0, 0, 19, 19, SWP_NOMOVE);
	m_bInitDlg = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMMRightTool::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	RECT rect;
	GetClientRect(&rect);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_MWIN_TOP_BACK);
	CBrush m_brush(&bmpBackground);
	dc.FillRect(&rect,&m_brush);	
	// Do not call CDialog::OnPaint() for painting messages
}

void CDlgMMRightTool::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(!m_bInitDlg)
		return;
	//RECT rect;
	//GetClientRect(&rect);
}

void CDlgMMRightTool::SetMVideoPtr(void* pMVideo)
{
	m_pMVideo = (CMultiWindow*)pMVideo;
}
void CDlgMMRightTool::SetAllPanelBtnUp()
{
	m_btnPane4.SetUp();
	m_btnPane9.SetUp();
	m_btnPane64.SetUp();
	m_btnPane6.SetUp();
	m_btnPane36.SetUp();
	m_btnPane16.SetUp();
	m_btnPane13.SetUp();
	m_btnPane10.SetUp();
	m_btnPane1.SetUp();
}
void CDlgMMRightTool::OnBtnPane1() 
{
	m_pMVideo->SplitWindow(1);
	SetAllPanelBtnUp();
	m_btnPane1.SetDown();
}

void CDlgMMRightTool::OnBtnPane4() 
{
	m_pMVideo->SplitWindow(4);
	SetAllPanelBtnUp();
	m_btnPane4.SetDown();
}

void CDlgMMRightTool::OnBtnPane6() 
{
	m_pMVideo->SplitWindow(6);
	SetAllPanelBtnUp();
	m_btnPane6.SetDown();
}

void CDlgMMRightTool::OnBtnPane9() 
{
	m_pMVideo->SplitWindow(9);
	SetAllPanelBtnUp();
	m_btnPane9.SetDown();
}

void CDlgMMRightTool::OnBtnPane10() 
{
	m_pMVideo->SplitWindow(10);
	SetAllPanelBtnUp();
	m_btnPane10.SetDown();
}

void CDlgMMRightTool::OnBtnPane13() 
{
	m_pMVideo->SplitWindow(13);
	SetAllPanelBtnUp();
	m_btnPane13.SetDown();
}

void CDlgMMRightTool::OnBtnPane16() 
{
	m_pMVideo->SplitWindow(16);
	SetAllPanelBtnUp();
	m_btnPane16.SetDown();
}

void CDlgMMRightTool::OnBtnPane36() 
{
	m_pMVideo->SplitWindow(36);
	SetAllPanelBtnUp();
	m_btnPane36.SetDown();
}

void CDlgMMRightTool::OnBtnPane64() 
{
	m_pMVideo->SplitWindow(64);
	SetAllPanelBtnUp();
	m_btnPane64.SetDown();
}
