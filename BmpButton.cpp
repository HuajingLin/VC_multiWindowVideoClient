// BmpButton.cpp : implementation file
//

#include "stdafx.h"
#include "BmpButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBmpButton

CBmpButton::CBmpButton()
{
	m_hCursor = NULL;
	m_ToolTip.m_hWnd = NULL;
	m_dwToolTipStyle = 0;

	OnMouse = FALSE;
	bMouseBown = FALSE;
	m_nCtrlId = -1;
	//SetCur(IDC_CURSOR_HAND,FALSE);
}

CBmpButton::~CBmpButton()
{
	if (m_hCursor) ::DestroyCursor(m_hCursor);
}


BEGIN_MESSAGE_MAP(CBmpButton, CButton)
	//{{AFX_MSG_MAP(CBmpButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBmpButton message handlers


void CBmpButton::SizeToContent()
{
	ASSERT(m_bitmap.m_hObject != NULL);
	CSize bitmapSize;
	BITMAP bmInfo;
	VERIFY(m_bitmap.GetObject(sizeof(bmInfo), &bmInfo) == sizeof(bmInfo));
	VERIFY(SetWindowPos(NULL, -1, -1, bmInfo.bmWidth, bmInfo.bmHeight,
		SWP_NOMOVE|SWP_NOZORDER|SWP_NOREDRAW|SWP_NOACTIVATE));
}

BOOL CBmpButton::AutoLoad(UINT nID, CWnd *pParent)
{
	// first attach the CBmpButton to the dialog control
	if (!SubclassDlgItem(nID, pParent))
		return FALSE;

    ModifyStyle(WS_TABSTOP, BS_OWNERDRAW); 

	CString buttonName;
	GetWindowText(buttonName);
	ASSERT(!buttonName.IsEmpty());      // must provide a title

	LoadBitmaps(buttonName + _T("U"), buttonName + _T("D"),
	  buttonName + _T("F"), buttonName + _T("X"));

	// we need at least the primary
	if (m_bitmap.m_hObject == NULL)
		return FALSE;

	// size to content
	SizeToContent();
	return TRUE;
}

BOOL CBmpButton::LoadBitmaps(LPCTSTR lpszBitmapResource,
	LPCTSTR lpszBitmapResourceSel, LPCTSTR lpszBitmapResourceFocus,
	LPCTSTR lpszBitmapResourceDisabled)
{
	// delete old bitmaps (if present)
	m_bitmap.DeleteObject();
	m_bitmapSel.DeleteObject();
	m_bitmapFocus.DeleteObject();
	m_bitmapDisabled.DeleteObject();

	if (!m_bitmap.LoadBitmap(lpszBitmapResource))
	{
//		TRACE0("Failed to load bitmap for normal image.\n");
		return FALSE;   // need this one image
	}
	BOOL bAllLoaded = TRUE;
	if (lpszBitmapResourceSel != NULL)
	{
		if (!m_bitmapSel.LoadBitmap(lpszBitmapResourceSel))
		{
		//	TRACE0("Failed to load bitmap for selected image.\n");
			bAllLoaded = FALSE;
		}
	}
	if (lpszBitmapResourceFocus != NULL)
	{
		if (!m_bitmapFocus.LoadBitmap(lpszBitmapResourceFocus))
			bAllLoaded = FALSE;
	}
	if (lpszBitmapResourceDisabled != NULL)
	{
		if (!m_bitmapDisabled.LoadBitmap(lpszBitmapResourceDisabled))
			bAllLoaded = FALSE;
	}
	return bAllLoaded;
}

