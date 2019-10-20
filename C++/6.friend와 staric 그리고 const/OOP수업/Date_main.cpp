#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>      /* printf, scanf */
#include <time.h>       /* time_t, struct tm, time, mktime */
#include "Date.h"

int main()
{
	//time_t rawtime;
	//struct tm * timeinfo;
	//int year, month, day;
	//const char * weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	////printf("Enter year: "); fflush(stdout); scanf("%d", &year);
	////printf("Enter month: "); fflush(stdout); scanf("%d", &month);
	////printf("Enter day: "); fflush(stdout); scanf("%d", &day);

	///* get current timeinfo and modify it to the user's choice */
	//time(&rawtime);
	//timeinfo = localtime(&rawtime);
	////timeinfo->tm_year = year - 1900;
	////timeinfo->tm_mon = month - 1;
	////timeinfo->tm_mday = day;
	//
	//mktime(timeinfo);

	//printf("Current local time and date: %s", asctime(timeinfo));
	//printf("Current local time and date: %d", timeinfo);

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("now: %d-%d-%d %d:%d:%d\n",	tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	Date date(tm.tm_mon + 1, tm.tm_mday, tm.tm_yday+1900);
	date.print();

	return 0;
}