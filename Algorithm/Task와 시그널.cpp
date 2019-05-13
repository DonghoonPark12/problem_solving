
void main()
{
	Make_Ready(Lamp_task());
	wait(DONE);        /* Lamp task는 init을 하고 DONE을 주고 WORK을 기다릴 것 */
	Make_Ready(Motor_task());
	wait(DONE);        /* Motor task는 init을 하고 DONE을 주고 WORK을 기다릴 것 */
	send(LAMP, WORK)   /* Lamp task에 깜빡임을 요청 */

		return;   
}


void Lamp_task()
{

	Lamp_init();	    /* 초기화는 무조건 */
	                                    
	send(main, DONE);   /* wait을 만나면 main으로 */

	while (1)
	{
		wait(WORK);        /* 여기서 WORK이라는 signal을 일단 기다림 */
		                   /* while(1)이므로 한번 깜빡이면 signal을 기다림 */
		                   /* Signal을 받으면 하면, 일을 시작 */
						   /* Task 정지 */


		clear(WORK);       /* WORK을 받았으니 다음번에도 WORK을 받을 수 있도록 초기화 */
		Lamp_on();
		time_wait(100); /* wait 100uS */

		Lamp_off();
		time_wait(100); /* wait 100uS */

		send(MOTOR, WORK);  /* Motor task야 Motor 동작 요청 */
	}
}

void Motor_task()
{

	Motor_init();		/* 초기화는 무조건 */
	                                    
	send(main, DONE);   /* wait을 만나면 main으로 */

	while (1)
	{
		wait(WORK);        /* 여기서 WORK이라는 signal을 일단 무작정 기다린다 */
		                   /* while(1)이니까 한번 깜빡이면 항상 여기서 signal을 기다린다 */
		                   /* Signal을 받기만 하면, 일을 시작 할 것 */
						   /* 여기서 Task 정지 */

		clear(WORK);       /* WORK을 받았으니, 다음번에도 WORK을 받을 수 있도록 초기화 */
		Motor_on();
		time_wait(100); /* wait 100uS */

		Motor_off();
		time_wait(100); /* wait 100uS */

		send(LAMP, WORK);   /* Lamp task에 Lamp를 깜빡임 요청 */
	}
}
