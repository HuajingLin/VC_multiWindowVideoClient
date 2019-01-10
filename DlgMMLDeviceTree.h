#if !defined(AFX_DLGMMLDEVICETREE_H__4BF50F96_5BDC_47E2_9E2A_CFE6E948F5D5__INCLUDED_)
#define AFX_DLGMMLDEVICETREE_H__4BF50F96_5BDC_47E2_9E2A_CFE6E948F5D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLDeviceTree.h : header file
//
#include "MultiWindow.h"
#include "DragDropTreeCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLDeviceTree dialog

class CDlgMMLDeviceTree : public CDialog
{
// Construction
public:
	CDlgMMLDeviceTree(CWnd* pParent = NULL);   // standard constructor
	void SetMultiWinPtr(void* pMultiWin);
private:
	BOOL GetDeviceList();
	BOOL ReleaseDataForTreeCtrl();
private:
	bool m_bInitDialog;
	CMultiWindow* m_pMultiWin; 
// Dialog Data
	//{{AFX_DATA(CDlgMMLDeviceTree)
	enum { IDD = IDD_MMLD_TREE };
	CDragDropTreeCtrl	m_TreeCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLDeviceTree)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLDeviceTree)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnDblclkTreeDevice(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLDEVICETREE_H__4BF50F96_5BDC_47E2_9E2A_CFE6E948F5D5__INCLUDED_)
