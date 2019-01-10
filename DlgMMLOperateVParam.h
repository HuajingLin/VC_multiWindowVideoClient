#if !defined(AFX_DLGMMLOPERATEVPARAM_H__05C72412_D5FE_4FF8_8EDA_9582356E28B7__INCLUDED_)
#define AFX_DLGMMLOPERATEVPARAM_H__05C72412_D5FE_4FF8_8EDA_9582356E28B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLOperateVParam.h : header file
//
#include "MySliderControl.h"
#include "BackgroundPic.h"
#include "ControlButton.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperateVParam dialog

class CDlgMMLOperateVParam : public CDialog
{
// Construction
public:
	CDlgMMLOperateVParam(CWnd* pParent = NULL);   // standard constructor
private:
	CBrush					m_bkBrush;
// Dialog Data
	//{{AFX_DATA(CDlgMMLOperateVParam)
	enum { IDD = IDD_MMLO_VIDEO_PARAM };
	CControlButton		m_btnDefault;
	CBackgroundPic		m_lblTitle;
	CMySliderControl	m_sliderSound;
	CMySliderControl	m_sliderSharp;
	CMySliderControl	m_sliderSaturat;
	CMySliderControl	m_sliderContrast;
	CMySliderControl	m_sliderBright;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLOperateVParam)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLOperateVParam)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLOPERATEVPARAM_H__05C72412_D5FE_4FF8_8EDA_9582356E28B7__INCLUDED_)
