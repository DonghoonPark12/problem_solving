#define _CRT_SECURE_NO_WARNINGS
/*
* 입력: 자연수 N (1<= N < 100)
* 출력: 자연수 N을 구할 수 있는 모든 자연수 합 경우의 수
* 
* (예제)
* 입력: 2  출력: 1
* 1+1
*
* 입력: 3  출력: 2
* 1+1+1
* 1+2
*
* 입력: 4  출력: 2
* 1+1+1+1
* 1+2+1         dp[3] + 1
* 2+2           dp[2] + 2
* 1+3

* 입력: 5  출력: 6
* 1+1+1+1+1
* 1+2+1+1
* 2+2+1
* 1+3+1         dp[4] + 1

* 3+2           dp[3] + 2

* 1+4
*
* 입력: 6 출력: 10
* 1+1+1+1+1+1
* 1+2+1+1+1
* 2+2+1+1
* 1+3+1+1
* 3+2+1
* 1+4+1
* 2+2+2
* 4+2
* 3+3

* 5+1
*/

#define   _CRT_SECURE_NO_WARNINGS
#include <cstdio>

//int n, dp[1000001] = { 1 };
int n, dp[1000001];
int main() {
	scanf("%d", &n);

	//for (int i = 1; i <= n; i++) {
	//	for (int j = i; j <= n; j++) {
	//		dp[j] = (dp[j] + dp[j - i]) % 1000000000;
	//	}
	//}

	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= i/2; j--) {
		//for (int j = 1; j <= n / 2; j++) {
			dp[i] += dp[j];
		}
		dp[i] += 1;
	}
	printf("%d", dp[n]);
	return 0;
}