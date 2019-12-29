#include <iostream>
#include <algorithm>
using namespace std;

// dfs�� Ǯ�� �ð� �ʰ� ����. 
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

//11052 ī�� �����ϱ�
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	for (int i = 1; i <= n; i++) { //n���� �����ϱ� ���� �ִ� �ݾ�
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], (dp[i - j] + value[j]));
		}
	}
	cout << dp[n];

	return 0;
}

//16194 ī�� �����ϱ�2
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	dp[0] = 0x7fffffff;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = min(dp[i], (dp[i - j] + value[j]));
		}
	}
	cout << dp[n];
	
	return 0;
}