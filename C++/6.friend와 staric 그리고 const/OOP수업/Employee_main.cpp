#include <iostream>
#include "Employee.h"
using namespace std;

//int main() {
//	// Employee�� object manager���� �̿��� 
//	// Date object �ΰ� ����
//	Date birth(7, 24, 1949);
//	Date hire(3, 12, 1988);
//
//	// �� �� Date object�� ����� Employee�� object manager ����
//	Employee manager("Bob", "Blue", birth, hire);
//
//	cout << endl;
//	manager.print();
//
//	// Date ��ü�� ��ȿ�� �˻� Ȯ��
//	cout << "\nTest Date constructor with invalid values:" << endl;
//	Date lastDayOff(14, 35, 1994);
//	cout << endl;
//	return 0;
//}

int main() {
	cout << "Number of employtt before instantiation of any object is" <<
		Employee::getCount() << endl;

	Employee *e1Ptr = new Employee("Susan", "Baker");
	Employee *e2Ptr = new Employee("Robert", "Jones");

	cout << "Number of Employee after object allocation" << e1Ptr->getCount();

	e1Ptr.
	delete e1Ptr;
	e1Ptr = 0;
	delete e2Ptr;
	e2Ptr = 0;

	cout << "Number of employees after object are deleted is " << Employee::getCount()
		<< endl;

	return 0;
}
