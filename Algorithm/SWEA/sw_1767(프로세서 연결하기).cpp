#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
	최대한 많은 코어에 전원을 연결하였을 경우, 전선 길이의 합을 구한다
*/
int l;
int ans;
int arr[13][13];
int backup[13][13];
vector<pair<int, int>> core;
int minl, maxc;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int vsz;
int cans;

bool check(int m, int i, vector<pair<int, int>> &line) {
	int ny = core[m].first;
	int nx = core[m].second;
	while (1) {
		if (nx == 0 || ny == 0 || nx == l - 1 || ny == l - 1) { //1) 벽에 닿으면 바로 true 리턴
			return true;
		}

		nx += dx[i];
		ny += dy[i];

		if (arr[ny][nx] == 0) {
			line.push_back({ ny, nx }); //계속 넣다가
		}
		else {
			return false; //2) 놓는 것이 불가능하면 false 리턴
		}
	}
}

void fill(vector<pair<int, int>> &line) {
	for (int i = 0; i < line.size(); i++) 
		arr[line[i].first][line[i].second] = 2;
}
void unfill(vector<pair<int, int>> &line) {
	for (int i = 0; i < line.size(); i++) 
		arr[line[i].first][line[i].second] = 0;
}
void dfs(int m, int cntc, int cntl, int n) {
	if (maxc > vsz - n + cntc) return;

	if (m == core.size()) {
		if (cntc > maxc) {
			maxc = cntc;
			minl = cntl;
		}
		else if (cntc == maxc && cntl < minl) {
			minl = cntl;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		vector<pair<int, int>> line;
		bool can_load = check(m, i, line);
		if (can_load) {
			fill(line);
			dfs(m + 1, cntc + 1, cntl + line.size(), n+1);
		}
		if (can_load) {
			unfill(line);
		}
	}	
	dfs(m + 1, cntc, cntl, n+1);
}
int main() {
	freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> l;
		memset(arr, 0, sizeof(arr));
		core.clear();
		minl = 0x7fffffff;
		maxc = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				cin>>arr[i][j];
				if (arr[i][j] == 1 && (i !=0 && j !=0 && i != l-1 && j != l-1))
					core.push_back({ i, j });
			}
		}
		cans = 0;
		vsz = core.size();
		dfs(0, 0, 0, 0);

		cout << "#"<<t<<' '<< minl<<'\n';
	}
	return 0;
}

//https://stackoverflow.com/questions/5333113/how-to-pass-a-vector-to-a-function
