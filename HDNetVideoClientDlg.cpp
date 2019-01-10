// HDNetVideoClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "HDNetVideoClientDlg.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef bool (*SWITCHLANGUAGE)(LPCTSTR str,const LANGID);
typedef UINT (*GETSTRBYSTR)(LPCTSTR, LPTSTR, const UINT);
BYTE		g_nLangu;		//全局变量 语言 0:Chinese; 1:English
HINSTANCE	hinstMultiLanguage = NULL;
GETSTRBYSTR GetStrByStr = NULL;
			
#define MAIN_TOOL_HEIGHT 40	//主窗口工具条高度

typedef enum _eSysModule
{
	eModuleMonior	= 1,	//模块监控
	eModuleMap,				//模块地图
	eModulePlayback,		//模块回放
	eModuleConfig,			//模块配置
	eModuleLog,				//模块日志
	eModuleHelp
}E_SYS_MODULE;

TCHAR* g_GetLanguage(LPCTSTR str,TCHAR* pStrBuf)
{
	UINT len =0;
	len = (GetStrByStr) (TEXT(str), pStrBuf, STR_LEN);
	if(len)
		return pStrBuf;
	else
		return NULL;
}
/////////////////////////////////////////////////////////////////////////////
// CHDNetVideoClientDlg dialog

CHDNetVideoClientDlg::CHDNetVideoClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHDNetVideoClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHDNetVideoClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bInitDialog = false;
	m_nCurrModule = eModuleMonior;
}

void CHDNetVideoClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHDNetVideoClientDlg)
	DDX_Control(pDX, IDC_BTN_CONFIG, m_btnConfig);
	DDX_Control(pDX, IDC_BTN_HELP, m_btnHelp);
	DDX_Control(pDX, IDC_BTN_LOG, m_btnLog);
	DDX_Control(pDX, IDC_BTN_MAP, m_btnMap);
	DDX_Control(pDX, IDC_BTN_MONITOR, m_btnMonitor);
	DDX_Control(pDX, IDC_LBL_TOOL_BAR, m_bkToolbar);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHDNetVideoClientDlg, CDialog)
	//{{AFX_MSG_MAP(CHDNetVideoClientDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_MONITOR, OnBtnMonitor)
	ON_BN_CLICKED(IDC_BTN_CONFIG, OnBtnConfig)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_LOG, OnBtnLog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHDNetVideoClientDlg message handlers

