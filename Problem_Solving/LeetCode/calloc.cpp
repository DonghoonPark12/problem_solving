#include <stdio.h> 
#include <stdlib.h>

/*
	void* calloc(size_t elt_count, size_t elt_size);

	malloc���� ������ : �Ҵ�� ������ ��� 0���� �ٲ۴�.
*/

int main() {
	int* arr = (int*)calloc(5, sizeof(int));
}