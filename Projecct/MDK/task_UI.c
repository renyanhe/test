#include "task_UI.h"

/**
* @brief ǰ��-�û�����.
* @param argument: Not used
* @retval None
*/
void Task_UI()
{
	OLED_Init();
//	OLED_Fill(0xFF);
	OLED_P6x8Str(10,10,"lalala");
	for(;;)
	{
		gpio_turn(A16);
	
		vTaskDelay(500);
	}
}
	
	
