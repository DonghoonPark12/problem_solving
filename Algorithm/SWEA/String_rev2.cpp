#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/*
	rev1 : 
	rev2 : https://boycoding.tistory.com/178
*/
int main() {
	//������ �������. string �Է��� ���� getlint(cin, str)�� ��� ������ <string> �̴�. <cstring> �ƴϴ�.

	/*
	string s1;

	char c[] = "c.string";
	string s2(c);
	string s3 = c;

	c[1] = '\0';

	string s4(c);  //c
	string s5 = c; //c

	string s6(10, '!');  // !!!!!!!!!!
	string s7 = "abcdefg";

	printf("%c\n", s2);
	*/

	//string s;
	//int cnt = 0;
	//while (cin >> s) { //���� �ڵ�. ������ �Է� ���� ���ϴ� cin Ư���� �״�� �̿��ߴ�. �ٵ� �� ��Ÿ�� ������ �ȶ��...
	//	cnt++;
	//}

	//char str[] = "";
	//string str;
	//int cnt = 0;
	//while (scanf("%s", str) == 1) { //���� �ڵ� 1. ���� ������ �����ϸ� ���� ������ �����ؾ� �ϴµ� ��Ÿ�� ������ ����. 
	//	cnt++;
	//}
	
	//string str; //�� ������ ���̴� 1,000,000�� ���� �ʴ´�. ������ ������ �Ǵ� �ɱ�...
	//getline(cin, str);//cin ��ɾ�� ���� ���ڿ��� string ������ ��´�. �������� NULL �� ä���ش�.

	//int i = 0;
	//int cnt = 1;
	//while (str[i]) { // ���� �ڵ� 2.  ����� �����ϴ� '������ �ܾ� ã��' �ε� �� Ʋ������ ���...
	//	if (str[i] == ' ')
	//		cnt++;
	//	i++;
	//}

	//printf("%d\n", cnt);

	/*string s = "abc";
	printf("%s\n", s.c_str());

	s += "def";
	printf("%s\n", s.c_str());

	s = "";
	printf("%s\n", s.c_str());

	s = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n", s.c_str());*/

	//string s = "book";
	//cout << s << ": " << s.size() << '\n';
	//cout << s << ": " << s.length() << '\n';
	//cout << s << ": " << s.empty() << '\n';

	//s = "";
	//cout << s << ": " << s.size() << '\n';
	//cout << s << ": " << s.size() -1 << '\n';
	//cout << s << ": " << s.empty() << '\n';

	//string s1 = "string";
	//string s2 = "string ";

	//if (s1 == s2) {
	//	cout << "s1 == s2" << '\n';
	//}
	//else if (s1 != s2) {
	//	cout << "s1 != s2" << '\n';
	//}

	//if (s1 < s2) {
	//	cout << "s1 < s2" << '\n';
	//}
	//else if (s1 > s2) {
	//	cout << "s1 > s2" << '\n';
	//}

	//string a = "Hello";
	//string b = "World";

	//string hello_world = a + " " + b;
	//hello_world += "!";
	//cout << hello_world << '\n';

	//hello_world.push_back('!');
	//cout << hello_world << '\n';

	//string a = "He";
	//a.append(2, 'l');
	//a.append("o").append(1, ' ');

	//string b = "";
	//const char *c = "World";
	//b.append(c);

	//string hello_world = a; //"Hello"
	//hello_world.append(b); //"Hello World"
	//hello_world.push_back('!');

	//cout << hello_world << '\n';

	//string s = "e";

	//s.insert(0, "H"); //"He"

	//s.insert(2, "o");//"Heo"

	//s.insert(2, 2, 'l').append(" "); //"Hello ";

	//string world = "Half the World Away";

	//s.insert(6, world, 9, 5).push_back('!');
	//
	//cout << s << '\n';

	//string str = "10";

	//int number = stoi(str);
	//print(str, number); //10

	//number = stoi(str, 0, 2);
	//print(str, number);

	//str = "ffff";
	//number = stoi(str, 0, 16);
	//print(str, number);

	//str = "21 Guns";
	//number = stoi(str);
	//print(str, number); //21

	//str = "3.141592";
	//number = stoi(str);
	//print(str, number); //3

	int n1 = 1;
	int n2 = 2;

	string s1 = to_string(n1); //"1"
	string s2 = to_string(n2); //"2"

	cout << s1 + ' ' + s2 << '\n';

	long long l1 = 2147483647;
	long long l2 = 2147483647;

	string s3 = to_string(l1); //"1"
	string s4 = to_string(l2); //"2"

	cout << s3 + ' ' + s4 << '\n';

	double d = 3.141592;
	float f = 65358979.0;

	string s5 = to_string(d); //"1"
	string s6 = to_string(f); //"2"

	cout << s5 + ' ' + s6 << '\n';

	return 0;

}

//#include <stdio.h>
//
//int main()
//{
//	int cnt = 0;
//	int c;
//
//	while ((c = getchar()) != '\n') {
//		if (c == ' ')
//			cnt++;
//	}
//	printf("%d", cnt + 1);
//	return 0;
//}


