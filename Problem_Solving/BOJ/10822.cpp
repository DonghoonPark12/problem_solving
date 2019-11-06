#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	string str;
	int sum = 0;
	int num;

	//getline(cin, str);
	//number = stoi(str);

	//while (getline(cin, str, ','))//','(구분자) 앞까지 str에 넣는다.
	//	sum += stoi(str);         // 다음으로 구분자 무시하고(!!) 다음 문자열 들어온다. 
	//printf("%d\n", sum);
	
	while(scanf("%d", &num) != -1) //scanf는 적절한 값이 들어온 갯수 만큼 Return
		sum += num;				   // EOF이면 -1 리턴하나 보다. 
	 printf("%d\n", sum);          // EOF(-1)만 아니면 다 입력 받는 덕분에 10,20,30,50,110 이 입력 가능 
								   // while(~scanf("%d",&num)) 혹은 while(scanf("%d", &num) != EOF )
	 return 0;
}

//#include <stdio.h>
//char s[110];
//int k, r;
//int main() {
//	scanf("%s", s);
//	for (int i = 0; s[i]; i++)
//		if (s[i] == ',') r += k, k = 0;
//		else k = 10 * k + s[i] - '0'; //문자는 정수보다 '0'만큼 값이 크다. 
//
//	printf("%d", r + k);
//	return 0;
//}