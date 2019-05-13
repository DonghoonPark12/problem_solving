/* FILE *포인터 이름 = fopen(파일명, 파일 모드) */
/* 성공하면 파일 포인터를 반환, 실패하면 NULL을 반환*/
/* fprintf(파일 포인터, 서식, 값1, 값2, ...) */
/* 성공하면 쓴 문자열의 길이를 반환, 실패하면 음수 반환*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	FILE *fp = fopen("Hello2.txt", "w"); //fopen(char const *_FileName, char const *_Mode); 

	fprintf(fp, "%s %d\n", "Hello", 400); // 문자열을 파일에 저장

//	fprintf(stdout, "%s %d\n", "Hello", 100); //printf와 기능 동일

	fclose(fp); // fclose(FILE *_stream)

	return 0;
}

