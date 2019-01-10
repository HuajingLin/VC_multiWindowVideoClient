#if !defined(AFX_DLGMMLOPERATECRUISE_H__78E653BE_6AA1_4D58_9219_02E763D1CE2F__INCLUDED_)
#define AFX_DLGMMLOPERATECRUISE_H__78E653BE_6AA1_4D58_9219_02E763D1CE2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLOperateCruise.h : header file
//
#include "BmpButton.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperateCruise dialog

class CDlgMMLOperateCruise : public CDialog
{
// Construction
public:
	CDlgMMLOperateCruise(CWnd* pParent = NULL);   // standard constructor
private:
	CBrush		m_bkBrush;
	CFont		m_font;
// Dialog Data
	//{{AFX_DATA(CDlgMMLOperateCruise)
	enum { IDD = IDD_MMLO_CRUISE };
	CBmpButton	m_btnStop;
	CBmpButton	m_btnStart;
	CBmpButton	m_btnSetCruise;
	CListCtrl	m_listCruise;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLOperateCruise)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLOperateCruise)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLOPERATECRUISE_H__78E653BE_6AA1_4D58_9219_02E763D1CE2F__INCLUDED_)
