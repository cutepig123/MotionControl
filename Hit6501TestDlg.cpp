// Hit6501TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Resource.h"
#include "Hit6501TestDlg.h"

#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define printf AddText


#define DIR_FORWARD 1
#define DIR_BACKWARD  2
//用于ListView中显示电机的状态
char szInfo[3][20]={
	{"停止"},{"前进"},{"后退"},
};

//电机和轴的对应信息（因为在接线时接得比较乱）

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


/////////////////////////////////////////////////////////////////////////////
// CHit6501TestDlg dialog

CHit6501TestDlg::CHit6501TestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHit6501TestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHit6501TestDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHit6501TestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHit6501TestDlg)
	DDX_Control(pDX, IDC_COMBO_MOTOR, m_MotorCombo);
	DDX_Control(pDX, IDC_LIST_MOTOR, m_MotorList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHit6501TestDlg, CDialog)
	//{{AFX_MSG_MAP(CHit6501TestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST_MOTOR, OnClickListMotor)
	ON_CBN_SELENDOK(IDC_COMBO_MOTOR, OnSelendokComboMotor)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHit6501TestDlg message handlers

BOOL CHit6501TestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	OnButtonStop();

	for(int i=0;i<6;i++)
	{
		motor_data[i].vel=10000;//GetDlgItemInt(IDC_EDIT_VEL);
	}
	//初始化ListView
	m_MotorList.SetExtendedStyle(m_MotorList.GetExtendedStyle()| LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	
	m_MotorList.InsertColumn(0, "电机", LVCFMT_LEFT, 30);
	m_MotorList.InsertColumn(1, "状态", LVCFMT_LEFT, 40);
	m_MotorList.InsertColumn(2, "设速", LVCFMT_LEFT, 50);
	m_MotorList.InsertColumn(3, "实速", LVCFMT_LEFT, 50);
#ifdef DBG_VEL_AVG		
	m_MotorList.InsertColumn(4, "均速", LVCFMT_LEFT, 50);
#endif
	//m_MotorList.InsertColumn(2, "地址", LVCFMT_LEFT, 40);
	//m_MotorList.InsertColumn(3, "轴", LVCFMT_LEFT, 30);
	m_MotorList.DeleteAllItems ();
	
	for(i=1;i<=6;i++)
	{
		char s[10];
		sprintf(s,"%d",i);
		m_MotorList.InsertItem(i,s);
		m_MotorList.SetItemText(i-1,1,szInfo[DIR_FORWARD]);
		m_MotorList.SetItemText(i-1,2,itoa(motor_data[i-1].vel,s,10));
		//m_MotorList.SetItemText(i-1,2,itoa(motor_data[i-1].baseaddr,s,10));
		//m_MotorList.SetItemText(i-1,3,itoa(motor_data[i-1].axis,s,10));

		m_MotorList.SetItemData(i-1,DIR_FORWARD);
	}

	//chushihua COmboBox	
	for (i=0;i<3;i++)
	{
		m_MotorCombo.InsertString(i,szInfo[i]);
	}
	m_MotorCombo.InsertString(i++,"全部前进");
	m_MotorCombo.InsertString(i++,"全部后退");
	m_MotorCombo.InsertString(i++,"3进3退");
	m_MotorCombo.InsertString(i++,"3退3进");
	m_MotorCombo.InsertString(i++,"左转弯");
	m_MotorCombo.InsertString(i++,"右转弯");
	//初始化Enable,Velocity编辑框的初始值
	SetDlgItemInt(IDC_EDIT_ENABLE,255);
	SetDlgItemInt(IDC_EDIT_VEL,10000);
	SetDlgItemInt(IDC_EDIT_RADIUS,0);
	m_MotorCombo.SetCurSel(DIR_FORWARD);

	AddText("Init ok\r\r\n");

	StartProc();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CHit6501TestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHit6501TestDlg::OnPaint() 
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
HCURSOR CHit6501TestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//点击ListView时，COmboBox对应着改变
void CHit6501TestDlg::OnClickListMotor(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	POSITION pos=m_MotorList.GetFirstSelectedItemPosition();
	while(pos)
	{
		int nItem=m_MotorList.GetNextSelectedItem(pos);
		DWORD dwIdx=m_MotorList.GetItemData(nItem);
		TRACE("dwIdx:%d,%s\r\n",dwIdx,szInfo[dwIdx]);
		m_MotorCombo.SetCurSel(dwIdx);
	}
	*pResult = 0;
}

//选好ComboBox时 更新ListView中的状态
void CHit6501TestDlg::OnSelendokComboMotor() 
{
	// TODO: Add your control notification handler code here
	//MessageBox("S");
	int cursel=m_MotorCombo.GetCurSel();
	if(cursel<3)
	{
		POSITION pos=m_MotorList.GetFirstSelectedItemPosition();
		if(!pos)
		{	MessageBox("请选择一个或多个电机");
			return;
		}
		
		while(pos)
		{
			int nItem=m_MotorList.GetNextSelectedItem(pos);
			m_MotorList.SetItemData(nItem,cursel);
			m_MotorList.SetItemText(nItem,1,szInfo[cursel]);

			char s[20];
			sprintf(s,"%6d",motor_data[nItem].vel);
			m_MotorList.SetItemText(nItem,2,s);
			//TRACE("dwIdx:%d,%s\r\n",dwIdx,szInfo[dwIdx]);
		}
		
		

	}
	else if(cursel==3)//前进 
	{
		for(int i=0;i<6;i++)
		{
			m_MotorList.SetItemText(i,1,szInfo[DIR_FORWARD]);
			m_MotorList.SetItemData(i,DIR_FORWARD);
		}
		for( i=0;i<6;i++)
		{
			char s[20];
			sprintf(s,"%6d",motor_data[i].vel);
			m_MotorList.SetItemText(i,2,s);
		}
	}
	else if(cursel==4)//后退
	{
		for(int i=0;i<6;i++)
		{
			m_MotorList.SetItemText(i,1,szInfo[DIR_BACKWARD]);
			m_MotorList.SetItemData(i,DIR_BACKWARD);
		}
		for( i=0;i<6;i++)
		{
			char s[20];
			sprintf(s,"%6d",motor_data[i].vel);
			m_MotorList.SetItemText(i,2,s);
		}
	}
	else if(cursel==5)//3f3b
	{
		for(int i=0;i<3;i++)
		{
			m_MotorList.SetItemText(i,1,szInfo[DIR_FORWARD]);
			m_MotorList.SetItemData(i,DIR_FORWARD);
		}
		for(i=3;i<6;i++)
		{
			m_MotorList.SetItemText(i,1,szInfo[DIR_BACKWARD]);
			m_MotorList.SetItemData(i,DIR_BACKWARD);
		}
	}
	else if(cursel==6)//3b3f
	{
		for(int i=0;i<3;i++)
		{
			m_MotorList.SetItemText(i,1,szInfo[DIR_BACKWARD]);
			m_MotorList.SetItemData(i,DIR_BACKWARD);
		}
		for(i=3;i<6;i++)
		{
			m_MotorList.SetItemText(i,1,szInfo[DIR_FORWARD]);
			m_MotorList.SetItemData(i,DIR_FORWARD);
		}
	}
	else if(cursel==7)//左转弯
	{
	}
	else if(cursel==8)//右转弯
	{
		int i;
		int v=GetDlgItemInt(IDC_EDIT_VEL);
		double p;
		char szR[100];
		GetDlgItemText(IDC_EDIT_RADIUS,szR,100);
		p=atof(szR);
		
		
#define PI 3.1415926
		AddText("右转弯R=%f,V=%d\r\n",p,v);
		if(v<=0 || v>90000 || p<=0 )
			MessageBox("半径或者速度不对");
		else
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
				motor_data[i].vel=(int)W_Velocity[i];
			}
			
			///
			for(i=0;i<6;i++)
			{
				m_MotorList.SetItemText(i,1,szInfo[DIR_FORWARD]);
				m_MotorList.SetItemData(i,DIR_FORWARD);
			}

			for(int i=0;i<6;i++)
			{
				char s[20];
				sprintf(s,"%6d",motor_data[i].vel);
				m_MotorList.SetItemText(i,2,s);
			}
			
			int V=GetDlgItemInt(IDC_EDIT_VEL);
			for( i=0;i<6;i++)
			{
				motor_data[i].vel=V;
			}
		}
		
	}
	
