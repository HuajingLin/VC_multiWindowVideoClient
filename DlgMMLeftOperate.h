#if !defined(AFX_DLGMMLEFTOPERATE_H__2B03CF25_EF4C_4399_A0AC_31AF8B6E1216__INCLUDED_)
#define AFX_DLGMMLEFTOPERATE_H__2B03CF25_EF4C_4399_A0AC_31AF8B6E1216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLeftOperate.h : header file
//
#include "TabButton.h"
#include "DlgMMLOperatePtz.h"
#include "DlgMMLOperatePreset.h"
#include "DlgMMLOperateCruise.h"
#include "DlgMMLOperateVParam.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLeftOperate dialog

class CDlgMMLeftOperate : public CDialog
{
// Construction
public:
	CDlgMMLeftOperate(CWnd* pParent = NULL);   // standard constructor
	void SetMultiWinPtr(void *pMultiWin);
private:
	bool					m_bInitDialog;
	BYTE					m_nCurrPanel;
	CDlgMMLOperatePtz		m_PanelPtz;			//云镜控制	
	CDlgMMLOperatePreset	m_PanelPreset;		//预置点
	CDlgMMLOperateCruise	m_PanelCruise;		//巡航路径
	CDlgMMLOperateVParam	m_PanelVParam;		//视频参数
	CBrush					m_bkBrush;
private:
	void TabButtonsUp();
// Dialog Data
	//{{AFX_DATA(CDlgMMLeftOperate)
	enum { IDD = IDD_MML_OPERATE };
	CTabButton	m_btnVParam;
	CTabButton	m_btnPtz;
	CTabButton	m_btnPreset;
	CTabButton	m_btnCruise;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLeftOperate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLeftOperate)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBtnPtz();
	afx_msg void OnBtnPreset();
	afx_msg void OnBtnCruise();
	afx_msg void OnBtnVParam();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLEFTOPERATE_H__2B03CF25_EF4C_4399_A0AC_31AF8B6E1216__INCLUDED_)
