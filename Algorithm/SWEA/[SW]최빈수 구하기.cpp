#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>

int arr[101]; //0�� ���� ~ 100������

int main()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);


	for(int tc=0;tc<10;tc++)
	{
		int n;
		scanf("%d", &n);
		int tmp = 0;
		//int Ans = 0;

		for (int i = 0; i <= 100; i++) 	arr[i] = 0;//�迭 �ʱ�ȭ

		for (int i = 0; i < 1000; i++)
		{
			scanf(" %d", &tmp); //41�� ������
			arr[tmp]++;//���� ������ �ε����� ++
		}

		int max = 0;//���� ���� ��Ÿ�� ���� ��� ��Ÿ������
		int idx = 0;//���� ���� ��Ÿ�� ���� ��� ��°�� ��ġ �ϴ���
		for (int i = 0; i <= 100; i++)
		{
			//�ε����� ������, ���ڰ� �� ũ�� �ֺ��
			if (arr[i] >= max) {//�� ���� ũ�� �ֺ��
				max = arr[i];
				idx = i;
			}
		}

		printf("#%d %d\n", n, idx);
	}

	return 0;
}



//�ֺ���� �������� ��� ���� ū ���� ���