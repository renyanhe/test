#ifndef _PID_H
#define _PID_H

#include "headfile.h"

typedef struct 
{
	float limit;
	float kp;
	float ki;
	float kd;
	float e0;
	float e1;
	float e2;
	float out;
} PID_IncreType;//ÔöÁ¿Ê½PID

void PID_Struct_Init(PID_IncreType* PID,float kp,float ki,float kd,float out_max);
float PID_Update_Incre(PID_IncreType* PID,float tar,float cur);

#endif

