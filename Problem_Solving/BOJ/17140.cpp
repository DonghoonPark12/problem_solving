#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
	<������ �迭�� ����>
	������ ���� ��� ���Դ��� �˾ƾ� �Ѵ�. 
	���� ���� Ƚ���� Ŀ���� ������, �׷��� ���� ����������
	���� Ŀ���� ������ ����.

	�迭 A�� ���ĵ� ����� �ٽ� �־�� �Ѵ�. (��, ����Ƚ��).

	R������ ����� ��쿡�� ���� ũ�Ⱑ ����ū ���� �������� ��� ���� ũ�Ⱑ Ŀ����,

	���� ������ �� 0�� �����Ѵ�. 

	map : ����, ��ȸ, ���� ��� O(logN) ��ŭ �ɸ���.

*/
// if(t>100) ans = -1;
// if(num[r-1][c-1] == k)

int r, c, k;
int num[100][100];
int num2[100][100];
//info bin[100]; // 1 ~ 99 ���� �󵵼� ǥ��

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
	int t = 0, h = 3, w = 3; //ó���� 3 x 3
	while (num[r-1][c-1] != k) {
		if (++t > 100) return -1;
		memset(num2, 0, sizeof(num2));//num2 ? 
		int ph = h, pw = w;
		/* -------------------------------------------------------- */
		if (ph >= pw) {//R ����
			int max_w = 0;
			for (int i = 0; i < ph; i++) {
				map<int, int> fq; //���� �󵵼��� ��� �ڷ� ����.
				vector<info> v;
				for (int j = 0; j < pw; j++) { if (num[i][j] != 0) fq[num[i][j]]++; } //�� '����'�� �󵵼��� �����ش�. 
				for (auto &it : fq) v.push_back({ it.first, it.second });
				sort(v.begin(), v.end());
				int k = 0;
				for (auto &e : v) {
					if (k + 2 < 100) {
						num2[i][k++] = e.n;    //Good Idea
						num2[i][k++] = e.freq; //�迭�� ũ��� 100�� ���� �ʰ� �Ѵ�. 
					}
				}
				//while (k > 0 && num2[i][k-1] == 0) k--;
				max_w = max(max_w, k);//���� ū ���� ��������
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