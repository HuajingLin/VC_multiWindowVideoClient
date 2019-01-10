#if !defined(AFX_MULTIWINDOW_H__C193DE1F_72BD_402D_8EAC_935B535F6FCB__INCLUDED_)
#define AFX_MULTIWINDOW_H__C193DE1F_72BD_402D_8EAC_935B535F6FCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MultiWindow.h : header file
//
#include "VideoWin.h"
#define PANEL_TYPE_TREE 1
#define PANEL_TYPE_PTZ	2
/////////////////////////////////////////////////////////////////////////////
// CMultiWindow window

class CMultiWindow : public CWnd
{
public:
	UCHAR		m_bFullScreen;
	UCHAR		m_nWinNum;		//分隔的窗口数
	UCHAR		m_nCurWin;		//当前选择的窗口序号0开始
	CWnd		*m_pParent;		//全屏时用
	CVideoWin	m_VideoWin[MAXWIN];
	WINDOWPLACEMENT m_wpeWindowPlacement;
// Construction
public:
	CMultiWindow();
	virtual ~CMultiWindow();
	BOOL	SplitWindow(UCHAR nWin);
	void	CancelAllWinSel();				//取消所有窗口选中状态
	void	SetCurSelectWin(byte nWin);
	UCHAR	GetCurSelectWin();				//取当前选中的窗口ID
	void	FullScreen();					//全屏
	void	SingleWinFullScreen(UCHAR nIndex);
	void	SetPanelPtr(byte nType,void* pPanel);
public:
	BOOL ConnectEncoder(int CameraID);
private:
	void* m_pPanelTree;
	void* m_pPanelPtz;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiWindow)
	//}}AFX_VIRTUAL

// Implementation

	// Generated message map functions
protected:
	//{{AFX_MSG(CMultiWindow)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIWINDOW_H__C193DE1F_72BD_402D_8EAC_935B535F6FCB__INCLUDED_)
