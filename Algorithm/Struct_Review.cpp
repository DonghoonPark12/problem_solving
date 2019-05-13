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

	/* 구조체 member 형식 정의 */
	//Member member = { "" };
	//strcpy(member.id, "jejutour");
	//strcpy(member.name, "장언휴");
	//strcpy(member.addr, "제주도 제주시 애월읍 고내리");
	//member.age = 20;
	//member.gender = 1;
	//printf("아이디: %s 이름: %s\n", member.id, member.name);
	//printf("주소: %s 나이: %d 성별: %d\n", member.addr, member.age, member.gender);

	/* 구조체 형식 변수를 입력인자로 전달할 때 버그 */
	//Student stu = { "홍길동", 100 };
	//Study(stu);
	//printf("main 이름: %s 아이큐: %d\n", stu.name, stu.iq);

	/* 구조체 포인터로 멤버 사용 */
	Point pt = { 2,3 };
	ViewPoint(&pt);
	return 0;
}

void Study(Student stu) {
	printf("%s 공부하다.\n", stu.name);
	stu.iq++;
	printf("IQ:%d\n", stu.iq);
}