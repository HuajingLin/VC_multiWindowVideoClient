#if !defined(AFX_DLGMMRIGHTLIST_H__7E1431DF_A13D_4167_9283_A7E87F0A5278__INCLUDED_)
#define AFX_DLGMMRIGHTLIST_H__7E1431DF_A13D_4167_9283_A7E87F0A5278__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMRightList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMMRightList dialog

class CDlgMMRightList : public CDialog
{
// Construction
public:
	CDlgMMRightList(CWnd* pParent = NULL);   // standard constructor
private:
	bool	m_bInitDlg;
	CFont	m_font;
// Dialog Data
	//{{AFX_DATA(CDlgMMRightList)
	enum { IDD = IDD_MMR_LIST };
	CListCtrl	m_listAlarm;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMRightList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMRightList)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMRIGHTLIST_H__7E1431DF_A13D_4167_9283_A7E87F0A5278__INCLUDED_)
