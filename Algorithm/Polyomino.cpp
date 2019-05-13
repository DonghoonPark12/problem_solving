#include <iostream>
#include <vector>
using namespace std;
const int MOD = 10 * 1000 * 1000;
long long poly(vector<vector<long long>> D, int N) {
	for (int n = 1; n <= N; n++) {
		for (int down = 1; down <= n; down++) {
			for (int i = 1; i <= n - down; i++) {
				D[n][down] += D[n - down][i] * (down + i - 1);
			}
			if (n == down)
				D[n][down] = 1;
			D[n][down] %= MOD;
		}
	}

	long long ans = 0;
	for (int down = 1; down<= N; down++) {
		ans += D[N][down];
		ans %= MOD;
	}

	return ans ;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n; cin >> n;
		vector<vector<long long>> D(101, vector<long long>(101));
		cout << poly(D, n) << endl;;
	}
	return 0;
}