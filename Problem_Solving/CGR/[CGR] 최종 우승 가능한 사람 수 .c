/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

/* 
참가자 수가 N일때 '직전 종합 점수'에 마지막 점수 N을 더하여 공동 동점이 되거나 그 이상이 될 수 있으면 우승 가능성이 있다.
N명이라면 직전 라운드 최고 점수자 보다 N-1을더해서 동점이면 되니 

4명일 경우 10최대 6 7 7 최소 면 모두 포함(x) 

1
N
m라운드 까지 점수 총합 ( n(n+1)/2 )*m <-- 필요 없는 고려사항

테스트 케이스를 만들 때 각 참가자(n명)의 점수 총합은 '시그마n'의 배수 일 필요가 있다.  
ex) 5 6 7 이라면 (3+2+1) *3라운드 진행
ex) 9 6 7 8 이라면 (4+3+2+1) *3라운드 진행 <-- 필요 없는 고려사항

-> 가장 높은 점수 - (참가자 수)  보다 크기만 하면 되네.
-> 가장 낮은 점수 + (참가자수)....  이건 기준이 되지 못한다. 1점만 받은 꼴지는 기준이 되지 못한다. 
*/
#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Answer;

int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		int n; // 참가자수
		int cnt = 0;
		int score;//참가자들 점수
		int temp = 0;//최대 수를 판별할 때 쓰이는 변수.
		int *arr;
		scanf("%d", &n);
		//int arr[] = { 0 }; //배열의 크기는 상수로 미리 정해야 하는 단점
		
		arr = (int *)malloc(sizeof(int) * n);//참가자 수 만큼의 (int) 동적 할당.

		for (int i = 0; i < n; i++) //배열에 넣는게 Sorting하는데(X) 최대수 뽑아내는데(O) 편하지 않을까. 다른 좋은 방법 있나?
		{
			scanf("%d", &score);
			arr[i] = score;
		}

		for (int j = 0; j < n; j++) //참가자 중 가장 높은 점수를 찾아낸다.
		{							
			if (arr[j] > temp)
			{
				temp = arr[j];
			}
		}

		for (int k = 0; k < n; k++)//n명의 참가자 중 (가장 높은 점수 - 참가자수) 보다 초과하는 인원수를 카운트 한다.
		{
			if (arr[k] > temp-n)
			{
				cnt++;
			}
		}
		Answer = cnt;
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}