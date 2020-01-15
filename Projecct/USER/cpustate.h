#ifndef __CPUSTATE_H__
#define __CPUSTATE_H__

#define OS_TASK_STAT_EN	1//����ͳ������


#if OS_TASK_STAT_EN>0
#define ABS(x) (x)>=0?(x):(-x)//�������ֵ
/*-----------------------------------------------------------------------------------------*/

#define TaskStat_STACK_SIZE	( ( unsigned short ) 86 ) //ͳ������Ķ�ջ��С
#define STAT_TASK_PRIO tskIDLE_PRIORITY+1//ͳ����������ȼ�����������ͳ������
#define tskIDLE_STACK_SIZE	configMINIMAL_STACK_SIZE

/*-----------------------------------------------------------------------------------------*/
void  OSStatInit (void);
/*-----------------------------------------------------------------------------------------*/
extern  volatile  unsigned int  OSIdleCtr;                                 /* Idle counter                   */
extern  unsigned int      OSIdleCtrMax;             /* Max. value that idle ctr can take in 1 sec.     */
extern  unsigned int      OSIdleCtrRun;             /* Val. reached by idle ctr at run time in 1 sec.  */
extern float      OSCPUUsage;               /* Percentage of CPU used  */

#endif
#endif /* __LWIPOPTS_H__ */
