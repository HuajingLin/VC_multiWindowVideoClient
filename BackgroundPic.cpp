// BackgroundPic.cpp : implementation file
//

#include "stdafx.h"
#include "BackgroundPic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBackgroundPic

CBackgroundPic::CBackgroundPic()
{
	m_hBitmap = NULL;
	m_bitMapID= 0;
}

CBackgroundPic::~CBackgroundPic()
{
}


BEGIN_MESSAGE_MAP(CBackgroundPic, CStatic)
	//{{AFX_MSG_MAP(CBackgroundPic)
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBackgroundPic message handlers

void CBackgroundPic::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// Do not call CStatic::OnPaint() for painting messages
}

bool CBackgroundPic::SetBitmapID(int bitMapID)
{
	HINSTANCE	hInstResource = NULL;
	m_bitMapID = bitMapID;
	if(m_bitMapID <= 0)
		return false;
	return true;
}

void CBackgroundPic::OnDestroy() 
{
	CStatic::OnDestroy();	
	if (m_hBitmap != NULL)
	{
		::DeleteObject(m_hBitmap);
		m_hBitmap = NULL;
	}
}

BOOL CBackgroundPic::OnEraseBkgnd(CDC* pDC) 
{
	if(m_bitMapID == 0)
		return CStatic::OnEraseBkgnd(pDC);
	CBitmap m_bmp;
	m_bmp.LoadBitmap(m_bitMapID);
	
	CRect rect;
	GetClientRect(&rect);
	CBrush m_brush(&m_bmp);
	pDC->FillRect(&rect,&m_brush);	
	return TRUE;
	return CStatic::OnEraseBkgnd(pDC);
}

