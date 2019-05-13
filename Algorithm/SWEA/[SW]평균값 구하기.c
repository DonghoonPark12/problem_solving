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
		printf("%.0f\n", sum); // float형으로 출력하되, 소수점 0번째(아예 안나타냄)짜리 까지 출력하겠다. 
	}



	return 0;

}