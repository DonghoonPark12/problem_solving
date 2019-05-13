#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	// 형식 : %[플래그][필드폭].[정밀도] 
	int d, o, x;

	int a, b, c;
	/* 10진수, 8진수, 16진수로 정수 입력이 가능하다. */
	/* 10을 입력하면 문자열 10이 각각 10진수, 8진수, 16진수 형식으로 변환된다.*/
	/* 그리고 해당 주소에 각각 값이 저장된다. */
	scanf("%d, %o, %x", &d, &o, &x);

	printf("d= %d, o= %d, x=%d\n", d, o, x);

	printf("%010d\n", 123);
	
	printf("%+d\n", 123);//+123  
	
	printf("%-d\n", -123); //-123

	printf("%d\n", -123); //-123

	printf("%#d\n", 123); //8진수일 경우 0, 16진수 일 경우 0x를 붙인다. 

	printf("정수 3개를 입력하시오: ");

	/* 문자 입력은 공백도 문자로 보지만, 정수 입력시 공백은 무시 하나 보다*/
	if (scanf("%d%d%d", &a, &b, &c) == 3)//<-- 10 20 30 //scanf("%c %c %c", &c1, &c2, &c3) <-- a b c 
		printf("%d %d %d", a, b, c);

	return 0;

}