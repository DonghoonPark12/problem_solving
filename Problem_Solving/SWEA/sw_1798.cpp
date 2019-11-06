#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m
//void get_input() {
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1+i; j <= n; j++) {
//			if (i != j) {
//				int tmp; cin >> tmp;
//				time[i][j] = tmp;
//				time[j][i] = tmp;
//			}
//		}
//	}
//	char loc;
//	for (int i = 1; i <= n; i++) {
//		cin >> loc;
//		if (loc == 'P') {
//			place[i][0] = loc;
//			cin >> place[i][1] >> place[i][2];
//		}
//		else{
//			place[i][0] = loc;
//		}
//	}
//}
/*int t*/;
//void dfs(int st) {
//	if (t >= 9 && des != 'H') {
//		return;
//	}
//
//}
//for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
//	sum_of_elems += *it;
//for (auto& n : vector)
//	sum_of_elems += n;

int p;//�������� ����
vector<vector<int>> time((n + 1), vector<int>(n + 1));
vector<vector<int>> place(n + 1, vector<int>(4));
vector<int> impossible(35,0);
int bfs(int st, int t_time, int satis) {


	/*------------�̵� ������ P�� �ִ��� �ð� üũ ---------------*/
	for (int i = 1; i <= n; i++) {
		if (place[i][0] == 'P' && (t_time + place[i][1] + time[st][i]) > 540)//��� P���� �̵� �� ���� �ð� ������ 9�ð��� �Ѵ´�.
			impossible[i] = 1;
	}
	int sum_of_ele = 0;
	for (auto it = impossible.begin(); it != impossible.end(); ++it)
		sum_of_ele += *it;
	/*------------------------------------------------------------*/

	if (sum_of_ele == p) {//ȣ�ڷ� ���ư��� �ȴ�.
		int can_go_h = 0;
		for (int i = 1; i <= n; i++) {
			if (place[i][0] == 'H' && (t_time + time[st][i]) <= 540) {
				can_go_h = 1;
				bfs(i, t_time, satis);
			}
		}
		if (!can_go_h) //P���� ���� ���ϰ�, ȣ�ڷ� ���ư����� ���ϴ� ��Ȳ�̸� ����
			return 0; 
	}
	else{ //ȣ�ڷ� ���ư��� �ʰ� �� ��Ƶ� �ȴ�. 
		for (int i = 1; i <= n; i++) {
			if (place[i][0] == 'P' && (t_time + place[i][1] + time[st][i]) < 540)
				bfs(i, t_time + place[i][1], satis + place[i][2]);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int tc;
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1 + i; j <= n; j++) {
				if (i != j) {
					int tmp; cin >> tmp;
					time[i][j] = time[j][i] = tmp;
				}
			}
		}
		char loc;
		for (int i = 1; i <= n; i++) {
			cin >> loc;
			if (loc == 'P') {
				place[i][0] = loc;
				cin >> place[i][1] >> place[i][2];
				p++;
			}
			else {
				place[i][0] = loc;
			}
		};
		bfs(1, 0, 0);



	}

	return 0;
}


