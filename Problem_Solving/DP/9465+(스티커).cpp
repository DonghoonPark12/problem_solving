#include <iostream>
#include <algorithm>
using namespace std;

// My first method (5108KB, 296ms) --> (5108KB, 84ms)
/*
	���� : �ڵ带 ȿ�����̰� �ۼ��� ���̾���.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	�Ʒ��� ÷�����ִ�, ��� ��Ⱥ��� ȿ���� ���Ҵ�.
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
		dp[0][0] = 0;         //���� ����
		dp[0][1] = arr[0][0]; //������ ����
		dp[0][2] = arr[1][0]; //�Ʒ����� ����
		for (int i = 1; i < n; i++) {
			//1) ���� �ܰ迡�� ���� �ʴ� ����, ���� ĭ����(���� �ʰų�, ���� ��ų�, �Ʒ��� ��ų�) ��� ���� �� �����ϴ�.
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])); 
			//2) ���� �ܰ迡�� ������ ��� ����, ���� ĭ���� �Ʒ��� ��ų�, (����ĭ���� �Ʒ����� �� ���� ��������) ���� �ʾҴ� ���� ���Ѵ�.
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + arr[0][i];
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + arr[1][i];
		}
		cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]) << '\n';
	}
	return 0;
}

