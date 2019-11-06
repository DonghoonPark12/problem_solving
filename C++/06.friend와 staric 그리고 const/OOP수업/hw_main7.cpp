// Driver program for class SavingsAccount.
#include <iostream> 
using std::cout;
using std::endl;

#include <iomanip> 
using std::setw;

#include "SavingsAccount.h" // SavingsAccount class definition

int main()
{
	SavingsAccount saver1(2000.0);
	SavingsAccount saver2(3000.0);

	SavingsAccount::modifyInterestRate(3); // change interest rate

	cout << "Initial balances:\nSaver 1: ";
	saver1.printBalance();
	cout << "\tSaver 2: ";
	saver2.printBalance();

	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	cout << "\n\nBalances after 1 month's interest applied at .03:\n"
		<< "Saver 1: ";
	saver1.printBalance();
	cout << "\tSaver 2: ";
	saver2.printBalance();

	SavingsAccount::modifyInterestRate(4); // change interest rate
	saver1.calculateMonthlyInterest();
	saver2.calculateMonthlyInterest();

	cout << "\n\nBalances after 1 month's interest applied at .04:\n"
		<< "Saver 1: ";
	saver1.printBalance();
	cout << "\tSaver 2: ";
	saver2.printBalance();
	cout << endl;
	return 0;
} // end main