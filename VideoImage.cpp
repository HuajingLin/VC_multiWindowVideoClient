// VideoImage.cpp : implementation file
//

#include "stdafx.h"
#include "VideoImage.h"
#include "VideoWin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVideoImage

CVideoImage::CVideoImage()
{
	m_pParent = NULL;
}

CVideoImage::~CVideoImage()
{
}


BEGIN_MESSAGE_MAP(CVideoImage, CStatic)
	//{{AFX_MSG_MAP(CVideoImage)
	ON_WM_CREATE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoImage message handlers

int CVideoImage::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_pParent = GetParent();
	CVideoWin* pVideoWin = (CVideoWin*)m_pParent;
	return 0;
}

void CVideoImage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
		
	CRect   rect;
	COLORREF color;
	CPen   BorderPen;
	GetClientRect(&rect);
	CBrush * pOldBrush;

	color=RGB(0,0,0);
	BorderPen.CreatePen(PS_SOLID,1,color);
	dc.SelectObject(&BorderPen); 
	dc.Rectangle(rect);
	BorderPen.DeleteObject();
		
	CBrush brushBackground(RGB(0x0,0x0,0x0));
	pOldBrush = dc.SelectObject( &brushBackground );
	dc.Rectangle( &rect );
	dc.SelectObject( pOldBrush );
	brushBackground.DeleteObject();
	
	// Do not call CStatic::OnPaint() for painting messages
}
