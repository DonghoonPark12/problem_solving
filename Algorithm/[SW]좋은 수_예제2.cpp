#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[5000]; //���� ����
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
		scanf("%d", &N); //6 ������ ũ��

		for (i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]); //A1, A2, ... , AN �� ������ ���� 10^5(100000) ���ٴ� �۴�. 

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