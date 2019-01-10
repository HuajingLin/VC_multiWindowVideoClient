// VideoWin.cpp : implementation file
//

#include "stdafx.h"
#include "VideoWin.h"
#include "MultiWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define VIDEO_TITLE_HEIGHT 19
/////////////////////////////////////////////////////////////////////////////
// CVideoWin

CVideoWin::CVideoWin()
{
	m_bSelected		= false;
	m_bFullScreen	= false;
	m_bRecording	= false;
	m_pMultWin		= NULL;
}

CVideoWin::~CVideoWin()
{
}

BEGIN_MESSAGE_MAP(CVideoWin, CWnd)
	//{{AFX_MSG_MAP(CVideoWin)
	ON_WM_CREATE()
	ON_WM_PAINT()	
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PARENTNOTIFY()	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoWin message handlers

int CVideoWin::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_pMultWin = GetParent();
	m_CTreeDropTarget.Register(this);
	RECT rect;
	memset(&rect,0,sizeof(rect));
	m_VideoImage.Create(NULL,WS_VISIBLE|WS_CHILD|WS_CLIPSIBLINGS, rect, this, IDC_LBL_VIDEO_IMAGE+m_nIndex);
	m_VideoTitle.Create(NULL,WS_VISIBLE|WS_CHILD, rect, this, IDC_LBL_VIDEO_TITLE+m_nIndex);
	if(m_nIndex==0)
		m_VideoTitle.SetCloseState(TRUE);
	return 0;
}

void CVideoWin::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	RECT  rect;
	GetClientRect(&rect);
	COLORREF color;
	if(m_bSelected)
		color=RGB(255,0,0);
	else
		color=RGB(255,255,255);

	CPen   BorderPen;
	BorderPen.CreatePen(PS_SOLID, 1, color);
	dc.SelectObject(&BorderPen); 
	dc.Rectangle(&rect);
	BorderPen.DeleteObject();	
	// Do not call CWnd::OnPaint() for painting messages
}

void CVideoWin::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	RECT rect,rect2;
	GetClientRect(&rect);
	if(rect.right<=0 || rect.bottom<=0) return;
	rect2 = rect;

	rect2.top += 1;
	rect2.left += 1;
	rect2.right -= 1;
	rect2.bottom = VIDEO_TITLE_HEIGHT;
	m_VideoTitle.MoveWindow(&rect2);
	rect2 = rect;
	rect2.left += 1;
	rect2.right -= 1;
	rect2.bottom -= 1;
	rect2.top = VIDEO_TITLE_HEIGHT;
	m_VideoImage.MoveWindow(&rect2);
}

void CVideoWin::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMultiWindow* pMWin=(CMultiWindow*)m_pMultWin;
	if(!pMWin) return;		
	pMWin->CancelAllWinSel();
	m_bSelected =TRUE;
	pMWin->SetCurSelectWin(m_nIndex);
	RefreshBorder();
	m_VideoTitle.SetCloseState(TRUE);
	if(pMWin->m_bFullScreen) return;
	//
	//刷新控件
	CWnd::OnLButtonDown(nFlags,point);
}

void CVideoWin::OnLButtonDblClk(UINT nFlags, CPoint point)	//双击全屏
{
	CMultiWindow* pMWin=(CMultiWindow*)m_pMultWin;
	if(!pMWin) return;
	
	if(pMWin->m_bFullScreen)
	{
		if(!pMWin) return;
		pMWin->FullScreen();
	}
	else
		FullScreen();
	
	CWnd::OnLButtonDblClk(nFlags, point);
}

void CVideoWin::CancelSel()
{
	m_bSelected=FALSE;
	RefreshBorder();
	m_VideoTitle.SetCloseState(FALSE);
}

void CVideoWin::RefreshBorder()							
{
	RECT   rect,rect2;
	GetClientRect(&rect);
	rect2=rect;
	rect2.bottom=1;
	InvalidateRect(&rect2);
	rect2=rect;
	rect2.right=1;
	InvalidateRect(&rect2);
	rect2=rect;
	rect2.top=rect.bottom-1;
	InvalidateRect(&rect2);
	rect2=rect;
	rect2.left=rect.right-1;
	InvalidateRect(&rect2);
}

void CVideoWin::FullScreen()						//全屏
{
	if(m_bFullScreen)
	{
		::SetWindowPlacement( GetSafeHwnd(), &m_wpeWindowPlacement );
		if(m_pParent) SetParent( m_pParent );
		m_bFullScreen = FALSE;
	}
	else
	{
	    m_pParent = GetParent();
		::GetWindowPlacement( GetSafeHwnd(), &m_wpeWindowPlacement );
		m_wpeWindowPlacement.length = sizeof( m_wpeWindowPlacement );		
		SetParent( NULL );		
		CRect rcScreen( 0, 0, GetSystemMetrics( SM_CXSCREEN ), GetSystemMetrics( SM_CYSCREEN ) );
		SetWindowPos( &wndTopMost,	rcScreen.left, rcScreen.top, rcScreen.Width(), rcScreen.Height(), SWP_SHOWWINDOW );
		SetFocus();
		m_bFullScreen = TRUE;
	}
}

void CVideoWin::OnParentNotify(UINT message, LPARAM lParam)  //播放视频时选中
{
	CWnd::OnParentNotify(message, lParam);
	if(message == WM_LBUTTONDOWN)
		OnLButtonDown(NULL,NULL);
}

BOOL CVideoWin::ConnectEncoder(int nCameraID)
{
	//TRACE("====CVideoWin::ConnectEncoder:%d\n",nCameraID);
	HWND hWnd = m_VideoImage.GetSafeHwnd();
	/*WORD nChNo;
	BOOL bRet = HD_EncoderLogin((LONG)m_hWnd, nCameraID, &nChNo);
	if(bRet == FALSE)
		return FALSE;
	bRet = HD_EncoderRealPlay((LONG)m_hWnd, (LONG)hWnd, nChNo);
	if(bRet)
		return TRUE;
	else
	{
		HD_EncoderLoginOut((LONG)m_hWnd);
		return FALSE;
	}*/
	return FALSE;
}
