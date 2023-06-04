// TestRoverView.cpp : implementation of the CTestRoverView class
//

#include "stdafx.h"
#include "TestRover.h"

#include "TestRoverDoc.h"
#include "TestRoverView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestRoverView

IMPLEMENT_DYNCREATE(CTestRoverView, CFormView)

BEGIN_MESSAGE_MAP(CTestRoverView, CFormView)
	//{{AFX_MSG_MAP(CTestRoverView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestRoverView construction/destruction

CTestRoverView::CTestRoverView()
	: CFormView(CTestRoverView::IDD)
{
	//{{AFX_DATA_INIT(CTestRoverView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CTestRoverView::~CTestRoverView()
{
}

void CTestRoverView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestRoverView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}





/////////////////////////////////////////////////////////////////////////////
// CTestRoverView printing

BOOL CTestRoverView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestRoverView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestRoverView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTestRoverView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CTestRoverView diagnostics

#ifdef _DEBUG
void CTestRoverView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTestRoverView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTestRoverDoc* CTestRoverView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestRoverDoc)));
	return (CTestRoverDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestRoverView message handlers

int CTestRoverView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	LoadInfo("CTestRoverView",GetParentFrame());
	return 0;
}

void CTestRoverView::OnDestroy() 
{
	SaveInfo("CTestRoverView",GetParentFrame());
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	
}
