#include<iostream>
using namespace std;

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int main(int argc, char** argv) {
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;


	for (test_case = 1; test_case <= T; ++test_case) {
		int P[10][5] = { 0 }; // x, y, S's number, length, finish
		int S[2][4] = { 0 };  // x, y, �ɸ��� �ð�, ���������ִ� �����
		int N;
		scanf("%d", &N);

		//int **arr = new int*[N]();
		//for (int i = 0; i < N; i++) {
		//   arr[i] = new int[N];
		//}

		int input_num = 0;
		int num_of_P = 0;
		int num_of_S = 0;
		int num_of_S1 = 0;
		int num_of_S2 = 0;
		for (int j = 0; j < N; j++) {    // column
			for (int i = 0; i < N; i++) {// row
				scanf("%d", &input_num);//arr[i][j]

				if (input_num == 1) { // Save P information, arr[i][j]
					P[num_of_P][0] = i;
					P[num_of_P][1] = j;
					num_of_P++;
				}
				else if (input_num > 1) { // Save S information, arr[i][j]
					S[num_of_S][0] = i;
					S[num_of_S][1] = j;
					S[num_of_S][2] = input_num;//arr[i][j]
					num_of_S++;
				}
			}
		}

		//for (int j = 0; j < N; j++) {    // column
		//   for (int i = 0; i < N; i++) {// row
		//      printf("%d ", arr[i][j]);
		//   }
		//   printf("\n");
		//}
		//printf("\n");
		//for (int j = 0; j < 3; j++) {    // column
		//   for (int i = 0; i < 2; i++) {// row
		//      printf("%d ", S[i][j]);
		//   }
		//   printf("\n");
		//}
		//printf("\n");
		//for (int j = 0; j < 4; j++) {    // column
		//   for (int i = 0; i < num_of_P; i++) {// row
		//      printf("%d ", P[i][j]);
		//   }
		//   printf("\n");
		//}
		//printf("\n");
		for (int p = 0; p < num_of_P; p++) {
			int length1 = abs(P[p][0] - S[0][0]) + abs(P[p][1] - S[0][1]);
			int length2 = abs(P[p][0] - S[1][0]) + abs(P[p][1] - S[1][1]);

			if (length1 + S[0][2] == length2 + S[1][2]) {
				if (num_of_S1*S[0][2] < num_of_S2*S[1][2]) {
					P[p][2] = 0;
					P[p][3] = length1;
					num_of_S1++;
				}
				else {
					P[p][2] = 1;
					P[p][3] = length2;
					num_of_S2++;
				}
			}
			else if (length1 + S[0][2] < length2 + S[1][2]) {
				P[p][2] = 0;
				P[p][3] = length1;
				num_of_S1++;

			}
			else {
				P[p][2] = 1;
				P[p][3] = length2;
				num_of_S2++;
			}
		}

		//for (int j = 0; j < 4; j++) {    // column
		//   for (int i = 0; i < num_of_P; i++) {// row
		//      printf("%d ", P[i][j]);
		//   }
		//   printf("\n");
		//}
		//printf("\n");

		int current_time = 0;
		int num_finish_time_P = 0;
		int result = 0;
		while (num_finish_time_P != num_of_P) {
			current_time++;
			printf("========== current_time : %d ==========\n", current_time);
			for (int p = 0; p < num_of_P; p++) {
				if (P[p][4] == current_time && P[p][4] != 0) {// ��� ������
					S[P[p][2]][3]--;
				}
			}
			for (int p = 0; p < num_of_P; p++) {
				if (P[p][3] < current_time && P[p][4] == 0) {// �Ա� ����
					if (S[P[p][2]][3] < 3) { //�������� ������� 3���� �۴ٸ�
						P[p][4] = current_time + S[P[p][2]][2];
						result = MAX(result, current_time + S[P[p][2]][2]);
						S[P[p][2]][3]++;
						num_finish_time_P++;
					}
				}
			}

			for (int j = 0; j < 4; j++) {    // column
				for (int i = 0; i < 2; i++) {// row
					printf("%d ", S[i][j]);
				}
				printf("\n");
			}
			printf("\n");
			for (int j = 0; j < 5; j++) {    // column
				for (int i = 0; i < num_of_P; i++) {// row
					printf("%d ", P[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}

		printf("#%d %d\n", test_case, result);
		int k = 0;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

//#include<iostream>
//#include<vector>
//#include<queue>
//using namespace std;
//
//int N;
//int board[10][10] = { 0, };
//vector<pair<int, int>> people;
//vector<pair<int, int>> stair;
//int s[10];
//int ans;
//int siz;
//
//int calc() {
//	int t = 0;
//	int chk = 0;
//	int d[10];
//	queue<int> c[2];
//
//	for (int i = 0; i < siz; i++) {
//		d[i] = abs(people[i].first - stair[s[i]].first) + abs(people[i].second - stair[s[i]].second);
//	}
//
//	while (true) {
//		if (t >= ans) return t;
//
//		if (chk == siz) return t;//�ο��� ��� ���������ٸ� �ð� t ����
//
//		/* ��� ���ο����� �̵� */
//		for (int i = 0; i < 2; i++) {   //��ܿ� �� �ο�, 1����� �ѹ�, 2�� ��� �ѹ� �˻�
//			int ss = c[i].size();
//
//			for (int j = 0; j < ss; j++) {
//				int top = c[i].front(); //top�� ��ܿ� �ִ� �ο��� ��ġ.
//				c[i].pop();
//				top--;
//				if (top != 0)
//					c[i].push(top);
//				else {
//					chk++;              //�������� �ο� üũ
//				}
//			}
//		}
//
//		/* �ð� �帧�� ���� ��ܿ� ������ �ο� */
//		for (int i = 0; i < siz; i++) {//�Ա��� ������ �ο� �ľ�
//			if (t == d[i]) {           //6�� �� ù��° ��ܵ� ����
//				
//				if (c[s[i]].size()<3)  //��� �Ա� ������ �ƹ��� ���ٸ�
//					c[ s[i] ].push( board[stair[s[i]].first][stair[s[i]].second] );
//				
//				else {
//					c [s[i] ].push( board[stair[s[i]].first][stair[s[i]].second] + c[s[i]].front());
//				}
//
//			}
//		}
//		t++;
//
//	}
//
//}
//
//void dfs(int cnt) {
//
//	if (cnt == people.size()) {
//		int tmp = calc();        //�ð��� ����
//		if (ans > tmp) ans = tmp;//�ð��� �� ª�� �ɸ��ٸ� ans ����
//		return;
//	}
//
//	s[cnt] = 0; dfs(cnt + 1); //��� 1�� ��ܿ� ���� ��� ~ ��� 2�� ��ܿ� ���� ���
//	s[cnt] = 1; dfs(cnt + 1);
//
//}
//
//int main() {//��� ������� ����� ������ �̵��� �Ϸ�Ǵ� �ð��� �ּҰ� �Ǵ� ���
//	freopen("input.txt", "r", stdin);
//	int T;
//	cin >> T;
//
//	for (int test_case = 1; test_case <= T; test_case++) {
//		cin >> N;
//		people.clear();
//		stair.clear();
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> board[i][j];
//				if (board[i][j] == 1) people.push_back({ i,j });
//				else if (board[i][j] > 1) stair.push_back({ i,j });
//			}
//		}
//		siz = people.size();
//		ans = 2e9;
//		dfs(0);
//		cout << "#" << test_case << ' ' << ans << '\n';
//
//	}
//	return 0;//��������
//}