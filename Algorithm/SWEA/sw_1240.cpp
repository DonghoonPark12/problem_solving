#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//int arr[50][100] = { 0 };
char str[100] = { 0 };
int binary[56] = { 0 }; //��ȣ�� ���� ����
//��ȣ�� 8�ڸ� ��
//0001101 (0) //13
//0011001 (1) //25
//0010011 (2) //19
//0111101 (3) //61
//0100011 (4) //35
//0110001 (5) //49
//0101111 (6) //47
//0111011 (7) //59
//0110111 (8) //55
//0001011 (9) //11
int decode(int n)
{
	int num;
	switch (n) {
	case 13:
		num = 0;
		break;
	case 25:
		num = 1;
		break;
	case 19:
		num = 2;
		break;
	case 61:
		num = 3;
		break;
	case 35:
		num = 4;
		break;
	case 49:
		num = 5;
		break;
	case 47:
		num = 6;
		break;
	case 59:
		num = 7;
		break;
	case 55:
		num = 8;
		break;
	case 11:
		num = 9;
		break;
	}
	return num;

}
int bin_to_deci(int i)//7�ڸ� 2������ 10������ �ٲ��ִ� �Լ�
{
	int position = 6;
	int deci = 0;

	int n = 7;
	while (n--)
	{
		if (binary[i++] == 1)
			deci += 1 << position;
		position--;
	}
	return deci;
}



int main(void)
{
	int n, m;
	int T,test_case;
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int flag = 0; //��ȣ�� �Է� ������ �˸��� ����
		int pass = 0;//������ �� ex)80
		int sum = 0;//��ȣ�ڵ�鿡 ���Ե� ���� �� ex)38
		scanf("%d %d\n", &n,&m);

		for (int i = 0; i < 56; i++) binary[i] = 0;//�ʱ�ȭ 

		int k = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			for (int j = m-1; j >=0; j--)
			{
				//arr[i][j] = str[j] - '0';
				if (str[j] - '0' != 0) flag = 1; //��ȣ�� �Է� ����
				
				if (flag && 55-k>=0)
					binary[55 - k++] = str[j] - '0';
			}
			//if (flag) break; ���� ������ �� ���� �׽�Ʈ ���̽� ������ �ȵȴ�. 
		}
		// ��ȣ �ڵ� ����
		int z = 0;
		for (int i = 0; i < 56; i +=7)
		{
			int decimal = bin_to_deci(i);

			if (z == 0) {
				pass += 3 * decode(decimal);
				sum += decode(decimal);
				z = 1;
			}
			else {
				pass += decode(decimal);
				sum += decode(decimal);
				z = 0;
			}
		}

		if (pass % 10 == 0)
			printf("#%d %d\n", test_case + 1, sum);
		else
			printf("#%d %d\n", test_case + 1, 0);

	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;

}