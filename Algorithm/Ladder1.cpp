#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[101][101];
int arr_visited[101][101];
char tmp[200];
int des = -1;
int f(int x, int y) {
	if (des >= 0) return des; //�湮�� �Ϸ� ������ ���� �ٽ� �ö��� �ʰ�, des�� ��� ����.
	else {
	arr_visited[x][y] = 1;
	if (x == 0) {
		//des = y;
		return y;
	}
		//��, �� �̵��� �켱������ �д�. 
		if (arr[x][y + 1] != 0 && arr_visited[x][y + 1] == 0) des = f(x, y + 1);//����������
		if (arr[x][y - 1] != 0 && arr_visited[x][y - 1] == 0) des = f(x, y - 1);//��������
		//��, �� �� �� ���� ������
		if (arr[x - 1][y] != 0 && arr_visited[x - 1][y] == 0) des = f(x - 1, y); //���� //���� ������ des>=0�̾ ���� ������ ����� ���� ���ͼ� �ٽ� des�� ����.
	}
	return des;
}
/*
* ���� �湮 �ߴٰ� y���� ���� ���� ��, des�� �����ϰ�, des�� �����Ѵ�. 
* �� ���� ��ġ ���� des�� ���� ���� �´�. 
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
		des = -1;//�������� des�� �ʱ�ȭ
		Ans = f(99, t);

		printf("#%d %d\n", n, Ans);
	}

}

/* ��Ͱ� ���� ����ð��� ���� �� ��� */
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
