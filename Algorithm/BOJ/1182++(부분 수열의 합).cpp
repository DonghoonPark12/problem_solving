#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
	이 문제는 부분 수열 중 특정 부분의 합이 s가 되는 경우를 카운트 하는 문제이다. 
	부분 집합의 경우의 수를 연습하기에는 좋은 문제이나, 문제에 dependent하게 최적화 할 수 있어서
	부분 집합을 연습하고 싶다면 2019swea문제를 참고한다.
*/
//int n,s,cnt;
//int arr[20];
//int sum;
//
//void dfs(int c, int sum) {
//	if (sum == s) {
//		cnt++;
//	    //return; 
//	}
//
//	for (int i = c; i < n; i++) {
//		dfs(i + 1, sum + arr[i]);
//	}
//}
//
//int main() {
//	//int tc; cin >> tc;
//	//for (int t = 0; t < tc; t++) {
//		cin >> n >> s;
//		for (int i = 0; i < n; i++) {
//			cin >> arr[i];
//		}
//		dfs(0,0);
//		if(s==0)
//			cout << cnt-1 << '\n';
//		else
//			cout << cnt << '\n';
//	//	cout << "#"<<t+1<<" "<<cnt<<'\n';
//	//}
//	return 0;
//}


int n, s, ans;
int a[20];

void solve(int index, int sums) {
	if (index >= n) {
		if (sums == s) ans++;
		return;
	}
	solve(index + 1, sums + a[index]);
	solve(index + 1, sums);
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i<n; i++) 
		scanf("%d", &a[i]);
	//1)dfs를 이용한 방법
	//solve(0, 0);
	//if (s == 0) ans--;
	//printf("%d\n", ans);

	//2) 비트 마스크를 이용한 방법
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int k = 0; k < n; k++) {
			if (i & (1 << k))
				sum += a[k];
		}
		if (sum == s)
			ans += 1;
	}
	return 0;
}
