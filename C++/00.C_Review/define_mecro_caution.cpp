#include <iostream>
#include <stdio.h>
using namespace std;

#define squared1(x) x * x
#define squared2(x) (x * x)
#define squared3(x) (x) * (x)
#define squared4(x) ((x) * (x))

#define MSG1 "All your base are belong to us!"


int main() {
	//Assignment 1.2
	//double ans1 = 18.0 / squared1(2 + 1); // 18.0 / 2 + 1*2 + 1         = 12.0
	//double ans2 = 18.0 / squared2(2 + 1); // 18.0 / (2 + 1*2 + 1)       = 3.6 
	//double ans3 = 18.0 / squared3(2 + 1); // 18.0 / (2 + 1) * (2 + 1)   = 18.0
	//double ans4 = 18.0 / squared4(2 + 1); // 18.0 / ((2 + 1) * (2 + 1)) = 2.0

	//cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n' << ans4 << '\n';

	//Assignment 1.4
	const char msg[] = MSG1;
	puts(msg);


	return 0;
}