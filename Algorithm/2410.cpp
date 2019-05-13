#define	_CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, dp[1000001] = { 1 };
int main() {
	scanf("%d", &n);


	for (int i = 1; i < n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - i]) % 1000000000;
		}
	}


	
	//for (int i = 1; i <= n; i<<=1) {

	//	for (int j = i; j <= n; j++) {
	//		dp[j] = (dp[j] + dp[j - i]) % 1000000000;
	//	}

	//}
	


	printf("%d", dp[n]);
}