#ifndef SALARIED_H
#define SALARIED_H
#include <string>
using namespace std;

#include "Employee.h"

class SalariedEmployee : public Employee {
private:
	double weekSalary;
public:
	SalariedEmployee(const string&, const string&, const string&, double = 0.0);

	void setweeklySalary(double);
	double getweekSalary() const;

	virtual double earnings() const; //pure virtual function, that makes Employee class as 'pure virtual base class'.
	virtual void print() const;
};

#endif // !EMPLOYEE_H
