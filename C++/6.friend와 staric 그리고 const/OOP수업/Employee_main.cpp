#include <iostream>
#include "Employee.h"
using namespace std;

//int main() {
//	// Employee의 object manager에서 이용할 
//	// Date object 두개 선언
//	Date birth(7, 24, 1949);
//	Date hire(3, 12, 1988);
//
//	// 위 두 Date object를 사용한 Employee의 object manager 선언
//	Employee manager("Bob", "Blue", birth, hire);
//
//	cout << endl;
//	manager.print();
//
//	// Date 객체의 유효성 검사 확인
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
