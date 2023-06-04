// hit405Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "hit405Dlg.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define PI 3.1415926
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


/////////////////////////////////////////////////////////////////////////////
// CHit405Dlg dialog

CHit405Dlg::CHit405Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHit405Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHit405Dlg)
	m_motor_v = 0;
	m_radius = 0.0;
	m_io = 0;
	m_nbase = 0;
	m_strYBPosFive = _T("");
	m_strYBPosFour = _T("");
	m_strYBPosOne = _T("");
	m_strYBPosSix = _T("");
	m_strYBPosThree = _T("");
	m_strYBPosTwo = _T("");
	m_dDegOne = 0.0;
	m_dDegFive = 0.0;
	m_dDegFour = 0.0;
	m_dDegTwo = 0.0;
	m_dDegSix = 0.0;
	m_dDegThree = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHit405Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHit405Dlg)
	DDX_Control(pDX, IDC_MOTORSIX_RIGHT, m_motorsix_right);
	DDX_Control(pDX, IDC_MOTORFOUR_RIGHT, m_motorfour_right);
	DDX_Control(pDX, IDC_MOTORFIVE_RIGHT, m_motorfive_right);
	DDX_Control(pDX, IDC_MOTORSIX_CHOOSE, m_MOTORSIX);
	DDX_Control(pDX, IDC_MOTORFIVE_CHOOSE, m_MOTORFIVE);
	DDX_Control(pDX, IDC_MOTORFOUR_CHOOSE, m_MOTORFOUR);
	DDX_Control(pDX, IDC_MOTORTWO_RIGHT, m_motortwo_right);
	DDX_Control(pDX, IDC_MOTORTHREE_RIGHT, m_motorthree_right);
	DDX_Control(pDX, IDC_MOTORONE_RIGHT, m_motorone_right);
	DDX_Control(pDX, IDC_MOTORTWO_CHOOSE, m_motortwo);
	DDX_Control(pDX, IDC_MOTORTHREE_CHOOSE, m_motorthree);
	DDX_Control(pDX, IDC_MOTORONE_CHOOSE, m_motorone);
	DDX_Text(pDX, IDC_MOTOR_V, m_motor_v);
	DDV_MinMaxInt(pDX, m_motor_v, 0, 100000);
	DDX_Text(pDX, IDC_EDIT_R, m_radius);
	DDX_Text(pDX, IDC_EDIT_IO, m_io);
	DDX_Text(pDX, IDC_EDIT_BASEADDRESS, m_nbase);
	DDX_Text(pDX, IDC_EDIT_YAOBI_FIVE, m_strYBPosFive);
	DDX_Text(pDX, IDC_EDIT_YAOBI_FOUR, m_strYBPosFour);
	DDX_Text(pDX, IDC_EDIT_YAOBI_ONE, m_strYBPosOne);
	DDX_Text(pDX, IDC_EDIT_YAOBI_SIX, m_strYBPosSix);
	DDX_Text(pDX, IDC_EDIT_YAOBI_THREE, m_strYBPosThree);
	DDX_Text(pDX, IDC_EDIT_YAOBI_TWO, m_strYBPosTwo);
	DDX_Text(pDX, IDC_DEG_YBONE, m_dDegOne);
	DDV_MinMaxDouble(pDX, m_dDegOne, -180., 180.);
	DDX_Text(pDX, IDC_DEG_YBFIVE, m_dDegFive);
	DDV_MinMaxDouble(pDX, m_dDegFive, -180., 180.);
	DDX_Text(pDX, IDC_DEG_YBOFOUR, m_dDegFour);
	DDV_MinMaxDouble(pDX, m_dDegFour, -180., 180.);
	DDX_Text(pDX, IDC_DEG_YBOTWO, m_dDegTwo);
	DDV_MinMaxDouble(pDX, m_dDegTwo, -180., 180.);
	DDX_Text(pDX, IDC_DEG_YBSIX, m_dDegSix);
	DDV_MinMaxDouble(pDX, m_dDegSix, -180., 180.);
	DDX_Text(pDX, IDC_DEG_YBTHREE, m_dDegThree);
	DDV_MinMaxDouble(pDX, m_dDegThree, -180., 180.);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHit405Dlg, CDialog)
	//{{AFX_MSG_MAP(CHit405Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MOTORONE_CHOOSE, OnMotoroneChoose)
	ON_BN_CLICKED(IDC_MOTORONE_RIGHT, OnMotoroneRight)
	ON_BN_CLICKED(IDC_MOTORONE_LEFT, OnMotoroneLeft)
	ON_BN_CLICKED(IDC_MOTORTWO_CHOOSE, OnMotortwoChoose)
	ON_BN_CLICKED(IDC_MOTORTWO_RIGHT, OnMotortwoRight)
	ON_BN_CLICKED(IDC_MOTORTWO_LEFT, OnMotortwoLeft)
	ON_BN_CLICKED(IDC_MOTORTHREE_CHOOSE, OnMotorthreeChoose)
	ON_BN_CLICKED(IDC_MOTORTHREE_RIGHT, OnMotorthreeRight)
	ON_BN_CLICKED(IDC_MOTORTHREE_LEFT, OnMotorthreeLeft)
	ON_BN_CLICKED(IDC_MOTOR_START, OnMotorStart)
	ON_BN_CLICKED(IDC_MOTOR_STOP, OnMotorStop)
	ON_BN_CLICKED(IDC_MOTORFOUR_CHOOSE, OnMotorfourChoose)
	ON_BN_CLICKED(IDC_MOTORFIVE_CHOOSE, OnMotorfiveChoose)
	ON_BN_CLICKED(IDC_MOTORSIX_CHOOSE, OnMotorsixChoose)
	ON_BN_CLICKED(IDC_MOTORFOUR_RIGHT, OnMotorfourRight)
	ON_BN_CLICKED(IDC_MOTORFOUR_LEFT, OnMotorfourLeft)
	ON_BN_CLICKED(IDC_MOTORFIVE_RIGHT, OnMotorfiveRight)
	ON_BN_CLICKED(IDC_MOTORFIVE_LEFT, OnMotorfiveLeft)
	ON_BN_CLICKED(IDC_MOTORSIX_RIGHT, OnMotorsixRight)
	ON_BN_CLICKED(IDC_MOTORSIX_LEFT, OnMotorsixLeft)
	ON_BN_CLICKED(ID_ENABLE, OnEnable)
	ON_BN_CLICKED(ID_TEST, OnTest)
	ON_BN_CLICKED(IDC_SELECTPMAC, OnSelectpmac)
	ON_BN_CLICKED(IDC_PMAC_TEST, OnPmacTest)
	ON_BN_CLICKED(IDC_YAOBI_ONE_U, OnYaobiOneU)
	ON_BN_CLICKED(IDC_YAOBI_ONE_D, OnYaobiOneD)
	ON_BN_CLICKED(IDC_YAOBI_ONE_S, OnYaobiOneS)
	ON_BN_CLICKED(IDC_YAOBI_TWO_U, OnYaobiTwoU)
	ON_BN_CLICKED(IDC_YAOBI_TWO_D, OnYaobiTwoD)
	ON_BN_CLICKED(IDC_YAOBI_TWO_S, OnYaobiTwoS)
	ON_BN_CLICKED(IDC_YAOBI_THREE_U, OnYaobiThreeU)
	ON_BN_CLICKED(IDC_YAOBI_THREE_D, OnYaobiThreeD)
	ON_BN_CLICKED(IDC_YAOBI_THREE_S, OnYaobiThreeS)
	ON_BN_CLICKED(IDC_YAOBI_FOUR_U, OnYaobiFourU)
	ON_BN_CLICKED(IDC_YAOBI_FOUR_D, OnYaobiFourD)
	ON_BN_CLICKED(IDC_YAOBI_FOUR_S, OnYaobiFourS)
	ON_BN_CLICKED(IDC_YAOBI_FIVE_U, OnYaobiFiveU)
	ON_BN_CLICKED(IDC_YAOBI_FIVE_D, OnYaobiFiveD)
	ON_BN_CLICKED(IDC_YAOBI_FIVE_S, OnYaobiFiveS)
	ON_BN_CLICKED(IDC_YAOBI_SIX_U, OnYaobiSixU)
	ON_BN_CLICKED(IDC_YAOBI_SIX_D, OnYaobiSixD)
	ON_BN_CLICKED(IDC_YAOBI_SIX_S, OnYaobiSixS)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHit405Dlg message handlers

