#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#define SIZE 3
#define SIZE 1000 //3��° 

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
	// ���� ���� ��ٰ�, �б� ���� �б�
	if ((fp = fopen("student.dat", "wb")) == NULL) {
		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}

	fwrite(table, sizeof(struct student), SIZE, fp);
	fclose(fp);

	if ((fp = fopen("student.dat", "rb")) == NULL) {
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}

	for (i = 0; i < SIZE; i++)
	{
		fread(&s, sizeof(struct student), 1, fp);
		printf("�й�: %d, �̸�: %s, ����: %f\n", s.number, s.name, s.gpa);
	}
	fclose(fp);
	*/

	//2�� ������ ������ ����� ó�� 16������ ǥ���ϴ� ���α׷�
	/*
	FILE *fp;
	char fname[100];
	int bytes;//�о� ���� ���� �����ϴ� ����
	unsigned char buffer[16];//unsigned char * 16�� = 16bytes
	int address;

	printf("���� ���� �̸�: "); scanf("%s", fname);
	
	if ((fp = fopen("fname", "rb")) == NULL) {
		fprintf(stderr, "���� ���� %s�� �� �� �����ϴ�.\n",fname);
		exit(1);
	}

	while (1) {
		bytes = fread(buffer, 1, 16, fp);//16bytes�� ���Ϸ� ���� �д´�. 
		if (bytes <= 0) break;
			printf("%08X: ", address);//������ �ּҸ� 8�ڸ� 16������ ǥ��

		for (int i = 0; i < bytes; i++)
			printf("%02X", buffer[i]);//���� ����Ʈ �� ��ŭ '2�ڸ� 16����'�� ǥ��. 8�ڸ��� 2�ڸ��� ǥ��.

		for (int i = 0; i < bytes; i++)
			if (isprint(buffer[i])) putchar(buffer[i]);//�μ� �����ϸ� 1byte �������� ���ڷ� ǥ��
			else putchar('.');//ǥ���� �Ұ��� �ϸ� .

		address += bytes;
		putchar('\n');
	}
	fclose(fp);	
	*/

	//���Ͽ� ������ 2������ ����, ���� ������ ���� 2������ ���� ���·� ����ϴ� ���α׷�
	int table[SIZE];
	int n, data;
	long pos;
	FILE *fp = NULL;

	init_table(table, SIZE);

	if ((fp = fopen("sample.dat", "wb")) == NULL) { //���� ������ ���� ���� open
		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}

	fwrite(table, sizeof(int), SIZE, fp);//�ּ�: table�� intũ�� ��ŭ 1000���� ����. ������ �׸�� ��ȯ
	fclose(fp);
	
	if ((fp = fopen("sample.dat", "rb")) == NULL) { //���� ������ �б� ���� open
		fprintf(stderr, "�Է��� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}

	while (1) {
		printf("���Ͽ��� ��ġ�� �Է��Ͻʽÿ�(0���� %d, ���� -1): ", SIZE - 1);
		scanf("%d", &n);///1000�� �Է��ϸ�..�׷��� 999������ �̵� 
		if (n == -1) break;
		pos = (long)n * sizeof(int);//��ġ  ex)3�̸� 4byte * 3 
		fseek(fp, pos, SEEK_SET);//fp�� pos ��ġ�� �̵�. SEEK_SET�� ���� ������ ó���� �������� �̵��Ѵٴ� ��. 
		fread(&data, sizeof(int), 1, fp); //fp��ġ���� intũ�⸸ŭ �ϳ��� �о data ������ ����. 
		printf("%d ��ġ�� ���� %d �Դϴ�.\n", n, data);
	}
	fclose(fp);

	return 0;
}

void init_table(int table[], int size)
{
	for (int i = 0; i < size; i++)
		table[i] = i*i;
}