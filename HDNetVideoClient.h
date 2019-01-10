// HDNetVideoClient.h : main header file for the HDNETVIDEOCLIENT application
//

#if !defined(AFX_HDNETVIDEOCLIENT_H__22276942_FF76_4186_8AC3_426F0599B5A6__INCLUDED_)
#define AFX_HDNETVIDEOCLIENT_H__22276942_FF76_4186_8AC3_426F0599B5A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#define IDC_MULTI_WIN 6001
/////////////////////////////////////////////////////////////////////////////
// CHDNetVideoClientApp:
// See HDNetVideoClient.cpp for the implementation of this class
//

class CHDNetVideoClientApp : public CWinApp
{
public:
	CHDNetVideoClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHDNetVideoClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHDNetVideoClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HDNETVIDEOCLIENT_H__22276942_FF76_4186_8AC3_426F0599B5A6__INCLUDED_)
