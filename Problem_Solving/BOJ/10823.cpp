#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	int num = 0;
	int sum = 0;
	char c;

	while ((c = getchar()) != EOF) {
		if (c == ',') {
			sum += num; num = 0;
		}
		else if (c == '\n') { //������ ���๮�� �� 10�� num�� ���� ���� ������ (1)
		}
		else
			num = num*10 + c - '0'; //num += num*10 + c - '0'; �� �ƴϴ�.

		//else if ( c >= '0'  && c <= '9')  //(c != '\n') 
		//        num = num*10 + c - '0'; // �̷��Ը� �ص� �ȴ� (2)
	}

	//printf("%d", sum); �� �ƴϴ�. �������� ','�� ������ �ʾ� sum�� �������� num�� ���� �ִ�.
	printf("%d", sum + num);//'ù ���ڿ� ������ ���ڴ� �׻� ����'
	return 0;
}


#include <iostream>
#include <sstream> 
#include <string>
using namespace std;

int main() {
	string s;
	string line;
	while (cin >> line) {
		s += line;
	}
	istringstream sin(s); //string�� ǥ�� ����� ó�� ����Ϸ���, istringstream�� ����Ѵ�. 
	string number;
	int sum = 0;
	while (getline(sin, number, ',')) {
		sum += stoi(number);
	}
	cout << sum << '\n';
	return 0;
}