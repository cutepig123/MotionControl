// TestRover.h : main header file for the TESTROVER application
//

#if !defined(AFX_TESTROVER_H__5A256AE3_16D8_48A6_A724_13F56266F7BA__INCLUDED_)
#define AFX_TESTROVER_H__5A256AE3_16D8_48A6_A724_13F56266F7BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestRoverApp:
// See TestRover.cpp for the implementation of this class
//

class CTestRoverApp : public CWinApp
{
public:
	void NewWindow(int i);
	CMultiDocTemplate* m_pDocTemplate_Main;
	CMultiDocTemplate* m_pDocTemplate_MotorInfo;
	CMultiDocTemplate* m_pDocTemplate_Terminal;
	CMultiDocTemplate* m_pDocTemplate_HIT405;
	CTestRoverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestRoverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestRoverApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTROVER_H__5A256AE3_16D8_48A6_A724_13F56266F7BA__INCLUDED_)
