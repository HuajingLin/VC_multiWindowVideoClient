// TabButton.cpp : implementation file
//

#include "stdafx.h"
#include "TabButton.h"
#include "MEMDCEX.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CButtonRecord

CTabButton::CTabButton()
{
	m_bBuDown = false;
	m_nGroup = 0;
	m_DrawMode=0;
	m_tracking =  FALSE;
	m_id = 0;
	memset(m_sText,0,BUTNTEXTLEN);
	m_nTextLeft = 0;
}

CTabButton::~CTabButton()
{
}


BEGIN_MESSAGE_MAP(CTabButton, CButton)
	//{{AFX_MSG_MAP(CTabButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonRecord message handlers


void CTabButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(m_id > 0)
		::SendMessage(GetParent()->m_hWnd, WM_BMP_BTNDOWN, m_id, 0);
	CButton::OnLButtonDown(nFlags, point);	
}
	
void CTabButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (!m_tracking)
	{
		TRACKMOUSEEVENT t = 
		{
            sizeof(TRACKMOUSEEVENT),
				TME_LEAVE, m_hWnd, 0  
		};
		
        if (::_TrackMouseEvent(&t))
		{
            m_tracking = true;
            Invalidate();
        }
    }
    CButton::OnMouseMove(nFlags, point);
}

void CTabButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(m_id > 0)
		::SendMessage(GetParent()->m_hWnd, WM_BMP_BTNUP, m_id, 0);
	CWnd::OnLButtonUp(nFlags, point);
}

LRESULT CTabButton::OnMouseLeave(WPARAM, LPARAM)
{
    m_tracking = false;
    Invalidate();
	return 0;
}

void CTabButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	RECT r=lpDrawItemStruct->rcItem;
	if (m_bBuDown)
	{
		DrawBitmap(pDC,(HBITMAP)m_bDown,r,m_DrawMode);
	}
	else
	{
		if ((m_tracking)&&(m_bOver.m_hObject != NULL))			
			DrawBitmap(pDC,(HBITMAP)m_bOver,r,m_DrawMode);
		else
			DrawBitmap(pDC,(HBITMAP)m_bNormal,r,m_DrawMode);				
	}
}

void CTabButton::SetSkin(UINT normal, UINT down, UINT over, UCHAR drawmode)
{
	m_bNormal.DeleteObject();
	m_bDown.DeleteObject();
	m_bOver.DeleteObject();
	
	if (normal>0) m_bNormal.LoadBitmap(normal);
	if (down>0)	  m_bDown.LoadBitmap(down);
	if (over>0)   m_bOver.LoadBitmap(over);	
	
	m_DrawMode=max(0,min(drawmode,2));
}

void CTabButton::DrawBitmap(CDC *dc, HBITMAP hbmp, RECT r, UCHAR DrawMode)
{
//	DrawMode: 0=Normal; 1=stretch;
	if(!hbmp) return;

	int cx=r.right  - r.left;
	int cy=r.bottom - r.top;
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(dc);
	HBITMAP hOldBitmap = (HBITMAP)dcBmp.SelectObject(hbmp);
	size_t TextLen = strlen(m_sText);
	CMemDCEX *pMemDC=NULL;
	if(!DrawMode)
	{
		if(TextLen==0)
			dc->BitBlt(r.left,r.top,cx,cy,&dcBmp,0,0,SRCCOPY);
		else
		{
			if(pMemDC==NULL) pMemDC=new CMemDCEX(dc,r);
			pMemDC->BitBlt(r.left,r.top,cx,cy,&dcBmp,0,0,SRCCOPY);
		}
	}
	else
	{
		BITMAP bm;
		GetObject(hbmp,sizeof(BITMAP),(PSTR)&bm);
		int bx=bm.bmWidth;
		int by=bm.bmHeight;
		if(TextLen==0)
			dc->StretchBlt(r.left,r.top,cx,cy,&dcBmp,0,0,bx,by,SRCCOPY);
		else
		{
			if(pMemDC==NULL) pMemDC=new CMemDCEX(dc,r);
			pMemDC->StretchBlt(r.left,r.top,cx,cy,&dcBmp,0,0,bx,by,SRCCOPY);
		}
	}
	if(TextLen>0)
	{
		if(pMemDC==NULL) pMemDC=new CMemDCEX(dc,r);
		int iMode = 0;
		iMode = pMemDC->SetBkMode(TRANSPARENT);
		COLORREF rgbText = RGB(0,0,0);
		pMemDC->SetTextColor(rgbText);
		CFont fontText;
		fontText.CreateFont(15,0,0,0,100,0,0,0,    
			ANSI_CHARSET,OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH|FF_DONTCARE,
			"Times New Roman"); 
		//////
		CFont * pOldFont = pMemDC->SelectObject(&fontText);
		RECT rect;
		rect.left=r.left+m_nTextLeft;
		rect.top=r.top+1;
		rect.bottom=r.bottom;
		rect.right=r.right;
		pMemDC->DrawText(m_sText, &rect, DT_VCENTER|DT_SINGLELINE); 
		if (NULL != pOldFont)
		{
			pMemDC->SelectObject(pOldFont);
		}
		pMemDC->SetTextColor(rgbText);
		pMemDC->SetBkMode(iMode);
	}
	if(pMemDC!=NULL) delete pMemDC;
	dcBmp.SelectObject( hOldBitmap );
	dcBmp.DeleteDC();
}

void CTabButton::PreSubclassWindow() 
{
	CButton::PreSubclassWindow();
	ModifyStyle(0, BS_OWNERDRAW);
}

void CTabButton::SetDown()
{
	m_bBuDown = true;
	Invalidate(FALSE);
}

void CTabButton::SetUp()
{
	m_bBuDown = false;
	Invalidate(FALSE);
}

void CTabButton::SetText(const char* sText,UCHAR left)
{
	if(sText!=NULL)
	{
		m_nTextLeft = left;
		size_t n= strlen(sText);
		strncpy(m_sText,sText,n);
	}
}
