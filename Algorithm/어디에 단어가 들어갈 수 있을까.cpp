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