// Member-function definitions for class Date.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;
using std::setfill;

#include <ctime>
using std::time;
using std::localtime;
using std::tm;
using std::time_t;

#include "hw_Date.h" // include Date class definition

// default constructor that sets date using <ctime> functions
Date::Date() {
	// pointer of type struct tm which holds calendar time components
	struct tm *ptr;
	 time_t t = time(0); // determine current calendar time      

	// convert current calendar time pointed to by t into
	ptr = localtime(&t);

	day = ptr->tm_mday; // broken down day of month
	month = 1 + ptr->tm_mon; // broken down month since January
	year = ptr->tm_year + 1900; // broken down year since 1900
} 

// constructor that takes date in ddd/yyyy format
Date::Date(int ddd, int yyyy) {
	year = yyyy;
	setMMDDFromDDD(ddd); 
}

// constructor that takes date in mm/dd/yy format
Date::Date(int mm, int dd, int yy) {
	setYYYYFromYY(yy); 
	setMonth(mm); 
	setDay(dd); 
} 

// constructor that takes date in Month dd, yyyy format
Date::Date(string monthName, int dd, int yyyy) {
	setMMFromMonth(monthName); 
	setDay(dd); 
	year = yyyy; 
} 

void Date::setDay(int d) { day = checkDay(d); }

void Date::setMonth(int m) {
	if (m > 0 && m <= 12) month = m;
	else { month = 1; cout << "Invalid month (" << m << ") set to 1.\n"; } 
} 

// print Date object in form: month/day/year
void Date::print() const { cout << month << '/' << day << '/' << year << endl; } 

// print Date object in form: ddd yyyy
void Date::printDDDYYYY() const {
	cout << convertDDToDDD() << ' ' << year << endl;
}

// print Date object in form: mm/dd/yy
void Date::printMMDDYY() const {
	cout << setw(2) << setfill('0') << month << '/'
		<< setw(2) << setfill('0') << day << '/'
		<< setw(2) << setfill('0') << convertYYYYToYY() << endl;
}

// print Date object in form: Month dd, yyyy
void Date::printMonthDDYYYY() const {
	cout << convertMMToMonth(month) << ' ' << day << ", " << year << endl;
} 

// output Date object to show when its destructor is called
Date::~Date()
{
	cout << "Date object destructor for date ";
	print();
	cout << endl;
} // end ~Date destructor

// utility function to confirm proper day value based on month and year; handles leap years, too
int Date::checkDay(int testDay) const {
	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysInMonth(month)) return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && isLeapYear())
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1; 
} 

int Date::daysInMonth(int m) const {
	if (isLeapYear() && m == 2) return 29;

	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return daysPerMonth[m];
}

bool Date::isLeapYear() const {
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true;
	else return false;
} 

// calculate 3-digit day based on Date object's current month and day
int Date::convertDDToDDD() const {
	int ddd = 0;

	// for each month that has passed, add days to ddd
	for (int i = 1; i < month; i++) ddd += daysInMonth(i);

	ddd += day;
	return ddd;
} 

// set month and day based on 3-digit day
void Date::setMMDDFromDDD(int ddd) {
	int dayTotal = 0;
	int m;

	//ddd를 바탕으로 언제까지 m을 카운트 할지 알려면, 지금까지 더한 dayTotal에
	//앞으로 더할 m의 daysInMonth(m)이 ddd 보다 작으면 for문을 종료한다. 
	for (m = 1; m <= 12 && (dayTotal + daysInMonth(m)) < ddd; m++)
		dayTotal += daysInMonth(m);

	setMonth(m);
	setDay(ddd - dayTotal);
} 

string Date::convertMMToMonth(int mm) const {
	static const string months[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return months[mm];
} 

// set month number based on month name    
void Date::setMMFromMonth(string m) {
	bool matchFound = false;

	for (int i = 1; i <= 12 && !matchFound; i++) {
		if (convertMMToMonth(i) == m) {
			setMonth(i);
			matchFound = true;
		} 
	} 

	if (!matchFound) {
		cout << "Invalid month name (" << month << "). month set to 1.\n";
		setMonth(1); 
	} 
} 

// utility function to convert 4-digit year to 2-digit year
int Date::convertYYYYToYY() const { return (year >= 2000 ? year - 2000 : year - 1900); } 

// utility function to convert 2-digit year to 4-digit year
void Date::setYYYYFromYY(int yy) {
	// if yy is less than 19, assume it is in the 2000s
	// if yy is greater than or equal to 7, assume it's in the 1900s
	// 07 미만이면 2000년대로 가정하고, 07보다 크면 1900년대로 본다??
	// 19로 바꿔야 겠네.
	year = (yy < 19 ? yy + 2000 : yy + 1900);
}