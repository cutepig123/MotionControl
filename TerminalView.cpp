// TerminalView.cpp : implementation file
//

#include "stdafx.h"
#include "TestRover.h"
#include "TerminalView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTerminalView

IMPLEMENT_DYNCREATE(CTerminalView, CFormView)

CTerminalView::CTerminalView()
	: CFormView(CTerminalView::IDD)
{
	//{{AFX_DATA_INIT(CTerminalView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CTerminalView::~CTerminalView()
{
}

void CTerminalView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTerminalView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTerminalView, CFormView)
	//{{AFX_MSG_MAP(CTerminalView)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDM_SEND_CMD, OnSendCmd)
	ON_WM_DESTROY()
	ON_WM_CLOSE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTerminalView diagnostics

#ifdef _DEBUG
void CTerminalView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTerminalView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTerminalView message handlers

int CTerminalView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	TRACE("CTerminalView::OnCreate");
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
//	RECT rect;
//	AfxGetMainWnd()->GetClientRect(&rect);
//	TRACE("MainFrame:(%d %d)-(%d %d)",rect.left,rect.top,rect.right,rect.bottom);
//	GetParentFrame()->MoveWindow(0,0,rect.right/2,rect.bottom/2,TRUE);
	LoadInfo("CTerminalView",GetParentFrame());
	
	CString s;
	GetParentFrame()->GetWindowText(s);
	TRACE("ParentText:%s",s.GetBuffer(0));
	GetParentFrame()->SetWindowText("Terminal");//没有反应？？
	return 0;
}


void CTerminalView::OnSendCmd() 
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("OK");
	char buf[256],s[1000];
	GetDlgItemText(IDC_EDIT_CMD,s,1000);
	if(strlen(s)<=0)
	{
		AfxMessageBox("输入为空，请重新输入");
		return;
	}
	
	AddText(m_hWnd,IDC_EDIT_INFO,"%s\r\n",s);
	PMACSendCmd(buf,s);
	AddText(m_hWnd,IDC_EDIT_INFO,"		%s\r\n",buf);
	SetDlgItemText(IDC_EDIT_CMD,"");
}


//怎么会没有执行呢？？
BOOL CTerminalView::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	TRACE("CTerminalView::DestroyWindow");
	SaveInfo("CTerminalView",GetParentFrame());
	return CFormView::DestroyWindow();
}



void CTerminalView::OnDestroy() 
{
	TRACE("CTerminalView::OnDestroy");
	SaveInfo("CTerminalView",GetParentFrame());
	CFormView::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CTerminalView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	RECT rect;
	GetClientRect(&rect);
	//ScreenToClient(&rect);
	
	if(rect.bottom-rect.top>100 && rect.right-rect.left>50)
	{
		::MoveWindow(::GetDlgItem(m_hWnd,IDC_EDIT_INFO),rect.left,rect.top,rect.right-5,rect.bottom-30,TRUE);
		::MoveWindow(::GetDlgItem(m_hWnd,IDC_EDIT_CMD),rect.left,rect.bottom-30,rect.right-30,rect.bottom,TRUE);
		::MoveWindow(::GetDlgItem(m_hWnd,IDM_SEND_CMD),rect.right-30,rect.bottom-30,rect.right,rect.bottom,TRUE);
	}
}


DWORD WINAPI CTerminalView::PMACExecProc()
{
	char buf[1000];

	{
		strcpy(buf,"返回信息 ");
		PMACSendCmd(buf+9,m_szCmd);
		MessageBox(buf);
	}
	return 0;
}

void CTerminalView::StartProc()
{
	DWORD (WINAPI CTerminalView::*p1)()=PMACExecProc;
	DWORD (WINAPI *p2)(LPVOID)=0;
	memcpy(&p2,&p1,sizeof(p1));
	m_hThread =::CreateThread(0,0,p2,this,0,0);
}