#ifndef HOURLY_H
#define HOURLY_H
#include <string>
using namespace std;

#include "Employee.h"

class HourlyEmployee : public Employee {
private:
	double wage;
	double hours;
public:
	HourlyEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);

	void setwage(double);
	double getwage() const;

	void setHour(double);
	double getHour() const;

	virtual double earnings() const; //pure virtual function, that makes Employee class as 'pure virtual base class'.
	virtual void print() const;
};

#endif 
