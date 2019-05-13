#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int Answer = 0;
	int result = 0;//계산된 결과 값
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &N);

	int arr[100] = { 0 };
	for (int i = 0; i < N; i++) scanf(" %d", &(arr[i])); //11

	//int op[N - 2] = { 0 };//연산을 저장하는 곳

	int op[100] = { 0 };

	for (int i = 0; i < (1 << N - 2); i++) // 2^9개
	{
		result = arr[0];//첫 시작 값은 항상 필요

		int count = 0;
		int temp = i;
		for (int j = 0; temp > 0; j++)
		{
			op[j] = temp % 2;
			temp = temp / 2;
			count++;//count를 증가하여 후에 배열을 몇 번 반목할지를 결정
		}//0000 00000 // 0000 00001 // ~~~ // 1111 11111

		for (int k = 0; k < N - 2; k++) //K는 9번만 돈다. 처음과 마지막을 제외하고 +/- 결정
		{
			if (op[k] == 0)
				result += arr[k+1]; //8 이후 원소 부터 적용
			else
				result -= arr[k+1];

			if (result < 0)
				break;//음수면 해단 연산은 넘긴다.
		}

		if (arr[N - 1] == result)
			Answer++;
	}
	printf("%d", Answer);

	free(op);
	return 0;
}