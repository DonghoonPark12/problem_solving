#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case=0;
	int Answer = 0;
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	//scanf("%d", &T);
	//for (test_case = 0; test_case < T; test_case++)
	//{
		int input;
		int arr[10] = { 0 };
		int tri = 0;
		int run = 0;
		/* ���� ��� */
		/* ���ڸ� �迭�� ������ ��, ���� */
		/* ���� Greedy */ // �㳪 �ݷʰ� �־���.
		////////////////////////////////////////////////////////////////////////////////////////		
		/*
		scanf("%d", &input);
		for (int i = 0; i < 6; i++)
		{
			scanf("%1d", &input);
			arr[input]++;
		}
		*/


		/////////////////////////////////////////////////////////////////////////////////////////


		// 2) ����
		//���� ����(ī��Ʈ�� ����) ��ŭ�� �迭�� �����ϴ� �͵� �� ���
		// ex) 012666 -> 1 1 1 0 0 0 3
		// ex) 123123 -> 0 2 2 2 0 0 0
		//�� ���ڸ� ������ �״�� �迭�� �Է��� ���� �ۿ� ���ұ�
		//�Ž����� ������ �ش� �迭(�Ž����� �׼� index)�� ī��Ʈ �ϰ� Greedy�� Ǯ����, BabyGin ������ ���� ������ Index�� ī��Ʈ++ �ϰ� Greedy�� Ǯ�� ���ϴ�. 
		/////////////////////////////////////////////////////////////////////////////////////////
		//scanf("%d", &input);
		for (int i = 0; i < 6; i++)
		{
			//arr[(input % 10)]++;
			//input /= 10;
			scanf("%1d", &input);
			arr[input]++;
		}

		for (int i = 0; i < 10; i++)
		{
			if (arr[i] >= 3)
			{
				arr[i] -= 3;
				tri++;
				i++;
			}
			if ((arr[i] >= 1) && (arr[i + 1] >= 1) && (arr[i + 2] >= 1))
			{
				arr[i] -= 1;
				arr[i + 1] -= 1;
				arr[i + 2] -= 1;
				run += 1;
				i++;
			}
		}

		//printf("Case #%d ", test_case + 1);

		if (run + tri == 2)
			printf("Baby Gin");
		else
			printf("Lose");

		/////////////////////////////////////////////////////////////////////////////////////////
	//}


	//printf("Case #%d ", test_case + 1);
	//printf("%s\n", Answer);

	return 0;

}



