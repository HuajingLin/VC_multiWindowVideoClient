// DlgMMLOperatePtz.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLOperatePtz.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define MMLOP_BK_COLOR RGB(0xCB,0xCD,0xD1)
/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperatePtz dialog


CDlgMMLOperatePtz::CDlgMMLOperatePtz(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLOperatePtz::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLOperatePtz)
	//}}AFX_DATA_INIT
	m_bkBrush.CreateSolidBrush(MMLOP_BK_COLOR);
	m_pMultiWin = NULL;
}


void CDlgMMLOperatePtz::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLOperatePtz)
	DDX_Control(pDX, IDC_SLIDER_PTZ, m_SliderSpeed);
	DDX_Control(pDX, IDC_BTN_LEFTRIGHT, m_btnLeftRight);
	DDX_Control(pDX, IDC_BTN_ZOOM2, m_btnZoomOut);
	DDX_Control(pDX, IDC_BTN_ZOOM1, m_btnZoomIn);
	DDX_Control(pDX, IDC_BTN_FOCAL2, m_btnFocalBack);
	DDX_Control(pDX, IDC_BTN_FOCAL1, m_btnFocalFront);
	DDX_Control(pDX, IDC_BTN_DOWN, m_btnDown);
	DDX_Control(pDX, IDC_BTN_APERT2, m_btnApertBig);
	DDX_Control(pDX, IDC_BTN_APERT1, m_btnApertSmall);
	DDX_Control(pDX, IDC_BTN_3D, m_btn3D);
	DDX_Control(pDX, IDC_BTN_WIPER, m_btnWiper);
	DDX_Control(pDX, IDC_BTN_UPRIGHT, m_btnUpRight);
	DDX_Control(pDX, IDC_BTN_UP, m_btnUp);
	DDX_Control(pDX, IDC_BTN_RIGHTDOWN, m_btnRightDown);
	DDX_Control(pDX, IDC_BTN_RIGHT, m_btnRight);
	DDX_Control(pDX, IDC_BTN_LIGHT, m_btnLight);
	DDX_Control(pDX, IDC_BTN_LEFTDOWN, m_btnLeftDown);
	DDX_Control(pDX, IDC_BTN_LEFT, m_btnLeft);
	DDX_Control(pDX, IDC_BTN_LEFTUP, m_btnLeftUp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLOperatePtz, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLOperatePtz)
	ON_WM_SIZE()
	ON_WM_CTLCOLOR()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_PTZ, OnReleasedcaptureSliderPtz)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperatePtz message handlers

void CDlgMMLOperatePtz::SetMultiWinPtr(void *pMultiWin)
{
	m_pMultiWin = (CMultiWindow*)pMultiWin;
	m_pMultiWin->SetPanelPtr(PANEL_TYPE_PTZ, this);
}

