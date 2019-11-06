#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//(1 ≤ A, B, C, D ≤ 1,000,000)
// 1,000,000,100,000,0 > 2^32
/* 놓친것
* 1. stoi는 정수 값으로 반환한다.
* 본 문제와 같이 문자열을 이었을 경우 큰 값이 나올 가능성이 크기 때문에
* stoi로 반환하려고 하면 안된다. 
*/
int main() {
	int A, B, C, D;
	A = B = C = D = 0;
	//scanf("%c %d %d %d", &A, &B, &C, &D);
	//1. char로 받아도 안된다. 수가 한자리수가 아닐 수 도 있기 때문
	//2. 정수로 받아서 *10 할 생각 하면 안된다. 앞의 수가 두자리 인지 세자리인지 모르기 때문
	// (1) 정수로 받아 문자열로 변환한뒤 '+' 연산자를 이용해 이은 문자열 만든 뒤 stoi 로 정수 변환 
	// (2) 
	scanf("%d %d %d %d", &A, &B, &C, &D);

	string a = to_string(A);
	string b = to_string(B);
	string c = to_string(C);
	string d = to_string(D);

	printf("%.0f\n",stof(a + b) + stof(c + d));

	return 0;
}

/*
정수형 크기
char    1바이트(8비트)
short   2바이트(16비트)
int     4바이트(32비트) <-stoi(): 문자열을 int형으로 변환
long    4바이트(32비트)
unsigned long           <- stoul()
long long   8바이트(64비트) <-stoll()
unsigned long long      <- stoull()

※ int와 longlong의 차이
※ 부호있는 정수 signed int의 경우 -2^31 - 1 ~ 0 ~ 2^31 까지 표현이 가능하다.
※ 2^16까지가 아니라... (2^32)/2 가 2^16이더냐 
※ 따라서 2^31인 2,147,483,647 까지 표현이 가능하다. 16진수 표현으로 7FFF,FFFF 이다. 2진수 표현으로 0: 1개, 1: 31개 이다. 
※ 16진수는 비트수 표현에서 4를 곱한다고 생각하면 길이가 맞다. 8*4 = 32bit수 

※ 똑같은 방식으로 longlong은 signed의 경우 -2^63 -1 ~ 0 ~ 2^63 까지 표현이 가능하다.
※ 16진수 표현으로 7FFF,FFFF,FFFF,FFFF 이다.

실수형 크기
float   4바이트(32비트) <- stof()
double   8바이트(64비트) <- stod() : 문자열을 double형으로 변환
long double 12바이트(96비트) <- stold()
*/
