#include <iostream>
#include <stack>
#include <string>
using namespace std;
/* 단어 뒤집기 2*/
int main() {
		string str;
		getline(cin, str); //getline은 개행문자 전까지 입력 받는다.
		str += '\n';
		stack<char> s;
		bool flag = false;
		for (char ch : str) {
			if (ch == '<') {
				flag = true;
				if (!s.empty()) {
					while (!s.empty()) { cout << s.top(); s.pop(); }
				}
			}

			/* ------------------------------------------------------------------ */
			if (!flag) { //flag false 일때만
				if (ch == ' ' || ch == '\n' ){ // || (ch == '<' && !s.empty())) {
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
			/* ------------------------------------------------------------------ */

			else if (ch == '>') {
				flag = false; cout << '>';
			}


			if (flag)
				cout << ch;
		}

	return 0;
}