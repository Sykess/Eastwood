/*
 Program Name: Rational.cpp
 Author: Nathan Caron
 Assignment #6
 Date: 4/9/14
 Purpose: Do fraction work arithmetic 
 in a class object.
*/


#include "rational.h"


void displayMenu();

int main()
{
	rational frac;
	int num;
	int den;

	
	char choice;
	do
	{
		displayMenu();
		cin >> choice;
	while (toupper(choice) < 'A' || toupper(choice) > 'I') 
     {
        cout << "Incorrect entry, please make a choice "
             << "in the range of A through I:";
        cin >> choice;
   	 }
   	 
   	 switch(choice)
   	 {
   	 	case 'a':
   	 	case 'A':do{
   	 			cout << "\nEnter the numerator: ";
   	 			cin >> num;
   	 			}while(!num);
   	 			do{
   	 			cout << "\nEnter the denominator: ";
   	 			cin >> den;
   	 			}while(den == 0); // we can have negatives right?
   	 			frac.loadFracOne(num, den);
   	 		
   	 	break;
   	 	
   		case 'b':
   		case 'B':do{
   	 			cout << "\nEnter the numerator: ";
   	 			cin >> num;
   	 			}while(!num);
   	 			do{
   	 			cout << "\nEnter the denominator: ";
   	 			cin >> den;
   	 			}while(den == 0);
   	 			frac.loadFracTwo(num, den);
   			
   		break;
   		
   		case 'c':
   		case 'C': frac.add();
   		break;
   		
   		case 'd':
   		case 'D': frac.subtract();
   		break;
   		
   		case 'e':
   		case 'E': frac.multiply();
   		break;
   		
   		case 'f':
   		case 'F': frac.divide();
   		break;
   		
   		case 'g':
   		case 'G': frac.displayFractions();
   		break;
   		
   		case 'h':
   		case 'H': frac.displayDecimal();
   		
   	 	
   	 }
	}while (toupper(choice) != 'I');
	
	
	return 0;
}

void displayMenu()
{
    cout << "\nMenu" << "\n";
    cout << "=====================\n";
    cout << "\t a) Load Fraction 1:\n";
    cout << "\t b) Load Fraction 2:\n";
    cout << "\t c) Add Fractions 1 & 2:\n";
    cout << "\t d) Subtract Fraction 2 from 1:\n";
    cout << "\t e) Multiply Fractions 1 & 2:\n";
    cout << "\t f) Divide Fraction 1 by 2:\n";
    cout << "\t g) Display All 3 Fractions:\n";
    cout << "\t h) Show Floating point of Fractions:\n";
    cout << "\t i) Exit Program: \n";
    cout << "Enter your choice: ";
}
