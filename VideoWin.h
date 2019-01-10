#if !defined(AFX_VIDEOWIN_H__815D70CC_CF47_490C_BE9D_F4B35C24916F__INCLUDED_)
#define AFX_VIDEOWIN_H__815D70CC_CF47_490C_BE9D_F4B35C24916F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoWin.h : header file
//
#include "VideoTitle.h"
#include "VideoImage.h"
#include "TreeDropTarget.h"
/////////////////////////////////////////////////////////////////////////////
// CVideoWin window

#define IDC_LBL_VIDEO_IMAGE 5101
#define IDC_LBL_VIDEO_TITLE 5201

class CSHVideoMClientDlg;
class CVideoWin : public CWnd
{
public:
	BYTE	m_nIndex;			//窗口序号
	CVideoTitle m_VideoTitle;	//标题栏
	CVideoImage m_VideoImage;	//视频图像
	bool	m_bSelected;		//是否被选中
	bool	m_bFullScreen;		//是否全屏
	bool	m_bRecording;
private:
	WINDOWPLACEMENT	m_wpeWindowPlacement;
	CTreeDropTarget m_CTreeDropTarget;	//树拖放目标
	CWnd	*m_pParent;					//用于全屏
	CWnd	*m_pMultWin;				//父窗口指针
	CFont	m_Font;						//字体
	//	
public:
	CVideoWin();
	void CancelSel();					//取消选中
	void RefreshBorder();				//刷新边框
	void FullScreen();					//全屏
public:
	BOOL ConnectEncoder(int nCameraID);
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoWin)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVideoWin();
	// Generated message map functions
protected:
	//{{AFX_MSG(CVideoWin)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();	
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnParentNotify(UINT message, LPARAM lParam);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOWIN_H__815D70CC_CF47_490C_BE9D_F4B35C24916F__INCLUDED_)
