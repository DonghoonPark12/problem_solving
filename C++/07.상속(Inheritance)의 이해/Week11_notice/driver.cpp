#include <iostream>
#include <iomanip>
using namespace std;
#include "BasePlusCommitionEmployee.h"

int main() {
	cout << fixed << setprecision(2);

	{
		CommitionEmployee employee1("Bob", "jones", "222-22-2222", 10000, .06);
	}
	cout << '\n';
	BasePlusCommisionEmployee employee2("Lisa", "preshel", "222-22-2222", 10000, .06, 300);

	cout << '\n';
	BasePlusCommisionEmployee employee3("Mark", "tweins", "222-22-2222", 10000, .06, 300);

	cout << endl;
	return 0;
}