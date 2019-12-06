#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
/*
srand는 호출할 때 전달받은 인자를 기반으로 난수를 초기화
rand는 srand로 인해 생성된 값을 바탕으로 난수를 생성.
time 함수는 인자값으로 NULL을 넘기면 1970년 1월 1일 0시(UTC 타임 존) 이후부터 인자값 까지 흐른 초 수를 리턴
*/
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


	srand(time(NULL)); // 이 줄을 rand함수 호출 전에 선언하면, 시간을 기준으로 초기화되는 Real 난수를 만들어 낼 수 있게 된다. 

	for (int i = 0; i < 5; i++) {
		int random = rand() % 100; // 0 ~ 100 범위의 난수 생성.
		cout << random << endl;
	}
	return(0);
}
