#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	string str;
	int num;

	int s=0;
	while (n--) {
		cin >> str;
		if (str == "add") { 
			cin >> num;
			s |= 1 << (num - 1);
		}
		else if (str == "check") {
			cin >> num;
			printf("%d\n", s & (1 << (num - 1)) ? 1 : 0 );
		}
		else if (str == "remove") {
			cin >> num;
			s &= ~(1 << (num - 1));
		}
		else if (str == "toggle") {
			cin >> num;
			s ^= 1 << (num - 1);
		}
		else if (str == "all") {
			s = (1 << 20) - 1;
		}
		else if (str == "empty") {
			s &= 0;
		}
	}
	return 0;
}


#include <iostream>
#include <cstring>
#include <set>
using namespace std;
/*
	set의 경우 내부에 원소를 추가할 때 BST 구조를 유지한다.
	set의 insert: O(logN)
	set의 find: O(logN)
*/
int main() {
	set<int> s;
	set<int> s2;
	for (int i = 1; i <= 20; i++) { s2.insert(i); }

	int n; cin >> n;
	string str;
	int num;

	int s = 0;
	while (n--) {
		cin >> str;
		if (str == "add") { //or if(s.compare("add) == 0)
			cin >> num;
			s.insert(num);
		}
		else if (str == "check") {
			cin >> num;
			if(s.find(num) != s.end())  //s의 iterator를 반환
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (str == "remove") {
			cin >> num;
			s.erase(num);
		}
		else if (str == "toggle") {
			cin >> num;
			if (s.find(num) == s.end())
				s.insert(num);
			else
				s.erase(num);
		}
		else if (str == "all") {
			s.swap(s2);
		}
		else if (str == "empty") {
			s.clear();
		}
	}
	return 0;
}