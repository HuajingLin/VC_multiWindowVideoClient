#if !defined(AFX_DLGMCDADDENCODER_H__F7BADD30_A8D1_43FA_B0E4_A6B0146A0F27__INCLUDED_)
#define AFX_DLGMCDADDENCODER_H__F7BADD30_A8D1_43FA_B0E4_A6B0146A0F27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMCDAddEncoder.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDAddEncoder dialog

class CDlgMCDAddEncoder : public CDialog
{
// Construction
public:
	CDlgMCDAddEncoder(CWnd* pParent = NULL);   // standard constructor
	void Test();
	BYTE m_nType;	//添加，编辑
	CString m_strDeviName;
	BYTE	m_nIPMode;
	CString m_strIP;
	WORD	m_nPort;
	CString m_strUser;
	CString m_strPwd;
	BYTE	m_nChannel;	//通道数
	CString m_strAreaName;
	CString m_strDnsIP;
	CString m_strMulticastIP;
	CString m_strDeviId;
	int		m_nAreaId;
	int		m_EncoderID;
// Dialog Data
	//{{AFX_DATA(CDlgMCDAddEncoder)
	enum { IDD = IDD_MCD_ADD_ENCODER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMCDAddEncoder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMCDAddEncoder)
	virtual BOOL OnInitDialog();
	afx_msg void OnSearch();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMCDADDENCODER_H__F7BADD30_A8D1_43FA_B0E4_A6B0146A0F27__INCLUDED_)
