#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#define STACK_CAPACITY 100000

/*
* 이 문제는 수열이 주어지고, push(n), pop()으로 되려 본 수열을 만들 수 있는지
* 만들 수 있다면 어떠한 연산 순서로 만들어야 하는지 역 추적 하는 문제.
* 오름 차순으로만 입력 되야 하며, 현재 스택에 남아있는 수중 가장 상단의 값만 pop()할 수 있다.
* 1) 스택에 남아 있는 수 보다 큰 값이 들어가는 것은 상관 없으나
* 2) 뺄 때, 오류가 날 수 있다. ex) 1 2 5 가 있을 때 5를 pop()할 수 있다. (4 3 6 5 2 1) (+++- - ++- ---)
* '2' 는pop()할 수 없으며, 즉, 해당 수열은 만들 수 없는 것이다. 
* 따라서 값이 j와 같거나 클 경우에만(n>=j)(오름차순 이니까) push(n)를 하며 ex) n이4(4는 pop), j는5가 되었음. 그다음 n이 5가 들어오면 push,pop가 된다.  
* 값이 작으면 pop을 하며, 이때 해당 값을 뺄수 있는지 검사하면 된다. 
* 빼지 못하는 경우라면 "No"를 출력한다. 
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
	int N,n; //수열과 입력되는 수
	scanf("%d\n", &N);
	int j = 1; //증가하는 수, j는 스택에 값을 저장하면서, 들어온 값이 오름차순 임을 검사하는 역할을 한다. 

	while(N--){ //8번 
		scanf("%d\n", &n); //입력 되는 수, 4

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