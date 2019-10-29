#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    
#include <time.h>       /* time_t, struct tm, time, mktime */
#include "Date.h"
/*
struct tm {
	int tm_sec;   // seconds of minutes from 0 to 61
	int tm_min;   // minutes of hour from 0 to 59
	int tm_hour;  // hours of day from 0 to 24
	int tm_mday;  // day of month from 1 to 31
	int tm_mon;   // month of year from 0 to 11
	int tm_year;  // year since 1900
	int tm_wday;  // days since sunday
	int tm_yday;  // days since January 1st
	int tm_isdst; // hours of daylight savings time
}
*/
int main()
{
	Date date;
	Date date(tm.tm_mday, curmon, curyear);
	Date date(month[tm.tm_mon], curmon, curyear);

	date.print();


	/*
	//사용자 설정
	//// get current timeinfo and modify it to the user's choice 
	//time_t t;
	//time(&t);
	//struct tm tm = *localtime(&t);
	//printf("Enter year: "); fflush(stdout); scanf("%d", &year);
	//printf("Enter month: "); fflush(stdout); scanf("%d", &month);
	//printf("Enter day: "); fflush(stdout); scanf("%d", &day);
	//tm.tm_year = year - 1900;
	//tm.tm_mon = month - 1;
	//tm.tm_mday = day;
	//mktime(&tm);
	*/
	return 0;
}