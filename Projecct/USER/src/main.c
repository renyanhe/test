/********************************************
============================================
    串口  
    波特率 115200 
    数据位 8 
    校验位 无
    停止位 1位
    流控   无
	串口连接注意事项：切勿使用蓝牙等无线串口连接
    RX                  PTD3
    TX                  PTD2
============================================
   
*********************************************/  
#include "headfile.h"
#include "task_init.h"
#include <string.h>

//任务优先级
#define TASK_INIT_PRIO		1
//任务堆栈大小	
#define TASK_INIT_SIZE 		256  
//任务句柄
TaskHandle_t Task_Init_Handler;
//任务函数
void Task_Init(void *pvParameters);

int main(void)
{      
  get_clk();//上电后必须运行一次这个函数，获取各个频率信息，便于后面各个模块的参数设置
	
	EnableInterrupts;
	uart_init(uart2,115200);//初始化串口2，波特率为115200，引脚对应查看MK60DN10_port_cfg.h
	gpio_init(A14,GPO,0);gpio_init(A15,GPO,1);gpio_init(A16,GPO,0);gpio_init(A17,GPO,1);
	
	//创建开始任务
  xTaskCreate((TaskFunction_t )Task_Init,            //任务函数
              (const char*    )"Task_Init",          //任务名称
              (uint16_t       )TASK_INIT_SIZE,        //任务堆栈大小
              (void*          )NULL,                  //传递给任务函数的参数
              (UBaseType_t    )TASK_INIT_PRIO,       //任务优先级
              (TaskHandle_t*  )&Task_Init_Handler);   //任务句柄              
  vTaskStartScheduler();          //开启任务调度

}




