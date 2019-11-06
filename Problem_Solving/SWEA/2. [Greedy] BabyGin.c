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
		/* 나의 방식 */
		/* 숫자를 배열에 저장한 후, 소팅 */
		/* 이후 Greedy */ // 허나 반례가 있었다.
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


		// 2) 예제
		//들어온 갯수(카운트된 갯수) 만큼을 배열에 저장하는 것도 한 방식
		// ex) 012666 -> 1 1 1 0 0 0 3
		// ex) 123123 -> 0 2 2 2 0 0 0
		//왜 숫자를 받으면 그대로 배열에 입력할 생각 밖에 못할까
		//거스름돈 문제도 해당 배열(거스름돈 액수 index)를 카운트 하고 Greedy로 풀듯이, BabyGin 문제도 들어온 수마다 Index를 카운트++ 하고 Greedy로 풀면 편하다. 
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



