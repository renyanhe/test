#ifndef __CPUSTATE_H__
#define __CPUSTATE_H__

#define OS_TASK_STAT_EN	1//开启统计任务


#if OS_TASK_STAT_EN>0
#define ABS(x) (x)>=0?(x):(-x)//定义绝对值
/*-----------------------------------------------------------------------------------------*/

#define TaskStat_STACK_SIZE	( ( unsigned short ) 86 ) //统计任务的堆栈大小
#define STAT_TASK_PRIO tskIDLE_PRIORITY+1//统计任务的优先级，仅仅高于统计任务
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
