// MotorInfoView.cpp : implementation file
//

#include "stdafx.h"
#include "TestRover.h"
#include "MotorInfoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//电机和轴的对应信息（因为在接线时接得比较乱）
struct MOTOR_DATA	motor_data[6]={
	{0x340,3,0x1828,0x828,0},
	{0x380,2,0x1828,0x828,0},
	{0x380,1,0x1828,0x828,0},
	{0x340,2,0x82a,0x1828,0},
	{0x380,3,0x82a,0x1828,0},
	{0x340,1,0x82a,0x1828,0},
};

/////////////////////////////////////////////////////////////////////////////
// CMotorInfoView

IMPLEMENT_DYNCREATE(CMotorInfoView, CFormView)

CMotorInfoView::CMotorInfoView()
	: CFormView(CMotorInfoView::IDD)
{
	//{{AFX_DATA_INIT(CMotorInfoView)
		// NOTE: the ClassWizard will add member initialization here
	m_hThread=0;
	//}}AFX_DATA_INIT
}

CMotorInfoView::~CMotorInfoView()
{
}

void CMotorInfoView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMotorInfoView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMotorInfoView, CFormView)
	//{{AFX_MSG_MAP(CMotorInfoView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_STOP_ALL_PMAC, OnButtonStopAllPmac)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_STOP_ALL_6501, OnButtonStopAll6501)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMotorInfoView diagnostics

#ifdef _DEBUG
void CMotorInfoView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMotorInfoView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMotorInfoView message handlers

int CMotorInfoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	LoadInfo("CMotorInfoView",GetParentFrame());
	StartProc();
//	SetWindowText("WIndowsText");
//	GetParent()->SetWindowText("PP");
//	
	return 0;
}

//没有执行？？



void CMotorInfoView::OnDestroy() 
{
	TRACE("CMotorInfoView::OnDestroy");
	SaveInfo("CMotorInfoView",GetParentFrame());
	if(m_hThread)
		TerminateThread(m_hThread,0);

	CFormView::OnDestroy();
}



DWORD WINAPI CMotorInfoView::ShowInfoProc()
{
	int i;
	char buf[1000];

	TRACE("Enter ShowInfoProc");
	
	
	while (1) 
	{
		
		SetText(m_hWnd,IDC_EDIT_MOTORINFO,"摇臂\r\n");
		AddText(m_hWnd,IDC_EDIT_MOTORINFO,"轴\t位置\r\n");
		char currPos[256]={0};
		PMACSendCmd(currPos,"#");
		AddText(m_hWnd,IDC_EDIT_MOTORINFO,"currPos\t%s\r\n",currPos);
		for (i=1;i<=6;i++) 
		{
			PMACSendCmd(buf,"#%dp",i);
			AddText(m_hWnd,IDC_EDIT_MOTORINFO,"%d\t%s\t",i,buf);

			PMACSendCmd(buf,"i%d00",i);
			AddText(m_hWnd,IDC_EDIT_MOTORINFO,"i%d00=\t%s\t",i,buf);

			PMACSendCmd(buf,"i%d24",i);
			AddText(m_hWnd,IDC_EDIT_MOTORINFO,"i%d24=\t%s\r\n",i,buf);
		}
		PMACSendCmd(buf,"#%s",currPos);

		AddText(m_hWnd,IDC_EDIT_MOTORINFO,"车轮\r\n");
		AddText(m_hWnd,IDC_EDIT_MOTORINFO,"轴\t速度\t位置\t\r\n");
		for (i=0;i<6 ;i++ )
		{
			set_base_address(motor_data[i].baseaddr);
			set_axis(motor_data[i].axis);
			AddText(m_hWnd,IDC_EDIT_MOTORINFO,"%d\t%d/%d\t%d/%d \r\n",
				i+1,get_real_vel(),get_desire_vel(),get_real_pos(),get_desire_pos());
			
		}
		
		Sleep(800);
	}
}

void CMotorInfoView::StartProc()
{
	DWORD (WINAPI CMotorInfoView::*p1)()=ShowInfoProc;
	DWORD (WINAPI *p2)(LPVOID)=0;
	memcpy(&p2,&p1,sizeof(p1));
	m_hThread =::CreateThread(0,0,p2,this,0,0);
}

void CMotorInfoView::OnButtonStopAllPmac() 
{
	// TODO: Add your control notification handler code here
	int i;
	char buf[256];
	for (i=1;i<32;i++)
	{
		PMACSendCmd(buf,"$$$");
	}
	MessageBox("OK");

}

void CMotorInfoView::OnButtonStopAll6501() 
{
	// TODO: Add your control notification handler code here
	int i;
	set_base_address(0x340);
	set_out(0);

	set_base_address(0x380);
	set_out(0);

	for (i=0;i<6 ;i++ )
	{
		set_base_address(motor_data[i].baseaddr);
		
		{
		//	printf("%d ",i);
			set_axis(motor_data[i].axis);//设置当前轴
			reset_6501();//对6501进行复位
			set_DAC();//将输出设置为DAC输出方式
			set_motion(0,0,0,0x100);//设置轨迹参数
			start_motion();//平滑停车
		}
		
	}
	MessageBox("OK");
}
