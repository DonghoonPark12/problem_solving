#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
int L[22];
int J[22];
int n;
int d[22][111];
//d[i][j] = i번 사람과 인사하려고 하고(i - 1번 사람까지는 인사를 할지, 안 할지를 결정했음), 그 때 체력이 j일때 얻을 수 있는 최대 기쁨
//인사를 하는 경우는 (j-L[i] > 0 일 경우) d[i+1][j-L[i]] + J[i] 이고, 인사를 하지 않는 경우는 d[i+1][j]가 됩니다
int go(int x, int y) { //x는 인덱스, y는 체력
	if (d[x][y]) return d[x][y];
	int &ans = d[x][y];
	if (x == n) {
		return 0;
	}
	if (y - L[x]>0) {
		ans = go(x + 1, y - L[x]) + J[x]; //얻는 기쁨
	}
	int temp = go(x + 1, y); //a[x]를 빼면 음수가 되니 인덱스만 증가
	if (ans < temp) ans = temp;
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", &L[i]);
	for (int i = 0; i<n; i++) scanf("%d", &J[i]);
	printf("%d\n", go(0, 100));
	return 0;
}