#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	
	//1
	//890 (���� ��)
	

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int i = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int money;
		int coins[] = { 500, 250, 100, 50, 10 };//�Ž����� ���� ���� �迭
		int count[5];

		scanf("%d", &money);
		
		while (money != 0)
		{
			if (money < 0) // -110���̴�
			{
				count[i]--; // �ٽ� ȸ��
				money += coins[i]; //�ٽ� ���ؼ� 390�� �����.
				i++; //���� �ذ�å �غ�: �Ѵܰ� ���� ������ �Ž����� �غ�
			}
			else
			{
				count[i]++;//500�� 1�� �غ� //500�� �Ѱ� �� �غ�
				money -= coins[i]; //500���� ���� => 390 //500�� ���� => -110
			}
		}
		// ���� ī��Ʈ �Ŀ� ��ü ������ ���� ���� �λ���
		// ������ ������ �ٽ� �ǵ��� ���� �͵� �λ���
		// ���� ���� �ܰ� �غ�

		for (int i = 0; i < 5; i++)
		{
			printf("Coin %d : %d\n", coins[i], count[i]);
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////
	}

	printf("Case #%d ", test_case + 1);
	printf("%d\n", Answer);

	return 0;

}