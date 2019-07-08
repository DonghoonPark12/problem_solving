#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 2차원 배열문제
//다익스트라 알고리즘

int arr[100][100];
int data[100][100];
char str[100];
int n;
int f(int x, int y){
		sum = f(x, y);

		if (x == n - 1 && y == n - 1)
			min = sum < min ? sum : min;


		f(x + 1, y);
		f(x - 1, y);
		f(x, y + 1);
		f(x, y - 1);

}

int main(void)
{
	int T, test_case;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			for (int j = 0; j < n; j++) {
				arr[i][j] = str[j] - '0';
			}
		}
		Answer = f(1,1);//전역변수로 배열을 선언한뒤, 좌표만 넘긴다. 
		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}