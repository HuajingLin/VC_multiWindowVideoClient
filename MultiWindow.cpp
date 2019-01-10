// MultiWindow.cpp : implementation file
//

#include "stdafx.h"
#include "MultiWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define VIDEO_WIN_ID	33300
/////////////////////////////////////////////////////////////////////////////
// CMultiWindow

CMultiWindow::CMultiWindow()
{
	m_nCurWin = 0;
	m_nWinNum = 0;
	m_pParent = NULL;
	m_bFullScreen = FALSE;
	//
	m_pPanelTree = NULL;
	m_pPanelPtz = NULL;
}

CMultiWindow::~CMultiWindow()
{
}


BEGIN_MESSAGE_MAP(CMultiWindow, CWnd)
	//{{AFX_MSG_MAP(CMultiWindow)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMultiWindow message handlers

int CMultiWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rect(0,0,0,0);
	for(UCHAR i=0; i<MAXWIN; i++)
	{
		m_VideoWin[i].m_nIndex = i;
		m_VideoWin[i].Create(NULL,NULL,WS_VISIBLE|WS_CHILD|WS_CLIPCHILDREN|WS_CLIPSIBLINGS, rect, this, VIDEO_WIN_ID+i);
		if(m_VideoWin[i].m_nIndex == 0)
			m_VideoWin[i].m_bSelected=TRUE;
	}
	return 0;
}

