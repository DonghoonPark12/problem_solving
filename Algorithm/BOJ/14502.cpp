#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
struct ����ü�̸� �����̸�[ũ��] = { { .����̸�1 = ��1, .����̸�2 = ��2 },
									 { .����̸�1 = ��3, .����̸�2 = ��4 } };
struct ����ü�̸� �����̸�[ũ��] = { { ��1, ��2 }, { ��3, ��4 } };

*/
const int dx[4] = { -1, 1, 0, 0 }; //������ ���� 4���� üũ
const int dy[4] = { 0, 0 ,-1, 1 }; //��, ��, ��, �Ʒ�
int n, m, ret; //��� ���� üũ 

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
//	//map[p.y][p.x] = 2; //�� �ʿ� ����. �̹� �����Ǿ� �ִ�. 
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
//					q.push({ ny,nx }); //�������� ���� ���� ��� ť�� ����
//					map[ny][nx] = 2;//���� �Ǿ���.
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
//		pick.push_back(clearp[i]); //�̷������� �ϸ� clearp ������ ������ ã�� �� �ִ�.
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
			backup[y][x] = map[y][x]; //���� ���� �̸� ���

			if (backup[y][x] == 2) { //���̷��� ������ �̶��
				q.push(y * 10 + x); //ť�� ����
				visited[y][x] = 1;  //�湮 ǥ��?? - ���̷����� �湮�� ������ ǥ��
			}

		}
	}

	while (!q.empty()) {
		int cur = q.front(); //���� ���̷����� ��ġ
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

void pick_dfs(int count, int sy, int sx) { //���� ���� ����, (���� ��ǥ)
	if (count == 3) {
		bfs();
		return;
	}

	for (int y = sy; y < n; y++) {
		for (int x = sx; x < m; x++) {
			if (map[y][x] == 0) {
				map[y][x] = 1;    //�����Ҹ� ���鼭 ������� ���� �����
				pick_dfs(count + 1, y, x);
				map[y][x] = 0;    //��Ʈ��ŷ(N-Queen) ���� ó�� �ٽ� ���� �ŵд�.
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

	// �̷��԰� �ȵȴ�. 
	// next_permutation�� ����ü�� ���Ұ� ���� ���͸� ��ȸ���� ���Ѵ�. ����, int�� ���Ҹ� ���� ���͸� �ǳ� ����.
	// clear�� ������ ������ ũ��� �ϴ� ���͸� ���� ��ȸ�� ���� �ְڴ�. 
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