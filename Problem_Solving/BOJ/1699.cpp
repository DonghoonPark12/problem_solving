#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[100001];

int main(void)
{
	int Answer = 0;
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

		/////////////////////////////////////////////////////////////////////////////////////////////////
		int N; scanf("%d", &N);

		//while (N) {
		//	for (int i = 1; i < 318; i++) {
		//		if (i != 1 && N == i*i) {
		//			Answer += 1;
		//			N -= i*i;
		//		}
		//		else if (i != 1 && N == i*i * 2) {
		//			Answer += 2;
		//			N -= 2 * i*i;
		//		}
		//		else if (i != 1 && N == i*i * 3) {
		//			Answer += 3;
		//			N -= 3 * i*i;
		//		}

		//		if (N >= i*i && N <= (i + 1)*(i + 1)) {
		//			Answer++;
		//			N -= i*i;
		//			i = 0;
		//		}
		//	}
		//}

		//dp[0] = 0;
		//for (int i = 1; i <= N; i++) {

		//	dp[i] = i;
		//	for (int j = 1; j * j <= i; j++) {

		//		int tmp = dp[i - j * j] + 1;

		//		dp[i] = dp[i] > tmp ? tmp : dp[i];
		//	}

		//}

		for (int i = 1; i <= N; i++) dp[i] = 1e9;

		for (int i = 1; i*i <= N; i++) 
			for (int j = i*i; j <= N; j++)
				dp[j] = min(dp[j - i*i] + 1, dp[j]);

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("%d\n", dp[N]);

	return 0;

}