BOOL CBmpButton::LoadBitmaps(UINT nIDBitmapResource,
						UINT nIDBitmapResourceSel,
						UINT nIDBitmapResourceFocus,
						UINT nIDBitmapResourceDisabled,
						int CtrlId)
{
	// delete old bitmaps (if present)
	m_nCtrlId = CtrlId;
	m_bitmap.DeleteObject();
	m_bitmapSel.DeleteObject();
	m_bitmapFocus.DeleteObject();
	m_bitmapDisabled.DeleteObject();

	if (!m_bitmap.LoadBitmap(nIDBitmapResource))
	{
//		TRACE0("Failed to load bitmap for normal image.\n");
		return FALSE;   // need this one image
	}
	BOOL bAllLoaded = TRUE;
	if (nIDBitmapResourceSel != 0)
	{
		if (!m_bitmapSel.LoadBitmap(nIDBitmapResourceSel))
		{
//			TRACE0("Failed to load bitmap for selected image.\n");
			bAllLoaded = FALSE;
		}
	}
	if (nIDBitmapResourceFocus != 0)
	{
		if (!m_bitmapFocus.LoadBitmap(nIDBitmapResourceFocus))
			bAllLoaded = FALSE;
	}
	if (nIDBitmapResourceDisabled != 0)
	{
		if (!m_bitmapDisabled.LoadBitmap(nIDBitmapResourceDisabled))
			bAllLoaded = FALSE;
	}
	return bAllLoaded;
}
// Handler for WM_MOUSELEAVE
LRESULT CBmpButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{

	SendMessage(WM_KILLFOCUS,0,0);
	OnMouse = FALSE;
	return S_OK;
} // End of OnMouseLeave

void CBmpButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd*				wndUnderMouse = NULL;
	CWnd*				wndActive = this;
	TRACKMOUSEEVENT		csTME;

	ClientToScreen(&point);
	wndUnderMouse = WindowFromPoint(point);

	if (wndUnderMouse && wndUnderMouse->m_hWnd == m_hWnd && wndActive)
	{
		csTME.cbSize = sizeof(csTME);
		csTME.dwFlags = TME_LEAVE;
		csTME.hwndTrack = m_hWnd;
		::_TrackMouseEvent(&csTME);
		OnMouse = TRUE;
		SendMessage(WM_SETFOCUS,(WPARAM)m_hWnd ,0);
	}
	CButton::OnMouseMove(nFlags, point);
}

void CBmpButton::DrawItem(LPDRAWITEMSTRUCT lpDIS) 
{
	//::OutputDebugString("CBmpButton::DrawItem\n");


	ASSERT(lpDIS != NULL);
	// must have at least the first bitmap loaded before calling DrawItem
	ASSERT(m_bitmap.m_hObject != NULL);     // required

	// use the main bitmap for up, the selected bitmap for down
	CBitmap* pBitmap = &m_bitmap;
	UINT state = lpDIS->itemState;
	if ((state & ODS_SELECTED) && m_bitmapSel.m_hObject != NULL)
		pBitmap = &m_bitmapSel;
	else if ( (state & ODS_FOCUS) && (m_bitmapFocus.m_hObject != NULL) && OnMouse )
		pBitmap = &m_bitmapFocus;   // third image for focused
	else if ((state & ODS_DISABLED) && m_bitmapDisabled.m_hObject != NULL)
		pBitmap = &m_bitmapDisabled;   // last image for disabled
	// draw the whole button
	if(bMouseBown)
	{
		if(m_bitmapSel.m_hObject != NULL)
			pBitmap = &m_bitmapSel;
		else
			pBitmap = &m_bitmap;
	}

	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap* pOld = memDC.SelectObject(pBitmap);
	if (pOld == NULL)
		return;     // destructors will clean up

	CRect rect;
	rect.CopyRect(&lpDIS->rcItem);
	pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),
		&memDC, 0, 0, SRCCOPY);
	//pDC->TextOut(0,0,"123");
	memDC.SelectObject(pOld);	
	DeleteDC(memDC);//add by xjm 2010-07-12
}

