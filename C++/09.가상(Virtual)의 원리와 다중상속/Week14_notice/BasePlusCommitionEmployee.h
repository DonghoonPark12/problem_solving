#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
using namespace std;

#include "CommisionEmployee.h"

class BasePlusCommisionEmployee : public CommitionEmployee
{
private:
	double baseSalary;
public:
	BasePlusCommisionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0, double = 0.0);
	//~BasePlusCommisionEmployee();

	void setBaseSalary(double);
	double getBaseSalary() const;
	
	virtual double earnings() const; //override
	virtual void print() const; //override
};
#endif // !BASEPLUS_H

