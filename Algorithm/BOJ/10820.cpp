#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
/* 내가 놓친 점
* 1. 개행문자도 문자로 취급된다.
* 아스키로 10진수:10, 16진수:0x0A
* 따라서 문장이 여러개 주어지더라도, 문자 입력이 끝날때 까지를 기준으로 잡으면 된다. 
* 개행문자 \n도 문자로 취급된다는 점을 몰랐던 나는 문자열을 하나씩 받았다.
* 하지만, EOF까지 문자로 생각하고 접근하면...
* while (scanf("%c", &c) != EOF) 혹은 while (~(c = getchar())) 
* while문 하나로 풀 수 있다. 

* 2. EOF는 문자가 아니다. -1값.
* 파일로 검사하는 온라인 검사는 마지막 테스트 케이스 끝에 (문자가 아닌)EOF가 붙는다. 
* 허나, 나와 예제 코드는 EOF입력을 (마지막에)기다린다. 그래서 기다린다. 답은 맞다.

* 3. !는 논리 연산자,  ~는 비트 연산자 
* while ( !(c = getchar()) ) 는 오답. 
* (쉽게 이해) while ( !** ) 이면 **가 들어오면 종료 된다. 
* 
* while ( (c = getchar()) != EOF ) 즉, 파일 마지막이 아닐 때 까지 문자를 계속 입력 받는게 모범.
* while (~(c = getchar()) ) 이게 왜 가능할까......
* 
*/

int main() {
	string s;
	int S, D, N, B;
	int i;
	while (getline(cin, s)) { //표준 입 출력으로 들어옴
		//S = 0, D = 0, N = 0, B = 0;
		S = D = N = B = 0;
		i = 0;
		while (s[i]) {  
			if (s[i]>='a' && s[i]<='z') //소문자
				S++;
			else if (s[i]>='A' && s[i]<='Z')//대문자
				D++;
			else if (s[i]>='0' && s[i]<='9')//숫자
				N++;
			else
				B++;
			i++;
		}
		printf("%d %d %d %d\n", S, D, N, B);
	}
	return 0;
}

// 위키
// C 표준 라이브러리에서 getchar와 같은 문자 입력 함수는 파일의 끝을 만났음을 알리기 위해
// 매크로로 정의된 EOF 값을 리턴한다. 
// EOF의 실제 값은 시스템에 따라 다르며 (그러나 보통 -1로 정의된다) 
// 어떠한 유효한 문자의 값과도 겹치지 않는다. 

#include <cstdio> // 예제코드 
int a, A, n, s;
char c;
int main() {
	  while( (c = getchar()) != EOF ) {   // while ( ~(c = getchar()) ) 
		if (c >= 'a' && c <= 'z') a++;
		if (c >= 'A' && c <= 'Z') A++;
		if (c >= '0' && c <= '9') n++;
		if (c == ' ') s++;
		if (c == '\n') printf("%d %d %d %d\n", a, A, n, s), a = A = n = s = 0;
	}
	return 0;
}


#include <stdio.h>
int main()
{
	char lineFeed = '\n';    // 제어 문자 \n 할당
	printf("%d %c 0x%x\n", lineFeed, lineFeed, lineFeed);    // 10 0xa: 제어 문자의 ASCII 코드 출력
	return 0;
}
// 10 (줄 바꿈 문자를 %c로 출력하면 줄바꿈이 된다.)
// 0xa 


//#include <stdio.h> // getchar()참고
//
//int main()
//{
//	int c;
//	puts("Enter text. Include a dot ('.') in a sentence to exit:");
//	do {
//		c = getchar();
//		putchar(c); //마침표 까지 입력되고 do ~ while() 이라서 
//	} while (c != '.'); //입력되면 종료 
//	return 0;
//}
	