//#include<stdio.h>
//int N, M, x, y, m, _max;
//int map[40][40], visit[40], st[40], top = -1, ans[40], at;
//struct aa {
//	char q[5];
//	int b;
//	int c;
//}po[40];
//
//void dfs(int now, int d, int s) {
//	int i, j, k = 0;
//
//	for (i = 2; i <= x + 1; i++) {
//		if (visit[i] == 0 && map[now][i] + d + po[i].b <= 540) {
//			visit[i] = 1;
//			k = 1;
//			st[++top] = i;
//			dfs(i, d + map[now][i] + po[i].b, s + po[i].c);
//			visit[i] = 0;
//			--top;
//		}
//	}
//	if (m == M) {
//		if (map[now][1] + d <= 540) {
//			if (_max < s) {
//				_max = s;
//				for (i = 0; i <= top; i++) ans[i] = st[i];
//				at = top;
//			}
//		}
//		else return;
//	}
//	else if (!k) {
//		for (i = x + 2; i <= N; i++) {
//			if (map[now][i] + d <= 540) {
//				m++;
//				st[++top] = i;
//				dfs(i, 0, s);
//				m--;
//				--top;
//			}
//		}
//	}
//}
//int main()
//{
//	int T, i, j, k, a;
//	char w[10];
//	//freopen("input.txt", "r", stdin);
//	scanf("%d", &T);
//	for (i = 1; i <= T; i++) {
//		scanf("%d %d", &N, &M);
//		for (j = 1; j < N; j++) {
//			for (k = j + 1; k <= N; k++) {
//				scanf("%d", &a);
//				map[j][k] = a;
//				map[k][j] = a;
//			}
//		}
//
//		x = 0;
//		for (j = 1; j <= N; j++) {
//			scanf("%s", &po[j].q);
//			if (po[j].q[0] == 'P') {
//				scanf("%d %d", &po[j].b, &po[j].c);
//				x++;
//			}
//		}
//		_max = 0;
//		m = 1;
//		dfs(1, 0, 0);
//		printf("#%d %d ", i, _max);
//		if (_max != 0) {
//			for (j = 0; j <= at; j++) printf("%d ", ans[j]);
//			printf("1");
//		}
//		printf("\n");
//	}
//	return 0;
//}


#include <iostream>
#include <string>
#include <time.h>
using namespace std;
#define size 36

struct Data {
	char name;
	int score, time;
	Data() {
		name = ' ';
		score = 0;
		time = 0;
	}
};


int check[size];
int path[size];
int ans_path[size];
int map[size][size];
Data node[size];
int ans = 0;
int N, M;


void dfs(int date, int cur, int score, int time, int count, int path[]) {
	if (date > M || time > 540) return;
	for (int i = 0; i < N; i++)
	{
		if (i == cur || date > M) continue; //���� ������ �ڱ� �ڽŰ� ���ų� �ް����� �����ų� üũ�Ǿ������� ����
		switch (node[i].name) { //���� ������
		case 'P': //�������� ���
			if (check[i]) continue; //�湮������ ����
			if (map[cur][i] + node[i].time + time > 540) continue; //����ð��� ���� �ð� ��� �ð��� ���ļ� 9�ð��� ������ ����
			check[i] = 1; //�湮
			path[count + 1] = i + 1; //��� �߰�
			dfs(date, i, score + node[i].score, map[cur][i] + node[i].time + time, count + 1, path); //�������� �ð��� ������
			check[i] = 0; //�湮����
			path[count + 1] = 0; //��� ����
			break;
		case 'A': //������ ���
			if (date != M || map[cur][i] + time > 540) continue; //���������� �ƴϰų� 9�ð��� ������ ����
			if (ans < score) { //�ִ븸�����̸�
				ans = score; path[count + 1] = i + 1; //�������� ��� ����
				for (int j = 1; j < size; j++) //���� ��θ� ����
					ans_path[j] = path[j];
			}
			break;
		case 'H': //ȣ���� ���
			if (map[cur][i] + time > 540) continue; //9�ð��� ������ ����
			path[count + 1] = i + 1; //��� �߰�
			dfs(date + 1, i, score, 0, count + 1, path); //��¥ + 1
			path[count + 1] = 0; //��� ����
			break;
		}
	}
}

int main()
{
	clock_t b, e;
	b = clock();
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		ans = 0;
		int airport;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < N - 1; i++)
			for (int j = i + 1; j < N; j++) {
				scanf("%d", &map[i][j]);
				map[j][i] = map[i][j];
			}

		for (int i = 0; i < N; i++)
		{
			Data d;
			scanf(" %c", &d.name);
			if (d.name == 'P') {
				scanf("%d %d", &d.time, &d.score);
			}
			if (d.name == 'A') airport = i;
			node[i] = d;
		}
		dfs(1, airport, 0, 0, 0, path); //date, cur, score, time, path

		if (!ans) printf("#%d 0\n", t);
		else {
			printf("#%d %d", t, ans);
			for (int i = 0; i < size; i++)
				if (ans_path[i]) printf(" %d", ans_path[i]);
			printf("\n");
		}
	}
	e = clock();
	cout << e - b << "\n";

	return 0;
}