#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//가장 긴 감소하는 부분 수열
int arr[1001];
int dp[1001];
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max = 0;
	dp[0] = 1;//처음의 길이는  1

	int _min = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	cout << max << endl;

	return 0;
}