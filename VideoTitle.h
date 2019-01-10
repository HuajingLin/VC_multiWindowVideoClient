#if !defined(AFX_VIDEOTITLE_H__15F529CE_55D7_4970_B755_B47CBBDD09D3__INCLUDED_)
#define AFX_VIDEOTITLE_H__15F529CE_55D7_4970_B755_B47CBBDD09D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoTitle.h : header file
//
//��Ƶ����ؼ�ID
#define IDC_LBL_TITLE_INDEX 4101
#define IDC_LBL_TITLE_STATE 4201
#define IDC_LBL_TITLE_RECOR 4301
#define IDC_LBL_TITLE_ALARM	4401
#define IDC_LBL_VIDEO		4501
#define IDC_BTN_CLOSE		4601
#define TITLE_STR_LEN	64
//#include "StateButton.h"
#include "TabButton.h"
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CVideoTitle window
class CVideoWin;
class CVideoTitle : public CStatic
{
// Construction
public:	
	CVideoTitle();
	virtual ~CVideoTitle();
public:
	void ShowRecordState(BOOL bSet);
	void ShowAlarmState(BOOL bSet);
	void SetCloseState(BOOL bDown);
	void SetTitleText(LPCTSTR szStr);
	void SetTips(LPCTSTR szStr);	//��ʱ��ʾ
private:	
	CFont		m_Font;
	CFont		m_FontBold;		//�Ӵ�����	
	bool		m_bShow;		//�Ƿ���ʾ��������Ϣ
	bool		m_bTimerRecord;		//������ʾ¼��ʱ��
	bool		m_bTimerAlarm;		//������ʾ������ʱ��
	CVideoWin	*m_pVideoWin;
	char		m_szStr[TITLE_STR_LEN];	//��ʾ�ı���
private:
	CStatic		m_lblIndex;		//�������
	CStatic		m_lblState;		//�豸����
	CStatic		m_lblRecord;	//¼��״̬
	CStatic		m_lblAlarm;		//����״̬
	CTabButton	m_btnClose;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoTitle)
	//}}AFX_VIRTUAL

// Implementation
	// Generated message map functions
protected:
	//{{AFX_MSG(CVideoTitle)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOTITLE_H__15F529CE_55D7_4970_B755_B47CBBDD09D3__INCLUDED_)
