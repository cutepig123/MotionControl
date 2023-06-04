// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__0609915D_EF3F_48DE_AB8A_EAD5B250F3E5__INCLUDED_)
#define AFX_STDAFX_H__0609915D_EF3F_48DE_AB8A_EAD5B250F3E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//#define _SIMULATE_
#include "myRuntime.h"
#include "Lib.h"

struct MOTOR_DATA{
	int baseaddr;//基地址 
	int axis;	//轴
	int forward_cmd;//前进的命令字，for set_motion()
	int backward_cmd;//后退的命令字，for set_motion()
	ULONG vel;
	//ULONG vel_real;
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__0609915D_EF3F_48DE_AB8A_EAD5B250F3E5__INCLUDED_)
