#define	_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
using namespace std;
//����Ʈ ī��

int diag_x[4] = { 1,-1,-1, 1 }; //������ �Ʒ�, ���� �Ʒ�
int diag_y[4] = { 1,1, -1,-1 };
int main(void)
{
	int T, test_case;
	int Answer = 0;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T); 
	for (test_case = 0; test_case < T; test_case++) {
		/////////////////////////////////////////////////////////////////////////////////////////////////
		int n; scanf("%d", &n);
		vector<vector<int>> arr(n, vector<int>(n));
		vector<int> dup(101);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %d", &arr[i][j]);
			}
		}
		int max_cnt = 0;
		int max = 0;
		int cnt = 0;
		int str_x, str_y;
		int cur_x, cur_y;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				//memset(dup, 0, sizeof(dup));
				fill(dup.begin(), dup.end(), 0);
				str_x = x; str_y = y;
				cur_x = x; cur_y = y;
				cnt = 0;
				
				dup[arr[cur_y][cur_x]] = 1;
				cout << arr[cur_y][cur_x];
				while( (cur_x + diag_x[0]) < n && (cur_y + diag_y[0]) < n
					&& (cur_x + diag_x[0]) >= 0 && (cur_y + diag_y[0]) >= 0
					&& !((cur_x + diag_x[0]) == n-1 && (cur_y + diag_y[0]) == n-1) //������ �Ʒ�
					&& dup[arr[cur_y + diag_y[0]][cur_x + diag_x[0]]] == 0) { //��踦 ����� �ʰ�, �湮 �ߴ� ���� �ƴ϶��, ������ �Ʒ��� �̵�
					
					cur_x = cur_x + diag_x[0]; cur_y = cur_y + diag_y[0];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;
				}
				while ((cur_x + diag_x[1]) < n && (cur_y + diag_y[1]) < n
					&& (cur_x + diag_x[1]) >= 0 && (cur_y + diag_y[1]) >= 0
					&& !((cur_x + diag_x[1]) == 0 && (cur_y + diag_y[1]) == n - 1) //���� �Ʒ�
					&& dup[arr[cur_y + diag_y[1]][cur_x + diag_x[1]]] == 0) { //�湮 �ߴ� ���� �ƴ϶��, ���� �Ʒ��� �̵�
					
					cur_x = cur_x + diag_x[1]; cur_y = cur_y + diag_y[1];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;
				}
				while ((cur_x + diag_x[2]) < n && (cur_y + diag_y[2]) < n
					&& (cur_x + diag_x[2]) >= 0 && (cur_y + diag_y[2]) >= 0
					&& !((cur_x + diag_x[2]) == 0 && (cur_y + diag_y[2]) == 0) //���� ��
					&& dup[arr[cur_y + diag_y[2]][cur_x + diag_x[2]]] == 0) { //�湮 �ߴ� ���� �ƴ϶��, ���� �Ʒ��� �̵�
					
					cur_x = cur_x + diag_x[2]; cur_y = cur_y + diag_y[2];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;
				}
				while ((cur_x + diag_x[3]) < n && (cur_y + diag_y[3]) < n
					&& (cur_x + diag_x[3]) >= 0 && (cur_y + diag_y[3]) >= 0
					&& !((cur_x + diag_x[3]) == n-1 && (cur_y + diag_y[3]) == 0) //������ ��
					&& dup[arr[cur_y + diag_y[3]][cur_x + diag_x[3]]] == 0
					|| ( ((cur_x + diag_x[3])==str_x) && ((cur_y + diag_y[3])==str_y) )) { //�湮 �ߴ� ���� �ƴ϶��, ���� �Ʒ��� �̵�
					cur_x = cur_x + diag_x[3]; cur_y = cur_y + diag_y[3];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;

					if ( (cur_x == str_x) && (cur_y == str_y) ) break;
				}
				while( (cur_x + diag_x[0]) < n && (cur_y + diag_y[0]) < n
					&& (cur_x + diag_x[0]) >= 0 && (cur_y + diag_y[0]) >= 0
					&& !((cur_x + diag_x[0]) == n - 1 && (cur_y + diag_y[0]) == n - 1) //������ �Ʒ�
					&& dup[arr[cur_y + diag_y[0]][cur_x + diag_x[0]]] == 0 
					|| ( ((cur_x + diag_x[0]) == str_x) && ((cur_y + diag_y[0]) == str_y) )){ //�湮 �ߴ� ���� �ƴ϶��, ������ �Ʒ��� �̵�
					cur_x = cur_x + diag_x[0]; cur_y = cur_y + diag_y[0];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;

					if ((cur_x == str_x) && (cur_y == str_y)) break;
				}
				while ((cur_x + diag_x[1]) < n && (cur_y + diag_y[1]) < n
					&& (cur_x + diag_x[1]) >= 0 && (cur_y + diag_y[1]) >= 0
					&& !((cur_x + diag_x[1]) == 0 && (cur_y + diag_y[1]) == n - 1) //���� �Ʒ�
					&& dup[arr[cur_y + diag_y[1]][cur_x + diag_x[1]]] == 0
					|| (((cur_x + diag_x[1]) == str_x) && ((cur_y + diag_y[1]) == str_y))){ //�湮 �ߴ� ���� �ƴ϶��, ���� �Ʒ��� �̵�
					cur_x = cur_x + diag_x[1]; cur_y = cur_y + diag_y[1];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;

					if ((cur_x == str_x) && (cur_y == str_y)) break;
				}
				while ((cur_x + diag_x[2]) < n && (cur_y + diag_y[2]) < n
					&& (cur_x + diag_x[2]) >= 0 && (cur_y + diag_y[2]) >= 0
					&& !((cur_x + diag_x[2]) == 0 && (cur_y + diag_y[2]) == 0) //���� ��
					&& dup[arr[cur_y + diag_y[2]][cur_x + diag_x[2]]] == 0
					|| (((cur_x + diag_x[2]) == str_x) && ((cur_y + diag_y[2]) == str_y))) { //�湮 �ߴ� ���� �ƴ϶��, ���� �Ʒ��� �̵�
					cur_x = cur_x + diag_x[2]; cur_y = cur_y + diag_y[2];
					dup[arr[cur_y][cur_x]] = 1;
					cout << arr[cur_y][cur_x];
					cnt++;

					if ((cur_x == str_x) && (cur_y == str_y)) break;
				}
				if (str_x == cur_x && str_y == cur_y) {
					if (cnt > max_cnt)
						max_cnt = cnt;
					cout << max_cnt;
				}

				cout << "\n";
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////
		printf("#%d ", test_case + 1);
		printf("%d\n", max_cnt);
	}

	return 0;

}