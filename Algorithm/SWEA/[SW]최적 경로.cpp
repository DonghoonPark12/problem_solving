#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define abs(x)		(((x)>0) ? : (x), (-x))
#define dist(x,y,xd,yd)		( abs((xd)-(x)) + abs((yd)-(y)) )	

int arr[12][2] = { 0 };//���� �ִ� 10�� + �� + ȸ��
int dist[12][12] = { 0 };//���� ����, �ִ� 200



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
		int n;//�� �� ��
		int f = 0;
		scanf("%d", &n);
		for (int i = 0; i < n + 2; i++)
		{
			if (f == 0) {scanf("%d", &(arr[i][0])); f = 1;}
			if (f == 1) {scanf("%d", &(arr[i][1])); f = 0;}
		}
		//arr[0][0]: ȸ�� x ��ǥ, arr[0][1] : ȸ�� y ��ǥ
		//arr[1][0]: �� x��ǥ, arr[1][1] :�� y��ǥ
		//arr[2][0] ~ arr[n + 1][0] : �� x��ǥ

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