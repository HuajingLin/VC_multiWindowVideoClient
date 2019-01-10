#if !defined(AFX_DLGMMLEFTPLAY_H__D81F3298_1478_47B0_B355_E5B82B34F4BF__INCLUDED_)
#define AFX_DLGMMLEFTPLAY_H__D81F3298_1478_47B0_B355_E5B82B34F4BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLeftPlay.h : header file
//
#include "StateButton.h"
#include "BmpButton.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftPlay dialog

class CDlgMMLeftPlay : public CDialog
{
// Construction
public:
	CDlgMMLeftPlay(CWnd* pParent = NULL);   // standard constructor
	CBrush				m_bkBrush;
// Dialog Data
	//{{AFX_DATA(CDlgMMLeftPlay)
	enum { IDD = IDD_MML_PLAY };
	CBmpButton	m_btnStopAll;
	CBmpButton	m_btnStop;	
	CBmpButton	m_btnPlay;
	CBmpButton	m_btnCapture;
	CStateButton	m_btnTalk;
	CStateButton	m_btnSound;
	CStateButton	m_btnRecord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLeftPlay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLeftPlay)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLEFTPLAY_H__D81F3298_1478_47B0_B355_E5B82B34F4BF__INCLUDED_)
