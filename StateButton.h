#if !defined(AFX_STATEBUTTON_H__85DB00EE_E96B_4E4B_A07C_B63756219A81__INCLUDED_)
#define AFX_STATEBUTTON_H__85DB00EE_E96B_4E4B_A07C_B63756219A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StateButton.h : header file
#define BUTNTEXTLEN     20
/////////////////////////////////////////////////////////////////////////////

class CStateButton : public CButton
{
// Construction
public:
	CStateButton();

// Attributes
public:

// Operations
public:
	//short	m_nType;
	UCHAR   m_nGroup;
	bool    m_bBuDown;
	UINT	m_id;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonRecord)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetUp();
	void SetDown();
	void SetSkin(UINT normal,UINT down, UINT over=0, UCHAR drawmode=0);
	void SetText(const char* sText,UCHAR left=20);
	void SetTooltipText(LPCTSTR lpszText, BOOL bActivate = TRUE);
	virtual ~CStateButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonRecord)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
	void DrawBitmap(CDC* dc, HBITMAP hbmp, RECT r, UCHAR DrawMode);
	void InitToolTip();
	void EnableBalloonTooltip();
protected:	
	CBitmap m_bNormal, m_bDown, m_bOver;
	UCHAR   m_tracking;
	UCHAR	m_DrawMode;				//0=normal; 1=stretch;
	char    m_sText[BUTNTEXTLEN];
	UCHAR	m_nTextLeft;
	CToolTipCtrl	m_ToolTip;
	DWORD			m_dwToolTipStyle;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONRECORD_H__85DB00EE_E96B_4E4B_A07C_B63756219A81__INCLUDED_)
