#define _CRT_SECURE_NO_WARNINGS
#include <math.h>  
#include <stdio.h>  

int main() //(int ac, char* av[])
{
	int x, y;
	int theta;
	scanf("%d %d", &x, &y);
	/*
	if (ac != 3) {
		fprintf(stderr, "Usage: %s <x> <y>\n", av[0]);
		return 1;
	}
	x = atof(av[1]);
	*/
	//theta = atan(x);
	//printf("Arctangent of %f: %f\n", x, theta);
	//y = atof(av[2]);
	theta = atan2(y, x);
	printf("Arctangent of %d / %d: %d\n", y, x, theta);
	return 0;
}