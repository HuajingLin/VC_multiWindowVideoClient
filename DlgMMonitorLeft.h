#if !defined(AFX_DLGMMONITORLEFT_H__A63E104F_03C8_4060_A98F_2936DED28095__INCLUDED_)
#define AFX_DLGMMONITORLEFT_H__A63E104F_03C8_4060_A98F_2936DED28095__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMonitorLeft.h : header file
//

#include "DlgMMLeftOperate.h"
#include "DlgMMLeftDevices.h"
#include "DlgMMLeftPlay.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMonitorLeft dialog

class CDlgMMonitorLeft : public CDialog
{
// Construction
public:
	CDlgMMonitorLeft(CWnd* pParent = NULL);   // standard constructor
	void SetMultiWinPtr(void* pMultiWin);
private:
	bool m_bInitDialog;
	CDlgMMLeftOperate	m_PanelOperate;
	CDlgMMLeftPlay		m_PanelPlay;
	CDlgMMLeftDevices	m_PanelDevices;
	CBrush				m_bkBrush;
// Dialog Data
	//{{AFX_DATA(CDlgMMonitorLeft)
	enum { IDD = IDD_MM_LEFT };
	//
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMonitorLeft)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMonitorLeft)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMONITORLEFT_H__A63E104F_03C8_4060_A98F_2936DED28095__INCLUDED_)
