#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int dp[100];

bool operator<(pair<int, int> l, pair<int, int> r)
{
	return l.first < r.first;
}
vector<pair<int, int>> vp;

int main()
{
	cin >> n;
	int i1, i2;
	for (int i = 0; i < n; i++) {
		cin >> i1 >> i2;
		vp.push_back({ i1, i2 });
	}

	sort(vp.begin(), vp.end());

	dp[0] = 1;

	int cnt = 0;
	int _max = -1;
	for (int i = 1; i < n; i++) 
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (vp[j].second < vp[i].second	&& dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		_max = max(_max, dp[i]);
	}

	cout << n - _max;
	return 0;
}