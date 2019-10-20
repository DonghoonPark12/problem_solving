// 근로자 class 멤버 함수 정의
#include <iostream>
#include <cstring>
using namespace std;

#include "Employee.h" // 근로자 class 헤더파일 이용

//#pragma warning(disable: 4996) // strncpy warning 방지
//
//// 근로자 생성자 정의, input은 이름, 성, 생일, 고용일
//Employee::Employee(const char * const first, const char * const last, const Date &dateOfBirth, const Date &dateOfHire)
//	:birthDate(dateOfBirth), hireDate(dateOfHire)
//{
//	int length = strlen(first); // length는 이름의 길이
//	length = (length < 25 ? length : 24); // 이름의 길이가 25보다 작으면 그대로
//	                                      // 아니라면 24로
//	strncpy(firstName, first, length); // firstName private 배열에 input first의 길이만큼 복사
//	firstName[length] = NULL; // 이름 private 배열의 끝을 표시
//
//	length = strlen(last); // length는 성의 길이
//	length = (length < 25 ? length : 24); // 성의 길이가 25보다 작으면 그대로
//	                                      // 아니라면 24로
//	strncpy(lastName, last, length); // lastName private 배열에 input last의 길이만큼 복사
//	lastName[length] = '\0'; // 성 private 배열의 끝을 표시
//
//	// Employee object의 생성 확인
//	cout << "Employee object constructor: "
//		<< firstName << ' ' << lastName << endl;
//}
//
//// 성, 이름, 생일, 고용일 출력 함수 정의
//void Employee::print() const {
//	cout << lastName << ", " << firstName << "\n  Hired: ";
//	hireDate.print();
//	cout << "  Birthday: ";
//	birthDate.print();
//	cout << endl;
//}
//
//// 근로자 소멸자 정의
//Employee::~Employee() {
//	// Employee object의 소멸 확인
//	cout << "Employee object destructor: "
//		<< lastName << ", " << firstName << endl;
//}

int Employee::count = 0;

int Employee::getCount() {
	return count;
}

Employee::Employee(const char * const first, const char *const last) {
	firstName = new char[strlen(first) + 1];
	strcpy(firstName, first);

	lastName = new char[strlen(last) + 1];
	strcpy(lastName, last);

	count++;

	cout << "Employee constructor for " << firstName << " " << lastName <<
		" called." << endl;
}

Employee::~Employee() {
	cout << "Employee destructor for " << firstName << " " << lastName <<
		" called." << endl;

	delete[] firstName;
	delete[] lastName;

	count--;
}

const char *Employee::getFirstName() const {
	return firstName;
}

const char *Employee::getLastName() const {
	return lastName;
}
