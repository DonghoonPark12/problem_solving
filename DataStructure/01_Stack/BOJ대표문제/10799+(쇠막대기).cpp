#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int N, Answer = 0;

	char str[100000] = { 0 };
	scanf("%s\n", str);

	char stack[100000] = { 0 };
	int top = 0;

	int n = strlen(str);

	int i = 0;
	while (n--)
	{
		if (str[i] == '(')//���� ��ȣ�� ����.
		{
			stack[top] = str[i]; //push
			top++;
		}
		if (str[i] == ')')
		{
			if (str[i - 1] == ')') //������� ��
			{
				top--;
				Answer += 1;
			}
			else                    //�������� �߻�
			{
				top--;
				Answer += top;
			}
		}
		i++;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
	printf("%d\n", Answer);
	return 0;
}
