// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A8C35054_9969_4922_A6C5_37850D9F8EDB__INCLUDED_)
#define AFX_STDAFX_H__A8C35054_9969_4922_A6C5_37850D9F8EDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxole.h>
#define STR_LEN 128		//语言字符长度
#define MAXWIN  64		//最大视频窗口数
#define WM_BMP_BTNDOWN	WM_USER+6
#define WM_BMP_BTNUP	WM_USER+7
TCHAR* g_GetLanguage(LPCTSTR str,TCHAR* pStrBuf);
#include "../HDNetVideoCentre/HDNetVideoCentre.h"
#include <string>
using namespace std;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A8C35054_9969_4922_A6C5_37850D9F8EDB__INCLUDED_)
