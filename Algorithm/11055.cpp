#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int arr[1000];
int dp[1000];
int main() {
	//int test_case, T;
	freopen("input.txt", "r", stdin);

		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int max = 0;
		for (int i = 0; i < n; i++) {
			dp[i] = arr[i];

			for (int j = 0; j <= i; j++) {
				if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) {
					dp[i] = dp[j] + arr[i];
				}
			}
			max = max > dp[i] ? max : dp[i];
		}
		cout << max << endl;

	return 0;
}