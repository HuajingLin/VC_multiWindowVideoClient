// DlgLogin.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog
extern BYTE	g_nLangu;
#define LOGIN_EXPAND_HEIGHT 160
//---test-------------------------------------------------
typedef UINT (*GETSTRBYSTR)(LPCTSTR, LPTSTR, const UINT);
extern GETSTRBYSTR GetStrByStr;
extern HINSTANCE hinstMultiLanguage;
typedef bool (*SWITCHLANGUAGE)(LPCTSTR str,const LANGID);
//--------------------------------------------------------
CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgLogin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDialog = false;
	m_bExpand = false;
}


void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgLogin)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialog)
	//{{AFX_MSG_MAP(CDlgLogin)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RADIO_CN, OnRadioCn)
	ON_BN_CLICKED(IDC_RADIO_EN, OnRadioEn)
	ON_BN_CLICKED(IDC_CHECK_LOGIN, OnCheckLogin)
	ON_BN_CLICKED(IDC_BTN_MODIFY, OnBtnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgLogin message handlers

BOOL CDlgLogin::OnInitDialog() 
{
	CDialog::OnInitDialog();
	ModifyStyleEx(0, WS_EX_APPWINDOW);
	if(!HD_Initialize(DATA_MODE_ALONE))
	{
		MessageBox("Initialize fail.","Tips");
		GetDlgItem(IDOK)->EnableWindow(FALSE);
		return FALSE;
	}
	LOGIN_SYS_DATA LoginData;
	memset(&LoginData,0,sizeof(LoginData));
	HD_GetLoginData(&LoginData);
	((CComboBox*)GetDlgItem(IDC_COMBO_USER))->AddString(LoginData.User);
	((CComboBox*)GetDlgItem(IDC_COMBO_USER))->SetCurSel(0);
	if(LoginData.bAuto)
	{
		int nRet = 1;//HD_SysUserLogin(LoginData.User, LoginData.Pwd);
		if(!nRet)
		{
			TCHAR tStr[STR_LEN];
			if(g_GetLanguage("UserOrPwdErr",tStr))
				GetDlgItem(IDC_STATIC_INFO)->SetWindowText(tStr);
			else
				GetDlgItem(IDC_STATIC_INFO)->SetWindowText("User or password error.");
			GetDlgItem(IDC_STATIC_INFO)->ShowWindow(FALSE);
			GetDlgItem(IDC_STATIC_INFO)->ShowWindow(TRUE);
		}
		else
		{
			CDialog::OnOK();
			return IDOK;
		}
	}
	g_nLangu = LoginData.nLang;
	if(g_nLangu==LANGUAGE_CN)
	{
		CButton *pChkLang = (CButton *)GetDlgItem(IDC_RADIO_CN);
		pChkLang->SetCheck(BST_CHECKED);
		pChkLang = (CButton *)GetDlgItem(IDC_RADIO_EN);
		pChkLang->SetCheck(BST_UNCHECKED);
		OnRadioCn();
	}
	else if(g_nLangu==LANGUAGE_EN)
	{
		CButton *pChkLang = (CButton *)GetDlgItem(IDC_RADIO_EN);
		pChkLang->SetCheck(BST_CHECKED);
		pChkLang = (CButton *)GetDlgItem(IDC_RADIO_CN);
		pChkLang->SetCheck(BST_UNCHECKED);
		OnRadioEn();
	}
	m_ModiPwd.Create(IDD_MODI_PWD,this);
	LoadLang();
	m_bInitDialog = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH CDlgLogin::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_STATIC)
	{
		switch(pWnd->GetDlgCtrlID()) 
		{   
		case IDC_STATIC_INFO:     
			pDC->SetTextColor(RGB(0xFF,0,0));   
			break;
		default:;
		}
		pDC->SetBkMode(TRANSPARENT); 
		return (HBRUSH)::GetStockObject(NULL_BRUSH); 
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgLogin::OnOK() 
{
	CString strUser,strPwd;
	GetDlgItem(IDC_COMBO_USER)->GetWindowText(strUser);
	if(strUser.GetLength() > 30) return;
	GetDlgItem(IDC_EDIT_PWD)->GetWindowText(strPwd);
	if(strUser.GetLength() > 30) return;
	int nPermit = 0;
	int nRet = HD_SysUserLogin(strUser, strPwd, &nPermit);
	if(!nRet)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("UserOrPwdErr",tStr))
			GetDlgItem(IDC_STATIC_INFO)->SetWindowText(tStr);
		else
			GetDlgItem(IDC_STATIC_INFO)->SetWindowText("User or password error.");
		GetDlgItem(IDC_STATIC_INFO)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_INFO)->ShowWindow(TRUE);
		return;
	}
	m_strUser = strUser;
	CDialog::OnOK();
}

