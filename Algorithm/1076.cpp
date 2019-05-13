#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
* 문자열에선 두개만 기억하자.
* 1. getline(cin,str)
* 2. str.compare(str2)
*/
//1,000,000,000
// 가장 큰 값인 99,000,000,000 가
// int 최대 표현 범위인 2,147,483,648 을 넘어간다. 
// long long 최대 표현 범위는 2^63 넉넉하다.
int power(int n) {
	int Ans = 1;
	for (int i = 0; i < n; i++) {
		Ans *= 10;
	}
	return Ans;
}

int f(string s) {
	if( s.compare("black")==0) {
		return 0;
	}
	else if (s.compare("brown")==0) {
		return 1;
	}
	else if (s.compare("red")==0) {
		return 2;
	}
	else if (s.compare("orange")==0) {
		return 3;
	}
	else if (s.compare("yellow")==0) {
		return 4;
	}
	else if (s.compare("green") == 0) {
		return 5;
	}
	else if (s.compare("blue") == 0) {
		return 6;
	}
	else if (s.compare("violet") == 0) {
		return 7;
	}
	else if (s.compare("grey") == 0) {
		return 8;
	}
	else {//if (s.compare("white") == 0) {
		return 9;
	}
	//else {
	//	return 0;
	//}
}

int main() {
	string str;
	getline(cin, str); 	int a = f(str);
	getline(cin, str); int b = f(str);
	getline(cin, str); int c = f(str);
	//long long Ans = (10 * a + b)*power(c); //★★ 처음에 이렇게 했었는데
	// (10 * a + b)*power(c) 가 int 형 이다 보니, 2,147,483,647 이상 커지지 않았다!!
	// 디버깅 해보니 Ans에 음수가 들어 갔다. 
	long long Ans = (long long)(10 * a + b)*power(c); //★★
	printf("%lld", Ans);

	map<string, int> d = {
		{ "black", 0 },{ "brown", 1 },{ "red", 2 },
		{ "orange", 3 },{ "yellow", 4 },{ "green", 5 },
		{ "blue", 6 },{ "violet", 7 },{ "grey", 8 },
		{ "white", 9 }
	};
	string a, b, c;
	cin >> a >> b >> c;

	long long ans = (long long)(d[a] * 10 + d[b]);//d["black"] -> 0
	for (int k = 0; k<d[c]; k++) {
		ans *= 10LL;
	}

	cout << ans << '\n';

	return 0;
}