BOOL CBmpButton::PreTranslateMessage(MSG* pMsg) 
{
	InitToolTip();
	m_ToolTip.RelayEvent(pMsg);

	if(pMsg->message == WM_LBUTTONDBLCLK)
		pMsg->message = WM_LBUTTONDOWN;
	
	return CButton::PreTranslateMessage(pMsg);
}

BOOL CBmpButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (m_hCursor != NULL)
	{
		::SetCursor(m_hCursor);
		return TRUE;
	}
	return CButton::OnSetCursor(pWnd, nHitTest, message);
}

BOOL CBmpButton::SetCur(HCURSOR hCursor, BOOL bRepaint)
{
	if (m_hCursor)
	{
		::DestroyCursor(m_hCursor);
		m_hCursor = NULL;
	}
	m_hCursor=hCursor;	
	if (bRepaint) Invalidate();
	return (m_hCursor == NULL ? FALSE : TRUE );
}

BOOL CBmpButton::SetCur(int nCursorId, BOOL bRepaint)
{
	HINSTANCE	hInstResource = NULL;
	if (m_hCursor)
	{
		::DestroyCursor(m_hCursor);
		m_hCursor = NULL;
	}
	if (nCursorId)
	{
		hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(nCursorId), RT_GROUP_CURSOR);
		m_hCursor = (HCURSOR)::LoadImage(hInstResource, MAKEINTRESOURCE(nCursorId), IMAGE_CURSOR, 0, 0, 0);
		if (bRepaint) Invalidate();
	}
	return (m_hCursor == NULL ? FALSE : TRUE );
}

///////////////////////////////////////////////////////////////////////////////
//                      CToolTipCtrl
///////////////////////////////////////////////////////////////////////////////

void CBmpButton::InitToolTip()
{
	if (m_ToolTip.m_hWnd == NULL)
	{
		m_ToolTip.Create(this, m_dwToolTipStyle);
		m_ToolTip.Activate(FALSE);
		m_ToolTip.SendMessage(TTM_SETMAXTIPWIDTH, 0, 400);
		//m_ToolTip.SendMessage(TTM_SETTITLE, TTI_INFO, (LPARAM)_T("Title"));
	} // if
}

void CBmpButton::SetTooltipText(int nText, BOOL bActivate)
{
	CString sText;
	sText.LoadString(nText);
	if (sText.IsEmpty() == FALSE) 
		SetTooltipText((LPCTSTR)sText, bActivate);
}

void CBmpButton::SetTooltipText(LPCTSTR lpszText, BOOL bActivate)
{
	if (lpszText == NULL) return;
	InitToolTip();
	if (m_ToolTip.GetToolCount() == 0)
	{
		CRect rectBtn; 
		GetClientRect(rectBtn);
		m_ToolTip.AddTool(this, lpszText, rectBtn, 1);
	}
	m_ToolTip.UpdateTipText(lpszText, this, 1);
	m_ToolTip.Activate(bActivate);
}

void CBmpButton::ActivateTooltip(BOOL bEnable)
{
	// If there is no tooltip then do nothing
	if (m_ToolTip.GetToolCount() == 0) return;
	// Activate tooltip
	m_ToolTip.Activate(bEnable);
}

void CBmpButton::EnableBalloonTooltip()
{
	m_dwToolTipStyle |= TTS_BALLOON;
}

//////////////////////////

void CBmpButton::SetMouseDown(BOOL bDown)
{
	bMouseBown = bDown;
	//if(! bMouseBown)
	Invalidate();
}


void CBmpButton::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_nCtrlId > -1)
	{
		::SendMessage(GetParent()->m_hWnd, WM_BMP_BTNDOWN, m_nCtrlId/*可为id号*/,   0);   
	}
	CButton::OnLButtonDown(nFlags, point);
}

void CBmpButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_nCtrlId > -1)
	{
		::SendMessage(GetParent()->m_hWnd,   WM_BMP_BTNUP, m_nCtrlId/*可为id号*/,   0); 
	}
	CButton::OnLButtonUp(nFlags, point);
}
