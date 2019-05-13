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
		for (int x = 0; x < N; x++) {//���� ��ġ����

			for (int a = 1; a < N; a++) {// a : 1~3, 2������ �ص� �ȴ�. 
				for (int b = 1; b < N; b++) {// b : 1~3, 1) �������� ����� �� �� �ִ� ��� �簢���� ���� ����

					if (x + a <= N - 1 //������ ����
						&& y + a + b <= N - 1 //�Ʒ� ����
						&& x - b >= 0 //���� ����
						&& (a + b) * 2 > result) { //������ ���ߴ� �� ���� Ŭ ���ɼ� �ִٸ� 
						                           //2) �簢���� �������� �ȵǸ� pass
						fill(isvisited.begin(), isvisited.end(), 0);

						bool isAble = true;
						int cur_y = y, cur_x = x;

						//(���� �ϴ�)
						for (int n = 0; n < a; n++) {
							cur_y++; cur_x++;
							if (!isvisited[map[cur_y][cur_x]])
								isvisited[map[cur_y][cur_x]] = true;
							else {
								isAble = false;
								break;
							}
						}
						if (!isAble) continue; //3) �簢���� ũ��� ������ �����ϰ�, �簢�� ���� �ߺ� ����Ʈ ���δ�
						                       //   �̵��ϸ鼭 �����Ѵ�. �ش� �簢���� ���� �ߺ� ���ڰ� ������ �н�

						//(���� �ϴ�)
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

						//(���� ���)
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

						//(���� ���)
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


