#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, dp[1000001] = { 1 };
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i <<= 1) {
		printf("%d", i);
	}
	printf("%d", dp[n]);
}