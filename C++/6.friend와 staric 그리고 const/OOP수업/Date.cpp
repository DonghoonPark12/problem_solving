// Date class의 멤버함수 정의.
#include "Date.h"

// 생성자 정의
Date::Date(int mn, int dy, int yr)
{
	// 만약 입력한 월이 1~12라면 그대로
	// 아니라면 1로 private 변수 month에 저장
	if (mn > 0 && mn <= 12)
		month = mn;
	else {
		month = 1;
		cout << "Invalid month (" << mn << ") set to 1.\n";
	}

	// 년도는 input대로 private 변수 year에 저장
	year = yr;

	// 일은 check하는 함수를 거쳐 private 변수 day에 저장
	day = checkDay(dy);

	// Date object의 생성 확인
	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

// 월/일/년 format의 날짜 출력 함수 정의
void Date::print() const
{
	cout << month << '/' << day << '/' << year;
} 

// 소멸자 정의
Date::~Date()
{
	// Date object의 소멸 확인
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

// 입력한 년도와 월에 맞는 일인지 확인하는 함수 정의
int Date::checkDay(int testDay) const
{
	// 배열을 이용해 각 월의 마지막 일을 선언
	// ex) 1월은 31이 마지막날, 2월은 윤달이 아닐 때의 28을 base로
	static const int daysPerMonth[13] = 
	{ 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };

	// 어떠한 월에 해당하는 일인지 유효성 검사
	if ((testDay > 0) && (testDay <= daysPerMonth[month]))
		return testDay;

	// 윤년을 check -> 2월 29일 check
	// 만약 입력으로 2월 29일을 받았을 때
	// 4로 나눠 떨어지는 해는 윤년
	// 그 중에서 100으로 나눠 떨어지는 해는 평년(윤년 x)
	// 하지만 400으로 또 나눠 떨어지는 해는 윤년
	if ((month == 2) && (testDay == 29) && 
		(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		// 조건에 맞으면 input을 일로
		return testDay;

	// 조건에 맞지 않는다면 1을 일로
	cout << "Invalid day (" << testDay << ") set to 1.\n";

	return 1;
}
