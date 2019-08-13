#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
struct 구조체이름 변수이름[크기] = { { .멤버이름1 = 값1, .멤버이름2 = 값2 },
									 { .멤버이름1 = 값3, .멤버이름2 = 값4 } };
struct 구조체이름 변수이름[크기] = { { 값1, 값2 }, { 값3, 값4 } };

*/
const int dx[4] = { -1, 1, 0, 0 }; //오염을 위해 4방향 체크
const int dy[4] = { 0, 0 ,-1, 1 }; //좌, 우, 위, 아래
int n, m, ret; //경계 영역 체크 

typedef struct XY{
	int y,x;
}xy;

vector<vector<int>> map(8, vector<int> (8));
//vector<vector<int>> map_old(8, vector<int> (8));
vector<xy> birus;//birus place check;
vector<xy> clearp;
vector<xy> pick;

//int safe_area;
//int clear_area;
//int para;

//void para_start(xy p) {
//	queue<xy> q;
//	q.push(p);
//	//map[p.y][p.x] = 2; //할 필요 없다. 이미 오염되어 있다. 
//	
//	while (!q.empty()) {
//		int curx = q.front().x;
//		int cury = q.front().y;
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = curx + dx[i];
//			int ny = cury + dy[i];
//			//cout << nx << " " << ny ;
//			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
//				if (map[ny][nx] == 0 ) {
//					para++;
//					q.push({ ny,nx }); //오염되지 않은 영역 모두 큐에 삽입
//					map[ny][nx] = 2;//오염 되었다.
//				}
//			}
//		}
//
//	}
//}

//void dfs(int pos) {
//	if (pick.size() == 3) {
//		para = 0;
//
//		for (int i = 0; i < birus.size(); i++) {
//			para_start(birus[i]);
//		}
//
//		safe_area = max(safe_area, clear_area - 3 - para);
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < m; j++) {
//				map[i][j] = map_old[i][j];
//			}
//		}
//		return;
//	}
//
//	for (int i = pos; i < clearp.size(); i++) {
//		pick.push_back(clearp[i]); //이런식으로 하면 clearp 벡터의 조합을 찾을 수 있다.
//		map[clearp[i].y][clearp[i].x] = 1;
//
//		dfs(i + 1);
//
//		pick.pop_back();
//		map[clearp[i].y][clearp[i].x] = 0;
//	}
//}

void bfs() {
	queue<int> q;
	int backup[8][8];
	int visited[8][8] = { 0, };

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			backup[y][x] = map[y][x]; //전염 전에 미리 백업

			if (backup[y][x] == 2) { //바이러스 시작점 이라면
				q.push(y * 10 + x); //큐에 삽입
				visited[y][x] = 1;  //방문 표시?? - 바이러스는 방문한 것으로 표시
			}

		}
	}

	while (!q.empty()) {
		int cur = q.front(); //현재 바이러스의 위치
		q.pop();
		int cy = cur / 10;
		int cx = cur % 10;
		backup[cy][cx] = 2;

		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (visited[ny][nx] == 0 && backup[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push(ny * 10 + nx);
			}
		}
	}

	int safe_area = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (backup[y][x] == 0) {
				safe_area++;
			}
		}
	}

	if (ret < safe_area) {
		ret = safe_area;
	}

}

void pick_dfs(int count, int sy, int sx) { //세운 벽의 갯수, (현재 좌표)
	if (count == 3) {
		bfs();
		return;
	}

	for (int y = sy; y < n; y++) {
		for (int x = sx; x < m; x++) {
			if (map[y][x] == 0) {
				map[y][x] = 1;    //연구소를 돌면서 빈공간에 벽을 세우고
				pick_dfs(count + 1, y, x);
				map[y][x] = 0;    //벡트레킹(N-Queen) 문제 처럼 다시 벽을 거둔다.
			}
		}
		sx = 0;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>map[i][j];
			if (map[i][j] == 2)
				birus.push_back({i,j});
			if(map[i][j] == 0){
				clearp.push_back({i,j});
			}
		}
	}
	
	pick_dfs(0, 0, 0);
	//dfs(0);

	// 이렇게가 안된다. 
	// next_permutation이 구조체가 원소가 남긴 벡터를 순회하지 못한다. 그저, int형 원소를 담은 벡터만 되나 보다.
	// clear한 지점의 갯수를 크기로 하는 벡터를 만들어서 순회할 수도 있겠다. 
	//do {

	//} while (next_permutation(clearp.begin(), clearp.end())); 

	//vector<int> cidx;
	//for (int i = 0; i < clear_area; i++) { cidx.push_back(i);}

	//for (int i = 0; i < birus.size(); i++) {
	//	junyum_start(birus[i]);
	//}
	//int safe_area = clear_area - junyumed;
	//cout << clear_area << safe_area << endl;

	//do {
	//	junyumed = 0;
	//	map[clearp[cidx[0]].y][clearp[cidx[0]].x] = 1;
	//	map[clearp[cidx[1]].y][clearp[cidx[1]].x] = 1;
	//	map[clearp[cidx[2]].y][clearp[cidx[2]].x] = 1;

	//	for (int i = 0; i < birus.size(); i++) {
	//		junyum_start(birus[i]);
	//	}

	//	int safe_area = clear_area - 3 - junyumed;
	//	if (safe_area > _max)
	//		_max = safe_area;

	//} while (next_permutation(cidx.begin(), cidx.end()));

	cout << ret << endl;

	return 0;
}