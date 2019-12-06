#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//가장 긴 증가하는 부분 수열
int arr[1001];
int dp[1001];
vector<int> v;
int main() {
	//O(n^2) https://www.youtube.com/watch?v=CE2b_-XfVDk
	// O(n^2)에서 dp[i]는 마지막 수가 x번째인 '가장 긴 최장증가수열'
	// O(nlogn)에서 dp[i]는 '길이가 x인 최장증가수열의 마지막 수의 최소값'
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int _max = 0;
	dp[0] = 1;//처음의 길이는  1

	for (int i = 1; i < n; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			//if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {//i번째 원소(마지막이라고 가정하는 원소)가 j번째 원소보다 크고, j번째 원소까지의 부분 수열에
			//	dp[i] = dp[j] + 1;					   //i번째 원소를 추가해주는 것이므로 dp[i]에 dp[j]+1을 넣어준다. 
			//}
			if (arr[j] < arr[i])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		if (_max < dp[i]) {
			_max = dp[i];
		}
	}
	/* ----------------------------------------------------------------------------------------------- */
	// 14002. 가장 긴 증가하는 부분 수열 출력 (my method, I passed but, I don't know this method is right.)
	int ch = _max;
	vector<int> v;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == ch) {
			v.push_back(arr[i]);
			ch--;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
	/* ----------------------------------------------------------------------------------------------- */
	return 0;
}

// baekjoon's method
#include <iostream>
using namespace std;
int a[1000];
int d[1000];
int v[1000];
void go(int p) { // Awesome Code. After go to first LIS index & print the number.
	// ? -> ? -> ... a[v[p]] -> a[p]
	// ---------------------
	//        go(v[p]);
	if (p == -1) {
		return;
	}
	go(v[p]);
	cout << a[p] << ' ';
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j; //<----- 어느 j서 부터 업데이트 되었는지 확인.
			}
		}
	}
	int ans = d[0];
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i; //LIS의 마지막 인덱스 위치
		}
	}
	cout << ans << '\n';
	go(p);
	cout << '\n';
	return 0;
}