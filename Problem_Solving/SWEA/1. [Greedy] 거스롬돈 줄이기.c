#include <stdio.h>

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);
	
	//1
	//890 (받은 돈)
	

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int i = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int money;
		int coins[] = { 500, 250, 100, 50, 10 };//거스름돈 종류 담은 배열
		int count[5];

		scanf("%d", &money);
		
		while (money != 0)
		{
			if (money < 0) // -110원이다
			{
				count[i]--; // 다시 회복
				money += coins[i]; //다시 더해서 390원 만든다.
				i++; //다음 해결책 준비: 한단계 작은 단위의 거스름돈 준비
			}
			else
			{
				count[i]++;//500원 1개 준비 //500원 한개 더 준비
				money -= coins[i]; //500원을 뺀다 => 390 //500원 뺀다 => -110
			}
		}
		// 먼저 카운트 후에 전체 돈에서 빼는 것이 인상적
		// 빼고나서 음수면 다시 되돌려 놓는 것도 인상적
		// 이후 차선 단계 준비

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