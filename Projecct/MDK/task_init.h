#ifndef _TASK_INIT_H
#define _TASK_INIT_H

#include "headfile.h"


//�������ȼ�
#define TASK_CONTROL_PRIO		3
//�����ջ��С	
#define TASK_CONTROL_SIZE 		256  
//������
extern TaskHandle_t Task_Control_Handler;
//������
void Task_Control(void *pvParameters);

//�������ȼ�
#define TASK_CAMERA_PRIO		4
//�����ջ��С	
#define TASK_CAMERA_SIZE 		256  
//������
extern TaskHandle_t Task_Camera_Handler;
//������
void Task_Camera(void *pvParameters);

//�������ȼ�
#define TASK_UI_PRIO		2
//�����ջ��С	
#define TASK_UI_SIZE 		256  
//������
extern TaskHandle_t Task_UI_Handler;
//������
void Task_UI(void *pvParameters);

void    task_init(void);

#endif
