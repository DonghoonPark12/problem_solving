#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <algorithm>
//#include <iostream>
//using namespace std;
/*
for�� ���鼭 max�� ���ϰ�(����)
�״��� ������ �迭���� max�� for�� ���鼭 �� ���ϰ� : �迭�� �����ϸ� max���� ����ϰ� �Ǿ� �� ���� �ʿ䰡 ����.
���ֱ� ���ؼ� for�� �� ���� : �迭�� �����ϸ� �״�� ���ش�.
�迭�� ���� ������ �� Ǫ�� ������ ���ο� (�����)�迭�� �ϳ� �� ����� �͵� ������ �ʴ�.
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
			max = 0; //max �ʱ�ȭ
					 //i = idx + 1; j = idx + 1;
			for (i; i < N; i++)// i=0 ~ N-1 // idx ~ N //
			{
				if (arr[i] > max) {
					idx = i; //idx����
					max = arr[i]; //max����
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