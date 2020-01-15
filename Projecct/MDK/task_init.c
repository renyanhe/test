#include "task_init.h"

TaskHandle_t 	Task_Control_Handler;
TaskHandle_t 	Task_Camera_Handler;
TaskHandle_t    Task_UI_Handler;

extern TaskHandle_t    Task_Init_Handler;

//开始任务任务函数
void Task_Init(void *pvParameters)
{
    taskENTER_CRITICAL();           //进入临界区
	
	//创建控制任务
    xTaskCreate((TaskFunction_t )Task_Control,     	
                (const char*    )"Task_Control",   	
                (uint16_t       )TASK_CONTROL_SIZE, 
                (void*          )NULL,				
                (UBaseType_t    )TASK_CONTROL_PRIO,	
                (TaskHandle_t*  )&Task_Control_Handler);   
    //创建视觉任务
    xTaskCreate((TaskFunction_t )Task_Camera,             
                (const char*    )"Task_Camera",           
                (uint16_t       )TASK_CAMERA_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )TASK_CAMERA_PRIO,        
                (TaskHandle_t*  )&Task_Camera_Handler);  
    //创建UI任务
    xTaskCreate((TaskFunction_t )Task_UI,             
                (const char*    )"Task_UI",           
                (uint16_t       )TASK_UI_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )TASK_UI_PRIO,        
                (TaskHandle_t*  )&Task_UI_Handler); 								
    vTaskDelete(Task_Init_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}

