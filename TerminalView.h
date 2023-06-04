#if !defined(AFX_TERMINALVIEW_H__83996F8C_7C6F_46DA_A17D_0940A414749C__INCLUDED_)
#define AFX_TERMINALVIEW_H__83996F8C_7C6F_46DA_A17D_0940A414749C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TerminalView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTerminalView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTerminalView : public CFormView
{
protected:
	CTerminalView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTerminalView)

// Form Data
public:
	//{{AFX_DATA(CTerminalView)
	enum { IDD = IDD_TERMINALVIEW_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	HANDLE m_hThread;
	void StartProc();
	DWORD WINAPI PMACExecProc();
	char m_szCmd[1000];
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerminalView)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTerminalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CTerminalView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSendCmd();
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERMINALVIEW_H__83996F8C_7C6F_46DA_A17D_0940A414749C__INCLUDED_)
