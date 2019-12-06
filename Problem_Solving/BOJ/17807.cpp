#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else {
		return gcd(b, a % b);
	}
}

int main() {
	int n, s;
	int a[10000];
	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		int diff = abs(x - s);
		a[i] = diff;
	}
	int ans = a[0];
	for (int i = 1; i < n; i++) {

		ans = gcd(ans, a[i]);
	}
	printf("%d\n", ans);
	return 0;

}