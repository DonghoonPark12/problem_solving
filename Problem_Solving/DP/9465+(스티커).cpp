#include <iostream>
#include <algorithm>
using namespace std;

// My first method (5108KB, 296ms) --> (5108KB, 84ms)
/*
	고찰 : 코드를 효율적이게 작성한 것이었다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	아래를 첨부해주니, 모범 답안보다 효율이 좋았다.
*/
//int arr[2][100001];
//int dp[2][100001];
//int main() {
//	int tc; cin >> tc;
//	while (tc--) {
//		int n; cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[0][i];
//		}
//		for (int i = 0; i < n; i++) {
//			cin >> arr[1][i];
//		}
//		dp[0][0] = arr[0][0]; 
//		dp[1][0] = arr[1][0];
//
//		dp[0][1] = arr[1][0] + arr[0][1];
//		dp[1][1] = arr[0][0] + arr[1][1];
//		for (int i = 2; i < n; i++) {
//			dp[0][i] = max(dp[1][i - 1] + arr[0][i], dp[1][i - 2] + arr[0][i]);
//			dp[1][i] = max(dp[0][i - 1] + arr[1][i], dp[0][i - 2] + arr[1][i]);
//		}
//		cout << max(dp[0][n-1], dp[1][n - 1])<<'\n';
//	}
//	return 0;
//}

//long long arr[100001][2];

 //My second method (5872KB, 308ms) --> (5872KB, 88ms)
long long arr[2][100001]; 
long long dp[100001][3];

int main() {
	int tc; cin >> tc;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (tc--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {	cin >> arr[0][i];	}
		for (int i = 0; i < n; i++) {	cin >> arr[1][i];	}
		dp[0][0] = 0;         //뜯지 않음
		dp[0][1] = arr[0][0]; //위쪽을 뜯음
		dp[0][2] = arr[1][0]; //아래쪽을 뜯음
		for (int i = 1; i < n; i++) {
			//1) 현재 단계에서 뜯지 않는 경우는, 이전 칸에서(뜯지 않거나, 위쪽 뜯거나, 아래쪽 뜯거나) 모두 경우와 비교 가능하다.
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])); 
			//2) 현재 단계에서 위쪽을 뜯는 경우는, 이전 칸에서 아래쪽 뜯거나, (전전칸에서 아래쪽을 뜯어서 같이 떨어져서) 뜯지 않았던 경우와 비교한다.
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + arr[0][i];
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + arr[1][i];
		}
		cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << '\n';
	}
	return 0;
}