void CMultiWindow::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
		CRect rect,rect2;
	GetClientRect(&rect);
	if(rect.right<=0||rect.bottom<=0) return;
	
	rect2 = rect;	
	if (1 == m_nWinNum)
	{
		for(short i=0; i<MAXWIN; i++)
		{
			if(m_VideoWin[i].m_bSelected)
				m_VideoWin[i].MoveWindow(&rect);
			else
				m_VideoWin[i].MoveWindow(CRect(0,0,0,0));
		}
	}
	else if(4 == m_nWinNum)
	{
		CRect tRect = rect;
		rect.bottom = rect.bottom / 2 -1;
		rect.right = rect.right / 2 - 1;
		m_VideoWin[0].MoveWindow(&rect);

		rect.left = rect.right + 2;
		rect.right = tRect.right;
		m_VideoWin[1].MoveWindow(&rect);
		
		rect = tRect;
		rect.top = rect.bottom / 2 + 1;
		rect.right = rect.right / 2 - 1;
		m_VideoWin[3].MoveWindow(&rect);

		rect.left = rect.right + 2 ;
		rect.right = tRect.right;
		m_VideoWin[2].MoveWindow(&rect);
		
		for(short i=4; i<MAXWIN; i++)
			m_VideoWin[i].MoveWindow(CRect(0,0,0,0));
	}
	else if(6 == m_nWinNum)
	{
		CRect tRect = rect;
		rect.bottom = rect.bottom / 3 * 2 -1;
		rect.right = rect.right / 3 * 2 - 1;
		m_VideoWin[0].MoveWindow(&rect);

		rect.left = rect.right + 2;
		rect.right = tRect.right;
		rect.bottom = tRect.bottom / 3 - 1;
		m_VideoWin[1].MoveWindow(&rect);

		rect.top = rect.bottom + 2;
		rect.bottom = tRect.bottom /3 * 2 - 1;
		m_VideoWin[2].MoveWindow(&rect);

		rect.top = rect.bottom + 2;
		rect.bottom = tRect.bottom;
		m_VideoWin[3].MoveWindow(&rect);

		rect.left = tRect.right / 3 + 1;
		rect.right = tRect.right / 3 * 2 - 1;
		m_VideoWin[4].MoveWindow(&rect);

		rect.right = rect.left - 2;
		rect.left = 0;
		m_VideoWin[5].MoveWindow(&rect);

		for(short i=6; i<MAXWIN; i++)
			m_VideoWin[i].MoveWindow(CRect(0,0,0,0));
	}
	else if(9 == m_nWinNum)
	{
		for(short i=1; i<=3; i++)
		{
			rect = rect2;
			long lRight = rect.right;
			if(1 == i)
				rect.bottom = rect.bottom / 3-1;
			else if(2 == i)
			{
				rect.top = rect.bottom / 3;
				rect.bottom = rect.bottom / 3 * 2-1;
			}
			else if(3 == i)
				rect.top = rect.bottom / 3 * 2;
			
			if(3 == i)
				rect.bottom = rect.bottom;
			else
				rect.bottom = rect.bottom - 1;
			rect.right = rect.right / 3 - 1;
			m_VideoWin[ 3 * i - 3].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = rect.right * 2 - 1;
			m_VideoWin[3 * i - 2].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight;
			m_VideoWin[3 * i - 1].MoveWindow(&rect);
		}
		for(short k=9; k<MAXWIN; k++)
			m_VideoWin[k].MoveWindow(CRect(0,0,0,0));
	}
	else if(10 == m_nWinNum)
	{
		CRect tRect = rect;
		rect.bottom = rect.bottom / 2 -1;
		rect.right = rect.right / 2 - 1;
		m_VideoWin[0].MoveWindow(&rect);

		rect.left = rect.right + 2;
		rect.right = tRect.right;
		m_VideoWin[1].MoveWindow(&rect);
		
		rect = tRect;
		rect.top = rect.bottom / 2 + 1;
		rect.right = rect.right / 4;
		rect.bottom = rect.bottom / 4 * 3;
		m_VideoWin[2].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = rect.right * 2;
		m_VideoWin[3].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right / 4 * 3;
		m_VideoWin[4].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right;
		m_VideoWin[5].MoveWindow(&rect);

		rect.top = rect.bottom + 2;
		rect.right = tRect.right / 4;
		rect.bottom = tRect.bottom;
		rect.left = 0;
		m_VideoWin[6].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = rect.right * 2;
		m_VideoWin[7].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right / 4 * 3 ;
		m_VideoWin[8].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right;
		m_VideoWin[9].MoveWindow(&rect);

		for(short i=10; i<MAXWIN; i++)
			m_VideoWin[i].MoveWindow(CRect(0,0,0,0));
	}
	else if(13 == m_nWinNum)
	{
		CRect tRect = rect;
		rect.top = rect.bottom / 4 + 1;
		rect.left = rect.right / 4  + 1;
		rect.bottom = rect.bottom / 4 * 3 - 1;
		rect.right = rect.right / 4 * 3 - 1;
		m_VideoWin[0].MoveWindow(&rect);

		rect.top = 0;
		rect.left = 0;
		rect.right = tRect.right / 4 - 1;
		rect.bottom = tRect.bottom / 4 -1;
		m_VideoWin[1].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right/4 * 2 - 1;		
		m_VideoWin[2].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right / 4 * 3 - 1;		
		m_VideoWin[3].MoveWindow(&rect);
		rect.left = rect.right + 2;
		rect.right = tRect.right;		
		m_VideoWin[4].MoveWindow(&rect);

		rect.left = 0;
		rect.right = tRect.right / 4 - 1;
		rect.top = tRect.bottom / 4 + 1;
		rect.bottom = tRect.bottom / 4 * 2 -1;
		m_VideoWin[5].MoveWindow(&rect);
		rect.left = tRect.right / 4 * 3 + 1;
		rect.right = tRect.right;		
		m_VideoWin[6].MoveWindow(&rect);
		rect.left = 0;
		rect.top = rect.bottom + 2;
		rect.right = tRect.right / 4 - 1;
		rect.bottom = tRect.bottom / 4 * 3 - 1;
		m_VideoWin[7].MoveWindow(&rect);
		rect.left = tRect.right / 4 * 3 + 1;
		rect.right = tRect.right;
		m_VideoWin[8].MoveWindow(&rect);

		rect.left = 0;
		rect.right = tRect.right/4 - 1;
		rect.bottom = tRect.bottom;
		rect.top = tRect.bottom / 4 * 3+1;
		m_VideoWin[9].MoveWindow(&rect);
		rect.left = tRect.right / 4 + 1;
		rect.right = tRect.right / 4 * 2 - 1;
		m_VideoWin[10].MoveWindow(&rect);
		rect.left = tRect.right / 4 * 2 + 1;
		rect.right = tRect.right / 4 * 3 - 1;
		m_VideoWin[11].MoveWindow(&rect);
		rect.left = tRect.right / 4 * 3 + 1;
		rect.right = tRect.right;
		m_VideoWin[12].MoveWindow(&rect);
		
		for(short i=13; i<MAXWIN; i++)
			m_VideoWin[i].MoveWindow(CRect(0,0,0,0));
	}
	else if(16 == m_nWinNum)
	{
		for(short i=1; i<=4; i++)
		{
			rect = rect2;
			long lRight = rect.right;
			if(1 == i)
				rect.bottom = rect.bottom / 4;
			else if(2 == i)
			{
				rect.top = rect.bottom / 4;
				rect.bottom = rect.bottom / 4 * 2;
			}
			else if(3 == i)
			{	rect.top = rect.bottom / 4 * 2;
				rect.bottom = rect.bottom / 4 * 3;
			}
			else if(4 == i)
				rect.top = rect.bottom / 4 * 3;
			
			if(4 == i)
				rect.bottom = rect.bottom;
			else
				rect.bottom = rect.bottom - 2;
			rect.right = rect.right / 4 - 1;
			m_VideoWin[4 * i - 4].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = rect.right * 2 - 1;
			m_VideoWin[4 * i - 3].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = rect.right / 2 * 3 - 1;
			m_VideoWin[4 * i - 2].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight;
			m_VideoWin[4 * i - 1].MoveWindow(&rect);
		}
		for(short j=16; j<MAXWIN; j++)
			m_VideoWin[j].MoveWindow(CRect(0,0,0,0));
	}
	else if(36 == m_nWinNum)
	{
		for(short i=1; i<=6; i++)
		{
			rect = rect2;
			long lRight = rect.right;
			if(1 == i)
				rect.bottom = rect.bottom / 6;
			else if(2 == i)
			{
				rect.top = rect.bottom / 6;
				rect.bottom = rect.bottom / 6 * 2;
			}
			else if(3 == i)
			{	rect.top = rect.bottom / 6 * 2;
				rect.bottom = rect.bottom / 6 * 3;
			}
			else if(4 == i)
			{
				rect.top = rect.bottom / 6 * 3;
				rect.bottom = rect.bottom / 6 * 4;
			}
			else if(5 == i)
			{
				rect.top = rect.bottom / 6 * 4;
				rect.bottom = rect.bottom / 6 * 5;
			}
			else if(6 == i)
			{
				rect.top = rect.bottom / 6 * 5;
			}
			if(6 == i)
				rect.bottom = rect.bottom;
			else
				rect.bottom = rect.bottom - 2;
			rect.right = lRight / 6 - 1;
			m_VideoWin[6 * i - 6].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = lRight / 6 * 2 - 1;
			m_VideoWin[6 * i - 5].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = lRight / 6 * 3 - 1;
			m_VideoWin[6 * i - 4].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight / 6 * 4 - 1;
			m_VideoWin[6 * i - 3].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight / 6 * 5 - 1;
			m_VideoWin[6 * i - 2].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight;
			m_VideoWin[6 * i - 1].MoveWindow(&rect);
		}
		for(short j=36; j<MAXWIN; j++)
			m_VideoWin[j].MoveWindow(CRect(0,0,0,0));
	}
	else if(64 == m_nWinNum)
	{
		for(short i=1; i<=8; i++)
		{
			rect = rect2;
			long lRight = rect.right;
			if(1 == i)
				rect.bottom = rect.bottom / 8;
			else if(2 == i)
			{
				rect.top = rect.bottom / 8;
				rect.bottom = rect.bottom / 8 * 2;
			}
			else if(3 == i)
			{	rect.top = rect.bottom / 8 * 2;
				rect.bottom = rect.bottom / 8 * 3;
			}
			else if(4 == i)
			{
				rect.top = rect.bottom / 8 * 3;
				rect.bottom = rect.bottom / 8 * 4;
			}
			else if(5 == i)
			{
				rect.top = rect.bottom / 8 * 4;
				rect.bottom = rect.bottom / 8 * 5;
			}
			else if(6 == i)
			{
				rect.top = rect.bottom / 8 * 5;
				rect.bottom = rect.bottom / 8 * 6;
			}
			else if(7 == i)
			{
				rect.top = rect.bottom / 8 * 6;
				rect.bottom = rect.bottom / 8 * 7;
			}
			else if(8 == i)
			{
				rect.top = rect.bottom / 8 * 7;
			}
			if(8 == i)
				rect.bottom = rect.bottom;
			else
				rect.bottom = rect.bottom - 2;
			rect.right = lRight / 8 - 1;
			m_VideoWin[8 * i - 8].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = lRight / 8 * 2 - 1;
			m_VideoWin[8 * i - 7].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight / 8 * 3 - 1;
			m_VideoWin[8 * i - 6].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = lRight / 8 * 4 - 1;
			m_VideoWin[8 * i - 5].MoveWindow(&rect);
			
			rect.left = rect.right + 2;
			rect.right = lRight / 8 * 5 - 1;
			m_VideoWin[8 * i - 4].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight / 8 * 6 - 1;
			m_VideoWin[8 * i - 3].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight / 8 * 7 - 1;
			m_VideoWin[8 * i - 2].MoveWindow(&rect);

			rect.left = rect.right + 2;
			rect.right = lRight;
			m_VideoWin[8 * i - 1].MoveWindow(&rect);
		}
	}
}

