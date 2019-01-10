#if !defined(AFX_DLGMMLOPERATEPTZ_H__727D01AC_2F4F_497C_89DF_59013A39044F__INCLUDED_)
#define AFX_DLGMMLOPERATEPTZ_H__727D01AC_2F4F_497C_89DF_59013A39044F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMMLOperatePtz.h : header file
//
#include "BmpButton.h"
#include "MySliderControl.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperatePtz dialog
#include "MultiWindow.h"
class CDlgMMLOperatePtz : public CDialog
{
// Construction
public:
	void SetMultiWinPtr(void *pMultiWin);
	CDlgMMLOperatePtz(CWnd* pParent = NULL);   // standard constructor
private:
	CBrush				m_bkBrush;
	CMultiWindow*		m_pMultiWin;

// Dialog Data
	//{{AFX_DATA(CDlgMMLOperatePtz)
	enum { IDD = IDD_MMLO_PTZ };
	CMySliderControl	m_SliderSpeed;
	CBmpButton	m_btnLeftRight;
	CBmpButton	m_btnZoomOut;
	CBmpButton	m_btnZoomIn;
	CBmpButton	m_btnFocalBack;
	CBmpButton	m_btnFocalFront;
	CBmpButton	m_btnDown;
	CBmpButton	m_btnApertBig;
	CBmpButton	m_btnApertSmall;
	CBmpButton	m_btn3D;
	CBmpButton	m_btnWiper;
	CBmpButton	m_btnUpRight;
	CBmpButton	m_btnUp;
	CBmpButton	m_btnRightDown;
	CBmpButton	m_btnRight;
	CBmpButton	m_btnLight;
	CBmpButton	m_btnLeftDown;
	CBmpButton	m_btnLeft;
	CBmpButton	m_btnLeftUp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMMLOperatePtz)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMMLOperatePtz)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnReleasedcaptureSliderPtz(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMMLOPERATEPTZ_H__727D01AC_2F4F_497C_89DF_59013A39044F__INCLUDED_)
