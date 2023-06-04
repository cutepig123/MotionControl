#include "StdAfx.h"
#include "DirectPort.h"
#include <windows.h>
#include <stdlib.h>
#include "lib.h"

#define st	 341e-6


int servo_ready(void);
int send16(int port, int data);
int send32(long count);
int send_acc(long acc);
int send_velocity(long velocity);//velocity的单位: 脉冲数/秒
int send_position(long position);//position的单位: 脉冲数

int command_port=0x340,board_base_address=0x340;
unsigned int last_get_value=0;
long encoder_value=0;

#ifdef _SIMULATE_
bool bTestMode=true;
#else
bool bTestMode=false;
#endif

void SetTestMode(int bTest)
{
	bTestMode=(bTest!=0);
}

//初始化函数
//函数1：set_base_address
int set_base_address(int base_address)
{
	board_base_address=base_address;
	return 0;
}

//函数2：set_axis
int set_axis(int number)
{
	if(number<1 || number>3) return -1;
	command_port=board_base_address+2*(number-1);
	return 0;
}

//函数3：reset_6501
int reset_6501(void)
{
	servo_ready();
	DP_OutpB (command_port,RESET);
	return 0;
}

//函数4：set_DAC
int set_DAC(void)
{
	servo_ready();
	DP_OutpB (command_port,PORT12);
	return 0;
}

//函数5：set_PWM
int set_PWM(void)
{
	servo_ready();
	DP_OutpB (command_port,5);
	return 0;
}

//函数6：set_home
int set_home(void)
{
	servo_ready();
	DP_OutpB (command_port,DFH);
	return 0;
}

//中断控制函数
//函数1：set_index_pos
int set_index_pos(void)
{
	servo_ready();
	DP_OutpB (command_port,SIP);
	return 0;
}

//函数2：set_pos_err
int set_pos_err(unsigned int position_error)
{
	if(position_error>0x7fff) return -1;
	servo_ready();
	DP_OutpB (command_port,LPEI);
	servo_ready();
	send16(command_port+1,position_error);
	return 0;
}

//函数3：set_pos_err_stop
int set_pos_err_stop(unsigned int position_for_stopping)
{
	if(position_for_stopping>0x7fff) return -1;
 	servo_ready();
	DP_OutpB (command_port,LPES);
	servo_ready();
	send16(command_port+1,position_for_stopping);
	return 0;
}

//函数4：set_abs_brk
int set_abs_brk(long absolute_breakpoint)
{
	if(absolute_breakpoint<-2e30 || absolute_breakpoint>0X3fffffff) return -1;
	servo_ready();
	DP_OutpB (command_port,SBPA);
	servo_ready();
	send_position(absolute_breakpoint);
	return 0;
}

//函数5:set_rela_brk
int set_rela_brk(long relative_breakpoint)
{
	long w;

	if(relative_breakpoint<-2e30 || relative_breakpoint>0x3fffffff) return -1;
	w=get_real_pos();
	if(w+relative_breakpoint<-2e30 || w+relative_breakpoint>0x3fffffff) return -1;
		
	servo_ready();
	DP_OutpB (command_port,SBPR);
	servo_ready();
	send_position(relative_breakpoint);
	return 0;
}

//函数6:set_intrpt_mask
int set_intrpt_mask(int mask_byte)
{
	servo_ready();
	DP_OutpB (command_port,MSKI);
	servo_ready();
	send16(command_port+1,mask_byte);
	return 0;
}

//函数7:reset_intrpt
int reset_intrpt(int reset_byte)
{
	servo_ready();
	DP_OutpB (command_port,RSTI);
	servo_ready();
	send16(command_port+1,reset_byte);
	return 0;
}

//PID参数控制函数
//函数1: set_PID
int set_PID(int kp,int ki,int kd,int il,int filter_control_word)
{
	servo_ready();
	DP_OutpB (command_port,LFIL);
	send16(command_port+1,filter_control_word);
	if(filter_control_word&0x8)	send16(command_port+1,kp);
	if(filter_control_word&0x4)	send16(command_port+1,ki);
	if(filter_control_word&0x2)	send16(command_port+1,kd);
	if(filter_control_word&0x1)	send16(command_port+1,il);
	return 0;
}

//函数2: update_PID
int update_PID(void)
{
      servo_ready();
      DP_OutpB (command_port,UDF);
      return 0;
}

//轨迹控制函数
//函数3: set_motion
int set_motion(long acc,long velocity,long position,int trajectory_control_word)
{
      servo_ready();
      DP_OutpB (command_port,LTRJ);
      send16(command_port+1,trajectory_control_word);
      if(trajectory_control_word&0x20 ||
	 trajectory_control_word&0x10)  send_acc(acc);
      if(trajectory_control_word&0x08 ||
	 trajectory_control_word&0x04) 	send_velocity(velocity);
      if(trajectory_control_word&0x02 ||
	 trajectory_control_word&0x01) 	send_position(position);
      return 0;
}

//函数4: start_motion
int start_motion(void)
{
	servo_ready();
	DP_OutpB (command_port,STT);
	return 0;
}

//运动状态读写函数
//函数1: get_status
int get_status(void)
{
//	servo_ready();
	return DP_InpB(command_port)&0xff;
}

//函数2: get_signals
int get_signals(void)
{
      int stat;
      servo_ready();
      DP_OutpB(command_port,RDSIGS);
      servo_ready();
      stat=DP_InpB(command_port+1);
      servo_ready();
      stat=stat*256+DP_InpB(command_port+1);
      return stat;
}

