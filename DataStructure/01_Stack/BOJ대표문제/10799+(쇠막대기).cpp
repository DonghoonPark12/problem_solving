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
		if (str[i] == '(')//여는 괄호는 저장.
		{
			stack[top] = str[i]; //push
			top++;
		}
		if (str[i] == ')')
		{
			if (str[i - 1] == ')') //막대기의 끝
			{
				top--;
				Answer += 1;
			}
			else                    //레이저의 발사
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
