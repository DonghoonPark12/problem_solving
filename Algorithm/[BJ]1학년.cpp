#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	int Answer = 0;
	int result = 0;//���� ��� ��
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &N);

	int arr[100] = { 0 };
	for (int i = 0; i < N; i++) scanf(" %d", &(arr[i])); //11

	//int op[N - 2] = { 0 };//������ �����ϴ� ��

	int op[100] = { 0 };

	for (int i = 0; i < (1 << N - 2); i++) // 2^9��
	{
		result = arr[0];//ù ���� ���� �׻� �ʿ�

		int count = 0;
		int temp = i;
		for (int j = 0; temp > 0; j++)
		{
			op[j] = temp % 2;
			temp = temp / 2;
			count++;//count�� �����Ͽ� �Ŀ� �迭�� �� �� �ݸ������� ����
		}//0000 00000 // 0000 00001 // ~~~ // 1111 11111

		for (int k = 0; k < N - 2; k++) //K�� 9���� ����. ó���� �������� �����ϰ� +/- ����
		{
			if (op[k] == 0)
				result += arr[k+1]; //8 ���� ���� ���� ����
			else
				result -= arr[k+1];

			if (result < 0)
				break;//������ �ش� ������ �ѱ��.
		}

		if (arr[N - 1] == result)
			Answer++;
	}
	printf("%d", Answer);

	free(op);
	return 0;
}