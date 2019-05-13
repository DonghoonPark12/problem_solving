#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[101][101];
int arr_visited[101][101];
char tmp[200];
int des = -1;
int f(int x, int y) {
	if (des >= 0) return des; //방문이 완료 됬으면 위로 다시 올라가지 않고, des를 계속 리턴.
	else {
	arr_visited[x][y] = 1;
	if (x == 0) {
		//des = y;
		return y;
	}
		//좌, 우 이동에 우선순위를 둔다. 
		if (arr[x][y + 1] != 0 && arr_visited[x][y + 1] == 0) des = f(x, y + 1);//오른쪽으로
		if (arr[x][y - 1] != 0 && arr_visited[x][y - 1] == 0) des = f(x, y - 1);//왼쪽으로
		//좌, 우 중 갈 곳이 없으면
		if (arr[x - 1][y] != 0 && arr_visited[x - 1][y] == 0) des = f(x - 1, y); //위로 //위로 갔으나 des>=0이어서 전역 변수에 저장된 값을 들고와서 다시 des에 저장.
	}
	return des;
}
/*
* 위로 방문 했다가 y값을 전달 받은 후, des에 저장하고, des를 리턴한다. 
* 그 다음 위치 들은 des를 끌고 내려 온다. 
*/
int main() {
	
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	for (int tc = 0; tc < 10; tc++) {
		int Ans = 0;
		int n;
		int i, j;
		scanf("%d", &n);

		for (i = 0; i < 100; i++) {
			for (j = 0; j < 100; j++) {
				arr[i][j] = 0;
				arr_visited[i][j] = 0;
			}
		}

		for (i = 0; i < 100; i++) {
			//scanf(" %s", &tmp);
			for (j = 0; j < 100; j++) {
				scanf(" %d", arr[i] + j);
				//arr[i][j/2] = tmp[j] - '0';
			}
		}
		int t;
		for (j = 0; j < 100; j++) {
			if (arr[99][j] == 2) {
				t = j;
				break;
			}
		}
		des = -1;//전역변수 des도 초기화
		Ans = f(99, t);

		printf("#%d %d\n", n, Ans);
	}

}

/* 재귀가 없어 실행시간이 단축 된 경우 */
#include <cstdio>
#include <string.h>

struct Pos {
	int x, y;
} start;

char map[100][102];
int tc = 10, t, i, j, max, sum;
int main()
{
	//freopen("input.txt", "r", stdin);
	for (t = 1; t <= tc; t++)
	{
		memset(map, '0', sizeof(map));
		scanf("%d\n", &t);
		for (i = 0; i < 100; i++)
		{
			for (j = 1; j <= 100; j++)
			{
				scanf("%1c ", &map[i][j]);
				if (map[i][j] == '2')
				{
					start.x = j; start.y = i;
				}
			}
		}
		while (true)
		{
			if (map[start.y][start.x - 1] == '1')
			{
				for (; map[start.y][start.x - 1] != '0'; start.x--);
				start.y--;
			}
			else if (map[start.y][start.x + 1] == '1')
			{
				for (; map[start.y][start.x + 1] != '0'; start.x++);
				start.y--;
			}
			else
			{
				start.y--;
			}
			if (start.y == 0)
				break;
		}
		printf("#%d %d\n", t, start.x - 1);
	}
	return 0;
}
