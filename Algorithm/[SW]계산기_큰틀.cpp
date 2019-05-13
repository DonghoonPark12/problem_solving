#include <stdio.h>
#define STACK_SIZE 1000
#define STRING_LENGTH 1000

// 입력된 수식을 후위 표기법으로 변경
char notationStack[STACK_SIZE];
int notationStackCount;
int notationStackPush(char c);
int notationStackPop(char &c);
int notationStackTop(char &c);
int notationStackIsEmpty();
int notationStackIsFull();

// 후위표기법 수식을 계산하기 위한 스택
int calculationStack[STACK_SIZE];
int caculationStackCount;
int caculationStackPush(int i);
int caculationStackPop(int &i);
int caculationStackTop(int &i);
int caculationStackIsEmpty();
int caculationStackIsFull();

// 연산자 우선순위
int priority(char c)
{
	if (c == '(') return 5;
	else if (c == '*') return 1;
	else if (c == '+') return 2;
	else return -1;
}

int main()
{
	int length;
	char input[STRING_LENGTH];

	char ans[STRING_LENGTH];
	int ansLength;

	int temp;
	char temp2;
	char temp3;

	int &i_temp = temp;
	char &c_temp = temp2;
	char &c_temp2 = temp3;

	int i, j;
	int t;

	scanf("%d", &t);
	for (int test_case = 1; test_case <= 2; test_case++)
	{
		notationStackCount = 0;
		caculationStackCount = 0;

		ansLength = 0;

		//후위 표기법으로 변경


		//계산
		int x;
		int y;

		int &xx = x;
		int &yy = y;

		for (int j = 0; j < ansLength; j++)
		{
			if (ans[j] >= '0' && ans[j] <= '9')
			{
				caculationStackPush((int)(ans[j] - 48));
			}
			else if (ans[j] == '*')
			{
				caculationStackPop(xx);
				caculationStackPop(yy);
				caculationStackPush(xx * yy);
			}
			else if (ans[j] == '+')
			{
				caculationStackPop(xx);
				caculationStackPop(yy);
				caculationStackPush(xx + yy);
			}
		}

		caculationStackPop(xx);
		printf("%d\n", xx);
	}

	return 0;
}
