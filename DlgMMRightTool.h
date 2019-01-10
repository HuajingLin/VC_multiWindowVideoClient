#if !defined(AFX_DLGMMRIGHTTOOL_H__A0C89F45_4FBA_4CB4_8BFD_AFECCB856157__INCLUDED_)
#define AFX_DLGMMRIGHTTOOL_H__A0C89F45_4FBA_4CB4_8BFD_AFECCB856157__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMRightTool.h : header file
//

#include "TabButton.h"
#include "BmpButton.h"
#include "MultiWindow.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMRightTool dialog

class CDlgMMRightTool : public CDialog
{
// Construction
public:
	CDlgMMRightTool(CWnd* pParent = NULL);   // standard constructor
	void SetMVideoPtr(void* pMVideo);
private:
	bool	m_bInitDlg;
	CMultiWindow* m_pMVideo;
private:
	void SetAllPanelBtnUp();
// Dialog Data
	//{{AFX_DATA(CDlgMMRightTool)
	enum { IDD = IDD_MMR_TOOL };
	CBmpButton	m_btnPrevi;
	CBmpButton	m_btnNext;
	CBmpButton	m_btnFullscreen;
	CTabButton	m_btnPane4;
	CTabButton	m_btnPane9;
	CTabButton	m_btnPane64;
	CTabButton	m_btnPane6;
	CTabButton	m_btnPane36;
	CTabButton	m_btnPane16;
	CTabButton	m_btnPane13;
	CTabButton	m_btnPane10;
	CTabButton	m_btnPane1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMRightTool)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMRightTool)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg void OnBtnPane1();
	afx_msg void OnBtnPane4();
	afx_msg void OnBtnPane6();
	afx_msg void OnBtnPane9();
	afx_msg void OnBtnPane10();
	afx_msg void OnBtnPane13();
	afx_msg void OnBtnPane16();
	afx_msg void OnBtnPane36();
	afx_msg void OnBtnPane64();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMRIGHTTOOL_H__A0C89F45_4FBA_4CB4_8BFD_AFECCB856157__INCLUDED_)
