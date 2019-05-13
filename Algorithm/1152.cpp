#include <iostream>
#include <string>

using namespace std;

int main() {

	int cnt = 0;

	string s;

	while (cin >> s) { //문장에서 단어의 갯수 판별. 띄어쓰기는 구분된다. 

		cnt += 1;

	}
	cout << cnt << '\n';
	return 0;

}

//문자열 문제: 1152, 10820, 10821, 2743, 10822, 10823, 10824