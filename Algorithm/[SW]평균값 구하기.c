#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case;
	
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		float sum = 0;
		int temp;
		for (int i = 0; i < 10; i++)
		{
			scanf("%d", &temp);
			if(temp %2 !=0)
			sum += temp;
		}
		//sum = sum / 10;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%.0f\n", sum); // float������ ����ϵ�, �Ҽ��� 0��°(�ƿ� �ȳ�Ÿ��)¥�� ���� ����ϰڴ�. 
	}



	return 0;

}