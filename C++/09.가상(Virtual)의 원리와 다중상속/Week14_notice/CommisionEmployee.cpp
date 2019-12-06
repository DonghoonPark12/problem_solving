#include "CommisionEmployee.h"
#include <iostream>
using namespace std;
CommitionEmployee::CommitionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
	:Employee(first, last, ssn)
{
	setGrossSales(sales);
	setCommitionRate(rate);

	//cout << "CommitionEmployee Constructor: " << endl;
	//print();
	//cout << "'\n\n";
}

//CommitionEmployee::~CommitionEmployee()
//{
	//cout << "CommitionEmployee Destructor: " << endl;
	//print();
	//cout << "'\n\n";
//}

void CommitionEmployee::setGrossSales(double sales){
	grossscales = (sales < 0.0) ? 0.0 : sales;
}

double CommitionEmployee::getGrossSales() const{
	return grossscales;
}

void CommitionEmployee::setCommitionRate(double rate){
	commitionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}

double CommitionEmployee::getCommitionRate() const{
	return commitionRate;
}

double CommitionEmployee::earnings() const{
	return getCommitionRate() * getGrossSales();
}

void CommitionEmployee::print() const{
	cout << "Commision employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales() << '\n';
	cout << "\ncommision rate: " << getCommitionRate() << '\n';;
}

