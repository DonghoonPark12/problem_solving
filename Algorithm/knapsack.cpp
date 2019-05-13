#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#define max(x,y) ((x)>(y)? x : y)
using namespace std;


//int C; //최대가치 


/*
	arr[0][0] - 물건의 부피
	arr[0][1] - 물건의 가치
*/
//int v;
//int c;
//int f(int i) {
//	 v += arr[i][0];
//	 c += arr[i][1];
//	 if (v > K) //최대 부피를 넘어가면 프로그램 종료
//		 return 0;
//
//	 if (v == K && c > C)// 물건을 더한 부피가 가방의 부피와 같고, 더한 가치가 저장된 가치보다 클때
//		 c = C;
//
//	 f(i + 1);
//
//
//}

//int KS(int W, int *wt, int *val, int N) { //용량, 부피, 가치, 갯수
//	if (W == 0 || N == 0) //최대 용량이 0이거나, 물건의 갯수가 0이면 최대 가치는 0
//		return 0;
//
//	else if (wt[N-1] > W) //부피 > 최대 수용량
//		return  KS(W, wt, val, N-1);
//
//	else {
//		return max(KS(W, wt, val, N - 1),
//			       val[N - 1] + KS(W - wt[N - 1], wt, val, N - 1));
//	}
//}

int d[1001][101];
int val[101];
int wt[101];

int knapSack(int W, int wt[], int val[], int N) 
{
	for (int w = 1; w <= W; w++)
	{
		for (int n = 1; n <= N; n++)
		{
			if (w >= wt[n]) 
				d[w][n] = max(d[w][n - 1], d[w - wt[n]][n - 1] + val[n]);
			else 
				d[w][n] = d[w][n - 1];
		}
	}
	return d[W][N];
}


//int knapSack(int W, int wt[], int val[], int n)
//{
//	int k[1001][101];
//
//	for (int i = 0; i < n; i++) {
//		for (int w = 0; w <= W; w++) {
//			if (i == 0 || w == 0)
//				k[i][w] = 0;
//			else if (wt[i - 1] <= w)
//				k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
//			else
//				k[i][w] = k[i - 1][w];
//		}
//	}
//	return k[n][W];
//}



int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	int T;

	scanf("%d", &T); //1

	for (int tc = 0; tc < T; tc++) {
		int N, W; //물건 갯수와 가방 수용 무게
		scanf(" %d %d", &N, &W); //4 5
		for (int i = 1; i <= N; i++) {
			scanf(" %d %d", wt+i, val+i);
		}
		printf("#%d %d\n", tc + 1, knapSack(W, wt, val, N)); //최대가치
	}

	return 0;
}


