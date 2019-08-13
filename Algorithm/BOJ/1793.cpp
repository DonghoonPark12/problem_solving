#include <iostream>
using namespace std;

long long a[10001];
int main() {
	a[1] = 1; a[2] = 2;
	for (int i = 3; i <= 10000; i++) {
		a[i] = 2 * a[i - 2] + a[i - 1];
	}
	//int t; cin >> t;
	int n;
	while (scanf("%d ",&n) > 0) {
		cin >> n;
		cout << a[n];
	}
	return 0;
}