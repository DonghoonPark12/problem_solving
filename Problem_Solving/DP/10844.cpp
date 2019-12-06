#include <iostream>
using namespace std;
const int mod = 1e9;

// ���� ��� ��

long long dp[101][10]; //�ִ� 100 ���� �� ����. ������ ��° ���� 0 ~ 9���� ���� ����

int main() {
	//1�� ���� �ڰ� � ���� �͵� ��ܼ��� 1.
	int n; cin >> n;
	//dp[i][0] = 0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	//2��° �ڸ� �� ����
	for (int i = 2; i <= n; i++) { 
		for (int j = 0; j <= 9; j++) {
			//if (j == 0) dp[i][j] = dp[i - 1][j + 1];
			//else if (j == 9) dp[i][j] = dp[i - 1][j - 1];
			//else {
			//	dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
			//}
			dp[i][j] = 0;
			if (j >= 1) dp[i][j] += dp[i - 1][j - 1]; //ex) dp[1][0] = 0; dp[2][1] = 1 <-- dp[1][0] + dp[1][2]
			if (j <= 8) dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int j = 0; j <= 9; j++)
		ans += dp[n][j];
	ans %= mod;
	cout << ans;
	return 0;
}


//int n;
//int dp[105][10];
//int rec(int cur, int pre)
//{
//	if (cur >= n)
//		return 1;
//	
//	int& ret = dp[cur][pre];
//	
//	if (ret)
//		return ret;
//
//	if (pre)
//		ret += rec(cur + 1, pre - 1);
//	
//	ret %= mod;
//	
//	if (pre<9)
//		ret += rec(cur + 1, pre + 1);
//	
//	ret %= mod;
//	return ret;
//}
//int main()
//{
//	cin >> n;
//	int ans = 0;
//	for (int i = 1; i <= 9; ++i)
//		ans = (ans + rec(1, i)) % mod;
//	cout << ans;
//	return 0;
//}

