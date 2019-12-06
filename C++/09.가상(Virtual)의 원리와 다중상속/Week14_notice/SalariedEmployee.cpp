#include <iostream>
using namespace std;
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(const string& first, const string& last, const string& ssn, double salary)
	:Employee(first, last, ssn)
{
	setweeklySalary(salary);
}

void SalariedEmployee::setweeklySalary(double salary) {
	weekSalary = (salary < 0.0) ? 0.0 : salary;
}

double SalariedEmployee::getweekSalary() const {
	return weekSalary;
}

double SalariedEmployee::earnings() const {
	return getweekSalary();
}

void SalariedEmployee::print() const {
	cout << "salaried employee: ";
	Employee::print();
	cout << "\nweekly salary: " << getweekSalary();
}