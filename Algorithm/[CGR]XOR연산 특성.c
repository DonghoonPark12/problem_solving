/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Answer;
//int n; //n개의 10진수 갯수.
//int deci;//n개의 10진수에 포함된 원소
//int a, b;//홀수개를 가지는 두수 
//int flag = 0; //for문을 돌면서 조건을 만족하는 두 수를 저장하려는데 꼭 이래야만 하는가. 
//int d[10] = { 0 };
int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	 freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, value;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &value);
			Answer ^= value;
		}
		/*
		for (i = 0; i < n; i++)
		{
			scanf("%d", &deci);
			d[deci]++;// d[2] == 1, d[5] == 1. d[3] == 2 d[0] ~ d[9] 까지 중에서 
		}
		
		for (i = 0; i < 10; i++)
		{
			if ((d[i] % 2 == 1)&&(flag == 0)) // 홀수번 카운트 되었다면 ex) d[2] or d[5]
			{
				a = i;  //a는 2가 된다. 
				flag = 1;
			}
			if (d[i] % 2 == 1 && i > a ) // 홀수번 카운트 되었다면
			{
				b = i;
			}
		}
		Answer = a ^ b;
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}