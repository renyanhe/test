#include "pid.h"

//PID���£����������PID�ṹ�壬Ŀ��ֵ����ǰֵ��
//����ֵΪPID���
float PID_Update_Incre(PID_IncreType* PID,float tar,float cur)
{
	float ep,ei,ed;

	PID->e0 =tar - cur;  //��ȡ���ڵ�������kp����
	
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
	PID->kp = kp;//����
	PID->ki = ki;//����
	PID->kd = kd;//΢��
	PID->e0 = 0;
	PID->e1 = 0;
	PID->e2 = 0;
	PID->limit = out_max;
	PID->out = 0;
}
