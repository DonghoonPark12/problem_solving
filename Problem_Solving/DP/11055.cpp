#include <iostream>
#include <cstdio>
using namespace std;

//가장 큰 증가하는 부분수열

int arr[1001];
int dp[1001];
int main() {
	int n; cin >> n;

	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	int max;
	max = dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = arr[i];

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) { //LIS와는 다르게 1--> arr[i]로 바꾸면 된다.
				dp[i] = dp[j] + arr[i];
			}
		}
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	cout << max << endl;

	return 0;
}