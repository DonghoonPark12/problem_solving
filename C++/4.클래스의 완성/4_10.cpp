#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Histogram {
	string str;
	int alpha[26];
public:
	Histogram(string _str)
		:str(_str)
	{};
	void put(string str);
	void putc(char c);
	void print();
	void test() { cout << str<<'\n'; }
};

void Histogram::put(string str) {
	// convert string to back to lower case
	//for_each(str.begin(), str.end(), [](char & c) {c = ::tolower(c);} );
	(this->str).append(str);
}

void Histogram::putc(char c) {
	(this->str) += c;
	//(this->str).push_back(c);
}

void Histogram::print() {
	cout << str << '\n';
	int cnt = 0;
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });
	for (int i = 0; i < size(str); i++) {
		if ((str[i] >= 'a') && (str[i] <= 'z')) 
			cnt++;
	}
	
	cout << "\nÃÑ ¾ËÆÄºª ¼ö " << cnt << '\n\n';

	memset(alpha, 0, sizeof(alpha));
	for (int i = 0; i<size(str); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			//cout << str[i] - 'a' << endl;
			alpha[str[i] - 'a']++;
		}
	}
	for (int i = 0; i<26; i++) {
		cout << char(i + int('a')) << " (" << alpha[i] << ")  :" << string(alpha[i], '*') << '\n';
	}
}

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.test();
	elvisHisto.print();

	return 0;
}