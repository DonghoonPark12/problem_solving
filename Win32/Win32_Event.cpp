// Win32.cpp : ���ø����̼ǿ� ���� �������� �����մϴ�.
#include "pch.h"
#include "framework.h"

#include "resource.h"
/*
	���μ��� : ��ɸ���� ������ �ִ� �޸𸮿� ����� �������� ��ü
	������   : ���μ����� ���Ե� ��ɾ �����ϴ� ��ü

	Window OS�� ����ȭ �۾��� ���� 'Event ��ü'�� ���

	c.f) ��Ƽ ���μ��� vs ��Ƽ ������
	- �θ�Ƽ ���μ����� �������� ���μ����� ���ÿ� ����Ǵ� �� ó�� ���ִ� ���̰�,
	- ��Ƽ ������� �ϳ��� ���μ����� �������� �����尡 ���� �����ϴ� ���̴�.
*/

/*
	�̺�Ʈ ��ü ���� 

	HANDLE CreateEvent(LPSECURITY_ATTRIBUTE lpEventAttributes,
					  BOOL bManualReset,
					  BOOL bInitialState,
					  LPCTSTR lpName);
	lpEventAttributes : NULL�� ����ϸ� ������ �̺�Ʈ ��ü�� �ڵ��� �ڽ� ���μ����� ��ӵ��� �ʴ´�.

	lpName : �ٸ� ���μ������� �̺�Ʈ ��ü�� �����ϰ� �ʹٸ�, ������ �̸��� ��� ����Ѵ�.
			 NULL�̶��, �̸� ���� �̺�Ʈ ��ü ����
*/
/* ������ 1 */
HANDLE h_event_object = CreateEvent(NULL, TRUE, FALSE, NULL);

SetEvent(h_event_object);								// �� �̺�Ʈ ��ü ���°��� TRUE�� �����Ѵ�.

/* ������ 2 */
//DWORD stat = WaitForSingleObject(h_event_object, INFINITE);
DWORD stat = WaitForSingleObject(h_event_object, 5000); // 5�ʰ� h_event_object ���� ����Ǿ����� üũ
if (state == WAIT_OBJECT_0)
{
	// 5�� �̳��� ���°� ����� ���
}
else if (state == WAIT_TIMEOUT)
{
	// 5�� �̳��� ���°� ������� �ʾƼ� Ÿ�� �ƿ� �߻�
}
CloseHandle(h_event_object); // �̺�Ʈ ��ü�� ��� �ߴ