/*
	size_t�� sizeof ����� unsigned ����Ÿ�Դϴ�.

*/

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
int main(void)
{

    // size_t �ڷ��� ��ü�� ũ�� �˾ƺ���
    printf("%u\n", sizeof(size_t));
    // ��� ���: 4
    // (32��Ʈ ȯ�濡���� size_t���� 4����Ʈ �� 32��Ʈ,
    // 64��Ʈ ȯ���̶�� 8�� ��µ� ����)

    // ���ڿ� ���� ���ϱ�
    size_t size = strlen("AAA BBB");
    // ������ ���� (unsigned int) �� ĳ�����ϸ�
    // size_t�� unsigned int�� ��ȯ��
    // unsigned int size = (unsigned int) strlen("AAA BBB");

    printf("%u\n", size);
    // ��� ���: 7

    return 0;


    //const size_t N = 100;
    //int numbers[N];
    //for (size_t ndx = 0; ndx < N; ++ndx)
    //    numbers[ndx] = ndx;
    //printf("SIZE_MAX = %zu\n", SIZE_MAX);
    //size_t size = sizeof numbers;
    //printf("size = %zu\n", size);
}