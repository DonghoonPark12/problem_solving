#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool match(const string& w, string& s);

int main() {
	//freopen("input.txt", "r", stdin);
	//int T;
	//string W;
	//int n; //파일명 갯수
	//for (int t = 0; t < T; t++) {
	//	cin >> W;
	//	cin >> n;
	//	string files[50];//파일 명은 최대 50개
	//	for (int i = 0; i < n; i++) {
	//		string tmp;
	//		cin >> tmp;
	//		files[i] = tmp;
	//	}
	//	//파일 입력 끝.
	//	int len = sizeof(W);
	//	vector<int> w(len,0);
	//	for (int i = 0; i < len; i++) {
	//		if (W[i] == '?') w[i] = 1;
	//		else if (W[i] == '*') w[i] = 2;
	//		else w[i] = 0;
	//	}

	//	int flag = 0;//파일명이 와일드 카드 패턴과 대응되지 않음을 알리는 flag
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
		pos는 s와 w의 크기보다 작아야 하며.
		w[pos]가 ? 로 don't care가 아닌데도, w[pos]와 s[pos]가 대응 되지 않으면 일단 중지
		*/
		pos++;
	}
	if (pos == w.size()) //1) w는 문자열 끝에 도달했고, s가 더 긴 경우 종료.  ex) aaa*b, aaaba
		return pos == s.size(); //2) "" 와 ""를 비교 하여 true 반환.

	if (w[pos] == '*') {//'*'를 만나서 끊긴 경우.
		for (int skip = 0; pos + skip <= s.size(); skip++) {//s.substr이 "" 일때 까지 조사 하기 위해서 '<='가 필요하다.
			cout << w.substr(pos + 1) << endl;;
			cout << s.substr(pos + skip)<<endl;
			cout << '\n';
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
		}
	}
	return false;//1) '*' 이후 재귀를 종료시키는 역할 2)다른 문자를 만났을 때 함수를 종료 시키는 역할 
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

///* 이항계수 */
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
///* 외발 뛰기 */
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
///* 외발 뛰기2 */
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