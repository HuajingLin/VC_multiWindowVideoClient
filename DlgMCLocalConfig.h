#if !defined(AFX_DLGMCLOCALCONFIG_H__88D7ECE9_10DB_48C6_AFE5_8AC5AB9763FA__INCLUDED_)
#define AFX_DLGMCLOCALCONFIG_H__88D7ECE9_10DB_48C6_AFE5_8AC5AB9763FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMCLocalConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMCLocalConfig dialog

class CDlgMCLocalConfig : public CDialog
{
// Construction
public:
	CDlgMCLocalConfig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgMCLocalConfig)
	enum { IDD = IDD_MC_LOCAL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMCLocalConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMCLocalConfig)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMCLOCALCONFIG_H__88D7ECE9_10DB_48C6_AFE5_8AC5AB9763FA__INCLUDED_)
