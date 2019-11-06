/*
	�̸�Ƽ�� ����.
	3���� ������ �����ϸ�, �ѹ��� ���ۿ� 1�ʰ� �ɸ���, ����(��)�� �����ϱ� ���� �ּ� �ð��� ���ϴ� �����̴�.

	2178.�̷�Ž��-->1679.���ٲ���-->14226.�̸�Ƽ��-->13549.���ٲ���3
	-->1261.�˰���--> 13460. ����Ż��2 �� ���̵��� �������� Ǯ �� �ִ�. 

	: �ܼ� 2���� �迭���� 4���� �̵� ������ bfs + dist[ny][nx]
	: 3���� �̵� ����� bfs + dist[MAX]�� �ð� ����.
	: 3���� �̵� ����� bfs + dist[][]�� ���¿� ���� �ð� ����.
    : ����ġ�� 0�� ������ �����Ҷ� bfs + dist[c]

	: �ܼ� 2���� �迭���� 4���� �̵� ����. ������ ���� �μ��� ���� ����ġ(1), ���� �̵��� ����ġ(0) : �̷�Ž�� + ���ٲ���3 ����.
	: 4���� �̵� ����� bfs + dist[][][][][]�� ���¿� ���� �ð� ����.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int dist[2*MAX][2*MAX];//������� �̸�Ƽ�� ��, Ŭ�������� �̸�Ƽ�� ��
int depth;
int s;
//void bfs() {
//	queue<pair<int, int>> q;
//	q.push({ 1,0 });
//	dist[1][0] = 1;
//	while (!q.empty()) {
//		
//		int size = q.size();
//		for (int i = 0; i < size; i++) {
//			int cm = q.front().first;
//			int cc = q.front().second;
//			q.pop();
//
//			if (cm == s) {
//				cout << depth;
//				return;
//			}
//			if (dist[cm][cm] != 1) {
//				q.push({ cm, cm });
//				dist[cm][cm] = 1;
//			}
//			if (cc != 0 && cm + cc <= s && dist[cm + cc][cc] != 1) { //����Ϳ� �ٿ��ֱ� �Ҷ�, s ���� Ŀ�� ������ ����. 1000���� �ص��ȴ�.
//				q.push({ cm + cc, cc });                             //2*s �ϴ� ��캸�� ����ð� ���� �Ƴ� �� �ִ�. 
//				dist[cm + cc][cc] = 1;
//			}
//			if (cm-1>=1 && dist[cm - 1][cc] != 1) { //s���� �۾����� �� ������ ����(x) --> >=s�� �ϸ� Ʋ������ �߸� >=1�� �ؾ� �������� ���.
//				q.push({ cm - 1, cc });
//				dist[cm - 1][cc] = 1;
//			}
//		}
//		depth++;
//	}
//
//}

void bfs2() {
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	int cm, cc;
	while (!q.empty()) {
		cm = q.front().first;
		cc = q.front().second;
		q.pop();
		if (cm == s) {
			cout << dist[cm][cc];
			return;
		}
		// --------------------------------------------- //
		//int nm[] = { cm, cm + cc, cm - 1 };
		//int nc[] = { cm,      cc,     cc };
		//for (int i = 0; i < 3; i++) {
		//	if (nm[i] < 0 || nm[i] > s) continue;
		//	if (dist[nm[i]][nc[i]]) continue;

		//	q.push({ nm[i], nc[i] });
		//	dist[nm[i]][nc[i]] = dist[cm][cc] + 1;
		//}
		// ����� ��ų
		// --------------------------------------------- //

		if (!dist[cm][cm]) {
			q.push({ cm, cm });
			dist[cm][cm] = dist[cm][cc] + 1;
		}

		if (cm + cc <= s && !dist[cm+cc][cc]) {
			q.push({ cm + cc, cc });
			dist[cm + cc][cc] = dist[cm][cc] + 1;
		}
		
		if (cm - 1 >= 0 && !dist[cm-1][cc]) {
			q.push({ cm - 1, cc });
			dist[cm - 1][cc] = dist[cm][cc] + 1;
		}
	}
}
int main() {
	cin >> s;
	bfs2();
	//cout<<bfs2();

	return 0;
}

/* ------------------------------------------------------------------------------------------------------------ */

//int _min = 0x7fffffff;

// �´� Ǯ�� ������, �ð��ʰ�
//bool operator==(vector<int> l, vector<int> r) {
//	if (l.size() == r.size()) {
//		for (int i = 0; i < l.size(); i++) {
//			if (l[i] != r[i])
//				return false;
//		}
//		return true;
//	}
//	return false;
//}
//
//void sit(vector<int> m, vector<int> c, int t) {
//	if (t > _min) return;
//	if (m.size() > n) return;
//	if (m.size() == n) {
//		_min = min(_min, t); return;
//	}
//	vector<int> tmp;
//
//	if (m != c) { //������ ����� �� ������ ����.
//		tmp = c; //copies all the elements from 'c' into the left.
//		sit(m, m, t + 1);//����Ϳ� �ִ� �̸�Ƽ���� Ŭ�����忡 �����
//		c = tmp;
//	}
//
//	if (!c.empty()) { //Ŭ�����尡 ��� ���� ���� ��쿡�� �ٿ��ֱ�
//		tmp = m;
//		m.insert(m.end(), c.begin(), c.end());//(https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector)
//		sit(m, c, t + 1);
//		m = tmp;
//	}
//
//	if (!m.empty()) {
//		int tm = m.back();
//		m.pop_back();
//		sit(m, c, t + 1);
//		m.push_back(tm);
//	}
//}
//int main() {
//	cin >> n;
//	vector<int> v;
//	vector<int> c;
//	v.push_back(1);
//	sit(v, c, 0);
//	cout << _min;
//	return 0;
//}
