/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;

	return ;
}


int main(void)
{
	int T, test_case;
	int Answer=0;
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

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int c;
		int sw, M, m;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int num[7] = { 0 };

		int i = 0;
		while ((c = getchar()) != ' ')
		{
			//scanf("%1d", &num[i]);
			num[i] = c-48; //0 ~ 9까지의 정수가 들어올 것.
			i++;
		}
		scanf("%d\n",&sw);

		/* 가장 큰 수의 index를 찾는다. */

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}