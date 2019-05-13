/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct n {
	int x;
	int y;
	//int value;
}NewOP;

NewOP and_op(int p )
{
	NewOP a;
	for (int i = 1; i <= 10000; i++)
	{
		if ((i*(i - 1) / 2)  + 1 <= p && p<=(i*(i - 1) / 2) + i)
		{
			a.x = p - (i*(i - 1) / 2);
			a.y = i+1 - a.x;
			break;
		}
	}
	return a;
}

int shap_op(int a, int b) //x, y 좌표로 부터 값 반환
{
	int temp = a + b - 2;
	return temp*(temp+1)/2 + a;
}


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
		int Answer = 0;
		int p, q;
		scanf("%d %d", &p, &q); 
		NewOP P, Q;
		P = and_op (p); Q = and_op (q);

		Answer = shap_op((P.x + Q.x), (P.y + Q.y));
		

		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}