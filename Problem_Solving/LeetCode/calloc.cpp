#include <stdio.h> 
#include <stdlib.h>

/*
	void* calloc(size_t elt_count, size_t elt_size);

	malloc과의 차이점 : 할당된 공간을 모두 0으로 바꾼다.
*/

int main() {
	int* arr = (int*)calloc(5, sizeof(int));
}