void CDlgLogin::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CDlgLogin::OnRadioCn() 
{
	g_nLangu = LANGUAGE_CN;
	SWITCHLANGUAGE SwitchLanguage = NULL;
	SwitchLanguage = (SWITCHLANGUAGE) GetProcAddress(hinstMultiLanguage, "SwitchLanguage");
	if (NULL == SwitchLanguage)
	{
		AfxMessageBox(TEXT("Load SwitchLanguage Failed.\n"));
		return ;
	}
	LANGID LangID=0x0804;
	bool ret = SwitchLanguage("",LangID);
	if(!ret)
	{
		AfxMessageBox("Switch Language error!");
		return ;
	}
	HD_SetLanguageID(g_nLangu);
	LoadLang();
	if(m_bInitDialog)
		m_ModiPwd.LoadLangu();
	Invalidate();
}

void CDlgLogin::OnRadioEn() 
{
	g_nLangu = LANGUAGE_EN;
	SWITCHLANGUAGE SwitchLanguage = NULL;
	SwitchLanguage = (SWITCHLANGUAGE) GetProcAddress(hinstMultiLanguage, "SwitchLanguage");
	if (NULL == SwitchLanguage)
	{
		AfxMessageBox(TEXT("Load SwitchLanguage Failed.\n"));
		return ;
	}
	LANGID LangID=0x0409;
	bool ret = SwitchLanguage("",LangID);
	if(!ret)
	{
		AfxMessageBox("Switch Language error!");
		return ;
	}
	HD_SetLanguageID(g_nLangu);
	LoadLang();
	if(m_bInitDialog)
		m_ModiPwd.LoadLangu();
	Invalidate();
}

void CDlgLogin::OnCheckLogin() 
{
	bool bAuto = false;
	if(((CButton*)GetDlgItem(IDC_CHECK_LOGIN))->GetCheck())
		bAuto = true;
	HD_SetAutoLogin(bAuto);
}

void CDlgLogin::OnBtnModify() 
{
	RECT rect;
	if(m_bExpand)
	{
		m_bExpand = false;
		GetWindowRect(&rect);
		rect.bottom -= LOGIN_EXPAND_HEIGHT;
		MoveWindow(&rect);
	}
	else
	{
		m_bExpand = true;
		GetWindowRect(&rect);
		rect.bottom += LOGIN_EXPAND_HEIGHT;
		MoveWindow(&rect);		
		m_ModiPwd.ShowWindow(SW_SHOW);
		
		GetClientRect(&rect);	
		rect.top += 210;
		m_ModiPwd.MoveWindow(&rect);
	}
}
void CDlgLogin::GetUserName(CString& User)
{
	GetDlgItem(IDC_COMBO_USER)->GetWindowText(User);
}
void CDlgLogin::SetTipsInfo(CString& str)
{
	GetDlgItem(IDC_STATIC_INFO)->SetWindowText(str);
	GetDlgItem(IDC_STATIC_INFO)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_INFO)->ShowWindow(TRUE);
}
void CDlgLogin::LoadLang()
{	
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("Login", tStr))
		SetWindowText(tStr);
	else
		SetWindowText("Login");
	if(g_GetLanguage("User",tStr))
	{
		strcat(tStr, ":");
		GetDlgItem(IDC_STATIC_USER)->SetWindowText(tStr);
	}
	else
		GetDlgItem(IDC_STATIC_USER)->SetWindowText("User:");
	if(g_GetLanguage("Password",tStr))
	{
		strcat(tStr, ":");
		GetDlgItem(IDC_STATIC_PASSWORD)->SetWindowText(tStr);
	}
	else
		GetDlgItem(IDC_STATIC_PASSWORD)->SetWindowText("Password:");
	if(g_GetLanguage("Languge", tStr))
	{
		strcat(tStr, ":");
		GetDlgItem(IDC_STATIC_LANGUAGE)->SetWindowText(tStr);
	}
	else
		GetDlgItem(IDC_STATIC_LANGUAGE)->SetWindowText("Language:");
	if(g_GetLanguage("AutoLogin", tStr))
		GetDlgItem(IDC_CHECK_LOGIN)->SetWindowText(tStr);
	else
		GetDlgItem(IDC_CHECK_LOGIN)->SetWindowText("Auto Login");
	if(g_GetLanguage("ModifyPwd", tStr))
		GetDlgItem(IDC_BTN_MODIFY)->SetWindowText(tStr);
	else
		GetDlgItem(IDC_BTN_MODIFY)->SetWindowText("Modify Password");
	if(g_GetLanguage("Login", tStr))
		GetDlgItem(IDOK)->SetWindowText(tStr);
	else
		GetDlgItem(IDOK)->SetWindowText("Login");
	if(g_GetLanguage("Exit", tStr))
		GetDlgItem(IDCANCEL)->SetWindowText(tStr);
	else
		GetDlgItem(IDCANCEL)->SetWindowText("Exit");
}