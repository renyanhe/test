#include "task_control.h"

/**
* @brief ��̨-����&״̬ת��.
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
	
	
