// �ٷ��� class ��� �Լ� ����
#include <iostream>
#include <cstring>
using namespace std;

#include "Employee.h" // �ٷ��� class ������� �̿�

//#pragma warning(disable: 4996) // strncpy warning ����
//
//// �ٷ��� ������ ����, input�� �̸�, ��, ����, �����
//Employee::Employee(const char * const first, const char * const last, const Date &dateOfBirth, const Date &dateOfHire)
//	:birthDate(dateOfBirth), hireDate(dateOfHire)
//{
//	int length = strlen(first); // length�� �̸��� ����
//	length = (length < 25 ? length : 24); // �̸��� ���̰� 25���� ������ �״��
//	                                      // �ƴ϶�� 24��
//	strncpy(firstName, first, length); // firstName private �迭�� input first�� ���̸�ŭ ����
//	firstName[length] = NULL; // �̸� private �迭�� ���� ǥ��
//
//	length = strlen(last); // length�� ���� ����
//	length = (length < 25 ? length : 24); // ���� ���̰� 25���� ������ �״��
//	                                      // �ƴ϶�� 24��
//	strncpy(lastName, last, length); // lastName private �迭�� input last�� ���̸�ŭ ����
//	lastName[length] = '\0'; // �� private �迭�� ���� ǥ��
//
//	// Employee object�� ���� Ȯ��
//	cout << "Employee object constructor: "
//		<< firstName << ' ' << lastName << endl;
//}
//
//// ��, �̸�, ����, ����� ��� �Լ� ����
//void Employee::print() const {
//	cout << lastName << ", " << firstName << "\n  Hired: ";
//	hireDate.print();
//	cout << "  Birthday: ";
//	birthDate.print();
//	cout << endl;
//}
//
//// �ٷ��� �Ҹ��� ����
//Employee::~Employee() {
//	// Employee object�� �Ҹ� Ȯ��
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
