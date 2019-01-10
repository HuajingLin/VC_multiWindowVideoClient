#if !defined(AFX_BBBB_H__29B6E0E1_1B79_4856_9529_93551C89CE23__INCLUDED_)
#define AFX_BBBB_H__29B6E0E1_1B79_4856_9529_93551C89CE23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define TTS_BALLOON             0x40
// BmpButton.h : header file
//
/*
    Note: 此位图按钮功能比较完善
	      Button属性:   Remove  WS_TABSTOP
		                Add     BS_OWNRDRAW
	      在AutoLoad()中 ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
*/
/////////////////////////////////////////////////////////////////////////////
// CBmpButton window

class CBmpButton : public CButton
{
// Construction
public:
	CBmpButton();
	virtual ~CBmpButton();
// Attributes
public:
	static int GetVersionI()		{return 10;}
	static LPCTSTR GetVersionC()	{return (LPCTSTR)_T("1.0");}

// Operations
public:
	BOOL SetCur(HCURSOR hCursor, BOOL bRepaint); 
	BOOL SetCur(int nCursorId, BOOL bRepaint);
	void EnableBalloonTooltip();
	void ActivateTooltip(BOOL bEnable = TRUE);
	void SetTooltipText(LPCTSTR lpszText, BOOL bActivate = TRUE);
	void SetTooltipText(int nText, BOOL bActivate = TRUE);
	void SetMouseDown(BOOL bDown);
	BOOL LoadBitmaps(LPCTSTR lpszBitmapResource,
			LPCTSTR lpszBitmapResourceSel = NULL,
			LPCTSTR lpszBitmapResourceFocus = NULL,
			LPCTSTR lpszBitmapResourceDisabled = NULL);
	BOOL LoadBitmaps(UINT nIDBitmapResource,
			UINT nIDBitmapResourceSel = 0,
			UINT nIDBitmapResourceFocus = 0,
			UINT nIDBitmapResourceDisabled = 0,
			int CtrlId = -1);
	BOOL AutoLoad(UINT nID, CWnd* pParent);
	void SizeToContent();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBmpButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDIS);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_nCtrlId;	

	// Generated message map functions
protected:
	// all bitmaps must be the same size
	CBitmap m_bitmap;           // normal image (REQUIRED)
	CBitmap m_bitmapSel;        // selected image (OPTIONAL)
	CBitmap m_bitmapFocus;      // focused but not selected (OPTIONAL)
	CBitmap m_bitmapDisabled;   // disabled bitmap (OPTIONAL)

	//{{AFX_MSG(CBmpButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitToolTip();
	LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
private:
	BOOL			bMouseBown;
	BOOL			OnMouse;
	CToolTipCtrl	m_ToolTip;
	DWORD			m_dwToolTipStyle;	// Style of tooltip control
	HCURSOR			m_hCursor;	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BBBB_H__29B6E0E1_1B79_4856_9529_93551C89CE23__INCLUDED_)
