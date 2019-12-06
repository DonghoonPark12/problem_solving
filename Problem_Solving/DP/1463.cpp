#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include <stdio.h>
	int Dp[1000001];

	int min(int a, int b) {
		return a > b ? b : a;
	}

	/*
		1�� �����
		Greedy�� Ǯ�� ����. �ݷ�: 10
		Greedy �� Ǯ ��� : 10 -> 5-> 4-> 2-> 1
		DP�� Ǯ ��� : 10 -> 9 -> 3 -> 1
	*/

	//Bottom-Up
	int main(void) {
		int N;
		scanf("%d", &N);

		Dp[1] = 0;

		for (int i = 2; i <= N; i++)
		{
			Dp[i] = Dp[i - 1] + 1;
			//if (i % 2 == 0)
			//	Dp[i] = min(Dp[i], Dp[i / 2] + 1);
			//if (i % 3 == 0)
			//	Dp[i] = min(Dp[i], Dp[i / 3] + 1);

			if (i % 2 == 0 && Dp[i] > Dp[i / 2] + 1)
				Dp[i] = Dp[i / 2] + 1;
			if (i % 3 == 0 && Dp[i] > Dp[i / 3] + 1)
				Dp[i] = Dp[i / 3] + 1;
		}

		printf("%d\n", Dp[N]);
		return 0;
	}

