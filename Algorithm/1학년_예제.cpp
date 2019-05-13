#include "stdafx.h"
#pragma warning(disable:4996)
#include<stdio.h>
#include <string.h>
using namespace std;
int arr[100] = { 0, };
long long memo[100][21];

long long GetSolve(int input, int idx, int sum)
{
	if (sum < 0 || sum > 20) return 0;
	if (idx == input - 1)return sum == arr[input - 1];
	if (memo[idx][sum] != -1) return memo[idx][sum];
	long long  count = 0;

	count += GetSolve(input, idx + 1, sum + arr[idx]);

	count += GetSolve(input, idx + 1, sum - arr[idx]);

	return memo[idx][sum] = count;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int input;
	memset(memo, -1, sizeof(memo));
	scanf("%d", &input);
	for (int i = 0; i < input; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("%lld\n", GetSolve(input, 1, arr[0]));
	return 0;
}