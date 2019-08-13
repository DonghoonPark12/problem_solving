#include <iostream>
using namespace std;

//int d[1000001];

//11726
//int dp(int n) {
//	if (n == 1) return 1;
//	if (n == 2) return 2;
//	if (d[n] != 0) return d[n];
//	return d[n] = (dp(n - 1) + dp(n - 2)) % 10007;
// }

//11727
//int dp(int n) {
//	if (n == 1) return 1;
//	if (n == 2) return 3;
//	if (d[n] != 0) return d[n];
//	return d[n] = (dp(n - 1) + dp(n - 2)*2) % 10007;
// }

//2133
//int dp(int n) {
//	if (n == 0) return 1;
//	if (n == 1) return 0;
//	if (n == 2) return 3;
//	//if (n == 4) return 11;
//	if (d[n] != 0) return d[n];
//
//	int tmp = dp(n - 2) * 3;
//
//	for (int i = 4; i <= n; i += 2) {
//		tmp += dp(n - i) * 2; //4개 전부터 2개씩 더 작아지는 경우는 다르게 계산해야 한다. 
//	}
//
//	return d[n] = tmp;
//}

//2133
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	dp[0] = 1;
//	dp[1] = 0;
//	dp[2] = 3;
//	for (int i = 3; i <= n; i++) {
//		dp[i] += dp[i - 2] * 3; //2개 전의 갚으로 미리 채워 넣고, 
//
//		for (int j = 4; j <= i; j += 2) 
//			dp[i] += dp[i - j] * 2; //i의 4개전 부터 2개씩 더 작은 경우는 다르게 계산한다. 
//	}
//
//	printf("%d\n", dp[n]);
//
//	return 0;
//}

//14852 - run time error
//int _d[1000001];
//int dp(int n) {
//	if (n == 0) return 1; //Important, but not intuitively
//	if (n == 1) return 2;
//	if (n == 2) return 7;
//	if (_d[n] != 0) return _d[n];
//	int tmp = (dp(n - 2) * 3 + dp(n - 1) * 2) % 1000000007;
//	
//	for (int i = 3; i <= n; i++) {
//		tmp += (dp(n - i) * 2) % 1000000007;
//	}
//	return _d[n] = tmp % 1000000007;
//}
//
////14852
//long long d[1000001][2];
//long long dp2(int n) {
//	d[0][0] = 1;
//	d[1][0] = 2;
//	d[2][0] = 7;
//	d[2][1] = 0;
//	for (int i = 3; i <= n; i++) {
//		d[i][1] = (d[i - 1][1] + d[i - 3][0]) % 100000007;
//		d[i][0] = (3 * d[i - 2][0] + 2 * d[i - 1][0] + 2 * d[i][1]) % 100000007;
//	}
//	return d[n][0];
//
//}

long long dp[1000001];
long long dp2[1000001];
long long dp3(int n) {
	//long dp[] = new long[N + 10]; 
	//long dp2[] = new long[N + 10];
	dp[1] = 2;
	dp[2] = 7;
	dp[3] = 22;
	dp2[3] = 1; 
	for (int i = 4; i <= 1000001; i++) {
		dp2[i] = (dp2[i - 1] + dp[i - 3]) % 1000000007;
		dp[i] = (dp[i - 2] * 3 + dp[i - 1] * 2 + dp2[i] * 2) % 1000000007;
	}
	return dp[n];
}

int main() {
	int n; cin >> n;

	cout << dp3(n);

	return 0;
}