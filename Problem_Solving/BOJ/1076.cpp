#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
* ���ڿ����� �ΰ��� �������.
* 1. getline(cin,str)
* 2. str.compare(str2)
*/
//1,000,000,000
// ���� ū ���� 99,000,000,000 ��
// int �ִ� ǥ�� ������ 2,147,483,648 �� �Ѿ��. 
// long long �ִ� ǥ�� ������ 2^63 �˳��ϴ�.
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
	//long long Ans = (10 * a + b)*power(c); //�ڡ� ó���� �̷��� �߾��µ�
	// (10 * a + b)*power(c) �� int �� �̴� ����, 2,147,483,647 �̻� Ŀ���� �ʾҴ�!!
	// ����� �غ��� Ans�� ������ ��� ����. 
	long long Ans = (long long)(10 * a + b)*power(c); //�ڡ�
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