BOOL CHDNetVideoClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//加载语言库
	SWITCHLANGUAGE SwitchLanguage = NULL;
	hinstMultiLanguage = LoadLibrary(TEXT("MultiLangu.dll"));
	if (hinstMultiLanguage == NULL)
	{
		AfxMessageBox(TEXT("Load MultiLanguage.dll Failed."));
		OnCancel();
		return TRUE;
	}
	GetStrByStr = (GETSTRBYSTR) GetProcAddress(hinstMultiLanguage, "GetStrByStr");
	if (NULL == GetStrByStr)
	{
		AfxMessageBox(TEXT("Load GetStrByStr Failed.\n"));
		OnCancel();
		return TRUE;
	}
	SwitchLanguage = (SWITCHLANGUAGE) GetProcAddress(hinstMultiLanguage, "SwitchLanguage");
	if (NULL == SwitchLanguage)
	{
		AfxMessageBox(TEXT("Load SwitchLanguage Failed.\n"));
		OnCancel();
		return 0;
	}
	/*/登录
	CDlgLogin DlgLogin(this);
	if(DlgLogin.DoModal() != IDOK)
	{
		OnCancel();
		return TRUE;
	}*/
	//加载语言
	LANGID LangID=0x0804;
	if(g_nLangu==LANGUAGE_CN)
	{
		LangID=0x0804;
	}
	else if(g_nLangu==LANGUAGE_EN)
	{
		LangID=0x0409;
	}
	bool ret = SwitchLanguage("",LangID);
	if(!ret)
	{
		AfxMessageBox("Switch Language error!");
		OnCancel();
		return 0;
	}
	m_bkToolbar.SetBitmapID(IDB_MAIN_TOP_BACK);
 	RECT rect;
 	GetClientRect(&rect);
 	RECT rect2 = rect;
 	rect2.bottom = MAIN_TOOL_HEIGHT;
 	m_bkToolbar.MoveWindow(&rect2);

	/*int nLeft = 1;
	int nTop = 2;
	m_btnMonitor.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnMonitor.LoadBitmaps (IDB_BTN_MONITOR,
		IDB_BTN_MONITOR2, NULL,NULL, IDC_BTN_MONITOR);
	m_btnMonitor.SizeToContent();
	m_btnMonitor.SetWindowPos (&wndTop, nLeft, nTop, 0, 0, SWP_NOSIZE);
	m_btnMonitor.SetTooltipText("放大");
	m_btnTab1.SetText(strLang,10);
	*/
	if(g_nLangu == LANGUAGE_CN)
	{
		m_btnMonitor.SetSkin(IDB_BTN_MONITOR,IDB_BTN_MONITOR2,IDB_BTN_MONITOR3);
		m_btnConfig.SetSkin(IDB_BTN_CONFIG1,IDB_BTN_CONFIG2,IDB_BTN_CONFIG3);
		m_btnLog.SetSkin(IDB_BTN_LOG1,IDB_BTN_LOG2,IDB_BTN_LOG3);
	}
	else
	{
		m_btnMonitor.SetSkin(IDB_BTN_MONITOR1_EN,IDB_BTN_MONITOR2_EN,IDB_BTN_MONITOR3_EN);
		m_btnConfig.SetSkin(IDB_BTN_CONFIG1_EN,IDB_BTN_CONFIG2_EN,IDB_BTN_CONFIG3_EN);
		m_btnLog.SetSkin(IDB_BTN_LOG1_EN,IDB_BTN_LOG2_EN,IDB_BTN_LOG3_EN);
	}
	m_btnMonitor.SetDown();

	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("NetVideoMonitor",tStr))
		SetWindowText(tStr);
	if(g_GetLanguage("Version",tStr))
		GetDlgItem(IDC_STATIC_VERSION)->SetWindowText(tStr);
	if(g_GetLanguage("User",tStr))
	{
		strcat(tStr,": ");
		strcat(tStr,"admin");//DlgLogin.m_strUser);
	}
	else
	{
		memset(tStr,0,STR_LEN);
		strcat(tStr,"User: ");
		strcat(tStr,"admin");//DlgLogin.m_strUser);
	}
	GetDlgItem(IDC_STATIC_USER)->SetWindowText(tStr);
	
	m_ModuleMonitor.Create(IDD_MODULE_MONITOR,this);
	m_ModuleMonitor.ShowWindow(SW_SHOW);
	m_ModuleConfig.Create(IDD_MODULE_CONFIG,this);
	m_ModuleConfig.ShowWindow(SW_HIDE);
	
	rect2 = rect;
	rect2.top += MAIN_TOOL_HEIGHT;
	m_ModuleMonitor.MoveWindow(&rect2);
	m_nCurrModule = eModuleMonior;
	m_bInitDialog = true;
	return TRUE;  // return TRUE  unless you set the focus to a control
}
HBRUSH CHDNetVideoClientDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_STATIC) // || nCtlColor==CTLCOLOR_EDIT
	{ 
		pDC->SetBkMode(TRANSPARENT); 
		pDC->SetTextColor(RGB(255,255,255));
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHDNetVideoClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHDNetVideoClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CHDNetVideoClientDlg::PreTranslateMessage(MSG* pMsg) 
{
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	{
		if(pMsg->wParam==VK_RETURN || pMsg->wParam==VK_ESCAPE)
			return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CHDNetVideoClientDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if(!m_bInitDialog) return;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.bottom = MAIN_TOOL_HEIGHT;
	m_bkToolbar.MoveWindow(&rect2);
	rect2 = rect;
	rect2.top = 20;
	rect2.left = rect2.right - 200;
	GetDlgItem(IDC_STATIC_USER)->MoveWindow(&rect2);

	rect2 = rect;
	rect2.top += MAIN_TOOL_HEIGHT;
	if(m_nCurrModule == eModuleMonior)
		m_ModuleMonitor.MoveWindow(&rect2);
	else if(m_nCurrModule == eModuleConfig)
		m_ModuleConfig.MoveWindow(&rect2);
}
void CHDNetVideoClientDlg::MainButtonsUp()
{
	m_btnConfig.SetUp();
	m_btnHelp.SetUp();
	m_btnLog.SetUp();
	m_btnMap.SetUp();
	m_btnMonitor.SetUp();
}
void CHDNetVideoClientDlg::OnBtnMonitor()  //显示模块-监控
{
	if(m_nCurrModule == eModuleMonior)
		return;
	MainButtonsUp();
	m_btnMonitor.SetDown();
	m_nCurrModule = eModuleMonior;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top += MAIN_TOOL_HEIGHT;
	m_ModuleMonitor.MoveWindow(&rect2);
	m_ModuleConfig.ShowWindow(SW_HIDE);
	m_ModuleMonitor.ShowWindow(SW_SHOW);
}

void CHDNetVideoClientDlg::OnBtnConfig()  //显示模块-配置
{
	if(m_nCurrModule == eModuleConfig)
		return;
	MainButtonsUp();
	m_btnConfig.SetDown();
	m_nCurrModule = eModuleConfig;
	RECT rect;
	GetClientRect(&rect);
	RECT rect2 = rect;
	rect2.top += MAIN_TOOL_HEIGHT;
	m_ModuleConfig.MoveWindow(&rect2);
	m_ModuleMonitor.ShowWindow(SW_HIDE);
	m_ModuleConfig.ShowWindow(SW_SHOW);
}

void CHDNetVideoClientDlg::OnBtnLog() 
{
	MainButtonsUp();
	if(m_nCurrModule == eModuleConfig)
		m_btnConfig.SetDown();
	else if(m_nCurrModule == eModuleMonior)
		m_btnMonitor.SetDown();	
}
void CHDNetVideoClientDlg::OnDestroy() 
{
	HD_Destroy();
	CDialog::OnDestroy();
}

