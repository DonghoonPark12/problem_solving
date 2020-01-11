/*
	size_t는 sizeof 결과의 unsigned 정수타입니다.

*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
int main(void)
{

    // size_t 자료형 자체의 크기 알아보기
    printf("%u\n", sizeof(size_t));
    // 출력 결과: 4
    // (32비트 환경에서는 size_t형이 4바이트 즉 32비트,
    // 64비트 환경이라면 8이 출력될 것임)

    // 문자열 길이 구하기
    size_t size = strlen("AAA BBB");
    // 다음과 같이 (unsigned int) 로 캐스팅하면
    // size_t가 unsigned int로 변환됨
    // unsigned int size = (unsigned int) strlen("AAA BBB");

    printf("%u\n", size);
    // 출력 결과: 7

    return 0;


    //const size_t N = 100;
    //int numbers[N];
    //for (size_t ndx = 0; ndx < N; ++ndx)
    //    numbers[ndx] = ndx;
    //printf("SIZE_MAX = %zu\n", SIZE_MAX);
    //size_t size = sizeof numbers;
    //printf("size = %zu\n", size);
}