//1<= N <= 20  1<= K <= 1000

#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
		/*
		int N, K;
		scanf("%d %d\n", &N, &K);

		int arr[20] = { 0 };

		for (int i = 0; i < N; i++)
			scanf("%d ", &arr[i]);

		for (int i = 0; i < N-1; i++) // 0 ~ 3 [4]
		{
			for (int j = i + 1; j < N; j++)
			{
				if (arr[i] + arr[j] == K)
					Answer++;
			}
		}
		*/

		// 2>>n
		int N, K,i,j;
		int A[20], D[1004] = { 1 };	
		scanf("%d%d", &N, &K);

		for (i = 0; i < N; i++) scanf("%d", A + i); // 1 2 1 2

		for (i = 1; i <= K; i++) D[i] = 0; //D[1] ~ D[3] = 0

		for (i = 0; i < N; i++) 
			for (j = K; j >= A[i]; j--) 
				D[j] += D[j - A[i]];

		printf("#%d %d\n", T, D[K]);



		/////////////////////////////////////////////////////////////////////////////////////////////////
		//printf("#%d ", test_case + 1);
		//printf("%d\n", Answer);
	}

	return 0;

}