BOOL CHit405Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	motor1=0;motor2=0;motor3=0;
	motor4=0;motor5=0;motor6=0;
	direction1=1;direction2=1;direction3=1;
	direction4=1;direction5=1;direction6=1;
	m_motorone_right.SetCheck(1);
	m_motortwo_right.SetCheck(1);
	m_motorthree_right.SetCheck(1);
	m_motorfour_right.SetCheck(1);
	m_motorfive_right.SetCheck(1);
	m_motorsix_right.SetCheck(1);

	//Pmac
	m_bDriverOpen = 0;
	m_nDevName = NULL;
	FlagOne = 0;FlagTwo = 0;FlagThree = 0;FlagFour = 0;FlagFive = 0;FlagSix = 0;

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
//	LoadInfo("CHit405Dlg",this);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHit405Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHit405Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHit405Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
//Close
void CHit405Dlg::close()
{
	KillTimer(1);
	if(m_bDriverOpen)
	{
		m_bDriverOpen = !ClosePmacDevice(m_nDevName);
	}
}
void CHit405Dlg::OnCancel() 
{
	close();	
	CDialog::OnCancel();
}

void CHit405Dlg::OnOK() 
{
	close();
	CDialog::OnOK();
}
void CHit405Dlg::OnClose() 
{
	close();
	CDialog::OnClose();
}


