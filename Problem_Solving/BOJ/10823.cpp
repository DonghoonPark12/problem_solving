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
		else if (c == '\n') { //없으면 개행문자 값 10이 num에 더해 질것 이지만 (1)
		}
		else
			num = num*10 + c - '0'; //num += num*10 + c - '0'; 가 아니다.

		//else if ( c >= '0'  && c <= '9')  //(c != '\n') 
		//        num = num*10 + c - '0'; // 이렇게만 해도 된다 (2)
	}

	//printf("%d", sum); 가 아니다. 마지막에 ','가 나오지 않아 sum에 못더해준 num의 값이 있다.
	printf("%d", sum + num);//'첫 문자와 마지막 문자는 항상 숫자'
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
	istringstream sin(s); //string을 표준 입출력 처럼 사용하려면, istringstream을 사용한다. 
	string number;
	int sum = 0;
	while (getline(sin, number, ',')) {
		sum += stoi(number);
	}
	cout << sum << '\n';
	return 0;
}