// Program Name: MonthlyPayments.cpp
// Author: Nathan Caron
// Assignment #2
// Date: 10/06/06
// Purpose: Calculates monthly payments, amount paid back, and interest paid


#include <iostream>
#include <iomanip> //allows setw use
#include <cmath> //allows use of exponents
using namespace std;


int main()
{
	int payments;
	double loanAmt, interestRate, payBack, monthlyPayment, interestPaid;

	cout << "\nEnter the number of payments you need to make on your loan: ";
	cin >> payments;

	cout << "\nEnter the amount of the loan: ";
	cin >> loanAmt;

	cout << "\nEnter the monthly interest rate in the form of a decimal: ";
	cin >> interestRate;

	monthlyPayment = ((interestRate * pow(1 + interestRate, payments))
		/(pow(1 + interestRate, payments) - 1)) * loanAmt;

	//rounds off decimals
	monthlyPayment = monthlyPayment * 100;
	monthlyPayment = monthlyPayment + 0.5;
	monthlyPayment = int(monthlyPayment);
	monthlyPayment = monthlyPayment / 100; 

	payBack = payments * monthlyPayment;

	//rounds off decimals
	payBack = payBack * 100;
	payBack = payBack + 0.5;
	payBack = int(payBack);
	payBack = payBack / 100; 

	interestRate = interestRate * 100;

	interestPaid = payBack - loanAmt;

	//forces 2 decimal places to be displayed
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);


	cout << "\nLoan Amount:               $ " << setw(9) << loanAmt;
	cout << "\nMonthly Interest Rate:       " << setw(8) << interestRate << "%";
	cout << "\nNumber of Payments:        $ " << setw(9) << payments;
	cout << "\nMonthly Payment:           $ " << setw(9) << monthlyPayment;
	cout << "\nAmount Paid Back:          $ " << setw(9) << payBack;
	cout << "\nInterest Paid:             $ " << setw(9) << interestPaid << "\n\n";
	

	return 0;
}

