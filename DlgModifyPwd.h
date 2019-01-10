#if !defined(AFX_DLGMODIFYPWD_H__8D0CD1C9_44E1_44BE_9608_73C300E7A3A9__INCLUDED_)
#define AFX_DLGMODIFYPWD_H__8D0CD1C9_44E1_44BE_9608_73C300E7A3A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgModifyPwd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgModifyPwd dialog

class CDlgModifyPwd : public CDialog
{
// Construction
public:
	CDlgModifyPwd(CWnd* pParent = NULL);   // standard constructor
	void LoadLangu();
// Dialog Data
	//{{AFX_DATA(CDlgModifyPwd)
	enum { IDD = IDD_MODI_PWD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgModifyPwd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CDlgModifyPwd)
	afx_msg void OnBtnOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMODIFYPWD_H__8D0CD1C9_44E1_44BE_9608_73C300E7A3A9__INCLUDED_)
