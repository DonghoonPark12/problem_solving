#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	/////////////////////////////////////////////////////////////////////////////////////////////////
	int a;
	int money;
	scanf("%d", &a);
	money = 1000 - a;
	
	int coins[6] = {500,100,50, 10, 5, 1 };
	int count[6] = { 0 };

	int i = 0;
	while (money != 0)
	{
		if (money < 0)
		{
			count[i]--;
			money += coins[i];
			i++;// 다음 거스름돈 준비
		}
		else
		{
			count[i]++;
			money -= coins[i];
		}
	}

	for (int i = 0; i < 6; i++)
	{
		Answer += count[i];
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////
		//printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	return 0;

}