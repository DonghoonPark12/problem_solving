#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STACK_SIZE 11

int main(void)
{
	char str[STACK_SIZE] = { 0 };
	char stack[STACK_SIZE] = { 0 };
	scanf("%s", str);

	stack[0] = str[0];
	int top = 1;

	for (int i = 1; str[i - 1]; i++)
	{
		if (top != 0 && stack[top - 1] == str[i])
			top--;
		else
			stack[top++] = str[i];
	}
	printf("%s\n", stack);




	/*
	int is_change = 1;

	while (is_change)
	{
		is_change = 0;

		for (int i = 0; arr[i + 1]; i++) //���ڿ��� ������ �˻� a[11]�� NULL�̹Ƿ� i�� 9������ ����ȴ�. 
		{
			if (arr[i] == arr[i + 1])
				is_change = 1;

			if(is_change)
				for (int j = i; arr[j + 1]; j++) //���� ��ġ ���� ���ڿ��� ������ 
				{
					arr[i] = arr[i + 2];
				}
		}
	}
	*/
	return 0;

}