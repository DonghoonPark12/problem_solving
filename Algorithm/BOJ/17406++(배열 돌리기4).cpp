#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
	����, ������ ��ͷ� Ǭ��. �ϰ����� �����ϴ� ���� ����. 
*/
int n, m, k;
bool pick[6];

int __min = 0x7fffffff;

struct op {
	int r, c, s;
};

vector<op> v;

int value_a(int (*map)[50]){
	int _min = 0x7fffffff;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			sum += map[i][j];
		}
		_min = min(_min, sum);
	}
	return _min;
}

void rotate(int r, int c, int s, int(*map)[50]) {
	for (int i = 1; i <= s; i++) {
		int sy = r - 1 - i, sx = c - 1 - i;
		int tmp = map[sy][sx];
		for (int m = 0; m < 2 * i; m++) { map[sy+m][sx]                   = map[sy+m+1][sx]; }
		for (int m = 0; m < 2 * i; m++) { map[sy + 2 * i][sx+m]           = map[sy + 2 * i][sx+m+1]; }
		for (int m = 0; m < 2 * i; m++) { map[sy + 2 * i - m][sx + 2 * i] = map[sy + 2 * i -(m+1)][sx + 2 * i]; }
		for (int m = 0; m<(2*i)-1; m++) { map[sy][sx + 2 * i -m]          = map[sy][sx + 2 * i -(m+1)]; }
		map[sy][sx + 1] = tmp;
	}

}
/*
	
*/
void dfs(int cnt, int (*map)[50]) {
	if (cnt == k) {
		__min = min(value_a(map), __min);
		return;
	}

	for (int i = 0; i < k; i++) {
		if (pick[i] == false) {
			pick[i] = true;
			int backup[50][50]; //�ڡ����������� �����Ѵ�. ��� �ٳ�͵�(?) �� �״�� �����ȴ�.(https://regularmember.tistory.com/129)
			memcpy(backup, map, sizeof(backup));
			int r = v[i].r, c = v[i].c, s = v[i].s;
			rotate(r, c, s, backup);
			
			dfs(cnt + 1, backup);

			pick[i] = false;
		}
	}
}

int main() {
	cin >> n >> m>>k;
	int map[50][50]; //�ڡ��������� �����ϸ� �ȵȴ�. �ֳ��ϸ�, ȸ�� ������ ���� ���ƿ;� �ϱ� �����̴�.(
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) { //����� vector�� �����ϴ� ������ ����� ������ ������ �ٲ㰡�� Ȯ���ؾ� �ϱ� ����.
		op tmp; cin >> tmp.r >> tmp.c >> tmp.s;
		v.push_back(tmp);
	}

	dfs(0, map); //������ ���� dfs�� ������. 

	cout << __min;
	return 0;
}