#include <stdio.h>
#define STACK_SIZE 10

int main()
{
	char str[STACK_SIZE] = { 0 };
	char stack[STACK_SIZE] = { 0 };

	scanf("%s", str);

	int top = 1;

	for (int i = 1; str[i - 1]; i++)
	{
		if (top != 0 && str[i] == stack[top - 1])
		{
			top--;
		}
		else
		{
			stack[top++] = str[i];
		}

	}
}