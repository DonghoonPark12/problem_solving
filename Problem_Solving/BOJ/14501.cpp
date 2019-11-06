/*
	상담하는데 걸리는 시간 Ti와 상담했을 때 받을 수 있는 금액 Pi
*/
//1)
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n;
//int T[16];
//int P[16];
//int dp[16];
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> T[i] >> P[i];
//		//dp[i] = P[i];
//	}
//	for (int i = 1; i <= n+1; i++) {
//		for (int j = 1; j < i; j++) {
//			if ((j + T[j]) == i)
//				dp[i] = max(dp[i], dp[i - T[j]] + P[j]);//현재 시점을 기준으로 상담금을 받을 수 있는지 확인
//			else
//				dp[i] = max(dp[i], dp[i - 1]);
//		}
//	}
//	cout << dp[n+1];
//	return 0;
//}

//2)
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n;
//int T[16];
//int P[16];
//int dp[16];
//int _max;
//void dfs(int d, int sum) {
//	if (d == n + 1) {
//		_max = max(_max, sum);
//		return;
//	}
//	if (d + T[d] <= n + 1) dfs(d + T[d], sum + P[d]); //미래 시점으로 가서 갱신
//	if (d + 1 <= n + 1) dfs(d + 1, sum); //상담을 안 할 경우
//}
//
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> T[i] >> P[i];
//	}
//	dfs(1, 0);
//	cout << _max;
//	return 0;
//}


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


//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//
//using namespace std;
//
//typedef pair<int, int> pii;
//pii day[20];
//
//int n;
//int dfs(int d) {
//	if (d > n)
//		return 0;
//
//	int ret = 0;
//	if (d + day[d].first <= n + 1)
//		ret = max(ret, dfs(d + day[d].first) + day[d].second);
//	ret = max(ret, dfs(d + 1));
//
//	return ret;
//}
//int main()
//{
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//		scanf("%d %d", &day[i].first, &day[i].second);
//
//	printf("%d", dfs(1));
//	return 0;
//}
//


//#include<iostream>
//#include<algorithm>
//using namespace std;
//int N;
//int T[15];
//int P[15];
//int ans = 0;
//
//void sum(int day, int part_sum) {
//
//	ans = max(part_sum, ans);
//
//	for (int i = day; i < N + 1; i++) { //저는 T[]배열이나 P[]배열의 인덱스 0은 무시합니다.
//		if ((i + T[i]) <= N + 1) {//N+1인 이유: N=7이라고 가정할 때, 하루가 걸리는 일은 7번째 날에도 할 수 있기 때문
//			sum(i + T[i], part_sum + P[i]);
//		}
//	}
//	return;
//
//}
//
//int main(void) {
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> T[i];
//		cin >> P[i];
//	}
//	sum(1, 0);
//	cout << ans << endl;
//
//}
