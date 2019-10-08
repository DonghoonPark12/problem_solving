#include <iostream>
#include <algorithm>
using namespace std;
/*
	포도주 시식
*/
int n, arr[10001], dp[10001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] = max(dp[i], dp[i - 2] + arr[i]);
		dp[i] = max(dp[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n];
	return 0;
}
