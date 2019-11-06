#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; 
int adjm[21][21];

int _min = 0x7fffffff;

//vector<int> num;
//vector<int> pick1;
//vector<int> pick2;
//
//vector<int> pick3;
//vector<int> pick;
//int sum1, sum2;

int team1[10], team2[10];
int pick[20];

//void dfs2(int pos, vector<int> &v, int &sum) {
//	if (pick3.size() == 2) {
//		sum += adjm[pick3[0]][pick3[1]];
//		sum += adjm[pick3[1]][pick3[0]];
//		return;
//	}
//	for (int i = pos; i < v.size(); i++) {
//		pick3.push_back(v[i]);
//		dfs2(i, v, sum);
//		pick3.pop_back();
//	}
//}

//void dfs(int pos) {
//	if (pick1.size() == (N / 2)) {
//		sum1 = 0;
//		sum2 = 0;
//
//		dfs2(0, pick1, sum1);
//			
//		pick2.clear();
//		for (int i = 1; i <= N; i++) {
//			bool flag = false;
//			for(int j=0;j<pick1.size();j++){
//				if (i == pick1[j])
//					flag = true;
//			}
//			if (!flag)
//				pick2.push_back(i);
//		}
//
//		dfs2(0, pick2, sum2);
//
//		_min = min(_min, abs(sum1 - sum2));
//		return;
//	}
//
//	for (int i = pos; i < num.size(); i++) {
//		pick1.push_back(num[i]);
//		dfs(i+1);
//		pick1.pop_back();
//	}
//}

void update() {
	int team1_size = 0, team2_size = 0;
	for (int i = 0; i < N; i++) {
		if (pick[i] == 1)
			team1[team1_size++] = i+1;//최대 N/2까지만 채워니지 덮어진다. (1,3,5)
		else
			team2[team2_size++] = i+1;//(2,4,6)
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {//조합
			sum1 += (adjm[team1[i]][team1[j]] + adjm[team1[j]][team1[i]]);
			sum2 += (adjm[team2[i]][team2[j]] + adjm[team2[j]][team2[i]]);
		}
	}
	_min = min(_min, abs(sum1 - sum2));
	 
}

void dfs(int cur, int count) {
	if (count == (N / 2)) {
		update();
		return;
	}
	for (int i = cur; i < N; ++i) {
		pick[i] = 1;
		dfs(i + 1, count + 1);
		pick[i] = 0;
	}
}
 
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> adjm[i][j];
		}
	}

	//for (int i = 1; i <= N; i++)
	//	num.push_back(i);

	//dfs(0);
	//cout << _min;

	dfs(0, 0);
	cout << _min;
	return 0;

}