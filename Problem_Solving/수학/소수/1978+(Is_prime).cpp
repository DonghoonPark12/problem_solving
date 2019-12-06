#include <iostream>

using namespace std;

bool is_prime(int n) {
	if (n == 1) return false;

	for (int i = 2; i * i <= n; i++) {// (2 ~ i*i<= n) <-- (2 ~ n/2)<-- (2 ~ n-1)
		if (n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n,m; cin >> n>>m;
	int input;
	int cnt = 0;
	for (int i = n; i <= m; i++) {
		//cin >> input;
		if (is_prime(i)) {
			//cnt++;
			cout << i << '\n';
		}
	}

	//cout << cnt;
	return 0;
}