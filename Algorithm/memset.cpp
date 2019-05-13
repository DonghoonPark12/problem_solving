//void * memset(void * ptr, int value, size_t num);

#include <string.h> // string.h 파일이 필요합니다.
#include <stdio.h>

int main() {

	char a[20];

	// 1바이트마다 모두 65로 초기화
	// 배열을 채울 때는 sizeof()함수를 사용하면 됩니다.
	// sizeof 함수 - 배열의 전체 바이트 크기를 반환합니다.
	memset(a, 65, sizeof(a));

	// 출력을 통해 확인
	for (int i = 0; i < (sizeof(a) / sizeof(char)); i++) {
		printf("%c\n", a[i]);
	}

	return 0;
}

