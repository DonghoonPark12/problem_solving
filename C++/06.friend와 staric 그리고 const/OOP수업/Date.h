// 날짜(Date) class 선언 밎 정의
#ifndef DATE_H
#define DATE_H

#include <string>
#include <time.h>   
using namespace std;

class Date {
private:
	int month, day, year;

	int checkDay(int) const; 
	int daysInMonth(int) const;
	bool isLeapYear() const;
	int convertDDToDDD() const;
	void setMMDDFromDDD(int);
	string convertMMToMonth(int) const;
	void setMMFromMonth(string);
	int convertYYYYToYY() const;

public:
	const int days_per_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const char *week[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	const string month[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	time_t t;
	struct tm tm = *localtime(&t);
	int curyear = tm.tm_year + 1900;
	int curmon = tm.tm_mon + 1;

	int total_day = 0;

	//cout << tm.tm_year + 1900 << "년 " << tm.tm_mon + 1 << "월 " << tm.tm_mday << "일" << tm.tm_hour << "시 " << tm.tm_min << "분 " << tm.tm_sec << "초" << endl << endl;
	//for (int x = 0; x<tm.tm_mday - 1; x++) total_day += days_per_month[x];
	//	total_day += tm.tm_mday;

	Date();
	Date(int = 1, int = 1900);
	Date(int = 1, int = 1, int = 1900); 
	Date(string str, int dy, int yr);
	void print() const; 
	~Date(); 

	void printDDDYYYY() const;
	void printMMDDYY() const;
	void printMonthDDYYYY() const;

}; 

//Date::Date(int, int, int) {
//
//}

#endif
