//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int time[16];
//int pay[16];
//int dp[16];
//int main() {
//	freopen("input.txt", "r", stdin);
//	int n; cin >> n;
//
//	int t, p;
//	for (int i = 1; i <= n; i++) {
//		cin >> t >> p;
//		time[i] = t; pay[i] = p;
//		dp[i] = pay[i];
//	}
//
//	for (int i = 2; i <= n; i++) {
//		for (int j = 1; j < i; j++) {
//			if (i - j >= time[j])
//				dp[i] = max(pay[i] + dp[j], dp[i]);
//		}
//	}
//
//	int _max = 0;
//	for (int i = 1; i <= n; i++) {
//		if (i + time[i] <= n + 1)
//			if (_max < dp[i])
//				_max = dp[i];
//	}
//	cout << _max;
//	return 0;
//}


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
pii day[20];

int n;
int dfs(int d) {
	if (d > n)
		return 0;

	int ret = 0;
	if (d + day[d].first <= n + 1)
		ret = max(ret, dfs(d + day[d].first) + day[d].second);
	ret = max(ret, dfs(d + 1));

	return ret;
}
int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d %d", &day[i].first, &day[i].second);

	printf("%d", dfs(1));
	return 0;
}

//https://donggod.tistory.com/21
