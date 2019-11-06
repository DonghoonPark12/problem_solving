#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int l, c; 
int mo;
vector<int> arr;
vector<int> pick;

void dfs(int cnt) {
	if (pick.size() == l) {
		int mo=0, za = 0;
		for (int i = 0; i < pick.size(); i++) {
			if(pick[i] == 'a' || pick[i] == 'e' || pick[i] == 'i' || pick[i] == 'o' || pick[i] == 'u') mo++;
			else za++;
		}
		if (mo >= 1 && za >= 2) {
			for (int i = 0; i < pick.size(); i++) {
				printf("%c", pick[i]);
			}
			cout << '\n';
		}
		return;
	}
	for (int i = cnt; i < c; i++) {
		pick.push_back(arr[i]);
		dfs(i + 1);
		pick.pop_back();
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >>l>>c;
	char t;
	for (int i = 0; i < c; i++) {
		cin >> t; 
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());
	dfs(0);
	return 0;
}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int L, C;
//char a[15];
//
//bool possible(string passwd) {
//	int vowel = 0, consonant = 0;
//	for (char c : passwd) {
//		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vowel++;
//		else consonant++;
//		if (vowel >= 1 && consonant >= 2) return true;
//	}
//	return false;
//}
//
//void solve(int index, string passwd) {
//	if ((int)passwd.length() == L) {
//		if (possible(passwd)) cout << passwd << '\n';
//		return;
//	}
//	if (index >= C) return;
//	solve(index + 1, passwd + a[index]);
//	solve(index + 1, passwd);
//}
//
//int main() {
//	cin >> L >> C;
//	for (int i = 0; i<C; i++) cin >> a[i];
//	sort(a, a + C);
//	solve(0, "");
//	return 0;
//}
//
//
//출처: https://rebas.kr/688 [PROJECT REBAS]

//from itertools import combinations
//L, C = map(int, input().split())
//a = sorted(input().split())
//for s in combinations(a, L) :
//	passwd = ""
//	vowel, consonant = 0, 0
//	for i in range(len(s)) :
//		if s[i] in "aeiou" :
//			vowel += 1
//		else :
//			consonant += 1
//			passwd += s[i]
//			if vowel >= 1 and consonant >= 2 :
//				print(passwd)
//
//
//				출처 : https ://rebas.kr/688 [PROJECT REBAS]