#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
	string s;
	//getline(cin, s);
	char c;
	int cnt = 0;

	while ((c = getchar()) != EOF) { // while( ~(c = getchar()) ) 
		if(c == ',')
			cnt++;
	}
	printf("%d", cnt+1);
	return	0;
}

#include<cstdio>
int r = 1;
char c;
int main() {
	while ((scanf("%c", &c)) != 0) //문자가 아닌 것이 들어오면 0 반환.    
		r += (c == ',');           //문자가 들어 오는 한 계속 돈다. 
	printf("%d", r);
	
	//printf("%d", EOF);  // -1
	//printf("%d", ~(-1));// 0
	//printf("%d", ~(0)); // -1	
	//printf("%d", ~(1)); // -2
	return 0;
}
// 그럼 while (!scanf("%c", &c))는 왜 안될까.
// 문자가 들어오면 !1 즉 0이 되므로 while문 빠져 나오므로 적절하지 않다. 

// while ( ~(scanf("%c", &c)) )는 왜 되는 것일까...

#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	int cnt = 0;
	while (getline(cin, s, ',')) { // getline의 세번째 인자는 구분자
		cnt += 1;
	}
	cout << cnt << '\n';
	return 0;
}