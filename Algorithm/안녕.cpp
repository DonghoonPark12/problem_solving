#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int heal = 100;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int N; scanf("%d", &N);

	int *L = (int *)malloc(sizeof(int) * N);
	int *J = (int *)malloc(sizeof(int) * N);

	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &tmp);
		L[i] = tmp;
	}
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &tmp);
		J[i] = tmp;
	}

	//for(int i=0;i<(1<<N);i++) //8번
	int M = (1 << N);//M은 4일 경우 16가지. 즉, 부분수열의 수
	int max = 0;
	int total_Lose = 0, total_Joy = 0;
	int arr[2 ^ 20][20] = { 0 };


	for (int i = 0; i < M; i++)
	{
		int count = 0;
		int temp = i;
		for (int j = 0; temp > 0; j++) {
			arr[i][j] = temp % 2;
			temp = temp / 2;
			count++;//count를 증가하여 후에 배열을 몇 번 반목할지를 결정
		}
	}



	for (int i = 1; i<(1 << N); i++) //8번
	{
		for (int j = 0; j < N; j++) // 3번 
		{
			total_Lose += L[j] * arr[i][j];
			total_Joy += J[j] * arr[i][j];
		}

		if (total_Lose < 100 && total_Joy > max)
			max = total_Joy;

		total_Lose = 0; total_Joy = 0;

	}

	printf("%d", max);
	return 0;
}

