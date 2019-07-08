#include <iostream>
using namespace std;
//홀수는 싫어 시간 초과
int n;
int arr[301][301];
bool visited[301][301]; // 지나 왔던 방향을 넣는 값 //미로를 똑 같이 본떠서 방문된 곳이면 빠져 나오면서 1로 채울 것.
int DP[301][301];
int x[4] = {1, 0, -1}; //아래, 오른쪽
int y[4] = { 0, 1, 0};
int max_even;
int min_odd = 300*300;
int flag = false;
int even;
int odd;

int nx, ny;
int sx;
int sy;
void previous(int i, int j) {

	for (int k = 0; k < 2; k++) {

		nx = i + x[k];
		ny = j + y[k];//아, 오

		if (visited[nx][ny] == true || nx == 0 || ny == 0 || nx == n + 1 || ny == n + 1)
			continue;

		if (arr[nx][ny] % 2 == 0) {
			even++;
			previous(nx, ny);
			even--;
		}
	} //최대로 (아래, 오른쪽, 왼쪽으로 가서) 갈 수 있는 짝수 길 찾는다.
	
	if ( (nx+ny) > (sx + sy)) {
		sx = nx; sy = ny-1;
	}
	return;

}

void dfs(int i, int j)
{
	if (flag) return;//이미 홀수가 0이라면 그 이후는 탐색 안해도 된다. 

	if (i == n && j == n) {
		if (odd<=min_odd) {
			max_even = even;
			min_odd = odd;
		}
		if (odd == 0) flag = true;
		return;
	}
	else
	{
		visited[i][j] = true;
		/*------------짝수 우선 순위------------*/
		for (int k = 0; k < 3; k++) {

			int ax = i + x[k];
			int ay = j + y[k];//아, 오, 위

			if (visited[ax][ay] == true || ax==0 || ay == 0 || ax == n+1 || ay == n+1)
				continue;

			if (arr[ax][ay] % 2 == 0) {
				even++;
				//cout << "Enter " << arr[ax][ay] << endl;
				dfs(ax, ay);
				//cout << "Exit " << arr[ax][ay] << endl;
				even--;
			}
		}
		/*--------------------------------------*/
		for (int k = 0; k < 3; k++) {

			int ax = i + x[k];
			int ay = j + y[k];

			if (visited[ax][ay] == true || ax == 0 || ay == 0 || ax == n + 1 || ay == n + 1)
				continue;

			if (arr[ax][ay] % 2 == 1) {
				odd++;
			//	cout << "Enter " << arr[ax][ay] << endl;
				dfs(ax, ay);
			//	cout << "Exit " << arr[ax][ay] << endl;
				odd--;
			}
		}

		visited[i][j] = false; //arr_V가 1이 되면서 현재 위치 왔는데 위,아,왼,오 도 아니면 arr_V를 다시 0으로
	}
}
//typedef struct _node {
//	int x, y;
//	_node(int _x, int _y)
//		:x(_x), y(_y)
//	{}
//}node;
//bool flag;
//queue<node> q;
//void dfs(int i, int j)
//{
//	if (arr[i][j] % 2 == 0)
//		even++;
//	else
//		odd++;
//
//	if (i == n && j == n) {
//		if (even > max_even) {
//			max_even = even;
//		}
//		if (odd < min_odd) {
//			min_odd = odd;
//		}
//		flag = 1;
//		return;
//	}
//	else
//	{
//		visited[i][j] = true;
//		/*------------짝수 우선 순위------------*/
//		for (int k = 0; k < 4; k++) {
//			int ax = i + x[k];
//			int ay = j + y[k];//아, 오, 위, 왼
//
//			if (visited[ax][ay] == true || ax==0 || ay == 0 || ax == n+1 || ay == n+1)
//				continue;
//
//			if (arr[ax][ay] % 2 == 0) {
//				even++;
//				//cout << "Enter " << arr[ax][ay] << endl;
//				dfs(ax, ay);
//				even--;
//			}
//
//		}
//		for (int k = 0; k < 4; k++) {
//			int ax = i + x[k];
//			int ay = j + y[k];//위, 아, 오, 왼
//
//			if (visited[ax][ay] == true || ax == 0 || ay == 0 || ax == n + 1 || ay == n + 1)
//				continue;
//			//cout << "Enter " << arr[ax][ay] << endl;
//			odd++;
//			dfs(ax, ay);
//			odd--;
//			//cout << "Exit " << arr[ax][ay] << endl;
//		}
//		/*-------------------------------------------*/
//
//		visited[i][j] = false; //arr_V가 1이 되면서 현재 위치 왔는데 위,아,왼,오 도 아니면 arr_V를 다시 0으로
//	}
//}
//
int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++){
		int Ans = 0;
		scanf("%d", &n);
		for (int i = 1; i<=n; i++) {
			for (int j = 1; j<=n; j++) {
				scanf(" %d",&arr[i][j]);
				visited[i][j] = false;
				DP[i][j] = 0;
			}
		}
		flag = false;

		sx = 0, sy = 0;
		previous(1, 1);
		even = sx + sy -1, odd = 0;
		int i;
		for (i = 1; i <= sx; i++) {
			visited[i][1] = true;
		}
		for (int j = 2; j <= sy; j++) {
			visited[i - 1][j] = true;
		}
		dfs(sx, sy);

		printf("#%d %d %d\n", test_case + 1, min_odd ,max_even);
	}
	return 0;

}