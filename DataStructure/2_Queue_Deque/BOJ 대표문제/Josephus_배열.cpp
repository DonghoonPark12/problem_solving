#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int value;
	node *next;
}NODE;
int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		/* 배열 */
		int N,K;// arr[N + 1]; arr[5001]하지 말고
		int *ptr;
		int *arr = (int *)malloc(sizeof(int)*N);//7개 생성

		scanf("%d %d", &N,&K);//7 3

		//ptr = (int *)malloc(sizeof(NODE)*N);//7개 생성
		/*	배열 */
		for (int i = 0; i < N; i++) arr[i] = i+1; //1 ~ 7
		int lo = 0;
		for(int i=0;i<N;i++)//7번 돌면서 
		{
			while (K--)
			{

			}
			lo += 2;

			if (lo >= N) lo = lo / 7;

			if (arr[lo] != 0)
			{
				lo++;
				printf("%d", arr[lo]);
				arr[lo] = 0;

			}
		}
		
		
		/* 리스트 */
		/*
		NODE* ptr;

		ptr = (int *)malloc(sizeof(NODE));
		*/
		

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}
