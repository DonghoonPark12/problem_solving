#include <iostream>
using namespace std;

#include <iomanip>
#include "CommisionEmployee.h"

int main() {
	CommitionEmployee employee("Sue", "jones", "222-22-2222", 10000, .06);

	cout << fixed << setprecision(2);
	cout << "Employee information obtained by get functions: \n" << endl;
	cout << "First Name is" << employee.getFirstName() << endl;
	cout << employee.getLastName() << endl;
	cout << employee.getSocialSecurityNumber() << endl;
	cout << employee.getGrossSales() << endl;
	cout << employee.getCommitionRate() << endl;
	employee.setGrossSales(8000);
	employee.setCommitionRate(.1);

	employee.print();
	employee.earnings();

	return 0;
}