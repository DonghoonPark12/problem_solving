#ifndef COMMITION_H
#define COMMITION_H
#include <string>
using namespace std;

#include "Employee.h"

class CommitionEmployee : public Employee{
private:
	double grossscales;
	double commitionRate;

public:
	CommitionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);

	void setGrossSales(double);
	double getGrossSales() const;

	void setCommitionRate(double);
	double getCommitionRate() const;

	virtual double earnings() const; 
	virtual void print() const;
};

#endif