/*
	time.h header file contains functions and macros that provide standardized access to time and date.
	Refer to : https://www.codingunit.com/c-tutorial-how-to-use-time-and-date-in-c
*/
#include <stdio.h>
#include <time.h>
int main() {
	time_t sec;
	sec = time(NULL);
	printf("Number of hours since January 1, 1970 is %ld \n", sec / 3600);
	return 0;

}

