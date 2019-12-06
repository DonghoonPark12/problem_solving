#include <iostream>
#include <iomanip>
#include <vector>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommisionEmployee.h"
#include "BasePlusCommitionEmployee.h"
using namespace std;

void virtualViaPointer(const Employee* const baseClassPtr) {
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings() << '\n\n';
}
void virtualViaReference(const Employee& baseClassRef) {
	baseClassRef.print();
	cout << "\nearned $" << baseClassRef.earnings() << '\n\n';
}

int main() {
	cout << fixed << setprecision(2);

	SalariedEmployee semployee("Jone", "jones", "111-22-2222", 800);

	//HourlyEmployee hemployee("karen", "Price", "222-22-2222", 16.75, 40);

	CommitionEmployee cemployee("Sue", "jones", "333-22-2222", 10000, .06);

	BasePlusCommisionEmployee bemployee("Bob", "Lewis", "444-33-3333", 20000, .07, 300);

	semployee.print();
	semployee.earnings();
	cout << "\n\n";
	//hemployee.print();
	//hemployee.earnings();
	//cout << "\n\n";
	cemployee.print();
	cemployee.earnings();
	cout << "\n\n";
	bemployee.print();
	bemployee.earnings();
	cout << "\n\n";

	vector<Employee*> employees(4);
	employees[0] = &semployee;
	//employees[1] = &hemployee;
	employees[2] = &cemployee;
	employees[3] = &bemployee;

	for (size_t i = 0; i < employees.size(); i++) {
		virtualViaPointer(employees[i]);
	}

	for (size_t i = 0; i < employees.size(); i++) {
		virtualViaReference(*employees[i]);
	}
	return 0;
}
