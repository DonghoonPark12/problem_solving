#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
/*
	O(N + M) : 처음 문자열 길이 + 명령어로 추가한 문자열 길이
*/

int main() {
	string s;
	cin >> s;
	
	stack<char> l;
	stack<char> r;

	int len = s.length();
	for (int i = 0; i < len; i++) l.push(s[i]);

	int n, tmp;
	char ch;
	cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (!l.empty()) {
				tmp = l.top(); l.pop();
				r.push(tmp);
			}
		}
		else if (cmd == 'D') {
			if (!r.empty()) {
				tmp = r.top(); r.pop();
				l.push(tmp);
			}
		}
		else if (cmd == 'B') { 
			if (!l.empty()) {
				l.pop();
			}
		}
		else if (cmd == 'P') { 
			cin >> ch;
			l.push(ch);
		}
	}

	int size = l.size();
	for (int i = 0; i < size; i++) {
		tmp = l.top(); l.pop();
		r.push(tmp);
	}
	size = r.size();
	for (int i = 0; i < size; i++) {
		cout << r.top(); r.pop();
	}

	return 0;
}
