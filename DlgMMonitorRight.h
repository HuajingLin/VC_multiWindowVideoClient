#if !defined(AFX_DLGMMONITORRIGHT_H__1871D5BD_14FA_42E2_A6C5_CE62A14CC28C__INCLUDED_)
#define AFX_DLGMMONITORRIGHT_H__1871D5BD_14FA_42E2_A6C5_CE62A14CC28C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMonitorRight.h : header file
//
#include "DlgMMRightTool.h"
#include "DlgMMRightList.h"
#include "MultiWindow.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMonitorRight dialog

class CDlgMMonitorRight : public CDialog
{
// Construction
public:
	CDlgMMonitorRight(CWnd* pParent = NULL);   // standard constructor
private:
	bool				m_bInitDialog;
	CDlgMMRightTool		m_PanelTool;
	CMultiWindow		m_MultiWindow;
	CDlgMMRightList		m_PanelList;
	CBrush				m_bkBrush;
// Dialog Data
	//{{AFX_DATA(CDlgMMonitorRight)
	enum { IDD = IDD_MM_RIGHT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMonitorRight)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMonitorRight)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMONITORRIGHT_H__1871D5BD_14FA_42E2_A6C5_CE62A14CC28C__INCLUDED_)
