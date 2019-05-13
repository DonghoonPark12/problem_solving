#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int arr[1000]; 

int main() {
	int test_case, T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {
		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int *dp = (int *)malloc(sizeof(int) * n);

		int max = 0;
		dp[0] = 1;//처음의 길이는  1

		for (int i = 1; i < n; i++) {
			dp[i] = 1;

			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
			if (max < dp[i]) 
				max = dp[i];
		}
		cout << max << endl;

		free(dp)
	}
	return 0;
}