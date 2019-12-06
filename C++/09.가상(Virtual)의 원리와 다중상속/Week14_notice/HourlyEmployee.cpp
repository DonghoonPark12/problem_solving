#include <iostream>
using namespace std;
#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(const string& first, const string& last, const string& ssn, double houlywage, double hoursworked)
	:Employee(first, last, ssn)
{
	setwage(houlywage);
	setHour(hoursworked);
}

void HourlyEmployee::setwage(double houlywage)
{
	wage = houlywage < 0.0 ? 0.0 : houlywage;
}

double HourlyEmployee::getwage() const
{
	return wage;
}

void HourlyEmployee::setHour(double hoursworked)
{
	hours = ((hoursworked >= 0.0) && (hoursworked <= 168.0)) ? hoursworked : 0.0;
}

double HourlyEmployee::getHour() const
{
	return hours;
}

double HourlyEmployee::earnings() const
{
	if (getHour() <= 40)
		return getwage() * getHour();
	else
		return 40 * getwage() + ((getHour() - 40) * getwage() * 1.5);
}

void HourlyEmployee::print() const
{
	cout << "hourly employee: ";
	Employee::print();
	cout << "\nhouly wage : " << getwage() <<
		"; hours worked : " << getHour();
}





