/* A Naive recursive implementation of 0-1 Knapsack problem */
#include<stdio.h>

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
//int knapSack(int W, int wt[], int val[], int n)
//{
//	// Base Case
//	if (n == 0 || W == 0)
//		return 0;
//
//	// If weight of the nth item is more than Knapsack capacity W, then
//	// this item cannot be included in the optimal solution
//	if (wt[n - 1] > W)
//		return knapSack(W, wt, val, n - 1);
//
//	// Return the maximum of two cases: 
//	// (1) nth item included 
//	// (2) not included
//	else return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), //n번째 원소를 가방에 넣은 경우 가치 증가, 수용량 감소
//		                         knapSack(W,             wt, val, n - 1) //n번째 원소를 고려하지 않은 경우
//	);
//}

int knapSack(int W, int wt[], int val[], int n)
{
	int k[1001][101];

	for (int i = 0; i < n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				k[i][w] = 0;
			else if (wt[i - 1] < w)
				k[i][w] = max(val[i-1] + k[i-1][w-wt[i-1]] , k[i-1][w]);
			else
				k[i][w] = k[i - 1][w];
		}
	}
	return k[n][W];
}

// Driver program to test above function
int main()
{
	int val[] = { 2, 2, 4, 3 };
	int wt[] = { 1, 3, 4, 2 };
	int  W = 5;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", knapSack(W, wt, val, n));
	return 0;
}

#include <cstdio>
#include <algorithm>
using namespace std;

int t, n, k, v[101], c[101], d[1001][101];

int main()
{
	scanf("%d", &t);
	for (int T = 1; T <= t; T++)
	{
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d %d", &v[i], &c[i]);
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i >= v[j]) d[i][j] = max(d[i][j - 1], d[i - v[j]][j - 1] + c[j]);
				else d[i][j] = d[i][j - 1];
			}
		}
		printf("#%d %d\n", T, d[k][n]);
	}
	return 0;
}

