#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[5000]; //수열 저장
int b[400001];

int main(void)
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T, t;
	int N, i, j;
	int cnt;

	scanf("%d", &T); 

	for (t = 1; t <= T; t++)
	{
		cnt = 0;
		scanf("%d", &N); //6 수열의 크기

		for (i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]); //A1, A2, ... , AN 각 원소의 값은 10^5(100000) 보다는 작다. 

			for (j = 0; j < i; j++)
			{
				if (b[arr[i] - arr[j] + 200000] == t)
				{
					cnt++;
					break;
				}
			}

			for (j = 0; j <= i; j++)
				b[arr[i] + arr[j] + 200000] = t;
		}

		printf("Case #%d\n%d\n", t, cnt);
	}
}