//	if(cursel>=0 && cursel<7)
//	{
//		int V=GetDlgItemInt(IDC_EDIT_VEL);
//		for(int i=0;i<6;i++)
//		{
//			motor_data[i].vel=V;
//		}
//	}

}

//启动电机
void CHit6501TestDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	
	int i;
	long vel=0;//=GetDlgItemInt(IDC_EDIT_VEL);
	int ienable=GetDlgItemInt(IDC_EDIT_ENABLE);

	

	printf("使能.%d,速度%d\r\n",ienable,vel);
	set_base_address(0x340);
	set_out(ienable);

	set_base_address(0x380);
	set_out(ienable);

	
	for (i=0;i<6 ;i++ )
	{

		set_base_address(motor_data[i].baseaddr);
		int imstate=m_MotorList.GetItemData(i);
		if(imstate<0||imstate>2)
		{
			MessageBox("程序有错误");
			ExitProcess(0);
		}
		AddText("电机%d,状态%s\r\n",i,szInfo[imstate]);
		set_axis(motor_data[i].axis);//设置当前轴
		reset_6501();//对6501进行复位
		set_DAC();//将输出设置为DAC输出方式
		set_PID(1,0,0,10000,0x0f);//设置PID参数
		update_PID();//使PID参数生效
		vel=motor_data[i].vel;
		if(imstate==1 )
			set_motion(80000,vel,0,motor_data[i].forward_cmd);
		else if(imstate==2)
			set_motion(80000,vel,0,motor_data[i].backward_cmd);
		start_motion();

	}
	SetTimer(1,1000,0);
}


