#include <iostream>
#include <stack>
#include <string>
using namespace std;
/* �ܾ� ������ 2*/
int main() {
		string str;
		getline(cin, str); //getline�� ���๮�� ������ �Է� �޴´�.
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
			if (!flag) { //flag false �϶���
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