BOOL CMultiWindow::SplitWindow(UCHAR nWin)			//分割窗口
{
	for (UCHAR i=0;i<MAXWIN;i++)
	{
		if(m_VideoWin[i].m_bFullScreen) return FALSE;
	}
	if(nWin==1||nWin==4||nWin==6||nWin==9||nWin==10||nWin==13||nWin==16||nWin==36||nWin==64)
	{
		m_nWinNum = nWin;
		OnSize(NULL,NULL,NULL);
		return TRUE;
	}
	else
		return FALSE;
}

void CMultiWindow::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	CRect   rect;	
	GetClientRect(&rect);
	//CBrush brushBackground(RGB(0xE1,0xEF,0xF1));
	CBrush brushBackground(RGB(0,0,0));
	CBrush * pOldBrush = dc.SelectObject( &brushBackground );
	dc.Rectangle( &rect );
	dc.SelectObject( pOldBrush );
	brushBackground.DeleteObject();
	// Do not call CWnd::OnPaint() for painting messages
}

void CMultiWindow::CancelAllWinSel()
{
	for (int i=0;i<MAXWIN;i++)
		m_VideoWin[i].CancelSel();
}
void CMultiWindow::SetCurSelectWin(byte nWin)
{
	m_nCurWin = nWin;
}
UCHAR CMultiWindow::GetCurSelectWin()
{
	return m_nCurWin;
}

void CMultiWindow::FullScreen()					//多窗体全屏
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

void CMultiWindow::SingleWinFullScreen(UCHAR nIndex)//单个小窗口全屏
{
	m_VideoWin[nIndex].FullScreen();
}

void CMultiWindow::SetPanelPtr(byte nType,void* pPanel)
{
	if(nType == PANEL_TYPE_TREE)
		m_pPanelTree = pPanel;	//CMonitorDeviceList
	else if(nType == PANEL_TYPE_PTZ)
		m_pPanelPtz = pPanel;
}
BOOL CMultiWindow::ConnectEncoder(int CameraID)
{
	return m_VideoWin[m_nCurWin].ConnectEncoder(CameraID);
}