#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int SDC(int arr[][9], int col, int row)
{
	int sum=0;
	//int **ptr = arr[col][row];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sum += arr[i][j];
		}
		if (sum != 45) return 0;
		sum = 0;
	}

	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			sum += arr[i][j];
		}
		if (sum != 45) return 0;
		sum = 0;
	}

	for (int i = 0; i < 9; i += 3)
	{
		for (int j = 0; j < 9; j += 3)
		{
			for (int m = 0; m < 3; m++) {
				for (int n = 0; n < 3; n++) {
					sum += arr[m + j][n + i];
				}
			}
			if (sum != 45) return 0;
			sum = 0;
		}
	}
	return 1;
}

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int arr[9][9] = { 0 };
		for(int i=0;i<9;i++)
		{
			for (int j = 0; j < 9; j++)
			{
				scanf(" %d", &arr[i][j]);
			}
			//scanf("\n");
			//fflush(stdin);
		}
		int col = sizeof(arr[0]) / sizeof(int);      
		int row = sizeof(arr) / sizeof(arr[0]);

		Answer = SDC(arr, col, row);

		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	return 0;

}