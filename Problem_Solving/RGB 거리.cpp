#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1001][1001] = { 0 };
int sum[1001][1001] = { 0 };

int f(int i, int j)
{
	if (j < 0)
		return 0;

	sum[i+1][j] =  arr[i][j+1] + 

	//sum[i][j] = min(sum[i - 1][j - 1] + arr[i][j], sum[i - 1][j + 1] + arr[i][j]);

	//if (sum[i][j] < min)
	//	min = sum[i][j];
}

int main()
{
	int Answer = 0;
	int n;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf(" %d", &arr[i][j]);
		}
	}

	Answer = f(0, 0);
	printf("%d", Answer);
}
