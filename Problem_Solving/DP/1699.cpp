#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[100001];

int main(void)
{
	int Answer = 0;

		/////////////////////////////////////////////////////////////////////////////////////////////////
		int N; scanf("%d", &N);

		//dp[0] = 0;
		for (int i = 1; i <= N; i++) {

			dp[i] = i;
			for (int j = 1; j * j <= i; j++) {

				dp[i] = min(dp[i - j*j] + 1, dp[i]);
			}

		}

		//for (int i = 1; i <= N; i++) 
		//	dp[i] = 1e9;

		//for (int i = 1; i*i <= N; i++) 
		//	for (int j = i*i; j <= N; j++)
		//		dp[j] = min(dp[j - i*i] + 1, dp[j]);

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("%d\n", dp[N]);

	return 0;

}