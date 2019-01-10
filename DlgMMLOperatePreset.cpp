// DlgMMLOperatePreset.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLOperatePreset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperatePreset dialog
#define MMLOR_BK_COLOR RGB(0xCB,0xCD,0xD1)

CDlgMMLOperatePreset::CDlgMMLOperatePreset(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLOperatePreset::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLOperatePreset)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bkBrush.CreateSolidBrush(MMLOR_BK_COLOR);
}


void CDlgMMLOperatePreset::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLOperatePreset)
	DDX_Control(pDX, IDC_LIST_PRESET, m_listPreset);
	DDX_Control(pDX, IDC_BTN_PRESET_SET, m_btnSet);
	DDX_Control(pDX, IDC_BTN_PRESET_DEL, m_btnDel);
	DDX_Control(pDX, IDC_BTN_PRESET_CALL, m_btnCall);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLOperatePreset, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLOperatePreset)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperatePreset message handlers

HBRUSH CDlgMMLOperatePreset::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CDlgMMLOperatePreset::OnInitDialog() 
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
	m_listPreset.SetFont(&m_font, TRUE);
	m_listPreset.SetExtendedStyle(
		LVS_EX_FLATSB           //扁平风格滚动条
		|LVS_EX_FULLROWSELECT   //允许整行选中
		|LVS_EX_HEADERDRAGDROP  //允许标题拖拽
		|LVS_EX_ONECLICKACTIVATE//高亮显示
		|LVS_EX_GRIDLINES       //画出网格线
		|LVS_EX_INFOTIP			//工具提示
		|LVS_EX_FULLROWSELECT
		);
	DWORD dwSystl = ::GetWindowLong(m_listPreset.m_hWnd,GWL_STYLE); 
	SetWindowLong(m_listPreset.m_hWnd,GWL_STYLE,dwSystl|LVS_REPORT); 
    DWORD Exsystl =m_listPreset.GetExtendedStyle();
	m_listPreset.SetExtendedStyle(Exsystl|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	if(g_GetLanguage("ID",tStr))
		m_listPreset.InsertColumn(0, tStr, LVCFMT_LEFT, 40, 1);
	else
		m_listPreset.InsertColumn(0, "ID", LVCFMT_LEFT, 40, 1);
	if(g_GetLanguage("PresetName",tStr))
		m_listPreset.InsertColumn(1, tStr, LVCFMT_LEFT, 155, 1);
	else
		m_listPreset.InsertColumn(1, "Preset Name", LVCFMT_LEFT, 155, 1);
	for (int i=128; i>0; i--)
	{
		sprintf(tStr,"%d",i);
		int nItem = m_listPreset.InsertItem(0, "");
		m_listPreset.SetItemText(nItem, 0, tStr);
	}
	m_btnCall.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnCall.LoadBitmaps(IDB_BTN_CALLPRESET1,IDB_BTN_CALLPRESET3,IDB_BTN_CALLPRESET2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnCall.SizeToContent();
	m_btnCall.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("PresetCall",tStr))
		m_btnCall.SetTooltipText(tStr);
	else
		m_btnCall.SetTooltipText("Preset Call");

	m_btnDel.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnDel.LoadBitmaps(IDB_BTN_DELPRESET1,IDB_BTN_DELPRESET3,IDB_BTN_DELPRESET2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnDel.SizeToContent();
	m_btnDel.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("PresetDel",tStr))
		m_btnDel.SetTooltipText(tStr);
	else
		m_btnDel.SetTooltipText("Preset Delete");

	m_btnSet.ModifyStyle(WS_TABSTOP, BS_OWNERDRAW);
	m_btnSet.LoadBitmaps(IDB_BTN_SETPRESET1,IDB_BTN_SETPRESET3,IDB_BTN_SETPRESET2,IDB_BTN_LEFTR4,IDC_BTN_FULLSCREEN);
	m_btnSet.SizeToContent();
	m_btnSet.SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOSIZE|SWP_NOMOVE);
	if(g_GetLanguage("PresetSet",tStr))
		m_btnSet.SetTooltipText(tStr);
	else
		m_btnSet.SetTooltipText("Preset Set");
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
