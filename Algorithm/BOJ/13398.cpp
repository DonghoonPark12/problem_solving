#include <iostream>
#include <algorithm>
using namespace std;
//13398. ¿¬¼ÓÇÕ2
int n, result, dp[100000][2];
int arr[100000] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i][0] = arr[i];
	}

	if (dp[0][0] < 0)
		dp[0][1] = 0;
	else
		dp[0][1] = dp[0][0];

	result = dp[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(arr[i], arr[i] + dp[i - 1][0]);
		//dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + arr[i]);
		if (arr[i] >= 0)
			dp[i][1] = dp[i - 1][1] + arr[i];
		else
			dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0] + 0);

		//result = max(result, dp[i][0]); 
		//result = max(result, dp[i][1]);
	}
	for (int i = 0; i < n; i++) {
		if (dp[i][1] > result) result = dp[i][1];
	}
	cout << result << "\n";
	return 0;
}