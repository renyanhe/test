#include "task_control.h"

/**
* @brief 后台-控制&状态转换.
* @param argument: Not used
* @retval None
*/
void Task_Control()
{
	for(;;)
	{
		gpio_turn(A14);
	
		vTaskDelay(2000);
	}
}
	
	
