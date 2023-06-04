// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "TestRover.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(IDM_VIEW_MAIN, OnViewMain)
	ON_COMMAND(IDM_VIEW_MotorInfo, OnVIEWMotorInfo)
	ON_COMMAND(IDM_VIEW_TERMINAL, OnViewTerminal)
	ON_COMMAND(IDM_SELECT, OnSelect)
	ON_WM_DESTROY()
	ON_COMMAND(IDM_VIEW_HIT405VIEW, OnViewHit405view)
	ON_COMMAND(IDM_VIEW_HIT6501TESTDLG, OnViewHit6501testdlg)
	ON_COMMAND(IDM_STOP_ALL_PMAC, OnStopAllPmac)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_pDlgHIT6501Test=0;
	m_pDlgHIT405=0;
}

CMainFrame::~CMainFrame()
{
	if(m_pDlgHIT6501Test)
	{
		TRACE("CMainFrame::~CMainFrame():删除dlg资源");
		delete m_pDlgHIT6501Test;
	}
	if(m_pDlgHIT405)
	{
		TRACE("CMainFrame::~CMainFrame():删除dlg m_pDlgHIT405资源");
		delete m_pDlgHIT405;
	}
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	
	//LoadInfo("CMainFrame",this);
	OpenRuntimeLink();
	Select();
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

#include "Hit6501TestDlg.h"
void CMainFrame::OnViewMain() 
{
	// TODO: Add your command handler code here
	CTestRoverApp*pApp=(CTestRoverApp*) AfxGetApp();
	pApp->NewWindow(1);

	
}

void CMainFrame::OnVIEWMotorInfo() 
{
	// TODO: Add your command handler code here
	CTestRoverApp*pApp=(CTestRoverApp*) AfxGetApp();
	pApp->NewWindow(2);
}

void CMainFrame::OnViewTerminal() 
{
	// TODO: Add your command handler code here
	CTestRoverApp*pApp=(CTestRoverApp*) AfxGetApp();
	pApp->NewWindow(3);
}

void CMainFrame::OnSelect() 
{
	// TODO: Add your command handler code here
	Select();	
}

void CMainFrame::OnDestroy() 
{
	SaveInfo("CMainFrame",this);
	CMDIFrameWnd::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CMainFrame::OnViewHit405view() 
{
	// TODO: Add your command handler code here
	CTestRoverApp*pApp=(CTestRoverApp*) AfxGetApp();
	pApp->NewWindow(4);
	
	if(!m_pDlgHIT405)
	{
		TRACE("建立dlg m_pDlgHIT405资源");
		m_pDlgHIT405=new CHit405Dlg;
		m_pDlgHIT405->Create(IDD_HIT405_DIALOG,this);
		m_pDlgHIT405->ShowWindow(SW_SHOW);
	}
	else
	{
		TRACE("显示dlg m_pDlgHIT405窗口");
		m_pDlgHIT405->ShowWindow(SW_SHOW);
	}
}

void CMainFrame::OnViewHit6501testdlg() 
{
	// TODO: Add your command handler code here
	
	if(!m_pDlgHIT6501Test)
	{
		TRACE("建立dlg资源");
		m_pDlgHIT6501Test=new CHit6501TestDlg;
		m_pDlgHIT6501Test->Create(IDD_HIT6501TEST_DIALOG,this);
		m_pDlgHIT6501Test->ShowWindow(SW_SHOW);
	}
	else
	{
		TRACE("显示dlg窗口");
		m_pDlgHIT6501Test->ShowWindow(SW_SHOW);
	}
}

void CMainFrame::OnStopAllPmac() 
{
	// TODO: Add your command handler code here
	int i;
	char buf[256];
	for (i=1;i<32;i++)
	{
		PMACSendCmd(buf,"$$$");
	}
}
