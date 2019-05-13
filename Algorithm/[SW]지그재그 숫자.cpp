#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		/* 문제의 본질을 찾은 경우 */
		int n;  scanf("%d", &n);
		if (n % 2 == 0) Answer = (-1)*(n / 2); //짝수
		else Answer = n / 2 + 1; //홀수

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}


