#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define STACK_CAPACITY 100000

/*
* �� ������ ������ �־�����, push(n), pop()���� �Ƿ� �� ������ ���� �� �ִ���
* ���� �� �ִٸ� ��� ���� ������ ������ �ϴ��� �� ���� �ϴ� ����.
* ���� �������θ� �Է� �Ǿ� �ϸ�, ���� ���ÿ� �����ִ� ���� ���� ����� ���� pop()�� �� �ִ�.
* 1) ���ÿ� ���� �ִ� �� ���� ū ���� ���� ���� ��� ������
* 2) �� ��, ������ �� �� �ִ�. ex) 1 2 5 �� ���� �� 5�� pop()�� �� �ִ�. (4 3 6 5 2 1) (+++- - ++- ---)
* '2' ��pop()�� �� ������, ��, �ش� ������ ���� �� ���� ���̴�. 
* ���� ���� j�� ���ų� Ŭ ��쿡��(n>=j)(�������� �̴ϱ�) push(n)�� �ϸ� ex) n��4(4�� pop), j��5�� �Ǿ���. �״��� n�� 5�� ������ push,pop�� �ȴ�.  
* ���� ������ pop�� �ϸ�, �̶� �ش� ���� ���� �ִ��� �˻��ϸ� �ȴ�. 
* ���� ���ϴ� ����� "No"�� ����Ѵ�. 
*/
int top = -1;
int stack_depth = 0;
int stack[STACK_CAPACITY];
char op[STACK_CAPACITY] = { 0 };
int k = 0;

void push(int n);
int pop();

int main(void) {
	int Answer = 1;
	int N,n; //������ �ԷµǴ� ��
	scanf("%d\n", &N);
	int j = 1; //�����ϴ� ��, j�� ���ÿ� ���� �����ϸ鼭, ���� ���� �������� ���� �˻��ϴ� ������ �Ѵ�. 

	while(N--){ //8�� 
		scanf("%d\n", &n); //�Է� �Ǵ� ��, 4

		if (n >= stack[top]) {
			while (j <= n) {
				push(j++);
			}
			pop();
		}
		else {
			Answer = 0;
			printf("No\n");
			break;
		}
	}

	int i = 0;
	if (Answer) {
		while(op[i] !='\0')
			printf("%c\n", op[i++]);
	}

	return 0;

}

void push(int n)
{
	op[k++] = '+';
	top++;
	stack[top] = n;
	return;
}

int pop()
{
	int r = 0;
	op[k++] = '-';
	stack[top]=0;
	top--;
	return r;
}