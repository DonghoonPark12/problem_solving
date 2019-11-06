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

	// ������ check -> 2�� 29�� check
	// 2�� 29�� �ε� �������� Ȯ��. 
	// 4�� ���� �������� �ش� ����
	// �� �߿��� 100���� ���� �������� �ش� ���(���� x)
	// ������ 400���� �� ���� �������� �ش� ����
	if ((month == 2) && (testDay == 29) && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1;
}
