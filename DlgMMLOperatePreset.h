#if !defined(AFX_DLGMMLOPERATEPRESET_H__7664207A_70F3_4CC2_B1F6_F709AF22F322__INCLUDED_)
#define AFX_DLGMMLOPERATEPRESET_H__7664207A_70F3_4CC2_B1F6_F709AF22F322__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLOperatePreset.h : header file
//
#include "BmpButton.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperatePreset dialog

class CDlgMMLOperatePreset : public CDialog
{
// Construction
public:
	CDlgMMLOperatePreset(CWnd* pParent = NULL);   // standard constructor
private:
	CBrush	m_bkBrush;
	CFont	m_font;
// Dialog Data
	//{{AFX_DATA(CDlgMMLOperatePreset)
	enum { IDD = IDD_MMLO_PRESET };
	CListCtrl	m_listPreset;
	CBmpButton	m_btnSet;
	CBmpButton	m_btnDel;
	CBmpButton	m_btnCall;	
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLOperatePreset)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLOperatePreset)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLOPERATEPRESET_H__7664207A_70F3_4CC2_B1F6_F709AF22F322__INCLUDED_)
