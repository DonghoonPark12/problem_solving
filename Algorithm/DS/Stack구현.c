/* �迭�� �̿��� ���� ����� */

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
			if (r != 0) printf("[%d]\n", r);//#1 �� ����� �� ������. 
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
		return 0; //#1 �̶� r=0�� �Ǵµ� [0]�� ���� ��µ� �ʿ�� ����. ��ؾ� �ұ�.
	}

	r = stack[top];
	top--;
	stack_depth--;
	return r;
}