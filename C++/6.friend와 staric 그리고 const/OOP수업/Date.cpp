#include "Date.h"
Date::Date() {
	month = tm.tm_mon + 1;
}

Date::Date(int dy, int yr) {

}

Date::Date(int mn, int dy, int yr) {
	if (mn > 0 && mn <= 12)
		month = mn;
	else {
		month = 1;
		cout << "Invalid month (" << mn << ") set to 1.\n";
	}

	year = yr;
	day = checkDay(dy);

	cout << "Date object constructor for date ";
	print();
	cout << endl;
}

Date::Date(string str, int dy, int yr) {

}

void Date::print() const {
	cout << month << '/' << day << '/' << year;
} 

Date::~Date() {
	cout << "Date object destructor for date ";
	print();
	cout << endl;
}

int Date::checkDay(int testDay) const {
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };

	if ((testDay > 0) && (testDay <= daysPerMonth[month])) return testDay;

	// 윤년을 check -> 2월 29일 check
	// 2월 29일 인데 윤년인지 확인. 
	// 4로 나눠 떨어지는 해는 윤년
	// 그 중에서 100으로 나눠 떨어지는 해는 평년(윤년 x)
	// 하지만 400으로 또 나눠 떨어지는 해는 윤년
	if ((month == 2) && (testDay == 29) && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1;
}
