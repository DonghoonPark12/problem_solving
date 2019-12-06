#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
private:
	string firstname;
	string lastname;
	string SocialSecurityNumber;
public:
	Employee(const string&, const string&, const string&);

	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSocialSecurityNumber(const string&);
	string getSocialSecurityNumber() const;

	virtual double earnings() const = 0; //pure virtual function, that makes Employee class as 'pure virtual base class'.
	virtual void print() const;
};

#endif // !EMPLOYEE_H
