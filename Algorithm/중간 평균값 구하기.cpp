#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include "Sort.h" //���� ����ų�, quicksort(arr, 0, 9); ��������
#include<algorithm> //������ ���ų�, sort(arr, arr+10); ��������
using namespace std;

int main(void)
{
	int T, test_case;
	float Answer = 0.0f;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		float sum = 0.0f;
		int arr[10] = { 0 };
		for (int i = 0; i < 10; i++)
		{
			scanf(" %d", &arr[i]);
		}
		//quicksort(arr, 0, 9);
		sort(arr,arr+10);

		for (int i = 1; i <= 8; i++)
		{
			sum += arr[i];
		}
		Answer = sum / 8;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%.0f\n", Answer);
	}
	return 0;
}