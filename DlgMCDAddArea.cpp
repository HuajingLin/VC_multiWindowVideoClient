// DlgMCDAddArea.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMCDAddArea.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDAddArea dialog


CDlgMCDAddArea::CDlgMCDAddArea(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMCDAddArea::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMCDAddArea)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nUpAreaId = 0;
	m_nAreaId = 0;
	m_nType = 0;
}


void CDlgMCDAddArea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMCDAddArea)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMCDAddArea, CDialog)
	//{{AFX_MSG_MAP(CDlgMCDAddArea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDAddArea message handlers

BOOL CDlgMCDAddArea::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	TCHAR tStr[STR_LEN];
	if(m_nType == 0)
	{
		if(m_nUpAreaId == 0)
			return FALSE;
		if(g_GetLanguage("AddArea", tStr))
			this->SetWindowText(tStr);
		else
			this->SetWindowText("Add Area");
	}
	else
	{
		if(m_nAreaId == 0)
			return FALSE;
		if(g_GetLanguage("EditArea", tStr))
			this->SetWindowText(tStr);
		else
			this->SetWindowText("Edit Area");
		GetDlgItem(IDC_EDIT_NAME)->SetWindowText(m_strName);	
	}
	CString str;
	if(g_GetLanguage("AreaInfo", tStr))
		GetDlgItem(IDC_STATIC_TITLE)->SetWindowText(tStr);
	if(g_GetLanguage("AreaName", tStr))
	{
		str = tStr;
		str += ":";
		GetDlgItem(IDC_STATIC_NAME)->SetWindowText(str);
	}
	if(g_GetLanguage("UpAreaName", tStr))
	{
		str = tStr;
		str += ":";
		GetDlgItem(IDC_STATIC_UPNAME)->SetWindowText(str);
	}
	GetDlgItem(IDC_EDIT_UP_NAME)->SetWindowText(m_strUPName);
	if(g_GetLanguage("OK", tStr))
		GetDlgItem(IDOK)->SetWindowText(tStr);
	if(g_GetLanguage("Cancel", tStr))
		GetDlgItem(IDCANCEL)->SetWindowText(tStr);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMCDAddArea::OnOK() 
{
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(m_strName);
	if(m_strName.GetLength() <= 3)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("stringLess", tStr))
			MessageBox(tStr);
		else
			MessageBox("Character too little.");
		return;
	}
	CDialog::OnOK();
}
