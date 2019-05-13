#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int Max(int a, int b) { return a > b ? (a) : (b); }

void main() {
	freopen("input.txt", "r", stdin);
	int i, j, n, max = 0; int arr[501][501] = { 0 }; cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			cin >> arr[i][j];
			if (j == 1) arr[i][j] = arr[i - 1][j] + arr[i][j];
			else if(j==i) arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
			else arr[i][j] = Max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	cout << max;
}
//#define max(a,b) ((a) >= (b) ? (a) : (b))
//int main(void){
//	int n;
//	freopen("input.txt", "r", stdin);
//	int input;
//	cin >> n;
//	int tri[499][499];
//	int reward[499][499];
//	for (int i = 0; i < n; i++) {
//		for(int j = 0; j < i + 1; i++) {
//			cin >> input;
//			tri[i][j] = input;
//		}
//	}
//
//	reward[0][0] = tri[0][0];
//	for (int h = 1; h < n; h++) {
//		reward[h][0] = reward[h - 1][h] + tri[h][0];
//		reward[h][h] = reward[h - 1][h - 1] + tri[h][h];
//		for (int i = 1; i < h; i++) {
//			reward[h][i] = max(reward[h - 1][i], reward[h - 1][i - 1]) + tri[h][i];
//		}
//	}
//	
//	int max = 0;
//	for (int i = 0; i < n; i++) {
//		if (reward[n - 1][i] > max)
//			max = reward[n - 1][i];
//	}
//	printf("%d\n", max);
//	return 0;
//}