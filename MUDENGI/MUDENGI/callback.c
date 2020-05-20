/*
blocking callbacks --> synchronous callbacks
: Invoke before function return

deferred callbacks --> asynchronous callbacks
: Invoke after function return
: i.g. event handling
*/

#include <stdio.h>
#include <stdlib.h>

/*
	Rather than It just print two number, 
	It doesn't implement detail and leave as an interface.

	It throw detail implementaion to Functions.
*/
void PrintTwoNumbers(int (*numberSource)(void)) {
	int val1 = numberSource();
	int val2 = numberSource();

	printf("%d and %d\n", val1, val2);
}

/* A possible callback */
int overNineThousand(void) {
	return (rand() % 1000) + 9001;
}

/* Another possible callback. */
int meaningOfLife(void) {
	return 42;
}

int main() {
	PrintTwoNumbers(&rand);
	PrintTwoNumbers(&overNineThousand);
	PrintTwoNumbers(&meaningOfLife);
}

/*
	�ݹ��� ȣ���Լ��� �����ϴ� �ڵ��, �Լ��� ���޵� �Ű����� ����
	�� �ʿ䰡 ����.
*/

#include <stdio.h>
#include <string.h>

typedef struct _MyMsg {
	int appId;
	char msgbody[32];
} MyMsg;

void myfunc(MyMsg* msg)
{
	if (strlen(msg->msgbody) > 0)
		printf("App Id = %d \nMsg = %s \n", msg->appId, msg->msgbody);
	else
		printf("App Id = %d \nMsg = No Msg\n", msg->appId);
}
 
/*
 * Prototype declaration
 */
void (*callback)(MyMsg*);

int main() {
	MyMsg msg1;

	msg1.appId = 100;
	strcpy(msg1.msgbody, "This is a test\n");

	callback = myfunc;//���� �Լ� �ּ� ����

	callback(&msg1);

	return 0;
}