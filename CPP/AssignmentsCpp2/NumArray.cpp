/*
 Program Name: NumArray.cpp
 Author: Nathan Caron
 Assignment #7
 Date: 4/16/14
 Purpose: Dynamically create array of numbers and show high/low/ave.
*/

#include "NumArray.h"
#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu();

int main()
{
	int qty, pos;
	char choice;
	
	do{
		cout << "\nHow many numbers do you want to use? ";
		cin >> qty;
		if(qty <= 0 || qty > 100)
		cout << "\nError, must be number between 1-100. :";
	}while(qty <= 0 || qty > 100);
	
	numArray n(qty);
	
	do{
		displayMenu();
		cin >> choice;
		
	while(toupper(choice) < 'A' || toupper(choice) > 'F')
	{
		cout << "Invalid entry, please make a choice "
		     << "in the range A through F: ";
		cin >> choice;
	}
	
	
	switch(choice)
	{
		case 'a':
		case 'A': do{
				  cout << "\nEnter a position:(1-" << qty << ")";
				  cin >> pos;
				  if(pos > qty || pos < 1)
				  cout << "\nInvalid position! ";
				  }while(pos > qty || pos < 1);
				  pos -= 1;
				  n.setNum(pos);
		break;
		
		case 'b':
		case 'B':do{
				 cout << "\nWhich position do you want to display? ";
				 cin >> pos;
				 if(pos > qty || pos < 1)
				 cout << "\nInvalid position! ";
				 }while(pos > qty || pos < 1);
				 pos -= 1;
				 n.getNum(pos);
		break;
		
		case 'c':
		case 'C': cout << "\nThe Highest value is: " << n.getHigh();
		break;
		
		case 'd':
		case 'D': cout << "\nThe Lowest value is: " << n.getLow();
		break;
		
		case 'e':
		case 'E': cout << "\nThe Average of all values is: "
					   << n.getAve();
		break;
	}
		
	}while(toupper(choice) != 'F');
	
	
	return 0;
}



void displayMenu()
{
    cout << "\nMenu" << "\n";
    cout << "=====================\n";
    cout << "\t a) Store number in a position\n";
    cout << "\t b) Display a number from a position\n";
    cout << "\t c) Display Highest value stored\n";
    cout << "\t d) Display Lowest value stored\n";
    cout << "\t e) Display Average value of all numbers\n";
    cout << "\t f) Exit the program\n";
    cout << "Enter your choice: ";
}
