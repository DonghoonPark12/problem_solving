// Employee(근로자) class 정의
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
//#include "Date.h" // class 복합 관계(Composition)에 이용할 헤더파일 include

class Employee
{
public:
	// const char * const: 이름 변수와 주소 모두 constant
	//Employee(const char * const, const char * const, const Date &, const Date &); // 근로자 class 생성자 선언
	//void print() const; // 정보 출력 함수
	//~Employee(); // 소멸자 선언

	Employee(const char* const, const char* const);
	~Employee();
	const char *getFirstName() const;
	const char *getLastName() const;

	static int getCount();
private:
	//char firstName[25]; // 근로자의 이름 private 배열 선언
	//char lastName[25]; // 근로자의 성 private 배열 선언
	//const Date birthDate; // 근로자의 생일 private 클래스 Date object
	//const Date hireDate; // 근로자의 고용일 private 클래스 Date object

	char *firstName;
	char *lastName;

	int count;
};

#endif