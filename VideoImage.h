#if !defined(AFX_VIDEOIMAGE_H__048044EC_6C4E_4EC6_A661_6F9998339BD3__INCLUDED_)
#define AFX_VIDEOIMAGE_H__048044EC_6C4E_4EC6_A661_6F9998339BD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoImage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVideoImage window

class CVideoImage : public CStatic
{
// Construction
public:
	CVideoImage();

// Attributes
public:
	CWnd*	m_pParent;
// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoImage)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVideoImage();

	// Generated message map functions
protected:
	//{{AFX_MSG(CVideoImage)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOIMAGE_H__048044EC_6C4E_4EC6_A661_6F9998339BD3__INCLUDED_)
