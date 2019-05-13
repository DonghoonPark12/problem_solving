#include <iostream>
#include <vector>
using namespace std;

int N;
int map[20][20];
//int isvisited[101];
vector<int> isvisited(101);
int result;

void init() {
	fill(isvisited.begin(), isvisited.end(), 0);
	result = -1;
}

void solve() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {//현재 위치에서

			for (int a = 1; a < N; a++) {// a : 1~3, 2까지만 해도 된다. 
				for (int b = 1; b < N; b++) {// b : 1~3, 1) 한점에서 만들어 질 수 있는 모든 사각형에 대해 조사

					if (x + a <= N - 1 //오른쪽 범위
						&& y + a + b <= N - 1 //아래 범위
						&& x - b >= 0 //왼쪽 범위
						&& (a + b) * 2 > result) { //이전해 구했던 값 보다 클 가능성 있다면 
						                           //2) 사각형에 생성조차 안되면 pass
						fill(isvisited.begin(), isvisited.end(), 0);

						bool isAble = true;
						int cur_y = y, cur_x = x;

						//(우측 하단)
						for (int n = 0; n < a; n++) {
							cur_y++; cur_x++;
							if (!isvisited[map[cur_y][cur_x]])
								isvisited[map[cur_y][cur_x]] = true;
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue; //3) 사각형의 크기는 위에서 결정하고, 사각형 내에 중복 디저트 여부는
						                       //   이동하면서 결정한다. 해당 사각형이 변에 중복 숫자가 있으면 패스

						//(좌측 하단)
						for (int n = 0; n < b; n++) {
							cur_y++; cur_x--;
							if (!isvisited[map[cur_y][cur_x]])
								isvisited[map[cur_y][cur_x]] = true;
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;

						//(좌측 상단)
						for (int n = 0; n < a; n++) {
							cur_y--; cur_x--;
							if (!isvisited[map[cur_y][cur_x]])
								isvisited[map[cur_y][cur_x]] = true;
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;

						//(우측 상단)
						for (int n = 0; n < b; n++) {
							cur_y--; cur_x++;
							if (!isvisited[map[cur_y][cur_x]])
								isvisited[map[cur_y][cur_x]] = true;
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue;

						result = 2 * (a + b);
					}

				}//end b
			}//end a

		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);

	int T;
	scanf("%d ", &T);
	for (int t = 1; t <= T; t++) {
		init();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		solve();
		printf("#%d %d\n", t, result);
	}
	return 0;
}


