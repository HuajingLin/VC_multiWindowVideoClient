// DlgMCDModiChannel.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMCDModiChannel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDModiChannel dialog
#define STREAM_TYPE_MAIN 0
#define STREAM_TYPE_SECOND 1

CDlgMCDModiChannel::CDlgMCDModiChannel(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMCDModiChannel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMCDModiChannel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_nChNo = 1;
	m_nStream = STREAM_TYPE_MAIN;
	m_nChannelID = 0;
	m_nEncoderID = 0;
}


void CDlgMCDModiChannel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMCDModiChannel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMCDModiChannel, CDialog)
	//{{AFX_MSG_MAP(CDlgMCDModiChannel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDModiChannel message handlers

BOOL CDlgMCDModiChannel::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	TCHAR tStr[STR_LEN];
	BYTE nLangugeID = HD_GetLanguageID();
	if(nLangugeID == LANGUAGE_CN)
	{		
		if(g_GetLanguage("MainStream", tStr))
			((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->AddString(tStr);
		else
			((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->AddString("Main Stream");

		if(g_GetLanguage("SecondStream", tStr))
			((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->AddString(tStr);
		else
			((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->AddString("Second Stream");
	}
	else if(nLangugeID == LANGUAGE_EN)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->AddString("Main Stream");
		((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->AddString("Second Stream");
	}
	if(g_GetLanguage("ModifyChannel", tStr))
		SetWindowText(tStr);
	if(g_GetLanguage("ChannelInfo", tStr))
		GetDlgItem(IDC_TITLE)->SetWindowText(tStr);
	CString strTemp;
	if(g_GetLanguage("ChannelName", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_NAME)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("ChannelNo", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_NO)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("DeviceName", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_DEVI_NAME)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("StreamType", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_STREAM)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("DeviceIP", tStr))
	{
		strTemp = tStr;
		strTemp += ":";
		GetDlgItem(IDC_STATIC_DEVI_IP)->SetWindowText(strTemp);
	}
	if(g_GetLanguage("OK", tStr))
		GetDlgItem(IDOK)->SetWindowText(tStr);
	if(g_GetLanguage("Cancel", tStr))
		GetDlgItem(IDCANCEL)->SetWindowText(tStr);
	char szIP[32];
	if(!HD_GetEncoderById(m_nEncoderID,NULL,NULL,szIP,NULL,NULL, NULL, NULL,NULL,NULL))
		return FALSE;
	m_strIP = szIP;
	GetDlgItem(IDC_EDIT_DEVI_IP)->SetWindowText(m_strIP);
	char szChName[32];
	if(!HD_GetEnChannelById(m_nChannelID, &m_nChNo, szChName, &m_nStream))
		return FALSE;
	m_strChannelName = szChName;
	GetDlgItem(IDC_EDIT_NAME)->SetWindowText(m_strChannelName);
	strTemp.Format("%d",m_nChNo);
	GetDlgItem(IDC_EDIT_NO)->SetWindowText(strTemp);
	GetDlgItem(IDC_EDIT_DEVI_NAME)->SetWindowText(m_strDeviName);
	
	((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->SetCurSel(m_nStream);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMCDModiChannel::OnOK() 
{
	CString strTemp;
	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(m_strChannelName);
	GetDlgItem(IDC_EDIT_NO)->GetWindowText(strTemp);
	m_nChNo = atoi(strTemp);
	GetDlgItem(IDC_EDIT_DEVI_NAME)->GetWindowText(m_strDeviName);
	m_nStream = ((CComboBox*)GetDlgItem(IDC_COMBO_STREAM))->GetCurSel();
	GetDlgItem(IDC_EDIT_DEVI_IP)->GetWindowText(m_strIP);
	CDialog::OnOK();
}
