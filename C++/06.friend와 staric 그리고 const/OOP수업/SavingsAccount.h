// Header file for class SavingsAccount.
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount
{
public:
	// constructor sets balance to value greater than or equal to zero
	SavingsAccount(double b)
	{
		savingsBalance = (b >= 0.0 ? b : 0.0);
	} // end SavingsAccount constructor

	void calculateMonthlyInterest(); // calculate interest; add to balance
	static void modifyInterestRate(double);
	void printBalance() const;
private:
	double savingsBalance; // the account balance
	static double annualInterestRate; // the interest rate of all accounts
}; // end class SavingsAccount

#endif