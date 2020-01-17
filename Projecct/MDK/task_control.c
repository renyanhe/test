#include "task_control.h"

uint16 xlimit;//距离阈值

void Init_control()
{
	 //舵机
	 ftm_quad_init(ftm1);//初始化ftm1为正交解码	引脚对应查看MK60DN10_port_cfg.h
	 ftm_quad_init(ftm2);//初始化ftm2为正交解码	引脚对应查看MK60DN10_port_cfg.h
	 //初始化ftm0模块，通道为50HZ，占空比为百分之50，默认精度为1000 引脚对应查看MK60DN10_port_cfg.h
	 ftm_pwm_init(ftm0,ftm_ch4,50,500);
	 ftm_pwm_init(ftm0,ftm_ch5,50,500);
	 ftm_pwm_init(ftm0,ftm_ch6,50,500);
	 ftm_pwm_init(ftm0,ftm_ch7,50,500);
	 //pid部分
	 PID_Struct_Init(&wheel_back.PID_Postion,1,0.01,0,1000);
	 PID_Struct_Init(&wheel_back.PID_Speed ,1,0.01,0,1000);
}

void Updata_out()
{
//	 wheel_back.Cur_postion = ;当前位置获取
	 if((wheel_back.Cur_postion - wheel_back.Tar_Postion > xlimit) || ((wheel_back.Tar_Postion - wheel_back.Cur_postion > xlimit)))
	 {
		  wheel_back.Tar_speed = 800;//80%满速
	 }
	 else
	 {
		  wheel_back.Tar_speed = PID_Update_Incre(&wheel_back.PID_Postion,wheel_back.Tar_Postion,wheel_back.Cur_postion);
	 }
	 wheel_back.speed_out = PID_Update_Incre(&wheel_back.PID_Speed,wheel_back.Tar_speed,wheel_back.Cur_speed);
}

void ReadKeyStatus(void)//状态机
{
	 static StateStatus state = wait;//待机初始
	
	 //pass=状态转换
	
	 switch(state)
	 {
		  case wait:
				 gpio_init(A14,GPO,1);
				 state = move;
				 break;
			case prepare:
				 break;
			case move:
				 if(1)//判断条件
				 {
					  gpio_turn(A15);
					  vTaskDelay(1500);
					  wheel_back.speed_out = 500;//测试用
					  ftm_pwm_duty(ftm0,ftm_ch4,wheel_back.speed_out);
					  ftm_pwm_duty(ftm0,ftm_ch5,wheel_back.speed_out);
					  ftm_pwm_duty(ftm0,ftm_ch6,wheel_back.speed_out);
					  ftm_pwm_duty(ftm0,ftm_ch7,wheel_back.speed_out);
					  //设置ftm0模块，通道占空比为百分之10，占空比 = speed_out/FTM0_PRECISON;				  
					  wheel_back.data1 = ftm_quad_get(ftm1);	//获取ftm1正交解码的值
		        wheel_back.data2 = ftm_quad_get(ftm2);	//获取ftm2正交解码的值
					  uart_putchar(uart2,0x5a);   //uart3发送 0x5a
		        uart_querychar(uart2,(uint8*)&wheel_back.data1);
			      uart_querychar(uart2,(uint8*)&wheel_back.data2);//使用查询方式接受串口数据
					  ftm_quad_clean(ftm1);		//清除ftm1正交解码的值
						ftm_quad_clean(ftm2);		//清除ftm2正交解码的值
				 }
				 break;
	 }
}

void Task_Control()
{
	 Init_control();
	 while(1)
	 {
		  Updata_out();
	    ReadKeyStatus();
		 
		  vTaskDelay(1);
	 }
}
	
	
