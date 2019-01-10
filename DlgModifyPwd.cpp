// DlgModifyPwd.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgModifyPwd.h"
#include "DlgLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyPwd dialog
extern BYTE	g_nLangu;

CDlgModifyPwd::CDlgModifyPwd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgModifyPwd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgModifyPwd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgModifyPwd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgModifyPwd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgModifyPwd, CDialog)
	//{{AFX_MSG_MAP(CDlgModifyPwd)
	ON_BN_CLICKED(IDC_BTN_OK, OnBtnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyPwd message handlers

BOOL CDlgModifyPwd::OnInitDialog() 
{
	CDialog::OnInitDialog();
	LoadLangu();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgModifyPwd::OnBtnOk() 
{
	CString strOld,strNew1,strNew2;
	GetDlgItem(IDC_EDIT_OLD)->GetWindowText(strOld);
	GetDlgItem(IDC_EDIT_NEW)->GetWindowText(strNew1);
	GetDlgItem(IDC_EDIT_NEW2)->GetWindowText(strNew2);
	CDlgLogin* pDlg = (CDlgLogin*)GetParent();
	if(strNew1 != strNew2)
	{
		CString str;
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("NewPassword",tStr))
			str = tStr;
		if(g_nLangu==LANGUAGE_EN)
			str += " ";
		if(g_GetLanguage("InputErr",tStr))
			str += tStr;
		pDlg->SetTipsInfo(str);
		return;
	}
	
	CString strUser;
	pDlg->GetUserName(strUser);
	BOOL bRet = HD_ModifyUserPwd(strUser,strOld,strNew1);
	if(bRet < 0)
	{
		CString str;
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("UserOrPwdErr",tStr))
			str = tStr;
		else
			str = "User or password error.";
		pDlg->SetTipsInfo(str);
	}
	else if(bRet == 0)
	{
		CString str;
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("ModiFail",tStr))
			str = tStr;
		else
			str = "Modify fail.";
		pDlg->SetTipsInfo(str);
	}
	else
	{
		CString str;
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("ModiSucc",tStr))
			str = tStr;
		else
			str = "Modify success.";
		pDlg->SetTipsInfo(str);
	}
}

void CDlgModifyPwd::LoadLangu()
{
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("OldPassword",tStr))
	{
		strcat(tStr,":");
		GetDlgItem(IDC_STATIC_OLD)->SetWindowText(tStr);
	}
	else
		GetDlgItem(IDC_STATIC_OLD)->SetWindowText("Old Password:");
	if(g_GetLanguage("NewPassword",tStr))
	{
		TCHAR tStr2[STR_LEN];		
		memcpy(tStr2, tStr, STR_LEN);
		strcat(tStr, ":");
		GetDlgItem(IDC_STATIC_NEW)->SetWindowText(tStr);
		
		if(g_nLangu==LANGUAGE_CN)
			memcpy(tStr, tStr2, STR_LEN);
		else
			memset(tStr, 0, STR_LEN);
		if(g_GetLanguage("Confirm",tStr2))
			strcat(tStr,tStr2);
		else
			strcat(tStr," Config");
		strcat(tStr, ":");
		
		GetDlgItem(IDC_STATIC_NEW2)->SetWindowText(tStr);
	}
	else
	{
		GetDlgItem(IDC_STATIC_NEW)->SetWindowText("New Password:");
		GetDlgItem(IDC_STATIC_NEW2)->SetWindowText("New Password:");
	}
	if(g_GetLanguage("OK",tStr))
		GetDlgItem(IDC_BTN_OK)->SetWindowText(tStr);
	else
		GetDlgItem(IDC_BTN_OK)->SetWindowText("OK");
}