//wheel
void CHit405Dlg::OnMotoroneChoose() 
{
	if (m_motorone.GetCheck()==1)
	{
		motor1=1;
	}
	else
	{
		motor1=0;
	}
}

void CHit405Dlg::OnMotoroneRight() 
{
	// TODO: Add your control notification handler code here
	direction1=1;
}

void CHit405Dlg::OnMotoroneLeft() 
{
	// TODO: Add your control notification handler code here
	direction1=2;
}

void CHit405Dlg::OnMotortwoChoose() 
{
	if (m_motortwo.GetCheck()==1)
	{
		motor2=1;
	}
	else
	{
		motor2=0;
	}
}

void CHit405Dlg::OnMotortwoRight() 
{
	// TODO: Add your control notification handler code here
	direction2=1;
}

void CHit405Dlg::OnMotortwoLeft() 
{
	// TODO: Add your control notification handler code here
	direction2=2;
}

void CHit405Dlg::OnMotorthreeChoose() 
{
	if (m_motorthree.GetCheck()==1)
	{
		motor3=1;
	}
	else
	{
		motor3=0;
	}
}

void CHit405Dlg::OnMotorthreeRight() 
{
	// TODO: Add your control notification handler code here
	direction3=1;
}

void CHit405Dlg::OnMotorthreeLeft() 
{
	// TODO: Add your control notification handler code here
	direction3=2;
}

