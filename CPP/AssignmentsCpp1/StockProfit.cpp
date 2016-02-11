// Program Name: StockProfit.cpp
// Author: Nathan Caron
// Assignment #5
// Date: 11/15/06
// Purpose: Calculate profit from stocks.

#include <iostream>
using namespace std;

//function prototypes
bool validNumbers(int NS, double SP, double SC, double PP, double PC);
double calcProfit(int NS, double SP, double SC, double PP, double PC);
void displayData(double profit);


int main()
{
	int NS;
	double SP, SC, PP, PC, profit;
	bool valid;

	cout << "\nAfter entering the following data into this program, "
		 << "\nit will display your stock's profit or loss.";

	do{
		cout << "\n\nEnter your number of shares : ";
		cin >> NS;

		cout << "\nEnter the sale price per share : ";
		cin >> SP;

		cout << "\nEnter the sale commission paid : ";
		cin >> SC;

		cout << "\nEnter the purchase price per share : ";
		cin >> PP;

		cout << "\nEnter the purchase commission paid : ";
		cin >> PC;

		valid = validNumbers(NS, SP, SC, PP, PC);

		if (!valid)
			cout << "\nYou entered incorrect data, Number of shares must be "
				 << "\n at least 1, and all others must be greater than 0.";

	}while(!valid);

	profit = calcProfit(NS, SP, SC, PP, PC);

	displayData(profit);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////

bool validNumbers(int NS, double SP, double SC, double PP, double PC)
{
	if ((NS < 1) || (SP < 0) || (SC < 0) || (PP < 0) || (PC < 0))
		return false;

	return true;
}

/////////////////////////////////////////////////////////////////////////////

double calcProfit(int NS, double SP, double SC, double PP, double PC)
{
	return ((NS * SP) - SC) - ((NS * PP) + PC);
}

/////////////////////////////////////////////////////////////////////////////

void displayData(double profit)
{
	if (profit >= 0)
		cout << "\nYour total profit is : " << profit;
	else
		cout << "\nYour total loss is : " << profit - 2 * profit;
	cout << endl << endl;
}

