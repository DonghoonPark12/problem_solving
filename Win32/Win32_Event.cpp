// Win32.cpp : 애플리케이션에 대한 진입점을 정의합니다.
#include "pch.h"
#include "framework.h"

#include "resource.h"
/*
	프로세스 : 명령목록을 가지고 있는 메모리에 적재된 실행파일 객체
	스레드   : 프로세스에 포함된 명령어를 실행하는 주체

	Window OS는 동기화 작업을 위해 'Event 객체'를 사용

	c.f) 멀티 프로세스 vs 멀티 스레드
	- 두멀티 프로세스는 여러개의 프로세스가 동시에 실행되는 것 처럼 해주는 것이고,
	- 멀티 스레드는 하나의 프로세스를 여러개의 스레드가 동시 실행하는 것이다.
*/

/*
	이벤트 객체 생성 

	HANDLE CreateEvent(LPSECURITY_ATTRIBUTE lpEventAttributes,
					  BOOL bManualReset,
					  BOOL bInitialState,
					  LPCTSTR lpName);
	lpEventAttributes : NULL을 명시하면 생성된 이벤트 객체의 핸들은 자식 프로세스에 상속되지 않는다.

	lpName : 다른 프로세스간에 이벤트 객체를 공유하고 싶다면, 동일한 이름을 적어서 사용한다.
			 NULL이라면, 이름 없는 이벤트 객체 생성
*/
/* 스레드 1 */
HANDLE h_event_object = CreateEvent(NULL, TRUE, FALSE, NULL);

SetEvent(h_event_object);								// 이 이벤트 객체 상태값을 TRUE로 변경한다.

/* 스레드 2 */
//DWORD stat = WaitForSingleObject(h_event_object, INFINITE);
DWORD stat = WaitForSingleObject(h_event_object, 5000); // 5초간 h_event_object 값이 변경되었는지 체크
if (state == WAIT_OBJECT_0)
{
	// 5초 이내에 상태가 변경된 경우
}
else if (state == WAIT_TIMEOUT)
{
	// 5초 이내에 상태가 변경되지 않아서 타임 아웃 발생
}
CloseHandle(h_event_object); // 이벤트 객체의 사용 중단