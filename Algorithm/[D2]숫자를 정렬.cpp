#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<algorithm> //가져다 쓰거나, sort(arr, arr+10); 오름차순
using namespace std;

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
		int N; scanf("%d", &N);
		int arr[50] = { 0 };
		for (int i = 0; i < N; i++)
		{
			scanf("%d ", &arr[i]);
		}
		sort(arr, arr + N);

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		//printf("%d\n", Answer);
		for (int i = 0; i < N; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}

	return 0;

}