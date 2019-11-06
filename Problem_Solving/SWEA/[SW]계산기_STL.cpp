#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
//#include <string>
//#include <stdlib.h>

#define stack_size 300
using namespace std;

char op_stack[stack_size];
char temp[stack_size];

stack<int> op_post;
stack<int> op_post2;
//void push(int n);
//int pop();

// (1) 저장: 연산 식을 배열에 저장한 후, 후위 순위 법으로 바꾼 후, op_post[STACK_SIZE]에 저장할 것
// Push하기 전에 자신의 우선순위 보다 낮은 연산자 일때까지 pop을 해준다. 
// (2) 연산: 

int f(char c, char d);
int tmp;

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int n;
		scanf("%d\n", &n);
		scanf("%s\n", op_stack);

		int i = 0;
		int top = 0, top2 = 0;
		while (op_stack[i] != '\0')
		{
			if (op_stack[i] == ')') // 닫는 괄호일 경우
			{
				top--;
				while (f(op_stack[i], temp[top]) != 1) //반대편 괄호가 나올 때 까지
				{
					op_post.push(temp[top]);//후위 스택에 저장
					top--;
				}
			}
			else if (op_stack[i] == '(')
			{

			}
			else if (op_stack[i] == '*' || op_stack[i] == '+')//|| op_stack[i] == '(')
			{
				// Push하기 전에 자신의 우선순위 보다 낮은 연산자 일때까지 pop을 해준다. 
				if (op_stack[i] == '*')
				{
					tmp = op_post.top() * (op_stack[i + 1] - '0');
					op_post.pop();
					op_post.push(tmp);
					i++;
				}

				//temp[top++] = op_stack[i]; //연산자거나, 여는 괄호 일 경우 Stack에 저장
			}
			else
			{
				op_post.push(op_stack[i] - '0');// -'0'; //피 연산자일 경우 후위 스택에 바로 저장
			}
			i++;
		}

		// 스택 비우기
		/*
		while (top != -1)
		{
			if (temp[top] != '(')
				op_post.top() = temp[--top];

		}
		*/

		// 후위 표기법 계산

		int x = 0;
		int y;

		int &xx = x;
		int &yy = y;

		int ansLength = op_post.size();
		/*
		for (int j = 0; j < ansLength; j++)
		{
			if (op_post[j] >= '0' && op_post[j] <= '9')
			{
				push((int)(op_post[j] - 48));
			}
			else if (op_post[j] == '*')
			{
				x = pop();
				y = pop();
				push(x * y);
			}
			else if (op_post[j] == '+')
			{
				x = pop();
				y = pop();
				push(x + y);
			}
		}*/
		while (!op_post.empty())
		{
			x += op_post.top();
			op_post.pop();
		}
		
		//x = pop();

		printf("#%d %d\n", test_case, x);
	}
	return 0;
}

// 괄호 짝이 맞는지 판별하는 함수
int f(char c, char d)
{
	if ((d == '(' && c == ')') || (d == '[' && c == ']') || (d == '{' && c == '}') || (d == '<' && c == '>'))
		return 1;
	else
		return 0;
}
/*
void push(int n)
{

	top3++;
	caculationStack[top3] = n;

	return;
}

int pop()
{
	int r = 0;

	r = caculationStack[top3];
	top3--;

	return r;
}
*/

