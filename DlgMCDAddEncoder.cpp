// DlgMCDAddEncoder.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMCDAddEncoder.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDAddEncoder dialog


CDlgMCDAddEncoder::CDlgMCDAddEncoder(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMCDAddEncoder::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMCDAddEncoder)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nType = 0;
	m_nIPMode = 0;
	m_nPort = 0;
	m_nChannel = 0;
	m_nAreaId = 0;
	m_EncoderID = 0;
}

void CDlgMCDAddEncoder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMCDAddEncoder)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMCDAddEncoder, CDialog)
	//{{AFX_MSG_MAP(CDlgMCDAddEncoder)
	ON_BN_CLICKED(IDC_SEARCH, OnSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDAddEncoder message handlers

BOOL CDlgMCDAddEncoder::OnInitDialog() 
{
	CDialog::OnInitDialog();
	TCHAR tStr[STR_LEN];
	BYTE nLangugeID = HD_GetLanguageID();
	if(nLangugeID == LANGUAGE_CN)
	{		
		if(g_GetLanguage("GeneralIP", tStr))
			((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->AddString(tStr);
		else
			((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->AddString("General IP");
	}
	else if(nLangugeID == LANGUAGE_EN)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->AddString("General IP");
	}
	((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->SetCurSel(0);
	if(m_nType == 0)
	{
		if(g_GetLanguage("AddDevice", tStr))
			SetWindowText(tStr);
		GetDlgItem(IDC_EDIT_CHANNEL)->SetWindowText("1");
	}
	else if(m_nType == 1)
	{
		if(g_GetLanguage("EditDevice", tStr))
			SetWindowText(tStr);
	}
	if(g_GetLanguage("DeviceInfo", tStr))
		GetDlgItem(IDC_STATIC_TITLE)->SetWindowText(tStr);
	CString strTemp;
	if(g_GetLanguage("DeviceName", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_NAME)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("DeviceIP", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_IP)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("ChannelNum", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_CHANNEL)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("DeviceID", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_ID)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("AddressMode", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_IPMODE)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("Port", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_PORT)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("User", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_USER)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("Password", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_PWD)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("InArea", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_AREA)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("Multicast", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_MULTICAST)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("ShowOnline", tStr))	
		GetDlgItem(IDC_SEARCH)->SetWindowText(tStr);
	if(g_GetLanguage("OK", tStr))
		GetDlgItem(IDOK)->SetWindowText(tStr);
	if(g_GetLanguage("Cancel", tStr))
		GetDlgItem(IDCANCEL)->SetWindowText(tStr);
	GetDlgItem(IDC_EDIT_AREA)->SetWindowText(m_strAreaName);
	if(m_nType == 0)
		return TRUE;
	char sName[32]={0};
	char sIP[32]={0};
	char sUser[16]={0};
	char sPwd[32]={0};
	char sDnsIP[32]={0};
	char sMulticastIP[32]={0};
	if(!HD_GetEncoderById(m_EncoderID,sName,&m_nIPMode,sIP,&m_nPort,sUser,sPwd,&m_nChannel,sDnsIP,sMulticastIP))
	{
		MessageBox("Get Encoder fail.");
		return FALSE;
	}
	CString str;
	GetDlgItem(IDC_EDIT_NAME)->SetWindowText(sName);	
	((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->SetCurSel(m_nIPMode);
	GetDlgItem(IDC_IPADDRESS_DEVICE)->SetWindowText(sIP);
	str.Format("%d",m_nPort);
	GetDlgItem(IDC_EDIT_PORT)->SetWindowText(str);
	GetDlgItem(IDC_EDIT_USER)->SetWindowText(sUser);
	GetDlgItem(IDC_EDIT_PWD)->SetWindowText(sPwd);
	str.Format("%d",m_nChannel);
	GetDlgItem(IDC_EDIT_CHANNEL)->SetWindowText(str);
	GetDlgItem(IDC_IPADDRESS_DNS)->SetWindowText(sDnsIP);
	GetDlgItem(IDC_IPADDRESS_MULTICAST)->SetWindowText(sMulticastIP);
	GetDlgItem(IDC_EDIT_ID)->SetWindowText(m_strDeviId);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMCDAddEncoder::OnSearch() 
{
	// TODO: Add your control notification handler code here
	
}

void CDlgMCDAddEncoder::OnOK() 
{
	CString str;
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(m_strDeviName);	
	m_nIPMode = ((CComboBox*)GetDlgItem(IDC_COMBO_MODE))->GetCurSel();
	GetDlgItem(IDC_IPADDRESS_DEVICE)->GetWindowText(m_strIP);
	GetDlgItem(IDC_EDIT_PORT)->GetWindowText(str);
	m_nPort = atoi(str);
	GetDlgItem(IDC_EDIT_USER)->GetWindowText(m_strUser);
	GetDlgItem(IDC_EDIT_PWD)->GetWindowText(m_strPwd);
	GetDlgItem(IDC_EDIT_CHANNEL)->GetWindowText(str);
	m_nChannel = atoi(str);
	GetDlgItem(IDC_IPADDRESS_DNS)->GetWindowText(m_strDnsIP);
	GetDlgItem(IDC_IPADDRESS_MULTICAST)->GetWindowText(m_strMulticastIP);
	GetDlgItem(IDC_EDIT_ID)->GetWindowText(m_strDeviId);
	if(m_strDeviName.GetLength() <= 3)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("stringLess", tStr))
			MessageBox(tStr);
		else
			MessageBox("Character too little.");
		GetDlgItem(IDC_EDIT_NAME)->SetFocus();
		return;
	}
	if(m_strIP.GetLength() <= 7 && m_strIP=="0.0.0.0")
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("InputErr", tStr))
			MessageBox(tStr);
		else
			MessageBox("Input error.");
		GetDlgItem(IDC_IPADDRESS_DEVICE)->SetFocus();
		return;
	}
	if(m_nPort <= 0)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("InputErr", tStr))
			MessageBox(tStr);
		else
			MessageBox("Input error.");
		GetDlgItem(IDC_EDIT_PORT)->SetFocus();
		return;
	}
	if(m_strUser.GetLength() <= 3)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("stringLess", tStr))
			MessageBox(tStr);
		else
			MessageBox("Character too little.");
		GetDlgItem(IDC_EDIT_USER)->SetFocus();
		return;
	}
	if(m_strPwd.GetLength() <= 3)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("stringLess", tStr))
			MessageBox(tStr);
		else
			MessageBox("Character too little.");
		GetDlgItem(IDC_EDIT_PWD)->SetFocus();
		return;
	}
	if(m_nChannel <= 0)
	{
		TCHAR tStr[STR_LEN];
		if(g_GetLanguage("InputErr", tStr))
			MessageBox(tStr);
		else
			MessageBox("Input error.");
		GetDlgItem(IDC_EDIT_CHANNEL)->SetFocus();
		return;
	}
	CDialog::OnOK();
}
