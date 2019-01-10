#if !defined(AFX_DLGMMLDEVICEGROUP_H__C69FD8B0_3FB0_4586_8050_4BF1464A5E85__INCLUDED_)
#define AFX_DLGMMLDEVICEGROUP_H__C69FD8B0_3FB0_4586_8050_4BF1464A5E85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLDeviceGroup.h : header file
//
#include "MultiWindow.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLDeviceGroup dialog

class CDlgMMLDeviceGroup : public CDialog
{
// Construction
public:
	CDlgMMLDeviceGroup(CWnd* pParent = NULL);   // standard constructor
	void SetMultiWinPtr(void* pMultiWin);
public:
	bool m_bInitDialog;
	CMultiWindow* m_pMultiWin; 
// Dialog Data
	//{{AFX_DATA(CDlgMMLDeviceGroup)
	enum { IDD = IDD_MMLD_GROUP };
	CTreeCtrl	m_treeGroup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLDeviceGroup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLDeviceGroup)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLDEVICEGROUP_H__C69FD8B0_3FB0_4586_8050_4BF1464A5E85__INCLUDED_)