void CHit6501TestDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	int i;
	printf("\r\n");
/*	set_base_address(0x340);
	set_out(0);

	set_base_address(0x380);
	set_out(0);
*/
	for (i=0;i<6 ;i++ )
	{
		set_base_address(motor_data[i].baseaddr);
		
		{
			printf("%d ",i);
			set_axis(motor_data[i].axis);//设置当前轴
			reset_6501();//对6501进行复位
			set_DAC();//将输出设置为DAC输出方式
			set_motion(0,0,0,0x100);//设置轨迹参数
			start_motion();//平滑停车
		}
		
	}
	printf("stopped\r\n");
	KillTimer(1);
}

void CHit6501TestDlg::AddText(char *szFormat, ...)
{
	CString s;
	GetDlgItemText(IDC_EDIT_DBGINFO,s);
	
	va_list l;
	char stmp[2000]="\0";
	va_start(l,szFormat);
	vsprintf(stmp,szFormat,l);

	if(s.GetLength()>2000)
		s=stmp;
	else
		s=(CString)stmp+s;

	SetDlgItemText(IDC_EDIT_DBGINFO,s);
}
//打印电机状态
void CHit6501TestDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
	{
		int i;
		char s[100];
#ifdef DBG_VEL_AVG		
		static double motor_vel_sum[6]={0,0,0,0,0,0};
		static ULONG cnt=0;
		cnt++;
#endif
		for (i=0;i<6 ;i++ )
		{
			set_base_address(motor_data[i].baseaddr);
			set_axis(motor_data[i].axis);
			AddText("%4d%8d/%d%8d/%d\r\n",
				i,get_real_vel(),get_desire_vel(),get_real_pos(),get_desire_pos());
			sprintf(s,"%6d",get_real_vel());
			m_MotorList.SetItemText(i,3,s);

#ifdef DBG_VEL_AVG					
			motor_vel_sum[i]+=get_real_vel();
			sprintf(s,"%6d",(ULONG)(motor_vel_sum[i]/cnt));
			m_MotorList.SetItemText(i,4,s);
#endif
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CHit6501TestDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	

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
	TerminateThread(m_hThread,0);
}


DWORD WINAPI CHit6501TestDlg::CheckVelProc()	//检查堵转情况
{
	int i,k;
	while (1) 
	{
		TRACE("Enter Thread CHit405View::CheckVelProc");
		for (k=0;k<6 ;k++ )
		{
			set_base_address(motor_data[k].baseaddr);
			set_axis(motor_data[k].axis);
			ULONG dv=get_desire_vel();
			ULONG rv=0;
			if(dv>5000)
			{
				rv=get_real_vel();
				if(rv<1000)
				{
					for (i=0;i<=k;i++) 
					{
						Beep(1000,150);
						Sleep(50);
					}
					Sleep(500);
				}
			}
		}

		Sleep(1000);
	}
}

void CHit6501TestDlg::StartProc()
{
	DWORD (WINAPI CHit6501TestDlg::*p1)()=CheckVelProc;
	DWORD (WINAPI *p2)(LPVOID)=0;
	memcpy(&p2,&p1,sizeof(p1));
	m_hThread =::CreateThread(0,0,p2,this,0,0);
}