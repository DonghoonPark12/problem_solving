#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
/*
	순열, 조합은 재귀로 푼다. 일관성을 유지하는 것이 좋다. 
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
			int backup[50][50]; //★★지역변수로 선언한다. 재귀 다녀와도(?) 값 그대로 유지된다.(https://regularmember.tistory.com/129)
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
	int map[50][50]; //★★전역으로 선언하면 안된다. 왜냐하면, 회전 이후의 경우로 돌아와야 하기 때문이다.(
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) { //명령을 vector에 저장하는 이유는 명령을 순열로 순서를 바꿔가며 확인해야 하기 때문.
		op tmp; cin >> tmp.r >> tmp.c >> tmp.s;
		v.push_back(tmp);
	}

	dfs(0, map); //순열을 위해 dfs를 돌린다. 

	cout << __min;
	return 0;
}