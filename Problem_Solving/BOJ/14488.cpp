#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//vector<int> num;
vector<int> op;
int num[100];
//int op[4];
int n;
long long ret_min;
long long ret_max;
void oper() {
	ret_min = 0x7fffffff;
	ret_max = ret_min * (-1);
	do {
		long long mid = num[0];

		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 0) mid += num[i + 1];
			if (op[i] == 1) mid -= num[i + 1];
			if (op[i] == 2) mid *= num[i + 1];
			if (op[i] == 3) mid /= num[i + 1];
		}

		if (mid < ret_min) {
			ret_min = mid;
		}

		if (mid > ret_max) {
			ret_max = mid;
		}

	} while (next_permutation(op.begin(), op.end()));
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &num[i]);
	}
	int tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		while (tmp--) op.push_back(i);
	}
	oper();
	cout << ret_max<<'\n';
	cout << ret_min<<'\n';
	return 0;
}

///* https://rebas.kr/693
//	��� �Լ� ���� ����: �ε����� ������ idx>=N �̸� ���� �Ѵ�.
//	������ �� �������� �ܿ� Ƚ���� 1�̻��� ��쿡 ����.
//	������ ������ ��, ����� �������� �ܿ� Ƚ���� 1ȸ ���� ��Ų��.
//*/
//void solve(int idx, int ans, int add, int sub, int mul, int div) {
//	if (idx == n) {
//		if (ans > ret_max) ret_max = ans;
//		if (ans < ret_min) ret_min = ans;
//		return;
//	}
//	if (add) solve(idx+1, ans + num[idx], add - 1, sub, mul, div);
//	if (sub) solve(idx+1, ans - num[idx], add , sub - 1, mul, div);
//	if (mul) solve(idx+1, ans * num[idx], add , sub, mul -1, div);
//	if (div) solve(idx+1, ans / num[idx], add , sub, mul, div -1);
//}
//int main() {
//	cin >> n;
//	int tmp;
//	for (int i = 0; i < n; i++) {
//		cin >> tmp;
//		num.push_back(tmp);
//	}
//	for (int i = 0; i < 4; i++) { 
//		cin >> tmp;
//		op.push_back(tmp);
//	}
//	solve(1, num[0], op[0], op[1], op[2], op[3]);
//	//oper();
//	cout << ret_max<<'\n';
//	cout << ret_min<<'\n';
//	
//	return 0;
//}

#include <stdio.h>

int n, i, mn = 2e9, mx = -2e9, a[11], op[4];

void dfs(int c, int v) {
	if (c == n) {
		mn = mn < v ? mn : v;
		mx = mx > v ? mx : v;
		return;
	}
	if (op[0]) --op[0], dfs(c + 1, v + a[c]), ++op[0];
	if (op[1]) --op[1], dfs(c + 1, v - a[c]), ++op[1];
	if (op[2]) --op[2], dfs(c + 1, v * a[c]), ++op[2];
	if (op[3]) --op[3], dfs(c + 1, v / a[c]), ++op[3];
}

int main() {
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0; i < 4; i++) scanf("%d", &op[i]);

	dfs(1, a[0]);

	printf("%d\n%d\n", mx, mn);

	return 0;
}