//函数3: get_index_pos
long get_index_pos(void)
{
	long count=0;
	unsigned char countb=0;
	int i;

	servo_ready();
	DP_OutpB(command_port,RDIP);
	for(i=1;i<=4;i++)
	{
		servo_ready();
		countb=DP_InpB(command_port+1);
		count=_lrotl(count,8)|countb;
	}
	return count;
}

//函数4: get_desire_pos
long get_desire_pos(void)
{
	long count=0;
	unsigned char countb=0;
	int i;

	servo_ready();
	DP_OutpB(command_port,RDDP);
	for(i=1;i<=4;i++)
	{
		servo_ready();
		countb=DP_InpB(command_port+1);
		count=_lrotl(count,8)|countb;
	}
	return count;
}

//函数5: get_real_pos
long get_real_pos(void)
{

	long count=0;
	unsigned char countb=0;
	int i;

	servo_ready();
	DP_OutpB(command_port,RDRP);
	for(i=1;i<=4;i++)
	{
		servo_ready();
		countb=DP_InpB(command_port+1);
		count=_lrotl(count,8)|countb;
	}
	return count;
}

//函数6: get_desire_vel
unsigned long get_desire_vel(void)//返回希望速度的单位: 脉冲数/秒
{
      int i;
      long count=0;
      unsigned char countb=0;
	  double w;

      servo_ready();
      DP_OutpB(command_port,RDDV);
      servo_ready();
      for(i=0;i<4;i++)
      {
		servo_ready();
		countb=DP_InpB(command_port+1);
		count=_lrotl(count,8)|countb;
      }
	  w=count/(65536.0*st);
      return w;
}

//函数7: get_real_vel
unsigned int get_real_vel(void)
{
      int i;
      int count=0;
      unsigned char countb=0;

      servo_ready();
      DP_OutpB(command_port,RDRV);
      servo_ready();
      for(i=0;i<2;i++)
      {
		servo_ready();
		countb=DP_InpB(command_port+1);
		count=_rotl(count,8)|countb;
      }
      return (1.0*count/st);
}

//函数8: get_isum
int get_isum(void)
{
      int sum;
      servo_ready();
      DP_OutpB(command_port,RDSUM);
      servo_ready();
      sum=DP_InpB(command_port+1);
      servo_ready();
      sum=sum*256+DP_InpB(command_port+1);
      return sum;
}

//辅助功能函数
//函数1：encoder_ini
int encoder_ini(void)
{
	last_get_value=(DP_InpB(board_base_address+10)<<8)|
	(DP_InpB(board_base_address+11)&0xff);
	return 0;
}

//函数2：get_encoder
int get_encoder(void)
{
	unsigned char 	low_byte,high_byte;
	unsigned int   	recent_get_value;
	int		return_value;

	high_byte=DP_InpB(board_base_address+10);
	low_byte =DP_InpB(board_base_address+11);
	recent_get_value=(high_byte<<8)|(low_byte&0xff);
	return_value=recent_get_value-last_get_value;
	if(return_value>30000)
	{
		return_value=65536-last_get_value+recent_get_value;
	}
	if(return_value<-30000)
	{
		return_value=-recent_get_value+last_get_value;
	}
	last_get_value=recent_get_value;
	encoder_value+=return_value;
	return 0;
}

//函数3：get_input
int get_input(void)
{
	return DP_InpB(board_base_address+6);
}

//函数4：set_out
int set_out(int output_value)
{
	DP_OutpB(board_base_address+8,output_value);
	return 0;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//以下是子函数

int servo_ready(void)
{
#ifndef _SIMULATE

	if(!bTestMode)
		while(DP_InpB(command_port)&0x01);
	else
	{
		
		int N=10,i=0;
		while((DP_InpB(command_port)&0x01) && (i++<N))
			Sleep(1);
		if(i>=N)
			OutputDebugString("超时 in TestMode");
	}
#endif
	return 0;
}

//
/*
int send16(int port, int data)
{
	int i;

	servo_ready();
	for (i=0;i<2;i++)
	{
	   DP_OutpB(port,data=_rotl(data,8));
	}
	return 0;
}
*/
int send16(int port, int data)
{
	int w1,w2;

	w1=(data>>8)&0xff;
	w2=data&0xff;
	servo_ready();
	DP_OutpB(port,w1);
	servo_ready();
	DP_OutpB(port,w2);
	return 0;
}
//
/*
int send32(long count)
{
	int i;

	for(i=0;i<2;i++)
	send16(command_port+1,count=_lrotl(count,16));
	return 0;
}
*/
int send32(long count)
{
	int w1,w2,w3,w4;

	w1=(count>>24)&0xff;
	w2=(count>>16)&0xff;
	w3=(count>>8)&0xff;
	w4=count&0xff;
	servo_ready();
	DP_OutpB(command_port+1,w1);
	servo_ready();
	DP_OutpB(command_port+1,w2);
	servo_ready();
	DP_OutpB(command_port+1,w3);
	servo_ready();
	DP_OutpB(command_port+1,w4);
	return 0;
}
//
int send_acc(long acc)
{
	long w;
	w=65536.0*st*st*acc;
	if(w<1 || w>0x3fffffff) return -1;
	send32(w);
	return 0;
}

//
int send_velocity(long velocity)//velocity的单位: 脉冲数/秒
{
	long w;
	w=65536.0*st*velocity;
	if(w<1 || w>0x3fffffff) return -1;
	send32(w);
	return 0;
}

//
int send_position(long position)//position的单位: 脉冲数
{
long w=0xc0000000;
	if(position<w ||position>0x3fffffff) return -1;
	send32(position);
	return 0;
}

