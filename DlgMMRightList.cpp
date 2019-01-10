// DlgMMRightList.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMRightList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMRightList dialog


CDlgMMRightList::CDlgMMRightList(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMRightList::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMRightList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bInitDlg = false;
}


void CDlgMMRightList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMRightList)
	DDX_Control(pDX, IDC_LIST_ALARM, m_listAlarm);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMRightList, CDialog)
	//{{AFX_MSG_MAP(CDlgMMRightList)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMRightList message handlers

BOOL CDlgMMRightList::OnInitDialog() 
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
	m_listAlarm.SetFont(&m_font, TRUE);
	m_listAlarm.SetExtendedStyle(
		LVS_EX_FLATSB           //扁平风格滚动条
		|LVS_EX_FULLROWSELECT   //允许整行选中
		|LVS_EX_HEADERDRAGDROP  //允许标题拖拽
		|LVS_EX_ONECLICKACTIVATE//高亮显示
		|LVS_EX_GRIDLINES       //画出网格线
		|LVS_EX_INFOTIP			//工具提示
		|LVS_EX_FULLROWSELECT
		);
	DWORD dwSystl = ::GetWindowLong(m_listAlarm.m_hWnd,GWL_STYLE); 
	SetWindowLong(m_listAlarm.m_hWnd,GWL_STYLE,dwSystl|LVS_REPORT); 
    DWORD Exsystl =m_listAlarm.GetExtendedStyle();
	m_listAlarm.SetExtendedStyle(Exsystl|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	if(g_GetLanguage("Time",tStr))
		m_listAlarm.InsertColumn(0, tStr, LVCFMT_LEFT, 150, 1);
	else
		m_listAlarm.InsertColumn(0, "Time", LVCFMT_LEFT, 150, 1);
	if(g_GetLanguage("DeviceName",tStr))
		m_listAlarm.InsertColumn(1, tStr, LVCFMT_LEFT, 150, 1);
	else
		m_listAlarm.InsertColumn(1, "Device Name", LVCFMT_LEFT, 150, 1);
	if(g_GetLanguage("ChannelName",tStr))
		m_listAlarm.InsertColumn(2, tStr, LVCFMT_LEFT, 150, 1);
	else
		m_listAlarm.InsertColumn(2, "Channel Name", LVCFMT_LEFT, 150, 1);
	if(g_GetLanguage("AlarmInfo",tStr))
		m_listAlarm.InsertColumn(3, tStr, LVCFMT_LEFT, 330, 1);
	else
		m_listAlarm.InsertColumn(3, "Alarm Info", LVCFMT_LEFT, 330, 1);
	m_bInitDlg = true;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMMRightList::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(!m_bInitDlg)
		return;
	RECT rect;
	GetClientRect(&rect);
	m_listAlarm.MoveWindow(&rect);
}