void CHit405Dlg::OnMotorStart() 
{
	// TODO: Add your control notification handler code here
	//set_base_address(0x340);// 设置6501板的基地址为0x340

	UpdateData();
	SetWheelVelocity();
    if(motor1==1)
	{
		set_base_address(0x340);
		set_axis(3);//设置1轴为当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
        set_PID(1,0,0,10000,0x0f);//设置PID参数
	    update_PID();//使PID参数生效
		switch(direction1)
		{
		  case 1: set_motion(80000,motorv[0],0,0x1828); break;
          case 2: set_motion(80000,motorv[0],0,0x82a); break;

		  //case 1: set_motion(80000,m_motor_v,0,0x1828); break;
          //case 2: set_motion(80000,m_motor_v,0,0x82a); break;
		}
	   start_motion();//开始运动
	}
    if(motor2==1)
	{
		set_base_address(0x380);
		set_axis(2);//设置1轴为当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
        set_PID(5,0,0,10000,0x0f);//设置PID参数
	    update_PID();//使PID参数生效
		switch(direction2)
		{
		  case 1: set_motion(80000,motorv[1],0,0x1828); break;
          case 2: set_motion(80000,motorv[1],0,0x82a); break;
		  //case 1: set_motion(80000,m_motor_v,0,0x1828); break;
          //case 2: set_motion(80000,m_motor_v,0,0x82a); break;
		}
	   start_motion();//开始运动
	}
	if(motor3==1)
	{
		set_base_address(0x380);
		set_axis(1);//设置1轴为当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
        set_PID(5,0,0,10000,0x0f);//设置PID参数
	    update_PID();//使PID参数生效
		switch(direction3)
		{
		  case 1: set_motion(80000,motorv[2],0,0x1828); break;
          case 2: set_motion(80000,motorv[2],0,0x82a); break;
		 
          //case 1: set_motion(80000,m_motor_v,0,0x1828); break;
          //case 2: set_motion(80000,m_motor_v,0,0x82a); break;
		}
	   start_motion();//开始运动
	}
	if(motor4==1)
	{
		set_base_address(0x340);
		set_axis(2);//设置1轴为当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
        set_PID(5,0,0,10000,0x0f);//设置PID参数
	    update_PID();//使PID参数生效
		switch(direction4)
		{
		  case 1: set_motion(80000,motorv[3],0,0x82a); break;
          case 2: set_motion(80000,motorv[3],0,0x1828); break;
		  
          //case 1: set_motion(80000,m_motor_v,0,0x82a); break;
		  //case 2: set_motion(80000,m_motor_v,0,0x1828); break;
		}
	   start_motion();//开始运动
	}
	if(motor5==1)
	{
		set_base_address(0x380);
		set_axis(3);//设置1轴为当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
        set_PID(5,0,0,10000,0x0f);//设置PID参数
	    update_PID();//使PID参数生效
		switch(direction5)
		{
		  case 1: set_motion(80000,motorv[4],0,0x82a); break;
          case 2: set_motion(80000,motorv[4],0,0x1828); break;
		  
          //case 1: set_motion(80000,m_motor_v,0,0x82a); break;
		  //case 2: set_motion(80000,m_motor_v,0,0x1828); break;
		}
	   start_motion();//开始运动
	}
	if(motor6==1)
	{
		set_base_address(0x340);
		set_axis(1);//设置1轴为当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
        set_PID(10,1,0,10000,0x0f);//设置PID参数
	    update_PID();//使PID参数生效
		switch(direction6)
		{
		  case 1: set_motion(80000,motorv[5],0,0x82a); break;
          case 2: set_motion(80000,motorv[5],0,0x1828); break;
		  //case 1: set_motion(80000,m_motor_v,0,0x82a); break;
          //case 2: set_motion(80000,m_motor_v,0,0x1828); break;
		}
	   start_motion();//开始运动
	}

}

void CHit405Dlg::OnMotorStop() 
{
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	set_base_address(0x340);// 设置6501板的基地址为0x340
	set_axis(1);//设置1轴为当前轴
	reset_6501();//对6501进行复位
	set_DAC();//将输出设置为DAC输出方式
	set_motion(0,0,0,0x100);//设置轨迹参数
	start_motion();//平滑停车

	set_axis(2);//设置1轴为当前轴
	reset_6501();//对6501进行复位
	set_DAC();//将输出设置为DAC输出方式
	set_motion(0,0,0,0x100);//设置轨迹参数
	start_motion();//平滑停车

	set_axis(3);//设置1轴为当前轴
	reset_6501();//对6501进行复位
	set_DAC();//将输出设置为DAC输出方式
	set_motion(0,0,0,0x100);//设置轨迹参数
	start_motion();//平滑停车

	
	set_base_address(0x380);

	set_axis(1);//设置1轴为当前轴
	reset_6501();//对6501进行复位
	set_DAC();//将输出设置为DAC输出方式
	set_motion(0,0,0,0x100);//设置轨迹参数
	start_motion();//平滑停车

	set_axis(2);//设置1轴为当前轴
	reset_6501();//对6501进行复位
	set_DAC();//将输出设置为DAC输出方式
	set_motion(0,0,0,0x100);//设置轨迹参数
	start_motion();//平滑停车

	set_axis(3);//设置1轴为当前轴
	reset_6501();//对6501进行复位
	set_DAC();//将输出设置为DAC输出方式
	set_motion(0,0,0,0x100);//设置轨迹参数
	start_motion();//平滑停车

	/*motor1=0;
	motor2=0;
	motor3=0;
	m_motorone.SetCheck(0);
	m_motortwo.SetCheck(0);
	m_motorthree.SetCheck(0);
	*/
}

void CHit405Dlg::OnEnable()
{
	UpdateData();
	set_base_address(0x340);
	//set_out(0x0f);
	set_out(m_io);

	set_base_address(0x380);
	set_out(m_io);
}

void CHit405Dlg::OnMotorfourChoose() 
{
	// TODO: Add your control notification handler code here
	if (m_MOTORFOUR.GetCheck()==1)
	{
		motor4=1;
	}
	else
	{
		motor4=0;
	}
}

