#include <iostream>
#include <vector>
using namespace std;

int D, W, K;
vector<vector<int>> arr(D, vector<int>(W));

bool performance_check() {
	int cur, prev;
	int cnt;
	vector<int> satisfy(W, 0);
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < D; j++) {
			cnt = 0;
			cur = arr[j][i];
			if (j != 0 && cur == prev) cnt++;
			else if (j == 0) cnt++;
			else if (cur != prev) cnt = 0;
			else {}

			if (cnt >= K)
				satisfy[i] = 1; //i, not j
			prev = arr[j][i];
		}
	}

	int sum = 0;
	for (int i = 0; i < W; i++) {
		sum += satisfy[i];
	}
	return sum == W ? true : false;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> D >> W >> K;

		//Data input
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}

	}
}