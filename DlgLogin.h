#if !defined(AFX_DLGLOGIN_H__51FF5869_2291_47CC_B6ED_250F950AA660__INCLUDED_)
#define AFX_DLGLOGIN_H__51FF5869_2291_47CC_B6ED_250F950AA660__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLogin.h : header file
//
#include "DlgModifyPwd.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgLogin dialog

class CDlgLogin : public CDialog
{
// Construction
public:
	CDlgLogin(CWnd* pParent = NULL);   // standard constructor
	void GetUserName(CString& User);
	void SetTipsInfo(CString& str);
private:
	void LoadLang();
private:
	bool m_bInitDialog;
	bool m_bExpand;
	CDlgModifyPwd m_ModiPwd;
public:
	CString m_strUser;
// Dialog Data
	//{{AFX_DATA(CDlgLogin)
	enum { IDD = IDD_LOGIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgLogin)
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRadioCn();
	afx_msg void OnRadioEn();
	afx_msg void OnCheckLogin();
	afx_msg void OnBtnModify();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLOGIN_H__51FF5869_2291_47CC_B6ED_250F950AA660__INCLUDED_)
