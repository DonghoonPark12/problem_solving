// 날짜(Date) class 선언 밎 정의
#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <time.h>   
using namespace std;

class Date
{
public:
	Date(int = 1, int = 1, int = 1900); // 월/일/년 format의 생성자
	void print() const; // 월/일/년 format의 날짜 출력 함수
	~Date(); // 소멸자 선언
private:
	int month; // 1월부터 12월
	int day; // 1일부터 31일
	int year; // 년도
	
	// 입력한 년도와 월에 맞는 일인지 확인하는 함수
	int checkDay(int) const; 

	void printDDDYYYY() const;
	void printMMDDYY() const;
	void printMonthDDYYYY() const;

	int daysInMonth(int) const;
	bool isLeapYear();
}; 

//Date::Date(int, int, int) {
//
//}

#endif
