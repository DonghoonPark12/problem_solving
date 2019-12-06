#ifndef COMMITION_H
#define COMMITION_H
#include <string>
using namespace std;

class CommitionEmployee {
//protected:
private:
	string firstname;
	string lastname;
	string SocialSecurityNumber;
	double grossscales;
	double commitionRate;

public:
	CommitionEmployee(const string&, const string&, const string&, double = 0.0, double = 0.0);
	~CommitionEmployee();
	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSocialSecurityNumber(const string&);
	string getSocialSecurityNumber() const;

	void setGrossSales(double);
	double getGrossSales() const;

	void setCommitionRate(double);
	double getCommitionRate() const;

	virtual double earnings() const; 
	virtual void print() const;
};

#endif