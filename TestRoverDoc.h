// TestRoverDoc.h : interface of the CTestRoverDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTROVERDOC_H__54C175EB_B960_40B1_AE83_4A5EBE1BD19B__INCLUDED_)
#define AFX_TESTROVERDOC_H__54C175EB_B960_40B1_AE83_4A5EBE1BD19B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestRoverDoc : public CDocument
{
protected: // create from serialization only
	CTestRoverDoc();
	DECLARE_DYNCREATE(CTestRoverDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestRoverDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestRoverDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestRoverDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTROVERDOC_H__54C175EB_B960_40B1_AE83_4A5EBE1BD19B__INCLUDED_)
