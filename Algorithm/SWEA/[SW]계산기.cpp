#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>

#define stack_size 300
using namespace std;

char op_stack[stack_size];
char temp[stack_size];
char op_post[stack_size];

int caculationStack[stack_size];
int top3 = 0;

void push(int n);
int pop();
//int caculationStackCount;
//int caculationStackPush(int i);
//int caculationStackPop(int &i);
//int caculationStackTop(int &i);
//int caculationStackIsEmpty();
//int caculationStackIsFull();

//stack<char> caculationStack;

// (1) ����: ���� ���� �迭�� ������ ��, ���� ���� ������ �ٲ� ��, op_post[STACK_SIZE]�� ������ ��
// Push�ϱ� ���� �ڽ��� �켱���� ���� ���� ������ �϶����� pop�� ���ش�. 
// (2) ����: 

int f(char c, char d);

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	for(int test_case = 1; test_case <= 10; test_case++)
	{
		int n;
		scanf("%d\n", &n);
		scanf("%s\n", op_stack);

		int i = 0;
		int top = 0, top2 = 0;
		while (op_stack[i] != '\0')
		{
			if (op_stack[i] == ')') // �ݴ� ��ȣ�� ���
			{
				top--;
				while (f(op_stack[i],temp[top]) != 1) //�ݴ��� ��ȣ�� ���� �� ����
				{
					op_post[top2] = temp[top];//���� ���ÿ� ����
					top2++; top--;
				}
			}
			else if (op_stack[i] == '*' || op_stack[i] == '+' )//|| op_stack[i] == '(')
			{
				// Push�ϱ� ���� �ڽ��� �켱���� ���� ���� ������ �϶����� pop�� ���ش�. 
				//if(op_stack[i] == '*')
				//	op_post[top2 - 1] = (op_post[top2 - 1] - '0') * (op_stack[i + 1] - '0');


				/* ������ ������ ���� ���� ����� �ǿ����ڸ� ���ؼ� op_post�� �ٽ� �������� �ߴ�.
				ASCII�� �ٲٷ���, '10'�� ����, '9'���� �ۿ� ����.
				if (op_stack[i] == '*')
				{
				op_post.top() = ((op_post.top()-'0') * (op_stack[i + 1]-'0') + '0');
				}
				*/

				temp[top++] = op_stack[i]; //�����ڰų�, ���� ��ȣ �� ��� Stack�� ����
			}
			else
			{
				op_post[top2++] = op_stack[i];// -'0'; //�� �������� ��� ���� ���ÿ� �ٷ� ����
			}
			i++;
		}

		// ���� ����
		while (top != -1)
		{
			if(temp[top] !='(')
				op_post[top2++] = temp[--top];
			
		}
		//printf("%s", op_post);

		// ���� ǥ��� ���

		int x;
		int y;

		int &xx = x;
		int &yy = y;

		int ansLength = strlen(op_post);

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
		}

		x = pop();

		printf("#%d %d\n", test_case, x);
	}
	return 0;
}

// ��ȣ ¦�� �´��� �Ǻ��ϴ� �Լ�
int f(char c, char d)
{
	if ((d == '(' && c == ')') || (d == '[' && c == ']') || (d == '{' && c == '}') || (d == '<' && c == '>'))
		return 1;
	else
		return 0;
}

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