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

// (1) ����: ���� ���� �迭�� ������ ��, ���� ���� ������ �ٲ� ��, op_post[STACK_SIZE]�� ������ ��
// Push�ϱ� ���� �ڽ��� �켱���� ���� ���� ������ �϶����� pop�� ���ش�. 
// (2) ����: 

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
			if (op_stack[i] == ')') // �ݴ� ��ȣ�� ���
			{
				top--;
				while (f(op_stack[i], temp[top]) != 1) //�ݴ��� ��ȣ�� ���� �� ����
				{
					op_post.push(temp[top]);//���� ���ÿ� ����
					top--;
				}
			}
			else if (op_stack[i] == '(')
			{

			}
			else if (op_stack[i] == '*' || op_stack[i] == '+')//|| op_stack[i] == '(')
			{
				// Push�ϱ� ���� �ڽ��� �켱���� ���� ���� ������ �϶����� pop�� ���ش�. 
				if (op_stack[i] == '*')
				{
					tmp = op_post.top() * (op_stack[i + 1] - '0');
					op_post.pop();
					op_post.push(tmp);
					i++;
				}

				//temp[top++] = op_stack[i]; //�����ڰų�, ���� ��ȣ �� ��� Stack�� ����
			}
			else
			{
				op_post.push(op_stack[i] - '0');// -'0'; //�� �������� ��� ���� ���ÿ� �ٷ� ����
			}
			i++;
		}

		// ���� ����
		/*
		while (top != -1)
		{
			if (temp[top] != '(')
				op_post.top() = temp[--top];

		}
		*/

		// ���� ǥ��� ���

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

// ��ȣ ¦�� �´��� �Ǻ��ϴ� �Լ�
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

