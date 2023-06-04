// TestRoverView.h : interface of the CTestRoverView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTROVERVIEW_H__E3E9EA9F_A4EF_4C8E_BADB_733CE388A1BC__INCLUDED_)
#define AFX_TESTROVERVIEW_H__E3E9EA9F_A4EF_4C8E_BADB_733CE388A1BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestRoverView : public CFormView
{
protected: // create from serialization only
	CTestRoverView();
	DECLARE_DYNCREATE(CTestRoverView)

public:
	//{{AFX_DATA(CTestRoverView)
	enum{ IDD = IDD_TESTROVER_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CTestRoverDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestRoverView)
	public:

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestRoverView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestRoverView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestRoverView.cpp
inline CTestRoverDoc* CTestRoverView::GetDocument()
   { return (CTestRoverDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTROVERVIEW_H__E3E9EA9F_A4EF_4C8E_BADB_733CE388A1BC__INCLUDED_)
