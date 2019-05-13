
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int wt, ans, n, k;
int mapArr[4][8][8];

void rot(int curD)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mapArr[curD][i][j] = mapArr[curD - 1][n - j - 1][i];
		}
	}
}

int main()
{
	scanf("%d", &wt);
	for (int ct = 1; ct <= wt; ct++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &mapArr[0][i][j]);

		for (int i = 1; i <= 3; i++)
			rot(i);

		printf("#%d\n", ct);
		for (int i = 0; i < n; i++)
		{
			for (int d = 1; d <= 3; d++)
			{
				for (int j = 0; j < n; j++)
				{
					printf("%d", mapArr[d][i][j]);
				}
				printf(" ");
			}
			printf("\n");
		}
	}

	return 0;
}