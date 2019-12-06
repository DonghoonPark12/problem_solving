#include <iostream>
#include <vector>
using namespace std;
//1, 2, 3 더하기
/*
//중복 순열로 풀 경우

vector<int> num;
vector<int> pick;

int ans;
int sum;

void dfs(int goal) {
	sum = 0;
	for (int i = 0; i < pick.size(); i++)
		sum += pick[i];
	if (sum > goal) return;
	if (sum == goal) {
		ans++;
		return;
	}
	for (int i = 0; i < num.size(); i++) {
		pick.push_back(num[i]);
		dfs(goal);
		pick.pop_back();
	}
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= 3; i++)
		num.push_back(i);
	while (t--) {
		int n; cin >> n;
		ans = 0;
		dfs(n);
		cout << ans << '\n';
	}
	return 0;
}
*/

//DP로 풀 경우

int main() {
	int t; cin >> t;
	int dp[12];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	while (t--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}