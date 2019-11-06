#include <iostream>
using namespace std;
/*
1,2,3 더하기
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
*/
int total_num(int count, int sum, int goal) {
	if (sum > goal) return 0;
	if (sum == goal) return 1;
	int res = 0;
	for(int i = 1; i <= 3; i++) {
		res += total_num(count + 1, sum + i, goal);
	}
	return res;
}

/*
1,2,3 더하기 3
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
*/
//long long dp[1000001] = { 0, 1, 2, 4 };
//int main() {
//	int tc; cin >> tc;
//
//	for (int i = 4; i <= 1000000; i++) {
//		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%1000000009;
//	}
//	while (tc--) {
//		int n; cin >> n;
//		cout << dp[n] << '\n';
//	}
//	return 0;
//}
/*
1,2,3 더하기 5 ( 같은 수를 두 번 이상 연속해서 사용하면 안 된다.)

1+2+1
1+3
3+1
*/

long long dp[100000][4];
int main() {
	dp[1][1] = 1, dp[1][2] = dp[1][3] = 0;
	dp[2][1] = 0, dp[2][2] = 1, dp[2][3] = 0;
	dp[3][1] = 1, dp[3][2] = 1, dp[3][3] = 1;
	int tc; cin >> tc;
	int n;
	for (int i = 4; i <= 100000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
	}
	while (tc--) {
		cin >> n;
		cout << (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009 << '\n';
	}
	
	return 0;
}
