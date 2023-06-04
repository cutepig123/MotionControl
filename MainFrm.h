// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__44E9FEAA_892D_40C7_8FAF_25FCA8142922__INCLUDED_)
#define AFX_MAINFRM_H__44E9FEAA_892D_40C7_8FAF_25FCA8142922__INCLUDED_
#include "Hit6501TestDlg.h"
#include "hit405Dlg.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:
	CHit6501TestDlg *m_pDlgHIT6501Test;
	CHit405Dlg *m_pDlgHIT405;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	
// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewMain();
	afx_msg void OnVIEWMotorInfo();
	afx_msg void OnViewTerminal();
	afx_msg void OnSelect();
	afx_msg void OnDestroy();
	afx_msg void OnViewHit405view();
	afx_msg void OnViewHit6501testdlg();
	afx_msg void OnStopAllPmac();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__44E9FEAA_892D_40C7_8FAF_25FCA8142922__INCLUDED_)
