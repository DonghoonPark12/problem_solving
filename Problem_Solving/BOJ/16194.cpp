#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

//int n;
//int dp[1001];
//int value[1001];
//int idx_sum;
//int sum;
//int _max;
//void dfs(int pos) {
//	if (idx_sum > n) return;
//	if (idx_sum == n) {
//		_max = max(sum, _max);
//		return;
//	}
//	for (int i= pos; i <= n; i++) {
//		idx_sum += i;
//		sum += value[i];
//		dfs(i);
//		sum -= value[i];
//		idx_sum -= i;
//	}
//}
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		dp[i] = i;
//		cin>>value[i];
//	}
//	dfs(1);
//	cout << _max;
//+
//	return 0;
//}

int n;
int value[1001];
int dp[1001];
int main() {
    int a, b, c, d;
    scanf("(%d, %d) + (%d, %d)",&a,&b,&c,&d);
    cout<<a<<' '<<b<<' '<<c<<' '<<d;

	// cin >> n;
	// for (int i = 1; i <= n; i++) {
	// 	cin >> value[i];
	// }
    // memset(dp, 10000, sizeof(dp));
	// dp[0] = 0;
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= i; j++) {
	// 		dp[i] = min(dp[i], (dp[i - j] + value[j]));
	// 	}
	// }
	// cout << dp[n]<<'\n';
	
	return 0;
}