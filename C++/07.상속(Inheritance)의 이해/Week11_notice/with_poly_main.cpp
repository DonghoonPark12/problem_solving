#include <iostream>
using namespace std;

#include <iomanip>
#include "CommisionEmployee.h"
#include "BasePlusCommitionEmployee.h"

int main() {
	CommitionEmployee cemployee("Sue", "jones", "222-22-2222", 10000, .06);

	CommitionEmployee* cptr = 0;

	BasePlusCommisionEmployee bemployee("Bob", "Lewis", "333-33-3333", 20000, .07, 300);

	BasePlusCommisionEmployee* bptr = 0;

	cout << fixed << setprecision(2);
	cemployee.print();
	cout << '\n';

	bemployee.print();
	cout << '\n\n';

	cptr = &cemployee;
	cptr->print();
	cout << '\n';

	bptr = &bemployee;
	bptr->print();
	cout << '\n';

	cptr = &bemployee; //기본클래스 포인터로 파생 클래스 포인터 가리킴
	cptr->print();
	cout << '\n';
	return 0;
}