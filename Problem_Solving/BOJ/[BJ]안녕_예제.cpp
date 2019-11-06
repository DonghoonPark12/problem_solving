#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
int L[22];
int J[22];
int n;
int d[22][111];
//d[i][j] = i�� ����� �λ��Ϸ��� �ϰ�(i - 1�� ��������� �λ縦 ����, �� ������ ��������), �� �� ü���� j�϶� ���� �� �ִ� �ִ� ���
//�λ縦 �ϴ� ���� (j-L[i] > 0 �� ���) d[i+1][j-L[i]] + J[i] �̰�, �λ縦 ���� �ʴ� ���� d[i+1][j]�� �˴ϴ�
int go(int x, int y) { //x�� �ε���, y�� ü��
	if (d[x][y]) return d[x][y];
	int &ans = d[x][y];
	if (x == n) {
		return 0;
	}
	if (y - L[x]>0) {
		ans = go(x + 1, y - L[x]) + J[x]; //��� ���
	}
	int temp = go(x + 1, y); //a[x]�� ���� ������ �Ǵ� �ε����� ����
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