#ifndef _TASK_INIT_H
#define _TASK_INIT_H

#include "headfile.h"


//任务优先级
#define TASK_CONTROL_PRIO		3
//任务堆栈大小	
#define TASK_CONTROL_SIZE 		256  
//任务句柄
extern TaskHandle_t Task_Control_Handler;
//任务函数
void Task_Control(void *pvParameters);

//任务优先级
#define TASK_CAMERA_PRIO		4
//任务堆栈大小	
#define TASK_CAMERA_SIZE 		256  
//任务句柄
extern TaskHandle_t Task_Camera_Handler;
//任务函数
void Task_Camera(void *pvParameters);

//任务优先级
#define TASK_UI_PRIO		2
//任务堆栈大小	
#define TASK_UI_SIZE 		256  
//任务句柄
extern TaskHandle_t Task_UI_Handler;
//任务函数
void Task_UI(void *pvParameters);

void    task_init(void);

#endif
