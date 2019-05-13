/*
* 10 <= can <= 100
* div<= can
* 40 12
* 40을 12 묶음으로 나누어서 최대수로 만들고자 한다.
* 4*4*4*4 *3*3*3*3 *3*3*3*3
* 5*5*5*5 *3*3*3*3 *2*2*2*2 
*/


#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	//int T, test_case;
	int TC, N, R;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &TC);

	for (int i = 1; i <= TC; ++i) {
		long long result = 1;
		scanf("%d %d", &N, &R);
		for (int j = R; j > 0; --j) {
			result *= N / j;
			N -= N / j;
		}
		printf("#%d %lld\n", i, result);
	}
	/* R = 9, N = 30
	* j = 9 (1)
	* j = 8, j > 0 (2)
	* j = 7, j > 0 (3)
	* j = 6, j > 0 (4)
	* j = 5, j > 0 (5)
	* j = 4, j > 0 (6)
	* j = 3, j > 0 (7)
	* j = 2, j > 0 (8)
	* j = 1, j > 0 (9)
	* j = 0, j > 0 : end
	*/

	/*
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		double Answer = 1;
		int can, div;
		int arr[100] = { 0 };
		scanf("%d %d\n", &can, &div);//40, 12 // 20, 5

		for (int i = 0; i < div; i++)
		{
			arr[i] = can / div;//3이 12번 들어간다.  //4가 5번 들어간다. 
		}

		for (int i = 0; i< can - (can / div)*div; i++)
		{
			arr[i] += 1;
		}

		for (int i = 0; i < div; i++)
		{
			Answer *= arr[i];
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%.0f\n", Answer);
	}
	*/

	return 0;

}