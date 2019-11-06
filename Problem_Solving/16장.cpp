#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#define SIZE 3
#define SIZE 1000 //3번째 

void init_table(int table[], int size);

struct student {
	int number;
	char name[20];
	double gpa;
};

int main()
{
	/*
	struct student table[SIZE] = {
		{1, "Kim", 3.99},
		{2, "Min", 2.68},
		{3, "Lee", 4.01}
	};

	struct student s;
	FILE *fp = NULL;
	int i;
	// 쓰기 모드로 썼다가, 읽기 모드로 읽기
	if ((fp = fopen("student.dat", "wb")) == NULL) {
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}

	fwrite(table, sizeof(struct student), SIZE, fp);
	fclose(fp);

	if ((fp = fopen("student.dat", "rb")) == NULL) {
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}

	for (i = 0; i < SIZE; i++)
	{
		fread(&s, sizeof(struct student), 1, fp);
		printf("학번: %d, 이름: %s, 평점: %f\n", s.number, s.name, s.gpa);
	}
	fclose(fp);
	*/

	//2진 파일의 내용을 디버거 처럼 16진수로 표시하는 프로그램
	/*
	FILE *fp;
	char fname[100];
	int bytes;//읽어 들인 값을 저장하는 변수
	unsigned char buffer[16];//unsigned char * 16개 = 16bytes
	int address;

	printf("이진 파일 이름: "); scanf("%s", fname);
	
	if ((fp = fopen("fname", "rb")) == NULL) {
		fprintf(stderr, "원본 파일 %s를 열 수 없습니다.\n",fname);
		exit(1);
	}

	while (1) {
		bytes = fread(buffer, 1, 16, fp);//16bytes를 파일로 부터 읽는다. 
		if (bytes <= 0) break;
			printf("%08X: ", address);//현재의 주소를 8자리 16진수로 표현

		for (int i = 0; i < bytes; i++)
			printf("%02X", buffer[i]);//읽은 바이트 수 만큼 '2자리 16진수'로 표현. 8자리를 2자리로 표현.

		for (int i = 0; i < bytes; i++)
			if (isprint(buffer[i])) putchar(buffer[i]);//인쇄 가능하면 1byte 단위마다 문자로 표현
			else putchar('.');//표현이 불가능 하면 .

		address += bytes;
		putchar('\n');
	}
	fclose(fp);	
	*/

	//파일에 정수를 2진수로 쓰고, 임의 접근을 통해 2진수를 정수 형태로 출력하는 프로그램
	int table[SIZE];
	int n, data;
	long pos;
	FILE *fp = NULL;

	init_table(table, SIZE);

	if ((fp = fopen("sample.dat", "wb")) == NULL) { //이진 파일을 쓰기 모드로 open
		fprintf(stderr, "출력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}

	fwrite(table, sizeof(int), SIZE, fp);//주소: table에 int크기 만큼 1000개를 쓴다. 저장한 항목수 반환
	fclose(fp);
	
	if ((fp = fopen("sample.dat", "rb")) == NULL) { //이진 파일을 읽기 모드로 open
		fprintf(stderr, "입력을 위한 파일을 열 수 없습니다.\n");
		exit(1);
	}

	while (1) {
		printf("파일에서 위치를 입력하십시오(0에서 %d, 종료 -1): ", SIZE - 1);
		scanf("%d", &n);///1000을 입력하면..그래도 999까지만 이동 
		if (n == -1) break;
		pos = (long)n * sizeof(int);//위치  ex)3이면 4byte * 3 
		fseek(fp, pos, SEEK_SET);//fp를 pos 위치로 이동. SEEK_SET은 현재 파일의 처음을 기준으로 이동한다는 말. 
		fread(&data, sizeof(int), 1, fp); //fp위치에서 int크기만큼 하나를 읽어서 data 변수에 저장. 
		printf("%d 위치의 값은 %d 입니다.\n", n, data);
	}
	fclose(fp);

	return 0;
}

void init_table(int table[], int size)
{
	for (int i = 0; i < size; i++)
		table[i] = i*i;
}