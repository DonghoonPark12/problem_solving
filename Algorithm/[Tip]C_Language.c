/* -------------------------------------------------------------- */
/* 주로 쓰이는 헤더파일 관리 및 선언 방법 									  */
/* #include "Header_manager.h" 방식 								  */
/* -------------------------------------------------------------- */

// Header_manager.h의 내용
#ifdef	INCLUDE_HEADER_MANAGEMENT
#error	"re-include Error INCLUDE_HEADER_MANAGEMENT"
#else	
#define	INCLUDE_HEDER_MANAGEMENT

/* hdr1 Header */
#ifdef		HDR1.H
#include	"hdr1.h"
#endif

/* hdr2 Header */
#ifdef		HDR2.H
#include	"hdr2.h"
#endif

#endif


//hdr1.h의 내용
#ifndef	_HDR1_H
#define	_HDR1_H
int add(int a, int b)
{
	int c;
	c=a+b;
	return c;
}
#endif


//hdr2.h의 내용
#ifndef	_HDR2_H
#define	_HDR2_H
int mul(int a, int b)
{
	int c;
	c=a*b;
	return c;
}
#endif

//tips1.c의 내용
#define _HDR1_H
#define _HDR2_H
#include "Header_manager.h" //이부분에서 "hdr1.h"와 "hdr2.h"가 추가된다.

int main(void)
{
	int Ans0,Ans1;
	Ans0= add(10,20);
	Ans1= mul(10,20);
	return 0;
}

/* 장점
1. 헤더파일을 추가하고 관리 하기 쉽다(#define 만으로 필요로 하는 헤더파일을 추가할 수 있다).
2. "Header_manager.h"에 헤더파일을 한눈에 보기 쉽게 정리할 수 있다.
3. 헤더파일 중복 선언을 피하는 장치를 넣기 쉽다. #ifndef는 헤더파일 호출 시 중복 선언을 방지하기에 사용하기 타당해 보인다. 
*/


/* -------------------------------------------------------------- */
/* 헤더파일 선언시 #ifndef을 붙여주는게 얼마나 유용한지 알게 해주는 예제 (1)  		  */
/*															      */
/* -------------------------------------------------------------- */

/* 컴파일 에러를 발생 시키는 코드 */

//hdr1.h의 내용
class DummyBase {
	private:
	int _i;
	
	public:
		DummyBase(int i): _i(i) {
	}
	
	int Get() {
		return _i;
	}
	
	void Set(int i){
		_i = i;
	}
};

//hdr2.h의 내용
#include "hdr1.h"  
class Dummy: DummyBase {
	public:
	  Dummy(int i): DummyBase(i) {
	}

	int operator() () {
		return Get();
	}

	int operator() (int multi) {
		return Get() * multi;
	}
};

// tips1.cpp
#include "hdr1.h"    <-------------여기서 중복 에러가 발생한다.       
#include "hdr2.h"    <--왜냐하면 "hdr2.h"에서 "hdr1.h" 파일을 이미 사용하기 때문

nt main()
{
  DummyBase db(200);
  Dummy d(100);
}

/* 해결책 */

//hdr1.h의 내용
#ifndef HDR1_H
#define HDR1_H
class DummyBase {
	...
};
#endif

//hdr2.h의 내용
#ifndef HDR2_H
#define HDR2_H

#include "hdr1.h"  
class Dummy: DummyBase {
	...
};
#endif

// tips1.cpp
#include "hdr1.h"    <------ HDR1_H define 됨    
#include "hdr2.h"    <------에서 "hdr1.h"를 한번 더 호출해도 HDR1_H이 define 되어 있으므로 헤더파일 추가 안된다.

int main(){
	...
}





/* 느낀점 
C언어는 쉽게 이해하면서 유용하게 쓰일 수 있는 코드가 좋은 코드 인 것 같다(말이 참 추상적이다).
(누구나 이해할 수 있게) 직관적으로 알 수 있는 코드를 작성하는 연습을 많이 해야겠다고 느꼈다. 
*/




/*
 [참조]
 https://ko.wikipedia.org/wiki/%ED%97%A4%EB%8D%94_%ED%8C%8C%EC%9D%BC
 http://yesarang.tistory.com/64
 https://dojang.io/mod/page/view.php?id=681
 [읽어 볼 것]
 https://ko.wikipedia.org/wiki/C_%ED%91%9C%EC%A4%80_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC
 http://www.eventhelix.com/RealtimeMantra/HeaderFileIncludePatterns.htm#.WO924sG1vD4
 */