#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList�� ���� �� �ʱ�ȭ ***/
	List list;
	int data;
	ListInit(&list);

	/*** 5���� ������ ���� ***/
	//LInsert(&list, 11);  LInsert(&list, 11);
	//LInsert(&list, 22);  LInsert(&list, 22);
	//LInsert(&list, 33);
	for (int i = 0; i < 9; i++) {
		LInsert(&list, i + 1);
	}

	/*** ����� �������� ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	int sum = 0;
	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);
		sum += data;
		
		while (LNext(&list, &data)) {    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
			sum += data;
		}
	}
	printf("sum = %d\n\n",sum);

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if(LFirst(&list, &data))
	{
		if(data%2 == 0 || data%3==0)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data%2 == 0 || data%3==0)
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}