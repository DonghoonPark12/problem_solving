#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_ID_LEN 20
#define MAX_NAME_LEN 30
#define MAX_ADDR_LEN 50

//typedef struct _Member {
//	char id[MAX_ID_LEN + 1];
//	char name[MAX_NAME_LEN + 1];
//	char addr[MAX_ADDR_LEN + 1];
//	int age;
//	int gender;
//}Member;

//typedef struct _Student {
//	char name[MAX_NAME_LEN + 1];
//	int iq;
//}Student;
//void Study(Student stu);

typedef struct _Point {
	double x;
	double y;
}Point;
void ViewPoint(Point *point);

int main() {

	/* ����ü member ���� ���� */
	//Member member = { "" };
	//strcpy(member.id, "jejutour");
	//strcpy(member.name, "�����");
	//strcpy(member.addr, "���ֵ� ���ֽ� �ֿ��� ����");
	//member.age = 20;
	//member.gender = 1;
	//printf("���̵�: %s �̸�: %s\n", member.id, member.name);
	//printf("�ּ�: %s ����: %d ����: %d\n", member.addr, member.age, member.gender);

	/* ����ü ���� ������ �Է����ڷ� ������ �� ���� */
	//Student stu = { "ȫ�浿", 100 };
	//Study(stu);
	//printf("main �̸�: %s ����ť: %d\n", stu.name, stu.iq);

	/* ����ü �����ͷ� ��� ��� */
	Point pt = { 2,3 };
	ViewPoint(&pt);
	return 0;
}

void Study(Student stu) {
	printf("%s �����ϴ�.\n", stu.name);
	stu.iq++;
	printf("IQ:%d\n", stu.iq);
}