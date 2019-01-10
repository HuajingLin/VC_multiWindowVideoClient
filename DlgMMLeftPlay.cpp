// DlgMMLeftPlay.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLeftPlay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftPlay dialog
#define MMLP_BK_COLOR RGB(0xCB,0xCD,0xD1)

CDlgMMLeftPlay::CDlgMMLeftPlay(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLeftPlay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLeftPlay)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bkBrush.CreateSolidBrush(MMLP_BK_COLOR);
}


void CDlgMMLeftPlay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLeftPlay)
	DDX_Control(pDX, IDC_BTN_TALK, m_btnTalk);
	DDX_Control(pDX, IDC_BTN_STOPALL, m_btnStopAll);
	DDX_Control(pDX, IDC_BTN_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BTN_SOUND, m_btnSound);
	DDX_Control(pDX, IDC_BTN_RECORD, m_btnRecord);
	DDX_Control(pDX, IDC_BTN_PLAY, m_btnPlay);
	DDX_Control(pDX, IDC_BTN_CAPTURE, m_btnCapture);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLeftPlay, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLeftPlay)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftPlay message handlers

BOOL CDlgMMLeftPlay::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	TCHAR tStr[STR_LEN];
	m_btnPlay.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnPlay.LoadBitmaps(IDB_BTN_PLAY1,IDB_BTN_PLAY3,IDB_BTN_PLAY2,0,IDC_BTN_FULLSCREEN);
	m_btnPlay.SizeToContent();
	m_btnPlay.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Play",tStr))
		m_btnPlay.SetTooltipText(tStr);
	else
		m_btnPlay.SetTooltipText("Play");

	m_btnStopAll.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnStopAll.LoadBitmaps(IDB_BTN_STOPALL1,IDB_BTN_STOPALL3,IDB_BTN_STOPALL2,0,IDC_BTN_FULLSCREEN);
	m_btnStopAll.SizeToContent();
	m_btnStopAll.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("StopAll",tStr))
		m_btnStopAll.SetTooltipText(tStr);
	else
		m_btnStopAll.SetTooltipText("Stop All");
	
	m_btnStop.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnStop.LoadBitmaps(IDB_BTN_STOP1,IDB_BTN_STOP3,IDB_BTN_STOP2,0,IDC_BTN_FULLSCREEN);
	m_btnStop.SizeToContent();
	m_btnStop.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Stop",tStr))
		m_btnStop.SetTooltipText(tStr);
	else
		m_btnStop.SetTooltipText("Stop");

	m_btnCapture.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnCapture.LoadBitmaps(IDB_BTN_CAPTURE1,IDB_BTN_CAPTURE3,IDB_BTN_CAPTURE2,0,IDC_BTN_FULLSCREEN);
	m_btnCapture.SizeToContent();
	m_btnCapture.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Capture",tStr))
		m_btnCapture.SetTooltipText(tStr);
	else
		m_btnCapture.SetTooltipText("Capture");
	
	m_btnRecord.SetSkin(IDB_BTN_RECORD1,IDB_BTN_RECORD3,IDB_BTN_RECORD2);
	if(g_GetLanguage("Record",tStr))
		m_btnRecord.SetTooltipText(tStr);
	else
		m_btnRecord.SetTooltipText("Record");
	
	m_btnSound.SetSkin(IDB_BTN_SOUND1,IDB_BTN_SOUND3,IDB_BTN_SOUND2);
	if(g_GetLanguage("Sound",tStr))
		m_btnSound.SetTooltipText(tStr);
	else
		m_btnSound.SetTooltipText("Sound");

	m_btnTalk.SetSkin(IDB_BTN_TALK1,IDB_BTN_TALK3,IDB_BTN_TALK2);
	//m_btnTalk.SetDown();
	if(g_GetLanguage("Talk",tStr))
		m_btnTalk.SetTooltipText(tStr);
	else
		m_btnTalk.SetTooltipText("Talk");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPT ION: OCX Property Pages should return FALSE
}

HBRUSH CDlgMMLeftPlay::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG)
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
