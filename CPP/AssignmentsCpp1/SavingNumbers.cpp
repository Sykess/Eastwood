// Program Name: SavingNumbers.cpp
// Author: Nathan Caron
// Assignment #2
// Date: 10/06/06
// Purpose: Saves 5 numbers to a file

#include <iostream>
#include <fstream> //needed for file I/O
using namespace std;

int main()
{	
	double num1, num2, num3, num4, num5;
	ofstream outFile;

	cout << "\nEnter number 1 :";
	cin >> num1;

	cout << "\nEnter number 2 :";
	cin >> num2;

	cout << "\nEnter number 3 :";
	cin >> num3;

	cout << "\nEnter number 4 :";
	cin >> num4;

	cout << "\nEnter number 5 :";
	cin >> num5;

	outFile.open("SavedNumbers.dat"); //opens a file for output


	outFile << num1 << endl << num2 << endl << num3 << endl << num4 << endl << num5;

	outFile.close();



	return 0;
}