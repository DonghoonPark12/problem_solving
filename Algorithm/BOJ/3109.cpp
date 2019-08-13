#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;//보드 크기, 사과 갯수
int b[101][101];//보드
const int x[4] = { 1, 0, -1, 0 };
const int y[4] = { 0, 1, 0, -1 };

//int sx[101];
//int sy[101];
queue<pair<int, int>> sn;
queue<pair<int, char>> order ;

int t = 0;
int d = 0;

void move() {
	//뱀의 움직임 표현
	int nx = 1;
	int ny = 1;
	b[ny][nx] = 2; //뱀의 이동을 큐에 넣고, 보드상에도 표시해야 한다.
	sn.push({ ny, nx }); //ny, nx 및 큐로 뱀의 위치를 tracking 해야 한다.

	while (1) {
		t++;
		ny = ny + y[d];
		nx = nx + x[d];

		if (ny < 1 || ny > n || nx < 1 || nx > n || b[ny][nx] == 2) {
			break;
		}

		sn.push({ ny, nx });

		if (b[ny][nx] != 1) {//사과가 아니면
			b[sn.front().first][sn.front().second] = 0;
			sn.pop();
			//b[ny - y[d]][nx - x[d]] = 0;
		}

		b[ny][nx] = 2;


		if (!order .empty()) {
			if (t == order .front().first) {
				if (order .front().second == 'D')
					d = (d + 1) % 4; //방향 전환 우->하>좌->상
				if (order .front().second == 'L')
					d = (d + 3) % 4;
				order .pop();
			}
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> k;
	int ay, ax;
	for (int i = 0; i < k; i++) {
		cin >> ay >> ax;
		b[ay][ax] = 1;//사과
	}
	
	int L; cin >> L;
	int a; char b;
	for (int i = 0; i < L; i++) {
		cin >> a >> b;
		order.push({ a,b });
	}

	move();
	cout << t;
	return 0;
}