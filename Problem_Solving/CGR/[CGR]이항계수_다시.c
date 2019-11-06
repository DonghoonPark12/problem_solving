#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 100
#define MOD 1000000007
#define min(X,Y) ((X) < (Y) ? (X) : (Y)) 
/* O(2^n) 왜??? 
int com(int n, int r)
{
	if ((n == r)|| (r == 0))
		return 1;
	else if (r == 1)
		return n;
	else
		return com(n - 1, r) + com(n - 1, r - 1);
}
*/

int getcom[MAX_SIZE][MAX_SIZE];
/*
int com(int n, int r)
{
	if (getcom[n][r] > 0)
		return getcom[n][r];//중복 연산을 최소화 하기 위해서 미리 메모리에 저장: Memoization
	if (r == 0 || n == r)
		return getcom[n][r] = 1;

	getcom[n][r] = com(n - 1, r) + com(n - 1, r - 1);

	return getcom[n][r];
}
*/


int com(int n, int r)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < min(i, r); j++)
		{
			if (j == 0 || j == i)
				getcom[i][j] = 1;
			else
				getcom[i][j] = (getcom[i-1][j] + getcom[i-1][j-1]) % MOD;
		}
	}
	return getcom[n][r];
}


int main(void)
{
	int T, test_case;
	int Answer = 0;
	//freopen("input.txt", "r", stdin);

	//setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int n, m;
		scanf("%d %d", &n, &m);

		//printf("%d", com(5, 2));


		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				Answer += com(i + j, i);
			}
		}
		

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("Case #%d ", test_case+1);
		printf("%d\n", Answer %MOD);
	}



	return 0;

}