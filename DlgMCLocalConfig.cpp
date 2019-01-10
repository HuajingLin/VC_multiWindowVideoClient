// DlgMCLocalConfig.cpp : implementation file
//

#include "stdafx.h"
#include "HDNetVideoClient.h"
#include "DlgMCLocalConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMCLocalConfig dialog


CDlgMCLocalConfig::CDlgMCLocalConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMCLocalConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMCLocalConfig)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgMCLocalConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMCLocalConfig)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMCLocalConfig, CDialog)
	//{{AFX_MSG_MAP(CDlgMCLocalConfig)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMCLocalConfig message handlers
