#include "task_control.h"

uint16 xlimit;//������ֵ

void Init_control()
{
	 //���
	 ftm_quad_init(ftm1);//��ʼ��ftm1Ϊ��������	���Ŷ�Ӧ�鿴MK60DN10_port_cfg.h
	 ftm_quad_init(ftm2);//��ʼ��ftm2Ϊ��������	���Ŷ�Ӧ�鿴MK60DN10_port_cfg.h
	 //��ʼ��ftm0ģ�飬ͨ��Ϊ50HZ��ռ�ձ�Ϊ�ٷ�֮50��Ĭ�Ͼ���Ϊ1000 ���Ŷ�Ӧ�鿴MK60DN10_port_cfg.h
	 ftm_pwm_init(ftm0,ftm_ch4,50,500);
	 ftm_pwm_init(ftm0,ftm_ch5,50,500);
	 ftm_pwm_init(ftm0,ftm_ch6,50,500);
	 ftm_pwm_init(ftm0,ftm_ch7,50,500);
	 //pid����
	 PID_Struct_Init(&wheel_back.PID_Postion,1,0.01,0,1000);
	 PID_Struct_Init(&wheel_back.PID_Speed ,1,0.01,0,1000);
}

void Updata_out()
{
//	 wheel_back.Cur_postion = ;��ǰλ�û�ȡ
	 if((wheel_back.Cur_postion - wheel_back.Tar_Postion > xlimit) || ((wheel_back.Tar_Postion - wheel_back.Cur_postion > xlimit)))
	 {
		  wheel_back.Tar_speed = 800;//80%����
	 }
	 else
	 {
		  wheel_back.Tar_speed = PID_Update_Incre(&wheel_back.PID_Postion,wheel_back.Tar_Postion,wheel_back.Cur_postion);
	 }
	 wheel_back.speed_out = PID_Update_Incre(&wheel_back.PID_Speed,wheel_back.Tar_speed,wheel_back.Cur_speed);
}

void ReadKeyStatus(void)//״̬��
{
	 static StateStatus state = wait;//������ʼ
	
	 //pass=״̬ת��
	
	 switch(state)
	 {
		  case wait:
				 gpio_init(A14,GPO,1);
				 state = move;
				 break;
			case prepare:
				 break;
			case move:
				 if(1)//�ж�����
				 {
					  gpio_turn(A15);
					  vTaskDelay(1500);
					  wheel_back.speed_out = 500;//������
					  ftm_pwm_duty(ftm0,ftm_ch4,wheel_back.speed_out);
					  ftm_pwm_duty(ftm0,ftm_ch5,wheel_back.speed_out);
					  ftm_pwm_duty(ftm0,ftm_ch6,wheel_back.speed_out);
					  ftm_pwm_duty(ftm0,ftm_ch7,wheel_back.speed_out);
					  //����ftm0ģ�飬ͨ��ռ�ձ�Ϊ�ٷ�֮10��ռ�ձ� = speed_out/FTM0_PRECISON;				  
					  wheel_back.data1 = ftm_quad_get(ftm1);	//��ȡftm1���������ֵ
		        wheel_back.data2 = ftm_quad_get(ftm2);	//��ȡftm2���������ֵ
					  uart_putchar(uart2,0x5a);   //uart3���� 0x5a
		        uart_querychar(uart2,(uint8*)&wheel_back.data1);
			      uart_querychar(uart2,(uint8*)&wheel_back.data2);//ʹ�ò�ѯ��ʽ���ܴ�������
					  ftm_quad_clean(ftm1);		//���ftm1���������ֵ
						ftm_quad_clean(ftm2);		//���ftm2���������ֵ
				 }
				 break;
	 }
}

void Task_Control()
{
	 Init_control();
	 while(1)
	 {
		  Updata_out();
	    ReadKeyStatus();
		 
		  vTaskDelay(1);
	 }
}
	
	
