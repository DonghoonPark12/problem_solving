#include "CommisionEmployee.h"
#include <iostream>
using namespace std;
CommitionEmployee::CommitionEmployee(const string& first, const string& last, const string& ssn, double sales, double rate)
	:firstname(first), lastname(last), SocialSecurityNumber(ssn)
{
	setGrossSales(sales);
	setCommitionRate(rate);

	//cout << "CommitionEmployee Constructor: " << endl;
	//print();
	//cout << "'\n\n";
}

CommitionEmployee::~CommitionEmployee()
{
	//cout << "CommitionEmployee Destructor: " << endl;
	//print();
	//cout << "'\n\n";
}

void CommitionEmployee::setFirstName(const string& first){
	firstname = first;
}

string CommitionEmployee::getFirstName() const{
	return firstname;
}

void CommitionEmployee::setLastName(const string& last){
	lastname = last;
}

string CommitionEmployee::getLastName() const{
	return lastname;
}

void CommitionEmployee::setSocialSecurityNumber(const string& ssn){
	SocialSecurityNumber = ssn;
}

string CommitionEmployee::getSocialSecurityNumber() const{
	return SocialSecurityNumber;
}

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
	cout << "Commision employee: " << getFirstName() << ' ' << getLastName() << '\n';
	cout << "social security number: " << getSocialSecurityNumber() << '\n';
	cout << "gross sales: " << getGrossSales() << '\n';
	cout << "commision rate: " << getCommitionRate() << '\n';
}

