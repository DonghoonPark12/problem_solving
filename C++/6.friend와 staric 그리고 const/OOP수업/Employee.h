// Employee(�ٷ���) class ����
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
//#include "Date.h" // class ���� ����(Composition)�� �̿��� ������� include

class Employee
{
public:
	// const char * const: �̸� ������ �ּ� ��� constant
	//Employee(const char * const, const char * const, const Date &, const Date &); // �ٷ��� class ������ ����
	//void print() const; // ���� ��� �Լ�
	//~Employee(); // �Ҹ��� ����

	Employee(const char* const, const char* const);
	~Employee();
	const char *getFirstName() const;
	const char *getLastName() const;

	static int getCount();
private:
	//char firstName[25]; // �ٷ����� �̸� private �迭 ����
	//char lastName[25]; // �ٷ����� �� private �迭 ����
	//const Date birthDate; // �ٷ����� ���� private Ŭ���� Date object
	//const Date hireDate; // �ٷ����� ����� private Ŭ���� Date object

	char *firstName;
	char *lastName;

	int count;
};

#endif