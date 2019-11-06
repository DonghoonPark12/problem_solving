#include <iostream>
#include <string>

using namespace std;

string operator+(const string left, const string right) {
	string tmp;// = "";
	tmp += left;
	tmp += " ";
	tmp += right;
	return tmp;
}
int main() {
	string str1 = "Happy";
	string str2 = "birth day";
	string str3 = "to you";

	cout << str1 + str2 + str3 << endl;
}