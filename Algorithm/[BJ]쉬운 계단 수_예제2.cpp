#include <stdio.h>
using namespace std;
const int mod = 1e9;
int n;
int dp[105][10];
int rec(int cur, int pre)
{
	if (cur >= n)return 1;
	int& ret = dp[cur][pre];
	if (ret)return ret;
	if (pre)ret += rec(cur + 1, pre - 1);
	ret %= mod;
	if (pre<9)ret += rec(cur + 1, pre + 1);
	ret %= mod;
	return ret;
}
int main()
{
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= 9; ++i)ans = (ans + rec(1, i)) % mod;
	printf("%d",ans);
}
