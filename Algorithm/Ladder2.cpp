#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[101][101];
int arr_visited[101][101];
int cnt = -1;
int total_move = -1;
int f(int x, int y) {
	if (total_move > 0) return total_move; //�湮�� �Ϸ� ������ ���� �ٽ� �ö��� �ʰ�, total_move�� ��� ����.
	else {
		arr_visited[x][y] = 1; 
		cnt++; //�̵��� ����
		if (x == 99) {
			total_move = cnt;
			return total_move;
		}

		if (arr[x][y + 1] != 0 && arr_visited[x][y + 1] != 1) total_move = f(x, y + 1);//����������
		if (arr[x][y - 1] != 0 && arr_visited[x][y - 1] != 1) total_move = f(x, y - 1);//��������
		if (arr[x + 1][y] != 0 && arr_visited[x + 1][y] != 1) total_move = f(x + 1, y); //�Ʒ���
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
		total_move = 0;//���� ���� �ʱ�ȭ
		for (int j = 0; j < 100; j++) {

			cnt = -1;//�̵��Ÿ� ���� ���� �ʱ�ȭ
			total_move = -1; // �Ϸ��� ������ �Ǵ� �������� �ʱ�ȭ (�߰����� ��� �� ������ ���´�)
			if (arr[0][j] != 0) { //�������� ���� ���� ���� ����(!!)

				for (int a = 0; a < 100; a++) {
					for (int b = 0; b < 100; b++) {
						arr_visited[a][b] = 0; //arr_visited�� ���⼭ �ѹ� �� �ʱ�ȭ ����� �Ѵ�. x���� �����ϱ� �����̴�(!!)
					}
				}

				tmp = f(0, j);
				if (tmp < min) { //�� �̵��Ÿ��� �۴ٸ�
					min = tmp;
					Ans = j;//�ش� y ��ġ�� �ľ� 
				}
			}
		}

		printf("#%d %d\n", n, Ans);
	}

}


