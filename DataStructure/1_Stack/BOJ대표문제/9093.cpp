#include <iostream>
#include <stack>
#include <string>
using namespace std;
/* 단어 뒤집기 */
int main() {
	int t;
	cin >> t; //2를 입력 받고
	cin.ignore(); //개행 문자를 입력 받는다.
	while (t--) {
		string str;
		getline(cin, str); //getline은 개행문자 전까지 입력 받는다.
		str += '\n';
		stack<char> s;
		for (char ch : str) {
			if (ch == ' ' || ch == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ch;
			}
			else {
				s.push(ch);
			}
		}
	}

	return 0;
}