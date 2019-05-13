#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STACK_CAPACITY 100000

/*
* ���� ���� ������ push(int n), pop() ���� (����)����� ���峪, 
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

void push(int n);
int pop();

char op[STACK_CAPACITY] = { 0 };
int k = 0;

int main(void)
{
	int Answer = 1;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	int N,n;
	scanf("%d\n", &N);
	int j = 1; //�����ϴ� ��, ���ÿ� push�� ������������ 
	//j�� ���ÿ� ���� �����ϸ鼭, ���� ���� �������� ���� �˻��ϴ� ������ �Ѵ�. 

	for (int i = 0; i < N; i++) //8�� 
	{
		scanf("%d\n", &n); //�Է� �Ǵ� ��, 4

		if (n >= j)// n=4(j�� 5���� ����) , 5
		{
			while (j <= n)//j�� 5, n �� 5, ���� 5�� push �ȴ�. 
			{
				push(j++);//+ + + +
			}
			pop();
		}
		else //n=3
		{
			/*
			pop();
			while (stack[top] == n)
			{
				pop();
			}
			*/
			if (stack[top] == n) //(n == 2)�� �Ǹ� No
			{
				pop();
			}
			else
			{
				Answer = 0;
				printf("No\n");
				break;
			}
		}
	}

	int i = 0;
	if (Answer)
	{
		while(op[i] !='\0')
			printf("%c\n", op[i++]);
	}
	

	return 0;

}

void push(int n)
{
	/*/
	if (stack_depth == STACK_CAPACITY)
	{
		printf("stack is full!!\n");
		return;
	}
	*/
	//printf("+\n");
	op[k++] = '+';
	top++;
	stack[top] = n;

	return;
}

int pop()
{
	int r = 0;

	/*
	if (stack_depth == 0)
	{
		printf("stack is emtpy!!\n");
		return 0; //#1 �̶� r=0�� �Ǵµ� [0]�� ���� ��µ� �ʿ�� ����. ��ؾ� �ұ�.
	}
	*/
	//printf("-\n");
	op[k++] = '-';
	stack[top]=0;
	top--;
	return r;
}