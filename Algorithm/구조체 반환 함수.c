#include <stdio.h>

typedef struct point
{
	int x;
	int y;
}POINT;

/*
POINT func()
{
	POINT s = { 10,10 }; //구조체 선언
	
	return s;
}
*/
/*
POINT *func() //C언어에서는 함수 오버로드 허용 하지 않으므로 위의 func() 함수 주석 처리
{			  //"반환 형식으로만 구분되는 함수를 오버로드 할 수 없습니다."
	static POINT s = { 10,10 };

	return &s; 
	//함수가 끝나면 구조체 변수도 사라진다.
	//따라서 주소 연산자로 구조체 변수의 메모리 주소를 반환하면 안되는데... 값은 잘 나오네??
}
*/
POINT *func()
{
	POINT *s = malloc(sizeof(POINT));//동적 메모리 할당

	s->x = 10;
	s->y = 10;
	
	return s; 
	//구조체 포인터의 주소를 반환
}

void main()
{
   //POINT p1;
	POINT *p1;

	p1 = func(); //반환된 구조체 값이 구조체 p1에 복사.

	printf("%d %d\n", p1->x, p1->y);
}