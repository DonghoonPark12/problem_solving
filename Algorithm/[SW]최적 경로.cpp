#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define abs(x)		(((x)>0) ? : (x), (-x))
#define dist(x,y,xd,yd)		( abs((xd)-(x)) + abs((yd)-(y)) )	

int arr[12][2] = { 0 };//고객수 최대 10명 + 집 + 회사
int dist[12][12] = { 0 };//사이 간격, 최대 200



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
		int n;//고객 집 수
		int f = 0;
		scanf("%d", &n);
		for (int i = 0; i < n + 2; i++)
		{
			if (f == 0) {scanf("%d", &(arr[i][0])); f = 1;}
			if (f == 1) {scanf("%d", &(arr[i][1])); f = 0;}
		}
		//arr[0][0]: 회사 x 좌표, arr[0][1] : 회사 y 좌표
		//arr[1][0]: 집 x좌표, arr[1][1] :집 y좌표
		//arr[2][0] ~ arr[n + 1][0] : 고객 x좌표

		for (int s = 2; s <= n + 1; s++) {
			for (int d = 2; d <= n + 1; d++) {
				dist[s][d] = dist(arr[s][0], arr[s][1], arr[d][0], arr[d][1]);
			}
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}