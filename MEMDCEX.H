#ifndef _MEMDC_H_
#define _MEMDC_H_

//////////////////////////////////////////////////
// CMemDC - memory DC
//
// Author: Keith Rule
// Email:  keithr@europa.com
// Copyright 1996-1997, Keith Rule
//
// You may freely use or modify this code provided this
// Copyright is included in all derived versions.
//
// This class implements a memory Device Context

class CMemDCEX : public CDC 
{
public:
	CBitmap*	m_bitmap;
	CBitmap*	m_oldBitmap;
	CDC*		m_pDC;
	CRect		m_rcBounds;
public:
	//默认构造函数
	CMemDCEX() : CDC()
	{
	}


	CMemDCEX(CDC* pDC, const CRect& rcBounds) : CDC()
	{
		CreateCompatibleDC(pDC);
		m_bitmap = new CBitmap;
		m_bitmap->CreateCompatibleBitmap(pDC, rcBounds.Width(), rcBounds.Height());
		m_oldBitmap = SelectObject(m_bitmap);
		m_pDC = pDC;
		m_rcBounds = rcBounds;
	}

	~CMemDCEX() 
	{
		m_pDC->BitBlt(m_rcBounds.left, m_rcBounds.top, m_rcBounds.Width(), m_rcBounds.Height(), 
					this, /*m_rcBounds.left, m_rcBounds.top*/0,0, SRCCOPY);
		SelectObject(m_oldBitmap);
		if (m_bitmap != NULL) 
			delete m_bitmap;
	}

	//赋值函数
	CMemDCEX& operator = (const CMemDCEX & memDCOther)
	{
		CreateCompatibleDC(memDCOther.m_pDC);
		m_bitmap = new CBitmap;
		m_bitmap->CreateCompatibleBitmap(memDCOther.m_pDC, memDCOther.m_rcBounds.Width(), memDCOther.m_rcBounds.Height());
		m_oldBitmap = SelectObject(m_bitmap);
		m_pDC = memDCOther.m_pDC;
		m_rcBounds = memDCOther.m_rcBounds;

		return *this;
	}

	CMemDCEX* operator->() 
	{
		return this;
	}
};

#endif