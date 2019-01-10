#if !defined(AFX_DLGMCDMODICHANNEL_H__EB167176_866B_434C_B7D5_30180E4A02EF__INCLUDED_)
#define AFX_DLGMCDMODICHANNEL_H__EB167176_866B_434C_B7D5_30180E4A02EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMCDModiChannel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDModiChannel dialog

class CDlgMCDModiChannel : public CDialog
{
// Construction
public:
	CDlgMCDModiChannel(CWnd* pParent = NULL);   // standard constructor
public:
	int		m_nChannelID;
	CString m_strChannelName;
	BYTE	m_nChNo;
	CString m_strDeviName;
	int 	m_nStream;
	CString m_strIP;
	int		m_nEncoderID;
// Dialog Data
	//{{AFX_DATA(CDlgMCDModiChannel)
	enum { IDD = IDD_MCD_MODIFY_CAMERA };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMCDModiChannel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMCDModiChannel)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMCDMODICHANNEL_H__EB167176_866B_434C_B7D5_30180E4A02EF__INCLUDED_)
