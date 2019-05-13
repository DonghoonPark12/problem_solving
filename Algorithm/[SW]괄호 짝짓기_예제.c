#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define stack_size 100
int top = -1;

char input[stack_size];
char stack[stack_size];

char pair[256] = { 0, };

int main()
{
	int i, test_Case;

	pair[')'] = '(';
	pair[']'] = '[';
	pair['}'] = '{';

	scanf("%d", &test_Case);
	
	while (test_Case--)
	{
		top = 0;
		scanf("%d", &i);
		scanf("%s", input);

		while (i--)
		{
			if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<')//���� ��ȣ�� ����.
			{
				stack[top] = input[i]; //push
				top++;
			}
			else
			{
				if (top == 0) //�ݴ� ��ȣ�� ��� �Դٸ� ����
					break;
				else if (stack[top - 1] == pair[input[i]]) //¦�� �ȴٸ� 
					top--;
				else //¦�� �ȵȴٸ� ����
					break; //�ش� break�� ���ΰ� �ִ� ���� ���� �ݺ��� ���� ���´�. 
			}
		}

		if(i==-1 && top == 0)
			printf("Y\n");
		else
			printf("N\n");
	}
	
}