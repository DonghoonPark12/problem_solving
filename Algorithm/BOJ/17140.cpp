#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
	<이차원 배열과 연산>
	각각의 수가 몇번 나왔는지 알아야 한다. 
	수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면
	수가 커지는 순으로 정렬.

	배열 A에 정렬된 결과를 다시 넣어야 한다. (수, 등장횟수).

	R연산이 적용된 경우에는 행의 크기가 가장큰 행을 기준으로 모든 행의 크기가 커지고,

	수를 정렬할 때 0은 무시한다. 

	map : 삽입, 조회, 수정 모두 O(logN) 만큼 걸린다.

*/
// if(t>100) ans = -1;
// if(num[r-1][c-1] == k)

int r, c, k;
int num[100][100];
int num2[100][100];
//info bin[100]; // 1 ~ 99 수의 빈도수 표현

struct info {
	int n, freq;

	//bool operator<(const info &t) {
	//	if (this->freq < t.freq)
	//		return true;
	//	else if (t.freq == this->freq)
	//		return t.n > this->n;
	//	else return false;
	//}
};

bool operator<(const info &u, const info &t) {
	if (t.freq > u.freq)
		return true;
	else if (t.freq == u.freq) {
		return t.n > u.n;
	}
	else return false;
}

int solve() {
	int t = 0, h = 3, w = 3; //처음은 3 x 3
	while (num[r-1][c-1] != k) {
		if (++t > 100) return -1;
		memset(num2, 0, sizeof(num2));//num2 ? 
		int ph = h, pw = w;
		/* -------------------------------------------------------- */
		if (ph >= pw) {//R 연산
			int max_w = 0;
			for (int i = 0; i < ph; i++) {
				map<int, int> fq; //수와 빈도수를 담는 자료 구조.
				vector<info> v;
				for (int j = 0; j < pw; j++) { if (num[i][j] != 0) fq[num[i][j]]++; } //그 '숫자'와 빈도수를 높여준다. 
				for (auto &it : fq) v.push_back({ it.first, it.second });
				sort(v.begin(), v.end());
				int k = 0;
				for (auto &e : v) {
					if (k + 2 < 100) {
						num2[i][k++] = e.n;    //Good Idea
						num2[i][k++] = e.freq; //배열의 크기는 100을 넘지 않게 한다. 
					}
				}
				//while (k > 0 && num2[i][k-1] == 0) k--;
				max_w = max(max_w, k);//가장 큰 행을 기준으로
			}
			w = max_w;
		}
		/* -------------------------------------------------------- */
		else {
			int max_h = h;
			for (int i = 0; i < pw; i++) {
				map<int, int> fq;
				vector<info> v;
				for (int j = 0; j < ph; j++) if (num[j][i] != 0) fq[num[j][i]]++;
				for (auto & it : fq) v.push_back({ it.first, it.second });
				sort(v.begin(), v.end());
				int k = 0;
				for (auto &x : v) {
					if (k + 2 < 100) {
						num2[k++][i] = x.n;
						num2[k++][i] = x.freq;
					}
				}
				//while(k > 0 && num2[k-1][i] == 0) k--;
				max_h = max(max_h, k);
			}
			h = max_h;
		}
		memcpy(num, num2, sizeof(num2));
		/* -------------------------------------------------------- */
	}
	return t;
}
int main() {
	cin >> r >> c >> k;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) { //?
			cin >> num[i][j];
		}
	}
	cout<< solve();
	return 0;
}