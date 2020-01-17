#ifndef _TASK_CONTROL_H
#define _TASK_CONTROL_H

#include "headfile.h"

typedef enum
{
    wait ,//����
		prepare ,//׼��
    move ,//����
}StateStatus;

typedef struct _wheel_t
{
	 volatile int16_t Cur_postion;//��ǰλ��
	 volatile int16_t Cur_speed;
	 PID_IncreType PID_Speed;
	 PID_IncreType PID_Postion;
	 volatile int16_t Tar_speed;
	 volatile int16_t Tar_Postion;//Ŀ��λ��
	 uint32 speed_out;//ռ�ձ�
	 int16 data1,data2;//����������
} wheel_t;//�Ժ��ֵĽṹ��
wheel_t wheel_back;

void Task_Control();

#endif

