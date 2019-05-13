#define	_CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<string.h>
#include<algorithm>
int list[300];
int size;
int dp[301];

int Solve(int idx, int jump)
{
	if (idx == 0) return list[0];
	if (idx == 1)
	{
		if (jump == 1) return list[1];
		else return list[1] + list[0];
	}
	if (jump == 1)
	{
		if (dp[idx] > 0) return dp[idx];
		return dp[idx] = Solve(idx - 2, 2) + list[idx];
	}
	else
	{
		return std::max(Solve(idx - 1, 1), Solve(idx - 2, 2)) + list[idx];
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &size);
	for (int i = 0; i < size; i++) scanf("%d", &list[i]);
	memset(&dp, 0, sizeof(dp));
	printf("%d\n", Solve(size - 1, 2));
	return 0;
}