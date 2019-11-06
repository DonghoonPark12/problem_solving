#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool match(const string& w, string& s);

int main() {
	//freopen("input.txt", "r", stdin);
	//int T;
	//string W;
	//int n; //���ϸ� ����
	//for (int t = 0; t < T; t++) {
	//	cin >> W;
	//	cin >> n;
	//	string files[50];//���� ���� �ִ� 50��
	//	for (int i = 0; i < n; i++) {
	//		string tmp;
	//		cin >> tmp;
	//		files[i] = tmp;
	//	}
	//	//���� �Է� ��.
	//	int len = sizeof(W);
	//	vector<int> w(len,0);
	//	for (int i = 0; i < len; i++) {
	//		if (W[i] == '?') w[i] = 1;
	//		else if (W[i] == '*') w[i] = 2;
	//		else w[i] = 0;
	//	}

	//	int flag = 0;//���ϸ��� ���ϵ� ī�� ���ϰ� �������� ������ �˸��� flag
	//	for (int i = 0; i < n; i++) { 
	//		for (int j = 0; j < sizeof(files[i]); j++) { //len -> sizeof(files[i])
	//			if (w[i] == 0 && W[j] != files[i][j])
	//				flag = 1;
	//		}
	//		if (!flag)
	//			cout << files[i];
	//	}
	//}
	string w,s;
	//string getstring(w, '*p*');
	//string getstring(s, 'aapa');
	w = "**a"; 
	s = "aaaab";
	cout << match(w, s);

	return 0;
}

bool match(const string& w, string& s) {
	int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos])) {
		/*
		pos�� s�� w�� ũ�⺸�� �۾ƾ� �ϸ�.
		w[pos]�� ? �� don't care�� �ƴѵ���, w[pos]�� s[pos]�� ���� ���� ������ �ϴ� ����
		*/
		pos++;
	}
	if (pos == w.size()) //1) w�� ���ڿ� ���� �����߰�, s�� �� �� ��� ����.  ex) aaa*b, aaaba
		return pos == s.size(); //2) "" �� ""�� �� �Ͽ� true ��ȯ.

	if (w[pos] == '*') {//'*'�� ������ ���� ���.
		for (int skip = 0; pos + skip <= s.size(); skip++) {//s.substr�� "" �϶� ���� ���� �ϱ� ���ؼ� '<='�� �ʿ��ϴ�.
			cout << w.substr(pos + 1) << endl;;
			cout << s.substr(pos + skip)<<endl;
			cout << '\n';
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}
	return false;//1) '*' ���� ��͸� �����Ű�� ���� 2)�ٸ� ���ڸ� ������ �� �Լ��� ���� ��Ű�� ���� 
}                // ex) aaab*, aaabaaa                   ex) aaab, aaaa

int cache[101][101];
string W, S;
bool memMatch(int w, int s) {
	int &ret = cache[w][s];
	if (ret != -1) return ret;
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
		++w; ++s;
	}
	if (w == W.size())
		return ret = (s == S.size());
	if(W[w] == '*')
		for (int skip = 0; skip + s < S.size(); ++skip) {
			if (memMatch(w + 1, s + skip))
				return ret = 1;
		}
	return ret = 0;
}

///* ���װ�� */
//int cache[30][30];
//int bino2(int n, int r) {
//	//basis
//	if (r == 0 || n == r) return 1;
//
//	if (cache[n][r] != -1)
//		return cache[n][r];
//	return cache[n][r] = bino2(n - 1, r - 1) + bino2(n - 1, r);
//
//}
//
///* �ܹ� �ٱ� */
//int n, board[100][100];
//bool jump(int y, int x) {
//	//basis
//	if (y >= n || x >= n) return false;
//	//basis2
//	if (y == n - 1 && x == n - 1) return true;
//	int jumpSize = board[y][x];
//	return jump(y + jumpSize, x) || jump(y, x + jumpSize);
//
//}
//
///* �ܹ� �ٱ�2 */
//int n, board[100][100];
//int cache[100][100];
//int jump2(int y, int x) {
//	//basis
//	if (y >= n || x >= n) return 0;
//	if (y == n - 1 && x == n - 1) return 1;
//
//	int &ret = cache[y][x];
//	if (ret != -1) return ret;
//	int jumpSize = board[y][x];
//	return ret = ( jump2(y + jumpSize, x) || jump2(y, x + jumpSize) );
//}