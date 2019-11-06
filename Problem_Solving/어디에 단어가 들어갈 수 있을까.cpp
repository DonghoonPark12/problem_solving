#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arr[15][15];

int main(void)
{
	int T, test_case;
	int Answer = 0;
	char str[15];
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int m, n, nn;  scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) {
			//scanf("%s", str);
			for (int j = 0; j < m; j++) {
				scanf(" %d", &nn);
				arr[i][j] = nn;
			}
		}
		int cnt;
		for (int i = 0; i < m; i++) {
			cnt = 0;
			for (int j = 0; j < m; j++) { 
				if (arr[i][j] == 1)
					cnt++;
				else
					cnt = 0;
				if(cnt == n && arr[i][j+1] == 0)
				    Answer++;
			}
		}

		for (int j = 0; j < m; j++) {
			cnt = 0;
			for (int i = 0; i < m; i++) { 
				if (arr[i][j] == 1)
					cnt++;
				else
					cnt = 0;
				if (cnt == n && arr[i+1][j] == 0)
					Answer++;
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}


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