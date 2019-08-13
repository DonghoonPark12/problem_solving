//#include <iostream>
//using namespace std;
//
//int cry, crx, cby, cbx, gy, gx;
//int map[10][10];
//int move;
//int move_save;
//int flag; //if(R --> O) : 1, if(B --> O) : -1
//int d_past;
//
//int dfs(int cry, int crx, int move) {
//	if (flag) return 1;
//	else return -1;
//
//	if (move >= 10) return 0;
//
//	for (int d = 0; d < 4; d++) {
//		if (d == 0 && (d_past != 0 || d_past != 2)) { //����
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cbx--; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 0;
//			dfs(cry, crx, move + 1);
//		}
//		else if (d == 1 && (d_past != 1 || d_past != 3)) { //�Ʒ���
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cby++; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 1;
//			dfs(cry, crx, move + 1);
//		}
//		else if (d == 2 && (d_past !=2 && d_past != 0)) { //������
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cbx++; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				crx++; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 2;
//			dfs(cry, crx, move + 1);
//		}
//		else if(d==3 && (d_past != 3 && d_past != 1)) { //d ==3 //����
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			while (map[cby][cbx] != '#' && map[cby][cbx] != 'R') {
//				cby--; if (map[cby][cbx] == 'O') { flag = -1; break; }
//			}
//			while (map[cry][crx] != '#' && map[cry][crx] != 'B') {
//				cry--; if (map[cry][crx] == 'O') { flag = 1; break; }
//			}
//			if (flag) { move_save = move; return 1; }
//			else return -1;
//			d_past = 3;
//			dfs(cry, crx, move + 1);
//		}
//		else
//		{ }
//	}
//
//	if (move < 10)
//		return 0;
//	else {
//		flag = -1; return 0;
//	}
//}
//
//int main() {
//	int n, m;//����, ����
//	cin >> n >> m;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m ; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 'R') { cry = i, crx = j; }
//			if (map[i][j] == 'B') { cby = i, cbx = j; }
//			if (map[i][j] == 'O') {  gy = i,  gx = j; }
//		}
//	}
//	dfs(cry, crx, 0);
//	if (move_save > 0)
//		cout << move_save << endl;
//	else
//		cout << -1 << endl;
//	return 0;
//}

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
	int ry, rx, by, bx, count;
};

INFO start;
char map[10][11];

int bfs() {
	const int dy[] = { -1, 1, 0, 0 }; //��, �Ʒ�, ����, ������
	const int dx[] = { 0, 0, -1, 1 };

	int visited[10][10][10][10] = { 0, };
	queue<INFO> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1; //ť�� �̿��ؼ� ������ ��ġ�� ����ϰ�, ���� ���·� ������ �̵� ��Ų��.

	int ret = -1;
	while (!q.empty()) {
		INFO cur = q.front(); //���� ���� ����, �Ķ� ���� ���� ť�� ���� �ִ´�. 
		q.pop();
		if (cur.count > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ret = cur.count; //������� ī��Ʈ�� ���� ����.
			break;
		}

		// ��� ��￩ ���� Ž��
		for (int dir = 0; dir < 4; ++dir) { //�� �������� �����
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			while (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {//���� �ƴϰ�, ������ �ƴ϶��
				next_ry += dy[dir], next_rx += dx[dir];//�� �������� ��� �̵�
			}
			if(map[next_ry][next_rx] == '#')
				next_ry -= dy[dir], next_rx -= dx[dir];//���̶�� �ٽ� ���ƿ� �ش�.

			while (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {//�Ķ� ������ ���� �̵��� �ش�.
				next_by += dy[dir], next_bx += dx[dir];
			}
			if(map[next_by][next_bx] == '#')
				next_by -= dy[dir], next_bx -= dx[dir];

			//������ �� ������ ���� ��ҿ� �ִ� ����̴�. 
			if (next_rx == next_bx && next_ry == next_by && map[next_ry][next_rx] != 'O') {
				int r_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx); //�̶� ���� ����, �Ķ� ���� �̵��� �Ÿ��� ����Ѵ�.
				int b_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx); //��� �������� ���� �̵��ؿԴ��� abx(y�̵�) + abs(x�̵�) ���� ����ϸ� �� �ʿ� ����.
				if (r_dist > b_dist)
					next_ry -= dy[dir], next_rx -= dx[dir];
				else
					next_by -= dy[dir], next_bx -= dx[dir];
			}

			//���� �߿��� �κ�.
			if (visited[next_ry][next_rx][next_by][next_bx] == 0) {//�ش� ������ �湮�� �ȵ��ִٸ�
				visited[next_ry][next_rx][next_by][next_bx] = 1; 
				INFO next;
				next.ry = next_ry; next.rx = next_rx;
				next.by = next_by; next.bx = next_bx;
				next.count = cur.count + 1;
				q.push(next);
			}
		} //4���� for��
	}//queue while ��
	return ret;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m ; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
				start.ry = i, start.rx = j;
			if (map[i][j] == 'B')
				start.by = i, start.bx = j;
		}
	}	
	start.count = 0;
	
	int ret = bfs();
	cout << ret << endl;
	return 0;
}