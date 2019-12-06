#include "BasePlusCommitionEmployee.h"
#include <iostream>
using namespace std;

BasePlusCommisionEmployee::BasePlusCommisionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate, double salary)
	:CommitionEmployee(first, last, ssn, sales, rate)
{
	setBaseSalary(salary);

	//cout << "BasePlusCommisionEmployee Constructor: " << endl;
	//print();
	//cout << "'\n\n";
}
//BasePlusCommisionEmployee::~BasePlusCommisionEmployee()
//{
	//cout << "BasePlusCommisionEmployee Destructor: " << endl;
	//print();
	//cout << "'\n\n";
//}

void BasePlusCommisionEmployee::setBaseSalary(double salary)
{
	baseSalary = (salary < 0.0) ? 0.0 : salary;
}

double BasePlusCommisionEmployee::getBaseSalary() const
{
	return baseSalary;
}

double BasePlusCommisionEmployee::earnings() const
{
	//return baseSalary + CommitionEmployee::getCommitionRate() + CommitionEmployee::getGrossSales();
	return baseSalary + CommitionEmployee::earnings();
}

void BasePlusCommisionEmployee::print() const
{
	//cout << "Commision employee: " << firstname << ' ' << lastname << endl;
	//cout << "social security number: " << SocialSecurityNumber << endl;
	//cout << "gross sales: " << grossscales << endl;
	//cout << "commision rate: " << commitionRate << endl;
	cout << "base-salaried ";
	CommitionEmployee::print();
	cout << "base salary: " << getBaseSalary()<<'\n';
}




