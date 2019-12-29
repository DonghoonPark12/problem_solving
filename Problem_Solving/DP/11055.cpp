#include <iostream>
#include <cstdio>
using namespace std;

//���� ū �����ϴ� �κм���

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
			if (arr[i] > arr[j] && dp[j] + arr[i] > dp[i]) { //LIS�ʹ� �ٸ��� 1--> arr[i]�� �ٲٸ� �ȴ�.
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