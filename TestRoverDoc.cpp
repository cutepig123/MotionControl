// TestRoverDoc.cpp : implementation of the CTestRoverDoc class
//

#include "stdafx.h"
#include "TestRover.h"

#include "TestRoverDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestRoverDoc

IMPLEMENT_DYNCREATE(CTestRoverDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestRoverDoc, CDocument)
	//{{AFX_MSG_MAP(CTestRoverDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestRoverDoc construction/destruction

CTestRoverDoc::CTestRoverDoc()
{
	// TODO: add one-time construction code here

}

CTestRoverDoc::~CTestRoverDoc()
{
}

BOOL CTestRoverDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestRoverDoc serialization

void CTestRoverDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestRoverDoc diagnostics

#ifdef _DEBUG
void CTestRoverDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestRoverDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestRoverDoc commands
