#include <iostream>
#include <string>
using namespace std;
int n, q;
char board[8][8];
char arr[8][8][10];
char que[5][8][8];

/*
	전체 n개의 원소들 중에서 k개를 뽑는 조합 :	https://twpower.github.io/90-combination-by-using-next_permutation

*/
void init() {
	scanf("%d", &n);
	//cin >> n;
	string tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 8; j++) {
			//getline(cin, tmp);
			scanf(" %s",&(arr[i]));
			//strcpy(arr[i][j], tmp.c_str());
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%s\n", &(que[i]));
			//getline(cin, tmp);
			//strcpy(que[i][j], tmp.c_str());
		}
	}
}

bool is_same(char *board[], char **que[], int n) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((board[i][j] == '.') && (que[n][i][j] == 'W'))
				continue;
			if (board[i][j] != que[n][i][j])
				return false;
		}
	}
	return true;
}

//void spin(int n) {
//	for (int i = 0; i<8; i++) {
//		for (int j = 0; j<8; j++) {
//			arr[n][j][7 - i][1] = arr[n][i][j][0];
//		}
//	}
//	for (int i = 0; i<8; i++) {
//		for (int j = 0; j<8; j++) {
//			arr[n][j][7 - i][2] = arr[n][i][j][1];
//		}
//	}
//	for (int i = 0; i<8; i++) {
//		for (int j = 0; j<8; j++) {
//			arr[n][j][7 - i][3] = arr[n][i][j][2];
//		}
//	}
//}

int main(void)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		init();
	/*	for (int i = 0; i < n; i++)
			spin(i);*/

		
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;

}