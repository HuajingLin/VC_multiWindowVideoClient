#if !defined(AFX_DLGMCDADDAREA_H__2F88A2F2_F74F_4A9C_9F2C_AF238CBF5D5E__INCLUDED_)
#define AFX_DLGMCDADDAREA_H__2F88A2F2_F74F_4A9C_9F2C_AF238CBF5D5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMCDAddArea.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDAddArea dialog

class CDlgMCDAddArea : public CDialog
{
// Construction
public:
	CDlgMCDAddArea(CWnd* pParent = NULL);   // standard constructor
public:
	BYTE m_nType;
	int m_nUpAreaId;
	int m_nAreaId;
	CString m_strUPName;
	CString m_strName;
// Dialog Data
	//{{AFX_DATA(CDlgMCDAddArea)
	enum { IDD = IDD_MCD_ADD_AREA };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMCDAddArea)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMCDAddArea)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMCDADDAREA_H__2F88A2F2_F74F_4A9C_9F2C_AF238CBF5D5E__INCLUDED_)
