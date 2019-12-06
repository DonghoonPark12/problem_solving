#define _CRT_SECURE_NO_WARNINGS
/*
* 입력: 자연수 N (1<= N < 100)
* 출력: 자연수 N을 구할 수 있는 모든 자연수 합 경우의 수
* 
* (예제)
* 입력: 5  출력: 6
* 1+1+1+1+1
* 2+1+1+1
* 2+2+1
* 3+1+1
* 3+2
* 4+1
*
* 입력: 6 출력: 10
* 1+1+1+1+1+1
* 2+1+1+1+1
* 3+1+1+1
* 4+1+1
* 5+1
* 2+2+1+1
* 2+2+2
* 3+2+1
* 3+3
* 4+2
*/

#define   _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int n, dp[1000001] = { 1 };
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - i]) % 1000000000;
		}
	}
	printf("%d", dp[n]);
}