#include <iostream>
using namespace std;

int dp[1001][10];
int main() {
	for(int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for(int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
			}
			dp[i][j] %= 10007;
		}
	}
	int n;  cin >> n;
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}
	cout << sum;
	return 0;
}