void CHit405Dlg::OnMotorfiveChoose() 
{
	// TODO: Add your control notification handler code here
	if (m_MOTORFIVE.GetCheck()==1)
	{
		motor5=1;
	}
	else
	{
		motor5=0;
	
	}
}

void CHit405Dlg::OnMotorsixChoose() 
{
	// TODO: Add your control notification handler code here
	if (m_MOTORSIX.GetCheck()==1)
	{
		motor6=1;
	}
	else
	{
		motor6=0;
	}
}

void CHit405Dlg::OnMotorfourRight() 
{
	// TODO: Add your control notification handler code here
	direction4=1;
}

void CHit405Dlg::OnMotorfourLeft() 
{
	// TODO: Add your control notification handler code here
	direction4=2;
}

void CHit405Dlg::OnMotorfiveRight() 
{
	// TODO: Add your control notification handler code here
	direction5=1;
}

void CHit405Dlg::OnMotorfiveLeft() 
{
	// TODO: Add your control notification handler code here
	direction5=2;
}

void CHit405Dlg::OnMotorsixRight() 
{
	// TODO: Add your control notification handler code here
	direction6=1;
}

void CHit405Dlg::OnMotorsixLeft() 
{
	// TODO: Add your control notification handler code here
	direction6=2;
}

void CHit405Dlg::SetWheelVelocity()
{
	UpdateData();
	int i;
	int v=m_motor_v;
	double p=m_radius;
	
	if (p!=0)
	{
		double l[]={0.425,0.175,-0.075,0.075,-0.175,-0.425};
		double L=0.3;
		double r=0.125;
		double R[6],eta[6];
		double deta[6]={(double)50/180*PI,(double)50/180*PI,(double)(180-50)/180*PI,(double)50/180*PI,(double)(180-50)/180*PI,(double)(180-50)/180*PI};
		double X[6];
		double Y[6]={0.44,0.44,0.44,-0.44,-0.44,-0.44};
		double M[6],W_Velocity[6];
	
		for(i=0;i<6;i++)
		{
			X[i]=l[i]+L*cos(deta[i]);
		}
		for(i=0;i<6;i++)
		{
			R[i]=sqrt(X[i]*X[i]+Y[i]*Y[i]);
			if (i<3)
			{
				eta[i]=atan(fabs(Y[i]/X[i]));
			}
			else
			{
				eta[i]=atan(fabs(Y[i]/X[i]))+PI;
			}
		}
		for(i=0;i<6;i++)
		{
			M[i]=v*(1-(R[i]*sin(eta[i]))/p);
			W_Velocity[i]=M[i];
			motorv[i]=(int)W_Velocity[i];
		}
	}
	else
	{
		for(i=0;i<6;i++)
		{
			motorv[i]=m_motor_v;
		}
	}
	/*
	CString str;
	str.Format("%d, %d, %d, %d, %d, %d",(int)W_Velocity[0],(int)W_Velocity[1],(int)W_Velocity[2],(int)W_Velocity[3],(int)W_Velocity[4],(int)W_Velocity[5]);
	MessageBox(str);
	*/
	
}

void CHit405Dlg::OnTest() 
{
	SetWheelVelocity();	
}


//Pmac
BOOL CHit405Dlg::OnSelectpmac() 
{
	OpenRuntimeLink();
	m_nDevName = PmacSelect(NULL);
	 
	if (m_nDevName >= 0 && m_nDevName <= 7)
	{
		if (OpenPmacDevice(m_nDevName))
		{
   			m_bDriverOpen = 1;
			MessageBox("Connected Pmac, Now!");
			SetTimer(1,100,0);
  			return TRUE;  // return TRUE  unless you set the focus to a control
		}
	}
	return FALSE;
	
}

BOOL CHit405Dlg::OnPmacTest() 
{
	if (m_bDriverOpen == 0)
	{
		MessageBox("not initialize");
		return FALSE;
	}

	CString msg;
	char vs[200],buf[255];
	
	PmacGetRomVersion(m_nDevName,vs,30);
	msg = "RomVersion is : " + (CString)vs;
	MessageBox(msg);

	PmacGetRomDate(m_nDevName,vs,30);
	msg = "RomDate is :" + (CString)vs;
	MessageBox(msg);

	PmacGetControlResponse(m_nDevName,buf,255,2);
	msg = "ControlResponse is :" + (CString)buf;
	MessageBox(msg);

	PmacGetResponse(m_nDevName,buf,255,"?");
	msg = "Response is :" + (CString)buf;
	MessageBox(msg);

	PmacGetResponse(m_nDevName,buf,255,"#8p");
	msg = "#1 Motor position is :" + (CString)buf;
	MessageBox(msg);

	return TRUE;
	
}

