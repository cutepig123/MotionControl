#if !defined(AFX_MOTORINFOVIEW_H__C4C31C41_0C16_4A47_9F88_52EE192A220F__INCLUDED_)
#define AFX_MOTORINFOVIEW_H__C4C31C41_0C16_4A47_9F88_52EE192A220F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MotorInfoView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMotorInfoView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CMotorInfoView : public CFormView
{
protected:
	CMotorInfoView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMotorInfoView)

// Form Data
public:
	//{{AFX_DATA(CMotorInfoView)
	enum { IDD = IDD_MOTORINFOVIEW_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	
// Attributes
public:

// Operations
public:
	HANDLE m_hThread;
	void StartProc();
	DWORD WINAPI ShowInfoProc();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMotorInfoView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMotorInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMotorInfoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnButtonStopAllPmac();
	afx_msg void OnButtonStopAll6501();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOTORINFOVIEW_H__C4C31C41_0C16_4A47_9F88_52EE192A220F__INCLUDED_)
