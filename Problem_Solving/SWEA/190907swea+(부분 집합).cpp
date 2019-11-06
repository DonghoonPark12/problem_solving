#include <iostream>
#include <cstring>
using namespace std;

int divide[9];
int vis[9];
int n;
int cnt;

int flag[9];

void dfs(int pos) {
	for (int i = 0; i < n; i++) {
		cout << divide[i] << " ";
	}
	cnt++;
	cout << '\n';

	for (int i = pos; i < n; i++) {
		divide[i] = 1;
		dfs(i + 1);
		divide[i] = 0;
	}
}

void subset2(int n, int depth) {
	if (n == depth) {
		for (int i = 0; i < n; i++) {
			if (flag[i]) cout << 1 << " ";
			else cout << 0 << " ";
		}
		cout << '\n';
		return;
	}
	flag[depth] = 1;
	subset2(n, depth + 1);
	flag[depth] = 0;
	subset2(n, depth + 1);
}

void subset3(int n) {
	int max = 1 << n;//1000
	for (int i = 0; i < max; i++) {//0 ~ 7
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) cout << flag[j] << " ";
			else cout << 0 << " ";
		}
		cout << '\n';
	}
}
int main() {
	//1. dfs를 이용하는 방법
	//cin >> n;
	//dfs(0);

	memset(flag, 2, sizeof(flag));
	//subset2(3, 0);

	subset3(3);
	//cout<<cnt;
	return 0;
}