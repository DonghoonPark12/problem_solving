/* Watch_Dog: Timer HW, ��� Task�� �� �� �������� ���� �� Target Reset ��Ű�� ����  */
void �ٸ� ��� task ()
{
	set_timer( ȣ���� �ڱ� �ڽ�, Dog,Report_Sig, �ڱ����� �˸��� �ð� );
	wait_signal( Dog_Report_Sig )
	if (get_Signal () == Dog_Report_Sig )
	  {
	    send_signal( Watchdog_task, �ڱ��ڽ� );
	    clr_signal ( Dog_Report_Sig )
	  }
} //������ Task�� �ڽ��� ��� ������ �˸���.

void Watch_Dog_Task ()
{
	set_timer( ȣ���� �ڱ� �ڽ�, Wake_Up_Sig, ������ �ֱ� )
	wait_signal( Wake_Up_Sig )
	if (get_Signal () == Wake_Up_Sig )
	  {
	    for (Task ����)
	    {
	      �� Task�� Timer�� Watch Dog�� �Ͼ�� �ֱ� ��ŭ ���ش�. 

		  
		  
		  
		}
	  }
}


/* --------------------------------------------*/
/* Task ����̶� �����ΰ�(�ñ���)�� ���� �˻� ���       	   */
/* 'Preemptive ��Ŀ� ���Ͽ�'                       */
/* --------------------------------------------*/
Non-Preemptive��� : �ϳ��� Task�� Scheduler�� ���� CPU ������ �Ҵ� �޾��� ��, Task�� CPU ������ �ݳ��� �� ����
���������� CPU ������� ������ �� ���� ���( Task > Scheduler )

Preemptive���: Scheduler�� �ʿ信 ���� Task�� ���� CPU ������� ������ ���Ҿ� �ٸ� Task�� ���� �� �� �ֵ��� Task�� 
���� ������ �����ϴ� ���( Task < Scheduler )

EX) Non-Preemptive��Ŀ��� �ú��� ����� �̿��ϸ�, (�����ϸ�) ��� Task���� ���ÿ� ���� �Ǵ� ��ó�� ���δ�.


http://recipes.egloos.com/5078728