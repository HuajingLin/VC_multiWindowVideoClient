// DlgMMLOperateCruise.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLOperateCruise.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperateCruise dialog
#define MMLOC_BK_COLOR RGB(0xCB,0xCD,0xD1)

CDlgMMLOperateCruise::CDlgMMLOperateCruise(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLOperateCruise::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLOperateCruise)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bkBrush.CreateSolidBrush(MMLOC_BK_COLOR);
}


void CDlgMMLOperateCruise::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLOperateCruise)
	DDX_Control(pDX, IDC_BTN_STOP_CRUI, m_btnStop);
	DDX_Control(pDX, IDC_BTN_START, m_btnStart);
	DDX_Control(pDX, IDC_BTN_SET_CRUISE, m_btnSetCruise);
	DDX_Control(pDX, IDC_LIST_CRUISE, m_listCruise);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLOperateCruise, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLOperateCruise)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperateCruise message handlers

HBRUSH CDlgMMLOperateCruise::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CDlgMMLOperateCruise::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	TCHAR tStr[STR_LEN];
	LOGFONT lf;
	memset(&lf, 0, sizeof(LOGFONT));
	if(HD_GetLanguageID()==LANGUAGE_CN)
	{
		lf.lfHeight = 12;
		strcpy(lf.lfFaceName, "宋体");
	}
	else
	{
		lf.lfHeight = 14;
		strcpy(lf.lfFaceName, "Times New Roman");
	}
	m_font.CreateFontIndirect(&lf);
	m_listCruise.SetFont(&m_font, TRUE);
	m_listCruise.SetExtendedStyle(
		LVS_EX_FLATSB           //扁平风格滚动条
		|LVS_EX_FULLROWSELECT   //允许整行选中
		|LVS_EX_HEADERDRAGDROP  //允许标题拖拽
		|LVS_EX_ONECLICKACTIVATE//高亮显示
		|LVS_EX_GRIDLINES       //画出网格线
		|LVS_EX_INFOTIP			//工具提示
		|LVS_EX_FULLROWSELECT
		);
	DWORD dwSystl = ::GetWindowLong(m_listCruise.m_hWnd,GWL_STYLE); 
	SetWindowLong(m_listCruise.m_hWnd,GWL_STYLE,dwSystl|LVS_REPORT); 
    DWORD Exsystl =m_listCruise.GetExtendedStyle();
	m_listCruise.SetExtendedStyle(Exsystl|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	if(g_GetLanguage("ID",tStr))
		m_listCruise.InsertColumn(0, tStr, LVCFMT_LEFT, 40, 1);
	else
		m_listCruise.InsertColumn(0, "ID", LVCFMT_LEFT, 40, 1);
	if(g_GetLanguage("CruiseName",tStr))
		m_listCruise.InsertColumn(1, tStr, LVCFMT_LEFT, 155, 1);
	else
		m_listCruise.InsertColumn(1, "Cruise Name", LVCFMT_LEFT, 155, 1);
	for (int i=64; i>0; i--)
	{
		sprintf(tStr,"%d",i);
		int nItem = m_listCruise.InsertItem(0, "");
		m_listCruise.SetItemText(nItem, 0, tStr);
	}
	m_btnStart.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnStart.LoadBitmaps(IDB_BTN_CALLPRESET1,IDB_BTN_CALLPRESET3,IDB_BTN_CALLPRESET2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnStart.SizeToContent();
	m_btnStart.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("CruiseStart",tStr))
		m_btnStart.SetTooltipText(tStr);
	else
		m_btnStart.SetTooltipText("Cruise Start");

	m_btnStop.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnStop.LoadBitmaps(IDB_BTN_CRUISE_STOP1,IDB_BTN_CRUISE_STOP3,IDB_BTN_CRUISE_STOP2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnStop.SizeToContent();
	m_btnStop.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("CruiseStop",tStr))
		m_btnStop.SetTooltipText(tStr);
	else
		m_btnStop.SetTooltipText("Cruise Stop");

	m_btnSetCruise.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnSetCruise.LoadBitmaps(IDB_BTN_SETPRESET1,IDB_BTN_SETPRESET3,IDB_BTN_SETPRESET2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnSetCruise.SizeToContent();
	m_btnSetCruise.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("CruiseSet",tStr))
		m_btnSetCruise.SetTooltipText(tStr);
	else
		m_btnSetCruise.SetTooltipText("Cruise Set");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
