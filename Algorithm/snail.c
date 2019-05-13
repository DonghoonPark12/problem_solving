#include <stdio.h>
void snail(int n)
{
	int arr[10][10] = { 0 };
	int **ptr = arr;

	for (int i = 1; i <= n; n++)
	{
		ptr[1][i] = i;
	}
	
	
	return snail(n - 1);
}

int main()
{
	int T, test_case;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		int n;
		/////////////////////
		scanf("%d", &n);



		//////////////////
	}
	return 0;
}