#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int board[50][50];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int _max = 0;
void check() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) { //행으로 최대 갯수 검색
		for (int j = 0; j < N - 1; j++) {
			if (board[i][j] == board[i][j + 1]) {
				cnt++;
				_max = max(cnt, _max);
			}
			else {
				cnt = 0;
			}
		}
		cnt = 0;
	}

	for (int i = 0; i < N; ++i) { //열로 최대 갯수 검색
		for (int j = 0; j < N - 1; j++) {
			if (board[j][i] == board[j + 1][i]) {
				cnt++;
				_max = max(cnt, _max);
			}
			else {
				cnt = 0;
			}
		}
		cnt = 0;
	}

	//return _max + 1;
}

int main() {
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp; int len = tmp.length();
		for (int j = 0; j < len; ++j)
			board[i][j] = tmp[j];
	}


	for (int i = 0; i < N; ++i) { //행으로 최대 갯수 검색
		for (int j = 0; j < N - 1; j++) {
			swap(board[i][j], board[i][j + 1]);
			check();
			swap(board[i][j + 1], board[i][j]);
		}
	}

	for (int i = 0; i < N; ++i) { //행으로 최대 갯수 검색
		for (int j = 0; j < N - 1; j++) {
			swap(board[j][i], board[j + 1][i]);
			check();
			swap(board[j + 1][i], board[j][i]);
		}
	}

	cout << _max+1;
	return 0;
}