#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int arr[5000];//���� ����
int arr_s[400001];//������ ����???

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int TC, test_case, T, i, j, num, a;
	int good;
	scanf("%d", &TC);

	for (test_case = 0; test_case < TC; test_case++)
	{
		memset(arr_s, 0, sizeof(arr_s));
		good = 0;
		scanf("%d", &T);
		for (i = 0; i < T; i++)
		{

			scanf("%d", &arr[i]);
			//���Ѽ� ���� üũ
			// ù��°�� ��� ������ ���Ѽ��� �ƴϴ�. ������ i = 0 �϶� ã�� �ʰ� ����
			// i ���� i - a , a-1>=0 �϶����� ���鼭 �ΰ� ���� ���� i - a �� ���� ã�´�.
			for (j = i - 1; j >= 0; j--)
			{
				if (arr_s[arr[i] - arr[j] + 200000] == 1)
				{
					good++;
					break;
				}//if
			}//for
			 //������ �տ� ��Ī �Ǵ� ���, �޸� ������ 1 ����
			 // ex arr_s[10 + 200000] = 1�̶�� ���� �� ���� ���� 10�� �Ǵ� �� ���� �����Ѵٴ� ��
			for (j = 0; j <= i; j++)
				arr_s[arr[i] + arr[j] + 200000] = 1;

		}//for		
		printf("Case #%d\n%d\n", test_case + 1, good);
	}//for
	return 0;
}