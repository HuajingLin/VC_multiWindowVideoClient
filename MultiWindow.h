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
	UCHAR		m_nWinNum;		//�ָ��Ĵ�����
	UCHAR		m_nCurWin;		//��ǰѡ��Ĵ������0��ʼ
	CWnd		*m_pParent;		//ȫ��ʱ��
	CVideoWin	m_VideoWin[MAXWIN];
	WINDOWPLACEMENT m_wpeWindowPlacement;
// Construction
public:
	CMultiWindow();
	virtual ~CMultiWindow();
	BOOL	SplitWindow(UCHAR nWin);
	void	CancelAllWinSel();				//ȡ�����д���ѡ��״̬
	void	SetCurSelectWin(byte nWin);
	UCHAR	GetCurSelectWin();				//ȡ��ǰѡ�еĴ���ID
	void	FullScreen();					//ȫ��
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
