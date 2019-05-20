/* 배열을 이용해 스택 만들기 */

#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>

#define STACK_CAPACITY 8

int stack[STACK_CAPACITY];
int top = -1;
int stack_depth = 0;

void push(int n);
int pop();

int main()
{
	int number, r = 0;

	do{
		printf("Input number: ");
		scanf("%d", &number);

		if (number > 0)
		{
			push(number);
		}
		else if (number == 0)
		{
			r = pop();
			if (r != 0) printf("[%d]\n", r);//#1 이 방법은 좀 구리다. 
		}
	} while (number >= 0);

	return 0;
}

void push(int n)
{
	if (stack_depth == STACK_CAPACITY)
	{
		printf("stack is full!!\n");
		return;
	}

	top++;
	stack[top] = n;
	stack_depth++;

	return;
}

int pop()
{
	int r = 0;

	if (stack_depth == 0)
	{
		printf("stack is emtpy!!\n");
		return 0; //#1 이때 r=0가 되는데 [0]이 굳이 출력될 필요는 없다. 어떻해야 할까.
	}

	r = stack[top];
	top--;
	stack_depth--;
	return r;
}