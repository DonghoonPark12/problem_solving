#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;// ��� ��
	int	tmp;//��� �ð� ����
	int Answer = 0;//�ð��� ��
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d\n", &N);
	int arr[1000] = { 0 };//�ð�
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d ", &tmp);
		arr[i] = tmp;
	}
	sort(arr, arr + N);

	for (int i = N-1; i >= 0; i--) //4, 3, 2, 1, 0
	{
		for (int j = 0; j <= i; j++)// 0~4, 0~3, 0~2, 0~1, 0
		{
			Answer += arr[j];
		}
	}

	printf("%d\n", Answer);
	return 0;

}