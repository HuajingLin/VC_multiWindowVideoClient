#if !defined(AFX_BACKGROUNDPIC_H__B8343DD6_A906_4AA1_B391_B35014994A65__INCLUDED_)
#define AFX_BACKGROUNDPIC_H__B8343DD6_A906_4AA1_B391_B35014994A65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BackgroundPic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackgroundPic window

class CBackgroundPic : public CStatic
{
// Construction
public:
	CBackgroundPic();

// Attributes
public:
	bool SetBitmapID(int bitMapID);
// Operations
private:
	HBITMAP m_hBitmap;
	CRect m_Rect;
	int   m_bitMapID;
private:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBackgroundPic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBackgroundPic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBackgroundPic)
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICPIC_H__B8343DD6_A906_4AA1_B391_B35014994A65__INCLUDED_)
