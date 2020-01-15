/*-----------------------------------------------------------------------------------*/
/* �ļ�����  OSState.c
 * ����: ͳ�������ʼ��������ͳ������. 
 *����;lee-2013-6-9
*/
#include "FreeRTOS.h"
#include "task.h"
#include "cpustate.h"
#include "StackMacros.h"

#if OS_TASK_STAT_EN>0

volatile  unsigned int  OSIdleCtr;                                 /* Idle counter                   */
unsigned int      OSIdleCtrMax;             /* Max. value that idle ctr can take in 1 sec.     */
unsigned int      OSIdleCtrRun;             /* Val. reached by idle ctr at run time in 1 sec.  */
float     OSCPUUsage;               /* Percentage of CPU used  */
void OS_TaskStat(void * pvParameters);//ͳ������

#if OS_TASK_STAT_EN>0

/*-----------------------------------------------------------------------------------*/
/* ��������  OSStatInit
 * ��������: ͳ�������ʼ��������ͳ������. 
 *   ��ڲ�����
 *  ��
 *ע����������������ڿ��к������ú�����������û����ǰ���ã���
 *   ���ز�������
 *����;lee-2013-6-9
*/
void  OSStatInit (void)
{
	  taskENTER_CRITICAL();						 //���ж�
      OSIdleCtr    = 0;                          /* Clear idle counter                                 */
      taskEXIT_CRITICAL();
      vTaskDelay(100);           /* Determine MAX. idle counter value for 1/10 second ,100ms��ʱ */
      taskENTER_CRITICAL();
      OSIdleCtrMax = OSIdleCtr;                    /* Store maximum idle counter count in 1/10 second����ȡ100ms��OSIdleCtrMax�ӵ������ֵ    */
 
      taskEXIT_CRITICAL();						//���ж�


	xTaskCreate(OS_TaskStat, "OS_TaskStat", TaskStat_STACK_SIZE, ( void * ) NULL,STAT_TASK_PRIO, NULL);//����ͳ���������ȼ������ڿ�������
}

void vApplicationIdleHook( void )//��������Ĺ��Ӻ��������е�ʱ�򣬴κ����ᱻִ��
{
   taskENTER_CRITICAL();						 //���ж�
   OSIdleCtr++;//���м�������һ
   taskEXIT_CRITICAL();						//���ж�
}

void OS_TaskStat(void * pvParameters)//ͳ������
{
   	  OSIdleCtrMax /= 100;
    if (OSIdleCtrMax == 0)
	{
       OSCPUUsage = 0;
    }
	    for (;;)
	{
        taskENTER_CRITICAL();
        OSIdleCtrRun = OSIdleCtr;                /* Obtain the of the idle counter for the past second */
        OSIdleCtr    = 0;                      /* Reset the idle counter for the next second         */
        taskEXIT_CRITICAL();	
        OSCPUUsage   = (100 - OSIdleCtrRun /(float) OSIdleCtrMax);
		OSCPUUsage =ABS(OSCPUUsage);//ȡ����ֵ����ֹ�������
        vTaskDelay(100);       /* Accumulate OSIdleCtr for the next 1/10 second   100msͳ��һ��   */
		//STM_EVAL_LEDToggle(LED1);
    }
}
#endif	
#endif /* __CPUSTATE_H__ */
