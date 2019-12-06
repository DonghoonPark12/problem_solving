#include <iostream>
using namespace std;
#include "Employee.h"

Employee::Employee(const string &first, const string &last, const string &ssn)
	:firstname(first), lastname(last), SocialSecurityNumber(ssn)
{}

void Employee::setFirstName(const string &first){
	firstname = first;
}

string Employee::getFirstName() const
{
	return firstname;
}

void Employee::setLastName(const string& last)
{
	lastname = last;
}

string Employee::getLastName() const
{
	return lastname;
}

void Employee::setSocialSecurityNumber(const string& ssn)
{
	SocialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const
{
	return SocialSecurityNumber;
}

void Employee::print() const {
	cout << "Commision employee: " << getFirstName() << ' ' << getLastName() << '\n';
	cout << "social security number: " << getSocialSecurityNumber();
}

