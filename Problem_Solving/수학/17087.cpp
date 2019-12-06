#include <iostream>
#include <vector>
using namespace std;
/* ¼û¹Ù²ÀÁú6 */
int gcd(int l, int r) {
	if (r == 0) return l;
	return gcd(r, l % r);
}
int main() {
	int n, s; cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		int diff = x - s;
		if (diff < 0) diff *= -1;
		v[i] = diff;
	}
	int ans = v[0];
	for (int i = 0; i < n; i++) {
		ans = gcd(ans, v[i]);
	}
	cout << ans << '\n';
	return 0;
}