BOOL CDlgMMLOperatePtz::OnInitDialog() 
{
	CDialog::OnInitDialog();
	TCHAR tStr[STR_LEN];
	m_btnLeftRight.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnLeftRight.LoadBitmaps(IDB_BTN_LEFTR1,IDB_BTN_LEFTR3,IDB_BTN_LEFTR2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnLeftRight.SizeToContent();
	m_btnLeftRight.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Cruise",tStr))
		m_btnLeftRight.SetTooltipText(tStr);
	else
		m_btnLeftRight.SetTooltipText("Cruise");

	m_btnZoomOut.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnZoomOut.LoadBitmaps(IDB_BTN_ZOOMO1,IDB_BTN_ZOOMO3,IDB_BTN_ZOOMO2,IDB_BTN_ZOOMO4,IDC_BTN_FULLSCREEN);
	m_btnZoomOut.SizeToContent();
	m_btnZoomOut.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("ZoomOut",tStr))
		m_btnZoomOut.SetTooltipText(tStr);
	else
		m_btnZoomOut.SetTooltipText("Zoom Out");

	m_btnZoomIn.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnZoomIn.LoadBitmaps(IDB_BTN_ZOOMIN1,IDB_BTN_ZOOMIN3,IDB_BTN_ZOOMIN2,IDB_BTN_ZOOMIN4,IDC_BTN_FULLSCREEN);
	m_btnZoomIn.SizeToContent();
	m_btnZoomIn.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("ZoomIn",tStr))
		m_btnZoomIn.SetTooltipText(tStr);
	else
		m_btnZoomIn.SetTooltipText("Zoom In");

	m_btnFocalBack.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnFocalBack.LoadBitmaps(IDB_BTN_FOCALB1,IDB_BTN_FOCALB3,IDB_BTN_FOCALB2,IDB_BTN_FOCALB4,IDC_BTN_FULLSCREEN);
	m_btnFocalBack.SizeToContent();
	m_btnFocalBack.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("FocalBack",tStr))
		m_btnFocalBack.SetTooltipText(tStr);
	else
		m_btnFocalBack.SetTooltipText("Focal Back");

	m_btnFocalFront.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnFocalFront.LoadBitmaps(IDB_BTN_FOCALF1,IDB_BTN_FOCALF3,IDB_BTN_FOCALF2,IDB_BTN_FOCALF4,IDC_BTN_FULLSCREEN);
	m_btnFocalFront.SizeToContent();
	m_btnFocalFront.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("FocalFront",tStr))
		m_btnFocalFront.SetTooltipText(tStr);
	else
		m_btnFocalFront.SetTooltipText("Focal Front");

	m_btnDown.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnDown.LoadBitmaps(IDB_BTN_DOWN1,IDB_BTN_DOWN3,IDB_BTN_DOWN2,IDB_BTN_DOWN4,IDC_BTN_FULLSCREEN);
	m_btnDown.SizeToContent();
	m_btnDown.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Down",tStr))
		m_btnDown.SetTooltipText(tStr);
	else
		m_btnDown.SetTooltipText("Down");
	
	m_btnApertBig.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnApertBig.LoadBitmaps(IDB_BTN_AB1,IDB_BTN_AB3,IDB_BTN_AB2,IDB_BTN_AB4,IDC_BTN_FULLSCREEN);
	m_btnApertBig.SizeToContent();
	m_btnApertBig.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("ApertBig",tStr))
		m_btnApertBig.SetTooltipText(tStr);
	else
		m_btnApertBig.SetTooltipText("Aperture Big");

	m_btnApertSmall.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnApertSmall.LoadBitmaps(IDB_BTN_AS1,IDB_BTN_AS3,IDB_BTN_AS2,IDB_BTN_AS4,IDC_BTN_FULLSCREEN);
	m_btnApertSmall.SizeToContent();
	m_btnApertSmall.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("ApertSmall",tStr))
		m_btnApertSmall.SetTooltipText(tStr);
	else
		m_btnApertSmall.SetTooltipText("Aperture Small");

	m_btn3D.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btn3D.LoadBitmaps(IDB_BTN_3DPOS1,IDB_BTN_3DPOS3,IDB_BTN_3DPOS2,IDB_BTN_3DPOS4,IDC_BTN_FULLSCREEN);
	m_btn3D.SizeToContent();
	m_btn3D.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("3DPosition",tStr))
		m_btn3D.SetTooltipText(tStr);
	else
		m_btn3D.SetTooltipText("3D Position");

	m_btnWiper.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnWiper.LoadBitmaps(IDB_BTN_WIPER1,IDB_BTN_WIPER3,IDB_BTN_WIPER2,IDB_BTN_WIPER4,IDC_BTN_FULLSCREEN);
	m_btnWiper.SizeToContent();
	m_btnWiper.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Wiper",tStr))
		m_btnWiper.SetTooltipText(tStr);
	else
		m_btnWiper.SetTooltipText("Wiper");

	m_btnUpRight.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnUpRight.LoadBitmaps(IDB_BTN_UPR1,IDB_BTN_UPR3,IDB_BTN_UPR2,IDB_BTN_UPR4,IDC_BTN_FULLSCREEN);
	m_btnUpRight.SizeToContent();
	m_btnUpRight.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("RightUp",tStr))
		m_btnUpRight.SetTooltipText(tStr);
	else
		m_btnUpRight.SetTooltipText("Right Up");

	m_btnUp.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnUp.LoadBitmaps(IDB_BTN_UP1,IDB_BTN_UP3,IDB_BTN_UP2,IDB_BTN_UP4,IDC_BTN_FULLSCREEN);
	m_btnUp.SizeToContent();
	m_btnUp.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Up",tStr))
		m_btnUp.SetTooltipText(tStr);
	else
		m_btnUp.SetTooltipText("Up");

	m_btnRightDown.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnRightDown.LoadBitmaps(IDB_BTN_RIGHTD1,IDB_BTN_RIGHTD3,IDB_BTN_RIGHTD2,IDB_BTN_RIGHTD4,IDC_BTN_FULLSCREEN);
	m_btnRightDown.SizeToContent();
	m_btnRightDown.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("RightDown",tStr))
		m_btnRightDown.SetTooltipText(tStr);
	else
		m_btnRightDown.SetTooltipText("Right Down");

	m_btnRight.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnRight.LoadBitmaps(IDB_BTN_RIGHT1,IDB_BTN_RIGHT3,IDB_BTN_RIGHT2,IDB_BTN_RIGHT4,IDC_BTN_FULLSCREEN);
	m_btnRight.SizeToContent();
	m_btnRight.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Right",tStr))
		m_btnRight.SetTooltipText(tStr);
	else
		m_btnRight.SetTooltipText("Right");

	m_btnLight.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnLight.LoadBitmaps(IDB_BTN_LIGHT1,IDB_BTN_LIGHT3,IDB_BTN_LIGHT2,IDB_BTN_LIGHT4,IDC_BTN_FULLSCREEN);
	m_btnLight.SizeToContent();
	m_btnLight.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Light",tStr))
		m_btnLight.SetTooltipText(tStr);
	else
		m_btnLight.SetTooltipText("Light");

	m_btnLeftDown.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnLeftDown.LoadBitmaps(IDB_BTN_DOWNLEFT1,IDB_BTN_DOWNLEFT3,IDB_BTN_DOWNLEFT2,IDB_BTN_DOWNLEFT4,IDC_BTN_FULLSCREEN);
	m_btnLeftDown.SizeToContent();
	m_btnLeftDown.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("LeftDown",tStr))
		m_btnLeftDown.SetTooltipText(tStr);
	else
		m_btnLeftDown.SetTooltipText("Left Down");

	m_btnLeft.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnLeft.LoadBitmaps(IDB_BTN_LEFT1,IDB_BTN_LEFT3,IDB_BTN_LEFT2,IDB_BTN_LEFT4,IDC_BTN_FULLSCREEN);
	m_btnLeft.SizeToContent();
	m_btnLeft.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("Left",tStr))
		m_btnLeft.SetTooltipText(tStr);
	else
		m_btnLeft.SetTooltipText("Left");
	
	m_btnLeftUp.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnLeftUp.LoadBitmaps(IDB_BTN_LEFTU1,IDB_BTN_LEFTU3,IDB_BTN_LEFTU2,IDB_BTN_LEFTU4,IDC_BTN_FULLSCREEN);
	m_btnLeftUp.SizeToContent();
	m_btnLeftUp.SetWindowPos (&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("LeftUp",tStr))
		m_btnLeftUp.SetTooltipText(tStr);
	else
		m_btnLeftUp.SetTooltipText("Left Up");
	m_SliderSpeed.SetRange(1,10);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMMLOperatePtz::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	
}

HBRUSH CDlgMMLOperatePtz::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	else if(nCtlColor==CTLCOLOR_STATIC)
	{ 
		if(pWnd->GetDlgCtrlID() == IDC_STATIC_VALUE)
		{
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::GetStockObject(NULL_BRUSH);
		}
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDlgMMLOperatePtz::OnReleasedcaptureSliderPtz(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString str;
	str.Format("%d",m_SliderSpeed.GetPos());
	GetDlgItem(IDC_STATIC_VALUE)->SetWindowText(str);
	GetDlgItem(IDC_STATIC_VALUE)->ShowWindow(0);
	GetDlgItem(IDC_STATIC_VALUE)->ShowWindow(1);
	*pResult = 0;
}

void CDlgMMLOperatePtz::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_PTZ))
	{
		CString str;
		str.Format("%d",m_SliderSpeed.GetPos());
		GetDlgItem(IDC_STATIC_VALUE)->SetWindowText(str);
		GetDlgItem(IDC_STATIC_VALUE)->ShowWindow(0);
		GetDlgItem(IDC_STATIC_VALUE)->ShowWindow(1);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
