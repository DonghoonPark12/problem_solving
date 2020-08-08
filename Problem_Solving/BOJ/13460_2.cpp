#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char map[10][11];

struct INFO {
	int ry, rx, by, bx, cnt;
};
INFO start;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

//구슬의 이동에 관한것 은 추상화 시켜 한 함수로 몰아준다.
void move(int& nry, int& nrx, int& nby, int& nbx, int i)
{
	int rm = 0; int bm = 0;
	while (map[nry + dy[i]][nrx + dx[i]] != '#' && map[nry][nrx] != 'O')
	{
		nry += dy[i], nrx += dx[i], rm++;
	}
	//if (map[nry][nrx] == '#')
	//	nry -= dy[i], nrx -= dx[i];

	while (map[nby + dy[i]][nbx + dx[i]] != '#' && map[nby][nbx] != 'O')
	{
		nby += dy[i], nbx += dx[i], bm++;
	}
	//if (map[nby][nbx] == '#')
	//	nby -= dy[i], nbx -= dx[i];

	//두개의 구슬이 같은 위치에 있을 경우, 이동거리를 계산하여 더 많이 이동한 것을 뒤로 빼준다.
	if (nry == nby && nby == nbx)
	{
		if (rm > bm)
			nry -= dy[i], nrx -= dx[i];
		else
			nby -= dy[i], nbx -= dx[i];
	}
}

int bfs()
{
	int visited[10][10][10][10] = { 0, };

	queue<INFO> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1;

	int ret = -1;
	while (!q.empty())
	{
		int crx = q.front().rx, cry = q.front().ry;
		int cbx = q.front().bx, cby = q.front().by;
		int ccnt = q.front().cnt; 
		q.pop();
		//1. 종료 조건 : 이동하고 종료하면, 11번 만에 이동한 것이므로 for문 타기 전에 멈춰야 한다. 
		if (map[cry][crx] == 'O' && map[cby][cbx] != 'O')
		{
			ret = ccnt; 
			break;
		}
		if (ccnt > 10)	
			break;

		for (int i = 0; i < 4; i++)
		{
			int nry = cry, nrx = crx, nby = cby, nbx = cbx;
			//각 방향으로 구슬 이동
			move(nry, nrx, nby, nbx, i);
			
			//2. 큐에 안담을 조건(블루를 구멍에 빠뜨리는 기울임 움직임은 하지 않는다는 말)
			if (map[nby][nbx] == 'O') continue;

			if (visited[nry][nrx][nby][nbx] == 0)
			{
				visited[nry][nrx][nby][nbx] = 1;
				q.push({ nry, nrx, nby, nbx, ccnt + 1 });
			}
		}
	}
	return ret;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R')
				start.ry = i, start.rx = j;
			if(map[i][j] == 'B')
				start.by = i, start.bx = j;
		}
	}

	start.cnt = 0;

	int res = bfs();
	cout << res << '\n';
	return 0;
}