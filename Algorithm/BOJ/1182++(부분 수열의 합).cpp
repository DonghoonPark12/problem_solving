#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
	�� ������ �κ� ���� �� Ư�� �κ��� ���� s�� �Ǵ� ��츦 ī��Ʈ �ϴ� �����̴�. 
	�κ� ������ ����� ���� �����ϱ⿡�� ���� �����̳�, ������ dependent�ϰ� ����ȭ �� �� �־
	�κ� ������ �����ϰ� �ʹٸ� 2019swea������ �����Ѵ�.
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
	//1)dfs�� �̿��� ���
	//solve(0, 0);
	//if (s == 0) ans--;
	//printf("%d\n", ans);

	//2) ��Ʈ ����ũ�� �̿��� ���
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
