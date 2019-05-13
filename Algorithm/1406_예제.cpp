#include <iostream>
#include <list>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;

	list<char> editor(s.begin(), s.end());
	auto cursor = editor.end();

	int n;
	cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (cursor != editor.begin()) {
				--cursor;
			}
		}
		else if (cmd == 'D') {
			if (cursor != editor.end()) {
				++cursor;
			}
		}
		else if (cmd == 'B') {
			if (cursor != editor.begin()) {
				auto temp = cursor;
				--cursor;
				editor.erase(cursor);
				cursor = temp;
			}
		}
		else if (cmd == 'P') {
			char c;
			cin >> c;
			editor.insert(cursor, c);
		}
	}

	for (char c : editor) {
		cout << c;
	}
	cout << '\n';

	return 0;
}