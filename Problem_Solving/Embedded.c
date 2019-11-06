/* Watch_Dog: Timer HW, 모든 Task가 제 때 응답하지 못할 시 Target Reset 시키기 위함  */
void 다른 모든 task ()
{
	set_timer( 호출한 자기 자신, Dog,Report_Sig, 자기한테 알맞은 시간 );
	wait_signal( Dog_Report_Sig )
	if (get_Signal () == Dog_Report_Sig )
	  {
	    send_signal( Watchdog_task, 자기자신 );
	    clr_signal ( Dog_Report_Sig )
	  }
} //각각의 Task가 자신이 살아 있음을 알린다.

void Watch_Dog_Task ()
{
	set_timer( 호출한 자기 자신, Wake_Up_Sig, 적당한 주기 )
	wait_signal( Wake_Up_Sig )
	if (get_Signal () == Wake_Up_Sig )
	  {
	    for (Task 갯수)
	    {
	      각 Task의 Timer를 Watch Dog이 일어나는 주기 만큼 빼준다. 

		  
		  
		  
		}
	  }
}


/* --------------------------------------------*/
/* Task 방식이란 무엇인가(궁금증)에 대한 검색 결과       	   */
/* 'Preemptive 방식에 관하여'                       */
/* --------------------------------------------*/
Non-Preemptive방식 : 하나의 Task가 Scheduler로 부터 CPU 사용권을 할당 받았을 때, Task가 CPU 사용권을 반납할 때 까지
강제적으로 CPU 제어권을 빼았을 수 없는 방식( Task > Scheduler )

Preemptive방식: Scheduler의 필요에 따라 Task로 부터 CPU 제어권을 강제로 빼았아 다른 Task가 실행 될 수 있도록 Task의 
실행 순서를 결정하는 방식( Task < Scheduler )

EX) Non-Preemptive방식에서 시분할 방식을 이용하면, (웬만하면) 모든 Task들이 동시에 실행 되는 것처럼 보인다.


http://recipes.egloos.com/5078728