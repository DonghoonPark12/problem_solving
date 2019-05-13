#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <algorithm>
//#include <iostream>
//using namespace std;
/*
for문 돌면서 max값 구하고(동일)
그다음 나머지 배열에서 max값 for문 돌면서 또 구하고 : 배열에 저장하면 max값을 기억하게 되어 또 구할 필요가 없다.
빼주기 위해서 for문 또 돌고 : 배열에 저장하면 그대로 빼준다.
배열에 값을 저장한 후 푸는 문제는 새로운 (저장용)배열을 하나 더 만드는 것도 나쁘지 않다.
*/
int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d\n", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		//int Answer = 0, idx = 0, i = 0, max = 0, j = 0;
		int Answer = 0;
		int N; scanf("%d\n", &N);
		int arr[1000000] = { 0 };
		int arr2[1000000] = { 0 };
		int max = 0;

		for (int i = 0; i < N; i++)
			scanf("%d ", &arr[N]);

		for (int i = N; i > 0; i--)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
			arr2[i] = max;
		}

		/*
		while (idx != N - 1)
		{
			max = 0; //max 초기화
					 //i = idx + 1; j = idx + 1;
			for (i; i < N; i++)// i=0 ~ N-1 // idx ~ N //
			{
				if (arr[i] > max) {
					idx = i; //idx갱신
					max = arr[i]; //max갱신
				}
			}

			for (j; j < idx; j++)
			{
				Answer += (max - arr[j]);
			}
		}
		*/
		for (int i = N; i > 0; i--)
		{
			Answer += (arr2[N] - arr[N]);
		}
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
		/////////////////////////////////////////////////////////////////////////////////////////////////
	}
	return 0;

}