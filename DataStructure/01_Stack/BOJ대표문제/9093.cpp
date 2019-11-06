#include <iostream>
#include <stack>
#include <string>
using namespace std;
/* �ܾ� ������ */
int main() {
	int t;
	cin >> t; //2�� �Է� �ް�
	cin.ignore(); //���� ���ڸ� �Է� �޴´�.
	while (t--) {
		string str;
		getline(cin, str); //getline�� ���๮�� ������ �Է� �޴´�.
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