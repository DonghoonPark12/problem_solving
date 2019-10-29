// Member-function defintions for class SavingsAccount.
#include <iostream> 
using std::cout;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "SavingsAccount.h" // SavingsAccount class definition

// initialize static data member
double SavingsAccount::annualInterestRate = 0.0;

// calculate monthly interest for this savings account
void SavingsAccount::calculateMonthlyInterest()
{
	savingsBalance += savingsBalance * (annualInterestRate / 12.0);
} // end function calculateMonthlyInterest

// function for modifying static member variable annualInterestRate
void SavingsAccount::modifyInterestRate(double i)
{
	annualInterestRate = (i >= 0.0 && i <= 1.0) ? i : 0.03;
} // end function modifyInterestRate

// prints balance of the savings account
void SavingsAccount::printBalance() const
{
	cout << fixed << '$' << setprecision(2) << savingsBalance;
} // end function printBalance
