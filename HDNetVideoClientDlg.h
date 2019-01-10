// HDNetVideoClientDlg.h : header file
//

#if !defined(AFX_HDNETVIDEOCLIENTDLG_H__0218EFB0_FB35_4747_AE00_052E77DE8B90__INCLUDED_)
#define AFX_HDNETVIDEOCLIENTDLG_H__0218EFB0_FB35_4747_AE00_052E77DE8B90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TabButton.h"
#include "BackgroundPic.h"
#include "DlgModuleMonitor.h"
#include "DlgModuleConfig.h"
/////////////////////////////////////////////////////////////////////////////
// CHDNetVideoClientDlg dialog

class CHDNetVideoClientDlg : public CDialog
{
// Construction
public:
	CHDNetVideoClientDlg(CWnd* pParent = NULL);	// standard constructor
private:
	void MainButtonsUp();
private:
	bool				m_bInitDialog;		//对话框初始化标志
	BYTE				m_nCurrModule;		//当前模块ID
	CDlgModuleMonitor	m_ModuleMonitor;	//模块- 监控
	CDlgModuleConfig	m_ModuleConfig;		//模块- 配置
// Dialog Data
	//{{AFX_DATA(CHDNetVideoClientDlg)
	enum { IDD = IDD_HDNETVIDEOCLIENT_DIALOG };
	CTabButton	m_btnConfig;
	CTabButton	m_btnHelp;
	CTabButton	m_btnLog;
	CTabButton	m_btnMap;
	CTabButton	m_btnMonitor;
	CBackgroundPic	m_bkToolbar;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHDNetVideoClientDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHDNetVideoClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnBtnMonitor();
	afx_msg void OnBtnConfig();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnLog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HDNETVIDEOCLIENTDLG_H__0218EFB0_FB35_4747_AE00_052E77DE8B90__INCLUDED_)
