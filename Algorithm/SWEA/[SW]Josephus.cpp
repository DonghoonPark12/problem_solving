#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int player[100000];

int main()
{
	int n, k, move_count, target = 0;
	int i, j;

	scanf("%d %d", &n, &k);

	for (i = 0; i < n; i++) //7번 돌고
	{
		player[i] = i + 1; //1~7
	}

	for (j = 0; j < n - 1; j++) // 6번
	{
		move_count =0;
		while (move_count < k) // <3
		{
			target = (target + 1) % n; //

			//-1원소가 있으면 이동 횟수에 치지 않는다. 
			if (player[target] != -1)
				move_count++;
		}
		printf("%d\n", player[target]);
		player[target] = -1;

		//-1이 아닌 곳까지 간다. 
		while (player[target] != -1)
			target = (target + 1) % n; //

		//printf("%d\n", player[target]);
	}
	

	return 0;
}

struct Node