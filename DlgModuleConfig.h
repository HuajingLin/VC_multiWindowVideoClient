#if !defined(AFX_DLGMODULECONFIG_H__3517F274_9ADD_4D19_B07F_BB55B9B4D101__INCLUDED_)
#define AFX_DLGMODULECONFIG_H__3517F274_9ADD_4D19_B07F_BB55B9B4D101__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgModuleConfig.h : header file
//
#include "DlgMCDeviceConfig.h"
#include "DlgMCUserConfig.h"
#include "DlgMCLocalConfig.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgModuleConfig dialog

class CDlgModuleConfig : public CDialog
{
// Construction
public:
	CDlgModuleConfig(CWnd* pParent = NULL);   // standard constructor
private:
	bool				m_bInitDialog;
	BYTE				m_nCurrPanel;
	CDlgMCDeviceConfig	m_DeviceConfig;
	CDlgMCLocalConfig	m_LocalConfig;
	CDlgMCUserConfig	m_UserConfig;
// Dialog Data
	//{{AFX_DATA(CDlgModuleConfig)
	enum { IDD = IDD_MODULE_CONFIG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgModuleConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgModuleConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBtnConfigDevice();
	afx_msg void OnBtnConfigLocal();
	afx_msg void OnBtnConfigUser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMODULECONFIG_H__3517F274_9ADD_4D19_B07F_BB55B9B4D101__INCLUDED_)
