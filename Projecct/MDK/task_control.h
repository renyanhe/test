#ifndef _TASK_CONTROL_H
#define _TASK_CONTROL_H

#include "headfile.h"

typedef enum
{
    wait ,//待机
		prepare ,//准备
    move ,//运行
}StateStatus;

typedef struct _wheel_t
{
	 volatile int16_t Cur_postion;//当前位置
	 volatile int16_t Cur_speed;
	 PID_IncreType PID_Speed;
	 PID_IncreType PID_Postion;
	 volatile int16_t Tar_speed;
	 volatile int16_t Tar_Postion;//目标位置
	 uint32 speed_out;//占空比
	 int16 data1,data2;//编码器数据
} wheel_t;//对后轮的结构体
wheel_t wheel_back;

void Task_Control();

#endif

