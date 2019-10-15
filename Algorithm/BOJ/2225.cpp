#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9;

int dp[201][201];
int f(int n, int k) {
	if (k == 1) return 1;
	int &ret = dp[n][k]; //참조자 선언
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i <= n; i++)
		ret = (ret + f(n - i, k - 1)) % MOD;

	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n, k; cin >> n >> k;
	cout << f(n, k);
	return 0;
}