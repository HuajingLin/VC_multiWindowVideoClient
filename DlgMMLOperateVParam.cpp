// DlgMMLOperateVParam.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMMLOperateVParam.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperateVParam dialog
#define MMLOV_BK_COLOR RGB(0xCB,0xCD,0xD1)

CDlgMMLOperateVParam::CDlgMMLOperateVParam(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMMLOperateVParam::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMMLOperateVParam)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_bkBrush.CreateSolidBrush(MMLOV_BK_COLOR);
}


void CDlgMMLOperateVParam::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMMLOperateVParam)
	DDX_Control(pDX, IDC_BTN_DEFAULT, m_btnDefault);
	DDX_Control(pDX, IDC_STATIC_BACK, m_lblTitle);
	DDX_Control(pDX, IDC_SLIDER_SOUND, m_sliderSound);
	DDX_Control(pDX, IDC_SLIDER_SHARP, m_sliderSharp);
	DDX_Control(pDX, IDC_SLIDER_SATURAT, m_sliderSaturat);
	DDX_Control(pDX, IDC_SLIDER_CONTRAST, m_sliderContrast);
	DDX_Control(pDX, IDC_SLIDER_BRIGHT, m_sliderBright);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMMLOperateVParam, CDialog)
	//{{AFX_MSG_MAP(CDlgMMLOperateVParam)
	ON_WM_CTLCOLOR()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMMLOperateVParam message handlers

HBRUSH CDlgMMLOperateVParam::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_DLG) 
		return (HBRUSH)m_bkBrush.GetSafeHandle();
	else if(nCtlColor==CTLCOLOR_STATIC)
	{
		int nCtrId = pWnd->GetDlgCtrlID();
		if((nCtrId == IDC_STATIC_BRIGHT)
		||(nCtrId == IDC_STATIC_CONTRAST)
		||(nCtrId == IDC_STATIC_SATURAT)
		||(nCtrId == IDC_STATIC_SHARP)
		||(nCtrId == IDC_STATIC_SOUND))
		{
			pDC->SetBkMode(TRANSPARENT);
			return (HBRUSH)::GetStockObject(NULL_BRUSH);
		}
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CDlgMMLOperateVParam::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_lblTitle.SetBitmapID(IDB_LBL_VPARM_TITLE);
	m_sliderSound.SetRange(1,100);
	m_sliderSound.SetTicFreq(5);
	m_sliderSharp.SetRange(1,255);
	m_sliderSharp.SetTicFreq(10);
	m_sliderSaturat.SetRange(1,255);
	m_sliderSaturat.SetTicFreq(10);
	m_sliderContrast.SetRange(1,255);
	m_sliderContrast.SetTicFreq(10);
	m_sliderBright.SetRange(1,255);
	m_sliderBright.SetTicFreq(10);
	m_btnDefault.SetSkin(IDB_BTN_DEFAULT_VALUE1,IDB_BTN_DEFAULT_VALUE3,IDB_BTN_DEFAULT_VALUE2);
	TCHAR tStr[STR_LEN];
	if(g_GetLanguage("DefaultValue",tStr))
		m_btnDefault.SetText(tStr,50);
	else
		m_btnDefault.SetText("Default Value",50);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMMLOperateVParam::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_BRIGHT))
	{
		CString str;
		str.Format("%d",m_sliderBright.GetPos());
		GetDlgItem(IDC_STATIC_BRIGHT)->SetWindowText(str);
		GetDlgItem(IDC_STATIC_BRIGHT)->ShowWindow(0);
		GetDlgItem(IDC_STATIC_BRIGHT)->ShowWindow(1);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_CONTRAST))
	{
		CString str;
		str.Format("%d",m_sliderContrast.GetPos());
		GetDlgItem(IDC_STATIC_CONTRAST)->SetWindowText(str);
		GetDlgItem(IDC_STATIC_CONTRAST)->ShowWindow(0);
		GetDlgItem(IDC_STATIC_CONTRAST)->ShowWindow(1);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_SATURAT))
	{
		CString str;
		str.Format("%d",m_sliderSaturat.GetPos());
		GetDlgItem(IDC_STATIC_SATURAT)->SetWindowText(str);
		GetDlgItem(IDC_STATIC_SATURAT)->ShowWindow(0);
		GetDlgItem(IDC_STATIC_SATURAT)->ShowWindow(1);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_SHARP))
	{
		CString str;
		str.Format("%d",m_sliderSharp.GetPos());
		GetDlgItem(IDC_STATIC_SHARP)->SetWindowText(str);
		GetDlgItem(IDC_STATIC_SHARP)->ShowWindow(0);
		GetDlgItem(IDC_STATIC_SHARP)->ShowWindow(1);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SLIDER_SOUND))
	{
		CString str;
		str.Format("%d",m_sliderSound.GetPos());
		GetDlgItem(IDC_STATIC_SOUND)->SetWindowText(str);
		GetDlgItem(IDC_STATIC_SOUND)->ShowWindow(0);
		GetDlgItem(IDC_STATIC_SOUND)->ShowWindow(1);
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
