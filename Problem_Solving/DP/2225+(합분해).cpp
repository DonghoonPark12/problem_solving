#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 1e9;

int dp[201][201];
//int f(int n, int k) {
//	if (k == 1) 
//		return 1;
//	
//	int &ret = dp[n][k]; //������ ����
//	
//	if (ret != -1) 
//		return ret;
//	ret = 0;
//
//	for (int i = 0; i <= n; i++)
//		ret = (ret + f(n - i, k - 1)) % MOD;
//
//	return ret;
//}
//int main() {
//	memset(dp, -1, sizeof(dp));
//	int n, k; 
//	cin >> n >> k;
//	
//	cout << f(n, k);
//	return 0;
//}

int main() {
	int N, K; cin >> N >> K;
	dp[0][0] = 1LL;

	for (int k = 1; k <= K; k++) { //k���� ���ؼ�
		for (int n = 0; n <= N; n++) { //���� n�� �Ǵ� ����� ��
			for (int l = 0; l <= n; l++) {
				dp[k][n] += dp[k - 1][n - l];
				dp[k][n] %= mod;
			}
		}
	}
}