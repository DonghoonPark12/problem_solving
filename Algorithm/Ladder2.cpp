#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[101][101];
int arr_visited[101][101];
int cnt = -1;
int total_move = -1;
int f(int x, int y) {
	if (total_move > 0) return total_move; //방문이 완료 됬으면 위로 다시 올라가지 않고, total_move를 계속 리턴.
	else {
		arr_visited[x][y] = 1; 
		cnt++; //이동시 증가
		if (x == 99) {
			total_move = cnt;
			return total_move;
		}

		if (arr[x][y + 1] != 0 && arr_visited[x][y + 1] != 1) total_move = f(x, y + 1);//오른쪽으로
		if (arr[x][y - 1] != 0 && arr_visited[x][y - 1] != 1) total_move = f(x, y - 1);//왼쪽으로
		if (arr[x + 1][y] != 0 && arr_visited[x + 1][y] != 1) total_move = f(x + 1, y); //아래로
	}
	return total_move;
}
int main() {
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	for (int tc = 0; tc < 10; tc++) {
		int tmp = 0; int Ans = 0;
		int n;

		scanf("%d", &n);

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				arr[i][j] = 0;
				//arr_visited[i][j] = 0;
			}
		}

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf(" %d", arr[i] + j);
			}
		}
		int min = 100*2 + 50;
		total_move = 0;//전역 변수 초기화
		for (int j = 0; j < 100; j++) {

			cnt = -1;//이동거리 전역 변수 초기화
			total_move = -1; // 완료의 기준이 되는 전역변수 초기화 (추가적인 재귀 문 입장을 막는다)
			if (arr[0][j] != 0) { //내려가는 길이 있을 때만 조사(!!)

				for (int a = 0; a < 100; a++) {
					for (int b = 0; b < 100; b++) {
						arr_visited[a][b] = 0; //arr_visited는 여기서 한번 더 초기화 해줘야 한다. x마다 조사하기 때문이다(!!)
					}
				}

				tmp = f(0, j);
				if (tmp < min) { //총 이동거리가 작다면
					min = tmp;
					Ans = j;//해당 y 위치를 파악 
				}
			}
		}

		printf("#%d %d\n", n, Ans);
	}

}


