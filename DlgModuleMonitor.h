#if !defined(AFX_DLGMODULEMONITOR_H__E9E95B82_536E_40A2_87DF_783F77592CA1__INCLUDED_)
#define AFX_DLGMODULEMONITOR_H__E9E95B82_536E_40A2_87DF_783F77592CA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgModuleMonitor.h : header file
//
#include "DlgMMonitorLeft.h"
#include "DlgMMonitorRight.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgModuleMonitor dialog

class CDlgModuleMonitor : public CDialog
{
// Construction
public:
	CDlgModuleMonitor(CWnd* pParent = NULL);	// standard constructor
	void SetMultiWinPtr(void* pMultiWin);		//设置多窗体指针
private:
	bool				m_bInitDialog;
	CDlgMMonitorLeft	m_MonitorLeft;
	CDlgMMonitorRight	m_MonitorRight;
// Dialog Data
	//{{AFX_DATA(CDlgModuleMonitor)
	enum { IDD = IDD_MODULE_MONITOR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgModuleMonitor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgModuleMonitor)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMODULEMONITOR_H__E9E95B82_536E_40A2_87DF_783F77592CA1__INCLUDED_)
