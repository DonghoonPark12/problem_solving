#include <iostream>
using namespace std;

int arr[21][21];

int N, X;
int check_row() {
	int cnt = 0;
	for (int h = 0; h < N; h++) {
		int st = 0;
		int i = 0;
		int pave[21] = { 0 };
		for (i = 0; i < N; i++) {
			/*---------------------------------------------*/
			if (arr[h][i] < arr[h][i + 1]) {				//�������� ���
				if (arr[h][i + 1] - arr[h][i] != 1) break;  //������ ���̰� 1�̻� �̶��

				int pass = 1;
				if (i == 0) break;							//ó�� ���ĺ��� ������ �� ����. 
				for (int c = 1; c < X; c++) {
					if ( (arr[h][i] != arr[h][i - c]) || (pave[i-c] == 1))
						pass = 0;
				}
				if (!pass) break;
			}
			/*---------------------------------------------*/
			if ( (arr[h][i] > arr[h][i + 1]) && (i!=N-1)) { //�������� ��� 
				if (arr[h][i] - arr[h][i + 1] != 1) break; 

				int pass = 1;
				int c;
				if (i + 2 == N) break; //!!
				for (c = 1; c < X; c++) {
					if (arr[h][i + 1] != arr[h][i + 1 + c]) //������ ������ X��ŭ
						pass = 0;                           //�̾����� �ʴ´ٸ�
					pave[i + c] = 1;
				}
				if (!pass) break;
				pave[i + c] = 1;
			}
			/*---------------------------------------------*/
		}
		if (i == N) //!!
			cnt++;
	}
	return cnt;
}

int check_col() {
	int cnt = 0;
	for (int w = 0; w < N; w++) {
		int st = 0;
		int i = 0;
		int pave[21] = { 0 };
		for (i = 0; i < N; i++) {
			/*---------------------------------------------*/
			if (arr[i][w] < arr[i+1][w]) {				  //�������� ���
				if (arr[i+1][w] - arr[i][w] != 1) break;  //������ ���̰� 1�̻� �̶��
				
				int pass = 1;
				if (i == 0) break;
				for (int c = 1; c < X; c++) {
					if ( (arr[i][w] != arr[i-c][w]) || (pave[i-c] == 1))
						pass = 0;
				}
				if (!pass) break;
			}
			/*---------------------------------------------*/
			if ( (arr[i][w] > arr[i+1][w]) && (i!=N-1)) { //�������� ��� 
				if (arr[i][w] - arr[i+1][w] != 1) break;

				int pass = 1;
				int c;
				if (i + 2 == N) break;
				for (c = 1; c < X; c++) {
					if (arr[i+1][w] != arr[i+1+c][w])    //������ ������ X��ŭ
						pass = 0;                        //�̾����� �ʴ´ٸ�
					pave[i + c] = 1;
				}
				if (!pass) break;
				pave[i + c] = 1;
			}
			/*---------------------------------------------*/
		}
		if (i == N) //!!
			cnt++;
	}
	return cnt;
}

int main(void)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int Answer = 0;
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		//for (int i = 0; i < N; i++) {
		Answer += check_col();
		Answer += check_row();
		//}
		printf("#%d ", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0; //#6, 7, 5, 10
			  //#6, 7, 10
}