void CHit405Dlg::OnYaobiOneU() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagOne = 1;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#1p");
		originone = atof(buf);
		overone = originone - m_dDegOne*4800/360;

		PmacSendCommandA(m_nDevName,"#1");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O-100");

		SetTimer(2,100,0);
	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiOneD() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagOne = 0;
		char buf[255];
		CString ss;
		PmacGetResponse(m_nDevName,buf,255,"#1p");
		originone = atof(buf);
		ss.Format("%f",originone);
		//MessageBox(ss);
		overone = originone + m_dDegOne*4800/360;


		ss.Format("%f",overone);
		//MessageBox(ss);

		PmacSendCommandA(m_nDevName,"#1");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O100");

		SetTimer(2,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiOneS() 
{
	if (m_bDriverOpen == 1)
	{
		PmacSendCommandA(m_nDevName,"#1");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"K");	
		KillTimer(2);
	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiTwoU() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagTwo = 1;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#2p");
		origintwo = atof(buf);
		overtwo = origintwo - m_dDegTwo*4800/360;

		PmacSendCommandA(m_nDevName,"#2");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O-100");

		SetTimer(3,100,0);
	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiTwoD() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagTwo = 0;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#2p");
		origintwo = atof(buf);
		overtwo = origintwo + m_dDegTwo*4800/360;

		PmacSendCommandA(m_nDevName,"#2");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O100");

		SetTimer(3,100,0);
	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiTwoS() 
{
	if (m_bDriverOpen == 1)
	{
		PmacSendCommandA(m_nDevName,"#2");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"K");
		KillTimer(3);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiThreeU() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagThree = 0;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#3p");
		originthree = atof(buf);
		overthree = originthree + m_dDegThree*4800/360;

		PmacSendCommandA(m_nDevName,"#3");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O100");
		SetTimer(4,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiThreeD() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagThree = 1;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#3p");
		originthree = atof(buf);
		overthree = originthree - m_dDegThree*4800/360;

		PmacSendCommandA(m_nDevName,"#3");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O-100");
		SetTimer(4,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiThreeS() 
{
	if (m_bDriverOpen == 1)
	{
		PmacSendCommandA(m_nDevName,"#3");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"K");
		KillTimer(4);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiFourU() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagFour = 1;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#4p");
		originfour = atof(buf);
		CString ss;
		ss.Format("%f",originfour);
		//MessageBox(ss);
		overfour = originfour - m_dDegFour*4800/360;
		ss.Format("%f",overfour);
		//MessageBox(ss);

		PmacSendCommandA(m_nDevName,"#4");
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O-100");
		SetTimer(5,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiFourD() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagFour = 0;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#4p");
		originfour = atof(buf);
		overfour = originfour + m_dDegFour*4800/360;

		PmacSendCommandA(m_nDevName,"#4");
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O100");
		SetTimer(5,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiFourS() 
{
	if (m_bDriverOpen == 1)
	{
		PmacSendCommandA(m_nDevName,"#4");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"K");	
		KillTimer(5);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiFiveU() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagFive = 1;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#5p");
		originfive = atof(buf);
		overfive = originfive - m_dDegFive*4800/360;

		PmacSendCommandA(m_nDevName,"#5");
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O-100");
		SetTimer(6,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiFiveD() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagFive = 0;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#5p");
		originfive = atof(buf);
		overfive = originfive + m_dDegFive*4800/360;

		PmacSendCommandA(m_nDevName,"#5");
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O100");
		SetTimer(6,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiFiveS() 
{
	if (m_bDriverOpen == 1)
	{
		PmacSendCommandA(m_nDevName,"#5");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"K");
		KillTimer(6);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiSixU() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagSix = 0;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#6p");
		originsix = atof(buf);
		oversix = originsix + m_dDegSix*4800/360;

		PmacSendCommandA(m_nDevName,"#6");
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O-100");
		SetTimer(7,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiSixD() 
{
	UpdateData(TRUE);
	if (m_bDriverOpen == 1)
	{
		FlagSix = 1;
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#6p");
		originsix = atof(buf);
		oversix = originsix - m_dDegSix*4800/360;

		PmacSendCommandA(m_nDevName,"#6");
		Sleep(10);
		PmacSendCommandA(m_nDevName,"O100");
		SetTimer(7,100,0);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

void CHit405Dlg::OnYaobiSixS() 
{
	if (m_bDriverOpen == 1)
	{
		PmacSendCommandA(m_nDevName,"#6");	
		Sleep(10);
		PmacSendCommandA(m_nDevName,"K");
		KillTimer(7);

	}
	else
	{
		MessageBox("not initialize");
	}
	
}

//Timer
void CHit405Dlg::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#1p");
		//m_strYBPosOne = buf;
		SetDlgItemText(IDC_EDIT_YAOBI_ONE,buf);

		PmacGetResponse(m_nDevName,buf,255,"#2p");
		//m_strYBPosTwo = buf;
		SetDlgItemText(IDC_EDIT_YAOBI_TWO,buf);

		PmacGetResponse(m_nDevName,buf,255,"#3p");
		//m_strYBPosThree = buf;
		SetDlgItemText(IDC_EDIT_YAOBI_THREE,buf);
		
		PmacGetResponse(m_nDevName,buf,255,"#4p");
		//m_strYBPosFour = buf;
		SetDlgItemText(IDC_EDIT_YAOBI_FOUR,buf);

		PmacGetResponse(m_nDevName,buf,255,"#5p");
		//m_strYBPosFive = buf;
		SetDlgItemText(IDC_EDIT_YAOBI_FIVE,buf);

		PmacGetResponse(m_nDevName,buf,255,"#6p");
		//m_strYBPosSix = buf;
		SetDlgItemText(IDC_EDIT_YAOBI_SIX,buf);
	}
	if (nIDEvent == 2)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#1p");
		double status1 = atof(buf);

		if (FlagOne == 0)
		{
			if (status1>=overone)
			{
				OnYaobiOneS();
				KillTimer(2);
			}
		}
		if (FlagOne == 1)
		{
			if (status1<=overone)
			{
				OnYaobiOneS();
				KillTimer(2);
			}
		}
	}

	if (nIDEvent == 3)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#2p");
		double status2 = atof(buf);

		if (FlagTwo == 0)
		{
			if (status2>=overtwo)
			{
				OnYaobiTwoS();
				KillTimer(3);
			}
		}
		if (FlagTwo == 1)
		{
			if (status2<=overtwo)
			{
				OnYaobiTwoS();
				KillTimer(3);
			}
		}
	}

	if (nIDEvent == 4)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#3p");
		double status3 = atof(buf);

		if (FlagThree == 0)
		{
			if (status3>=overthree)
			{
				OnYaobiThreeS();
				KillTimer(4);
			}
		}
		if (FlagThree == 1)
		{
			if (status3<=overthree)
			{
				OnYaobiThreeS();
				KillTimer(4);
			}
		}
	}

	if (nIDEvent == 5)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#4p");
		double status4 = atof(buf);

		if (FlagFour == 0)
		{
			if (status4>=overfour)
			{
				OnYaobiFourS();
				KillTimer(5);
			}
		}
		if (FlagFour == 1)
		{
			if (status4<=overfour)
			{
				OnYaobiFourS();
				KillTimer(5);
			}
		}
	}

	if (nIDEvent == 6)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#5p");
		double status5 = atof(buf);

		if (FlagFive == 0)
		{
			if (status5>=overfive)
			{
				OnYaobiFiveS();
				KillTimer(6);
			}
		}
		if (FlagFive == 1)
		{
			if (status5<=overfive)
			{
				OnYaobiFiveS();
				KillTimer(6);
			}
		}
	}

	if (nIDEvent == 7)
	{
		char buf[255];
		PmacGetResponse(m_nDevName,buf,255,"#6p");
		double status6 = atof(buf);

		if (FlagSix == 0)
		{
			if (status6>=oversix)
			{
				OnYaobiSixS();
				KillTimer(7);
			}
		}
		if (FlagSix == 1)
		{
			if (status6<=oversix)
			{
				OnYaobiSixS();
				KillTimer(7);
			}
		}
	}

	CDialog::OnTimer(nIDEvent);
}

void CHit405Dlg::OnDestroy() 
{
	SaveInfo("CHit405Dlg",GetParentFrame());
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}
