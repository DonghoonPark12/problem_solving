#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int Max(int a, int b) { return a > b ? a : b; }
int main(void)
{
	int Answer = 0;
	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	int stair[301] = { 0 }; //내가 헷갈리지 않기 위해서 idx:1을 첫번째 계단으로 하였다면 첫번째 stair[1] 부터 입력이 들어간다. 
	int reward[301] = { 0 }; //그러므로 계단 갯수가 300이 최대일때, 300개의 변수를 담으려면 stair[301]을 선언해야 한다. 
	for (int i = 1; i <= n; i++) { cin >> stair[i]; }
	reward[0] = stair[0];
	reward[1] = stair[1];
	reward[2] = stair[1] + stair[2];
	for (int i = 3; i <= n; i++) {
		cout << reward[i - 2] + stair[i] << endl;
		cout << reward[i - 3] + stair[i - 1] + stair[i] << endl;
		reward[i] = Max(reward[i - 2] + stair[i], reward[i - 3] + stair[i - 1] + stair[i]);
	}
	cout << reward[n]<<endl;
	return 0;
}


//int n, stair[301];
//int dp[301];
//
//int Max(int a, int b) {
//	return a > b ? a : b;
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> stair[i];
//	}
//
//	dp[0] = stair[0];
//	dp[1] = Max(stair[0] + stair[1], stair[1]);
//	dp[2] = Max(stair[0] + stair[2], stair[1] + stair[2]);
//
//	for (int i = 3; i < n; i++) {
//		dp[i] = Max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
//	}
//
//	cout << dp[n - 1] << '\n';
//
//	return 0;
//}
