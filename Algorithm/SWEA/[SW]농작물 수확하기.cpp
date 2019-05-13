#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
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
		int N,t;
		scanf("%d", &N);

		int arr[49][49] = { 0 };//

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j]; //sca
			}
		}

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
			{
				scanf("%1d", &t);
				if (abs(j - N / 2) + abs(k - N / 2) <= N / 2) Answer += t;
			}
		/*
		for (int i = 0; i < 2 * (frame / 2)*(frame / 2) + frame; i++) //5
		{
			for (int j = 0; j < frame / 2; j++)
			{
				for (int k = 0; k < frame / 2; k++)
				{
					arr[frame / 2 + 1 + j][frame / 2 + 1 + frame / 2) -j];
				}
			}

		}
		*/

		// 3->5
		//5 -> 13
		//7 -> 2*(frame/2)*(frame/2)+frame
		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}

