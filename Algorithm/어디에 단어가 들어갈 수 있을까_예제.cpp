#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 16

int map[MAX_N][MAX_N];

int main()
{
	int test, t;

	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &test);

	for (t = 0; t<test; t++)
	{
		int N, K, i, j;
		int cnt = 0, sol = 0, flag = 0;

		memset(map, 0, sizeof(map));

		scanf("%d %d", &N, &K);

		for (i = 0; i<N; i++)
		{
			for (j = 0; j<N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		for (i = 0; i<N; i++)
		{
			cnt = 0;

			for (j = 0; j<N; j++)
			{
				if (map[i][j] == 1)
				{
					cnt++;
				}
				else
				{
					cnt = 0;
				}

				if (cnt == K && map[i][j + 1] == 0)
				{
					sol++;
					cnt = 0;
				}

			}

		}

		cnt = 0, flag = 0;

		for (j = 0; j<N; j++)
		{
			cnt = 0;

			for (i = 0; i<N; i++)
			{
				if (map[i][j] == 1)
				{
					cnt++;
				}
				else
				{
					cnt = 0;
				}

				if (cnt == K && map[i + 1][j] == 0)
				{
					sol++;
					cnt = 0;
				}
			}


		}

		printf("#%d %d\n", t + 1, sol);

	}

	return 0;
}
