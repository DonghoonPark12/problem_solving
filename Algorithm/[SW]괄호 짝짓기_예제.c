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
			if (input[i] == '(' || input[i] == '[' || input[i] == '{' || input[i] == '<')//여는 괄호는 저장.
			{
				stack[top] = input[i]; //push
				top++;
			}
			else
			{
				if (top == 0) //닫는 괄호가 들어 왔다면 에러
					break;
				else if (stack[top - 1] == pair[input[i]]) //짝이 된다면 
					top--;
				else //짝이 안된다면 에러
					break; //해단 break를 감싸고 있는 가장 작은 반복문 빠져 나온다. 
			}
		}

		if(i==-1 && top == 0)
			printf("Y\n");
		else
			printf("N\n");
	}
	
}