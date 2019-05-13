#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<vector>
using namespace std;
int N, a[103], dest;
long long dp[103][40];

long long go(int idx, int sum) {

	// caution 1
	if (sum<0 || sum>20)
		return 0;
	if (N - 1 == idx) {
		if (sum == dest)
			return 1;
		else
			return 0;
	}

	long long& ret = dp[idx][sum];
	if (ret != -1) return ret;

	ret = go(idx + 1, sum + a[idx + 1]) + go(idx + 1, sum - a[idx + 1]);
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	for (int i = 1; i<N; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &dest);
	printf("%lld", go(1, a[1]));
	return 0;
}