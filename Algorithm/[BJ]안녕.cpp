#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int N;
int heal = 100;
int arr[21][101] = { 0 };
int L[21];
int J[21];

int GetSolve(int idx, int y) //idx는 인덱스, y는 체력
{
	if (arr[idx][heal] != -1) return arr[idx][heal];
	int &max_joy = arr[idx][heal];
	if (idx == N) return 0;

	if(y - L[idx] >0)
		max_joy =  GetSolve(idx + 1, y - L[idx]) + J[idx];
	int temp = GetSolve(idx + 1, y);

	if (temp > max_joy) max_joy = temp;

	return max_joy;
}



int  main()
{
	int heal = 100;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &N);

	//int *L = (int *)malloc(sizeof(int) * N);
	//int *J = (int *)malloc(sizeof(int) * N);

	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &tmp);
		L[i] = tmp; //잃는 체력
	}
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &tmp);
		J[i] = tmp; //얻는 기쁨	
	}
	memset(arr, -1, sizeof(arr));
	printf("%d", GetSolve(0,100));
	/*
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
			count++;//count를 증가하여 후에 배열을 몇 번 반복할지를 결정
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
	*/
	return 0;

}
