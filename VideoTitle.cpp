// VideoTitle.cpp : implementation file
//

#include "stdafx.h"
#include "VideoTitle.h"
#include "VideoWin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define EVENT_SHOW_RECORD	1
#define EVENT_SHOW_TITLE	2
/////////////////////////////////////////////////////////////////////////////
// CVideoTitle

CVideoTitle::CVideoTitle()
{
	m_pVideoWin = NULL;
	m_bShow = false;
	m_bTimerRecord = false;
	m_bTimerAlarm = false;
	memset(m_szStr,0,TITLE_STR_LEN);
}

CVideoTitle::~CVideoTitle()
{
}


BEGIN_MESSAGE_MAP(CVideoTitle, CStatic)
	//{{AFX_MSG_MAP(CVideoTitle)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoTitle message handlers

int CVideoTitle::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_Font.CreateFont(14,0,0,0,0,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,DEFAULT_PITCH|FF_MODERN, _T("MS Sans Serif"));
	m_pVideoWin = (CVideoWin *)GetParent();
	if(m_pVideoWin==NULL)
		return -1;
	m_FontBold.CreateFont(14,0,0,0,FW_BLACK,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY,DEFAULT_PITCH|FF_MODERN, _T("MS Sans Serif"));
	if(m_pVideoWin->m_nIndex > MAXWIN)
		return -1;
	RECT rect;
	memset(&rect,0,sizeof(rect));
	char szIndex[4];
	sprintf(szIndex,"%d.",m_pVideoWin->m_nIndex+1);
	m_lblIndex.Create(szIndex, WS_VISIBLE, CRect(3,3,18,18), this, IDC_LBL_TITLE_INDEX+m_pVideoWin->m_nIndex);
	m_lblIndex.SetFont(&m_FontBold);
	m_lblState.Create(NULL, WS_VISIBLE, rect, this, IDC_LBL_TITLE_STATE+m_pVideoWin->m_nIndex);
	m_lblState.SetFont(&m_Font);
	m_lblRecord.Create(NULL, WS_CHILD|WS_VISIBLE, rect, this, IDC_LBL_TITLE_RECOR+m_pVideoWin->m_nIndex);
	m_lblRecord.SetFont(&m_FontBold);
	m_lblAlarm.Create(NULL, WS_CHILD|WS_VISIBLE, rect, this, IDC_LBL_TITLE_RECOR+m_pVideoWin->m_nIndex);
	m_lblAlarm.SetFont(&m_FontBold);
	m_btnClose.Create(NULL, WS_VISIBLE, rect, this, IDC_BTN_CLOSE);	
	m_btnClose.SetSkin(IDB_BTN_CLOSEVIDEO1,IDB_BTN_CLOSEVIDEO2);	
	SetTimer(EVENT_SHOW_TITLE, 2000, NULL);
	return 0;
}

void CVideoTitle::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	RECT  rect,tmpRect;
	GetClientRect(&rect);
	if(rect.right<=0 || rect.bottom<=0) return;
	tmpRect = rect;
	tmpRect.top = 3;
	tmpRect.left = 19;
	tmpRect.bottom -= 3;
	tmpRect.right = rect.right - 50;
	m_lblState.MoveWindow(&tmpRect);

	tmpRect.right = rect.right - 33;
	tmpRect.left = tmpRect.right - 15;
	m_lblAlarm.MoveWindow(&tmpRect);

	tmpRect.right = rect.right - 18;
	tmpRect.left = tmpRect.right - 15;
	m_lblRecord.MoveWindow(&tmpRect);

	tmpRect.top = 2;
	tmpRect.bottom = rect.bottom - 1;
	tmpRect.right = rect.right - 1;
	tmpRect.left = tmpRect.right - 16;
	m_btnClose.MoveWindow(&tmpRect);
}

HBRUSH CVideoTitle::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor == CTLCOLOR_STATIC)
	{
		int nCtlID = pWnd->GetDlgCtrlID() - m_pVideoWin->m_nIndex;
		if(nCtlID==IDC_LBL_TITLE_INDEX)
		{
			if(m_btnClose.m_bBuDown)
			{
				pDC->SetBkMode(TRANSPARENT);
				pDC->SetTextColor(RGB(255,0,0));
			}
		}
		else if((nCtlID==IDC_LBL_TITLE_RECOR)||(nCtlID==IDC_LBL_TITLE_ALARM))
		{
			pDC->SetBkMode(TRANSPARENT);
			pDC->SetTextColor(RGB(255,0,0));
		}
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CVideoTitle::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent == EVENT_SHOW_RECORD)
	{
		if(m_bShow)
		{
			if(m_bTimerRecord == true)
				m_lblRecord.SetWindowText("R");
			if(m_bTimerAlarm == true)
				m_lblAlarm.SetWindowText("A");
			m_bShow = false;
		}
		else
		{
			if(m_bTimerRecord == true)
				m_lblRecord.SetWindowText(NULL);
			if(m_bTimerAlarm == true)
				m_lblAlarm.SetWindowText(NULL);
			m_bShow = true;
		}
	}
	else if(nIDEvent == EVENT_SHOW_TITLE)
	{
		m_lblState.SetWindowText(m_szStr);
	}
	CStatic::OnTimer(nIDEvent);
}

void CVideoTitle::ShowRecordState(BOOL bSet)
{
	if(bSet)
	{
		if(m_bTimerRecord == true)
			return;
		if(m_bTimerAlarm == false)
			SetTimer(EVENT_SHOW_RECORD, 600, NULL);
		m_bTimerRecord = true;
	}
	else
	{
		if(m_bTimerRecord == false)
			return;
		m_bTimerRecord = false;
		if(m_bTimerAlarm == false)
			KillTimer(EVENT_SHOW_RECORD);
		m_lblRecord.SetWindowText(NULL);
	}
}
void CVideoTitle::ShowAlarmState(BOOL bSet)
{
	if(bSet)
	{
		if(m_bTimerAlarm == true)
			return;
		if(m_bTimerRecord == false)
			SetTimer(EVENT_SHOW_RECORD, 600, NULL);
		m_bTimerAlarm = true;
	}
	else
	{
		if(m_bTimerAlarm == false)
			return;
		m_bTimerAlarm = false;
		if(m_bTimerRecord == false)
			KillTimer(EVENT_SHOW_RECORD);
		m_lblAlarm.SetWindowText(NULL);
	}
}
void CVideoTitle::SetTitleText(LPCTSTR szStr)
{
	strncpy(m_szStr,szStr,TITLE_STR_LEN);
}
void CVideoTitle::SetTips(LPCTSTR szStr)
{
	m_lblState.SetWindowText(szStr);
	SetTimer(EVENT_SHOW_TITLE, 2000, NULL);
}
void CVideoTitle::OnBtnClose() 
{
	TRACE("====OnBtnClose\n");
}
void CVideoTitle::SetCloseState(BOOL bDown)
{
	if(bDown)
		m_btnClose.SetDown();
	else
		m_btnClose.SetUp();
	m_lblIndex.Invalidate(FALSE);
}
