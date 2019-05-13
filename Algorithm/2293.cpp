#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//int cnt = 0;
//int sum = 0;
//int mem[10][10];
//void recur(int value, int goal) {
//	if (value == goal) {
//		cnt++;
//		return;
//	}
//	recur(value + 1, goal);
//	recur(value + 2, goal);
//	recur(value + 5, goal);
//	return;
//}
//int main(void)
//{
//	int M,N;
//	int Answer = 0;
//	//freopen("input.txt", "r", stdin);
//	cin >> M>>N;
//	memset(mem, -1, sizeof(mem));
//
//	recur(0, N);
//	cout << cnt;
//
//	return 0;
//
//}

int main() {
	int n, k;
	int c[101];
	int dp[10001] = { 0 };
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k ; j++) {
			if (j >= c[i]) {
				dp[j] += dp[j - c[i]];
			}
		}
	}
	cout << dp[k];
	return 0;
}