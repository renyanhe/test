#include "pid.h"

//PID更新，输入参数：PID结构体，目标值，当前值；
//返回值为PID输出
float PID_Update_Incre(PID_IncreType* PID,float tar,float cur)
{
	float ep,ei,ed;

	PID->e0 =tar - cur;  //读取现在的误差，用于kp控制
	
	ep = PID->e0 - PID->e1;
	ei = PID->e0;
	ed = PID->e0 - 2*PID->e1 + PID->e2;
	
	PID->out += PID->kp*ep + PID->ki*ei + PID->kd*ed;
	
	PID->e2 = PID->e1;
	PID->e1 = PID->e0;	
	
	return PID->out;
}

void PID_Struct_Init(PID_IncreType* PID,float kp,float ki,float kd,float out_max)
{
	PID->kp = kp;//比例
	PID->ki = ki;//积分
	PID->kd = kd;//微分
	PID->e0 = 0;
	PID->e1 = 0;
	PID->e2 = 0;
	PID->limit = out_max;
	PID->out = 0;
}
