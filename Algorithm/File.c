/* FILE *������ �̸� = fopen(���ϸ�, ���� ���) */
/* �����ϸ� ���� �����͸� ��ȯ, �����ϸ� NULL�� ��ȯ*/
/* fprintf(���� ������, ����, ��1, ��2, ...) */
/* �����ϸ� �� ���ڿ��� ���̸� ��ȯ, �����ϸ� ���� ��ȯ*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	FILE *fp = fopen("Hello2.txt", "w"); //fopen(char const *_FileName, char const *_Mode); 

	fprintf(fp, "%s %d\n", "Hello", 400); // ���ڿ��� ���Ͽ� ����

//	fprintf(stdout, "%s %d\n", "Hello", 100); //printf�� ��� ����

	fclose(fp); // fclose(FILE *_stream)

	return 0;
}

