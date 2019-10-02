#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n;
	time_t t;
	n = 5;
	
	/* Initalizes random number generator */
	srand((unsigned)time_t(&t));

	/* Print 5 random numbers from 0 to 49 */
	for (int i = 0; i < 5; i++) {
		printf("%d\n", rand() % 50);
	}

	return(0);
}
