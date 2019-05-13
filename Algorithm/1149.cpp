#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define min(a,b) ((a)<=(b) ? (a) : (b))
int main(void)
{
	int N;
	int Answer = 0;
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);//ÁýÀÇ ¼ö (N,3)
	int R_, G_, B_;
	int RGB[1000][3];
	int DP[1000][3];
	//int *R = new int[N];
	//int *G = new int[N];
	//int *B = new int[N];
	//for (int i= 0; i< N; i++)
	//{
	//	cin >> R_>> G_>> B_;
	//	R[i] = R_; G[i] = G_; B[i] = B_;
	//}
	for (int i = 0; i < N; i++)
	{
		cin >> R_ >> G_ >> B_;
		RGB[i][0] = R_; RGB[i][1] = G_; RGB[i][2] = B_;
	}

	int min = N * 1000;
	int sum = 0;
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		if (j == i) continue;
	//		for (int k = 0; k < 3 ; k++) {
	//			if (k == j) continue;
	//			for (int q = 0; q < 3; q++) {
	//				sum += RGB[i][0] + RGB[j][1] + RGB[k][2] + RGB[q][3];
	//				if (sum < min)
	//					min = sum;
	//				sum = 0;
	//			}
	//		}
	//	}
	//}
	DP[0][0] = RGB[0][0]; DP[0][1] = RGB[0][1]; DP[0][2] = RGB[0][2];
	for (int i = 1; i < N; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + RGB[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + RGB[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + RGB[i][2];
	}
	printf("%d\n", min(min(DP[N-1][0], DP[N-1][1]),DP[N-1][2]));
	return 0;

}
