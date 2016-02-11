// Program Name: RestaurantBill.cpp
// Author: Nathan Caron
// Assignment #1
// Date: 9/22/06
// Purpose: Calculate tax and tip of a meal

#include <iostream>
using namespace std;

int main()
{
	float meal, tip, tax;

	cout << "\nEnter the meal charge: ";
	cin >> meal;

	tax = meal * 0.0675; //calculates tax

	//rounds off decimals
	tax = tax * 100;
	tax = tax + 0.5;
	tax = int(tax);
	tax = tax / 100; 

	//forces 2 decimal places to be displayed
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "\nThe tax is: " << tax;

	tip = (tax + meal) * 0.15;

	tip = tip * 100;
	tip = tip + 0.5;
	tip = int(tip);
	tip = tip / 100;

	cout << "\nThe tip amount is: " << tip; 

	meal = tip + tax + meal;

	meal = meal * 100;
	meal = meal + 0.5;
	meal = int(meal);
	meal = meal / 100;

	cout << "\nThe total cost is: " << meal;

	cout << endl << endl;

	return 0;
}