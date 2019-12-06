#include <iostream>
#include <string>
#include <algorithm>

#include <vector>

using namespace std;

string operator+(const string &left, const string &right) {
	string tmp;// = "";
	tmp += left;
	tmp += " ";
	tmp += right;
	return string(tmp);
}

int main() {
	string str1 = "Happy";
	string str2 = "birth day";
	string str3 = "to you";
	//string tmp = str1 + str2;
	//cout << str1 + str2<< endl;
	cout << str1 + str2 + str3 << endl;
	//str1.operator+(str2)
}