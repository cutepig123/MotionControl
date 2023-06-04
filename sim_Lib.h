#define RESET 		0x00
#define PORT12 		0x06
#define DFH			0x02
#define SIP 		0x03
#define LPEI    	0x1b
#define LPES    	0x1a
#define SBPA		0x20
#define SBPR 		0x21
#define MSKI		0x1c
#define RSTI		0x1d
#define LFIL		0x1e
#define UDF			0x04
#define LTRJ		0x1f
#define STT			0x01
#define RDSIGS		0x0c
#define RDIP		0x09
#define RDDP		0x08
#define RDRP		0x0a
#define RDDV		0x07
#define RDRV		0x0b
#define RDSUM		0x0d

//初始化函数
int set_base_address(int base_address){return 0;}
int set_axis(int number){return 0;} 
int reset_6501(void){return 0;} 
int set_DAC(void){return 0;} 
int set_PWM(void){return 0;} 
int set_home(void){return 0;} 
//中断控制函数 
int set_index_pos(void){return 0;}
int set_pos_err(unsigned int position_error){return 0;}
int set_pos_err_stop(unsigned int position_for_stopping){return 0;}
int set_abs_brk(long absolute_breakpoint){return 0;}
int set_rela_brk(long relative_breakpoint){return 0;}
int set_intrpt_mask(int mask_byte){return 0;}
int reset_intrpt(int reset_byte){return 0;}
//PID参数控制函数
int set_PID(int kp,int ki,int kd,int il,int filter_control_word){return 0;}
int update_PID(void){return 0;}
//轨迹控制函数
int set_motion(long acc,long velocity,long position,int trajectory_control_word){return 0;}
int start_motion(void){return 0;}
//运动状态读写函数
int get_status(void){return 0;}
int get_signals(void){return 0;}
long get_index_pos(void){return 0;}
long get_desire_pos(void){return 0;}
long get_real_pos(void){return 0;}
unsigned long get_desire_vel(void){return 0;}//返回希望速度的单位: 脉冲数/秒
unsigned int get_real_vel(void){return 0;}
int get_isum(void){return 0;}
//辅助功能函数
int encoder_ini(void){return 0;}
int get_encoder(void){return 0;}
int get_input(void){return 0;}
int set_out(int output_value){return 0;}
 