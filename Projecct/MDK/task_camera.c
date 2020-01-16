#include "task_camera.h"

/**
* @brief 后台-视觉处理.
* @param argument: Not used
* @retval None
*/
void Task_Camera()
{
	camera_init();
	for(;;)
	{
		gpio_turn(A15);
	
		vTaskDelay(1000);
	}
}
	

	