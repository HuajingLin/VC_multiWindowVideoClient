#if !defined(AFX_DLGMCDEVICECONFIG_H__89B377D6_77CD_444D_8216_A36F41C0B9DE__INCLUDED_)
#define AFX_DLGMCDEVICECONFIG_H__89B377D6_77CD_444D_8216_A36F41C0B9DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMCDeviceConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgMCDeviceConfig dialog

class CDlgMCDeviceConfig : public CDialog
{
// Construction
public:
	CDlgMCDeviceConfig(CWnd* pParent = NULL);   // standard constructor
private:
	bool				m_bInitDialog;
	CMenu				m_MenuPop;		//µ¯³ö²Ëµ¥
	HTREEITEM			m_hSelItem;
	CWinThread*			m_pReloadTreeThread;
private:
	BOOL GetDeviceList();
	BOOL ReleaseDataForTreeCtrl();
	static UINT ReloadTreeThread(LPVOID lpParam);
	void ReloadTree();
// Dialog Data
	//{{AFX_DATA(CDlgMCDeviceConfig)
	enum { IDD = IDD_MC_DEVICE };
	CTreeCtrl	m_TreeCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMCDeviceConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMCDeviceConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnAddArea();
	afx_msg void OnAddDevice();
	afx_msg void OnDelNode();
	afx_msg void OnDblclkTreeDevice(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickTreeDevice(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMCDEVICECONFIG_H__89B377D6_77CD_444D_8216_A36F41C0B9DE__INCLUDED_)
