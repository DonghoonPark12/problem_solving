#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <queue>
using namespace std;
//bool visited[50];
//int _move = 0; //�̵��Ÿ��� ī��Ʈ �ϴ� ����
//int _min = 0; //�̵��Ÿ��� �����ϸ�, �ּҰ� �� �� �����Ѵ�.
//
//int is_different(string a, string b) {
//	int cnt = 0;
//	for (int i = 0; i<a.size(); i++) {
//		if (a[i] != b[i])
//			cnt++;
//	}
//	if (cnt == 1)
//		return 1;
//	else
//		return 0;
//}
//bool once = true;
//void dfs(int i, string target, vector<string> words) {
//	visited[i] = true;
//	_move += 1;
//	if (words[i] == target) {
//		if (once) {
//			_min = _move;
//			_move -= 1;
//			visited[i] = false;
//			once = false;
//			return;
//		}
//		else if (_move<_min) {
//			_min = _move;
//			_move -= 1;
//			visited[i] = false;
//			return;
//		}
//	}
//	int j;
//	for (j = 0; j<words.size(); j++) {
//		if (visited[j] != true && is_different(words[i], words[j])) //�湮���� �ʾҰ�, �ܾ����̰� �ϳ����
//			dfs(j, target, words);
//	}
//	visited[i] = false;
//	_move -= 1;
//	return;
//}
//
//int solution(string begin, string target, vector<string> words) {
//	for (int i = 0; i<words.size(); i++) {
//		if (is_different(begin, words[i]))
//			dfs(i, target, words);
//	}
//	return _min;
//}

bool check_words(string a, string b) {
	int sz = a.length();
	int cnt = 0;
	for (int i = 0; i<sz; i++) {
		if (a[i] == b[i]) cnt++;
	}
	if (cnt == sz - 1) return true;
	else return false;
};

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int n = words.size();
	queue<pair<int, int>>q; // index of word, level 
	bool visited[51];
	for (int i = 0; i<51; i++) visited[i] = false;
	//1. check if the word is contained in words
	bool hastarget = false;
	for (int i = 0; i<n; i++) {
		if (words[i] == target) hastarget = true;
	}
	if (hastarget == false) return 0;

	int idx = 0;
	int level = 1;
	while (1) {
		for (int i = 0; i<n; i++) {
			if (check_words(begin, words[i]) == true && visited[i] == false) {
				if (words[i] == target) return level;
				q.push(make_pair(i, level)); //words�� �ε����� Level ����. 
				visited[i] = true;
			}
		}
		answer = level;
		begin = words[q.front().first]; //�ε����� ���� words�� begin�̸�(hot)
		level = q.front().second;  //level�� 1 �����ش�(?)
		level++;
		q.pop();
	}

	return answer;
}


int main(void)
{
	int N;
	int Answer = 0;
	//freopen("input.txt", "r", stdin);
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	Answer = solution(begin, target, words);
	cout << Answer << endl;

	return 0;

}