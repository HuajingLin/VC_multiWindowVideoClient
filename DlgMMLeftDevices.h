#if !defined(AFX_DLGMMLEFTDEVICES_H__4A435BC0_AEF0_49D9_A2BB_3A6C24599407__INCLUDED_)
#define AFX_DLGMMLEFTDEVICES_H__4A435BC0_AEF0_49D9_A2BB_3A6C24599407__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLeftDevices.h : header file
//
#include "TabButton.h"
#include "DlgMMLDeviceTree.h"
#include "DlgMMLDeviceGroup.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftDevices dialog

class CDlgMMLeftDevices : public CDialog
{
// Construction
public:
	CDlgMMLeftDevices(CWnd* pParent = NULL);   // standard constructor
	void SetMultiWinPtr(void *pMultiWin);
private:
	void TabButtonsUp();
private:
	bool				m_bInitDialog;
	BYTE				m_nCurrPanel;
	CDlgMMLDeviceTree	m_DeviceTree;
	CDlgMMLDeviceGroup	m_DeviceGroup;
	CBrush				m_bkBrush;
// Dialog Data
	//{{AFX_DATA(CDlgMMLeftDevices)
	enum { IDD = IDD_MML_DEVICES };
	CTabButton	m_btnList;
	CTabButton	m_btnGroup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLeftDevices)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLeftDevices)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnBtnList();
	afx_msg void OnBtnGroup();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLEFTDEVICES_H__4A435BC0_AEF0_49D9_A2BB_3A6C24599407__INCLUDED_)
