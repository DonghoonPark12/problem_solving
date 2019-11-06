//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int n;
////vector<vector<int>> board;
//int board[20][20];
//int backup[20][20];
//int _max;
//queue<int> q;
//
////vector<vector<int>> sit;
////vector<vector<int>> sit_backup;
////queue< vector<vector<int>> > q;
//int lvl;


//void bfs(int cnt) {
//	//for (int i = 0; i < n; i++) {
//	//	for (int j = 0; j < n; j++) { sit[i][j] = sit_backup[i][j] = q.front()[i][j]; }
//	//}
//	while (!q.empty()) {
//		if (lvl == (4 + 16 + 64 + 256 + 1024)) break;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) { sit[i][j] = sit_backup[i][j] = q.front()[i][j]; }
//		}
//		q.pop();
//			
//		for (int i = 0; i < 4; i++) {
//			if (i == 0) {
//				//위로 이동			
//
//				//
//			}
//			if (i == 1) {
//				//아래로 이동
//
//				//
//			}
//			if (i == 2) {
//				//오른쪽 이동
//
//				//
//			}
//			if (i == 3) {
//				//왼쪽 이동
//
//				//
//			}
//			q.push(sit);
//			if (i != 3) {
//				for (int i = 0; i < n; i++) {
//					for (int j = 0; j < n; j++) { sit[i][j] = sit_backup[i][j]; }
//				}
//			}
//			lvl++;
//		}
//	}
//}

//void get(int i, int j) {
//	if (board[i][j]) {
//		q.push(board[i][j]);
//		board[i][j] = 0;
//	}
//}
//
//void merge(int i, int j, int di, int dj) {
//	while (!q.empty()) {
//		int f = q.front(); q.pop();
//
//		if (!board[i][j]) 
//			board[i][j] = f;//비어 있다면
//
//		else if (board[i][j] == f) {
//			board[i][j] = f*2;//놓인 숫자가 큐에서 꺼낸 값과 동일하면
//			i += di, j += dj;
//		}
//		else {// 다르면 다음 좌표에서 꺼낸 숫자를 둔다.
//			i += di, j += dj;
//			board[i][j] = f;
//		}
//
//	}
//}
//
//void move(int d) {
//	if (d == 0) {
//		//위
//		for (int j = 0; j < n; j++){
//			for (int i = 0; i < n; i++){
//				get(i, j); 
//				merge(0, j, 1, 0);
//			}
//		}
//	}
//	else if (d == 1) {
//		//아래
//		for (int j = 0; j < n; j++){
//			for (int i = n-1; i >= 0; i--){
//				get(i, j); 
//				merge(n-1, j, -1, 0);
//			}
//		}
//	}
//	else if (d == 2) {
//		//왼쪽
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				get(i, j); 
//				merge(i, 0, 0, 1);
//			}
//		}
//
//	}
//	else {
//		//오른쪽
//		for (int i = 0; i < n; i++){
//			for (int j = n-1; j >= n; j--){
//				get(i, j); 
//				merge(i, n-1, 0, -1);
//			}
//		}
//	}
//}
//
//void dfs(int cnt) {
//	if (cnt == 5) {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				_max = max(_max, board[i][j]);
//			}
//		}
//		return;
//	}
//
//	memcpy(backup, board, sizeof(board));
//	for (int d = 0; d < 4; d++) {
//		move(d);
//		dfs(cnt + 1);
//		memcpy(board, backup, sizeof(backup));
//	}
//}
//	
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> n;
//	//board.resize(n);
//	//int tmp;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> board[i][j];
//		}
//	}
//
//	dfs(0);
//
//	cout << _max << '\n';
//
//	//q.push(map);
//	//bfs(0);
//	//int _max;
//	//for (int i = 0; i < q.size(); i++) {
//	//	for (int y = 0; y < n; y++) {
//	//		for (int x = 0; x < n; x++) {
//	//			_max = max(_max, q.front()[y][x]);
//	//		}
//	//	}
//	//}
//	//cout << _max << '\n';
//
//
//	return 0;
//}

//2048(easy)
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, ans;
int board[20][20];
queue<int> q;
int lvl;

void get(int i, int j) {
	if (board[i][j]) {
		q.push(board[i][j]);
		board[i][j] = 0;
	}
}

void merge(int i, int j, int di, int dj) {
	while (!q.empty()) {
		int x = q.front(); q.pop(); //queue에서 pop

		if (!board[i][j]) board[i][j] = x;//값이 존재하지 않으면 그냥 대입

		else if (board[i][j] == x) { //값이  
			board[i][j] = x * 2;
			i += di, j += dj;
		}

		else {
			i += di, j += dj;
			board[i][j] = x;
		}
	}
}

void move(int k) {
	if (k == 0) {
		// Up
		for (int j = 0; j<n; j++) { //x고정
			for (int i = 0; i<n; i++) get(i, j); //y이동
			merge(0, j, 1, 0);
		}
	}
	else if (k == 1) {
		// Down
		for (int j = 0; j<n; j++) {
			for (int i = n - 1; i >= 0; i--) get(i, j);
			merge(n - 1, j, -1, 0);
		}
	}
	else if (k == 2) {
		// Left
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) get(i, j);
			merge(i, 0, 0, 1);
		}
	}
	else {
		// Right
		for (int i = 0; i<n; i++) {
			for (int j = n - 1; j >= 0; j--) get(i, j);
			merge(i, n - 1, 0, -1);
		}
	}
}

void solve2(int cnt) {
	while (!q.empty()) {
		if (lvl == (1+4+16+64+256)) break;
		q.push(*board[n]);
		int b[20][20];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) b[i][j] = board[i][j];
		}
		q.pop();
		for (int d = 0; d < 4; d++) {
			move(d);
			q.push(*board[n]);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) board[i][j] = b[i][j];
			}
		}
		lvl++;
	}
}

void solve(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				if (ans < board[i][j]) ans = board[i][j];
			}
		}
		return;
	}
	int b[20][20];
	memcpy(b, board, sizeof(board));
	for (int k = 0; k<4; k++) {
		move(k);
		solve(cnt + 1);
		memcpy(board, b, sizeof(b));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	solve(0);

	//int _max = 0;
	//for (int i = 0; i < q.size(); i++) {
	//	for (int y = 0; y < n; y++) {
	//		for (int x = 0; x < n; x++) {
	//			int *ptr = q.front();
	//			_max = max(_max, (*ptr)[y][x]);
	//		}
	//	}
	//}

	printf("%d\n", ans);
	return 0;
}



