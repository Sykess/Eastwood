// Program Name: OpeningNumbers.cpp
// Author: Nathan Caron
// Assignment #2
// Date: 10/06/06
// Purpose: Opens and adds 5 numbers from a file


#include <iostream>
#include <fstream> //needed for file I/O
using namespace std;


int main()
{	
	double num1, num2, num3, num4, num5;

	ifstream inFile;
	inFile.open("SavedNumbers.dat"); //opens file
		
	inFile >> num1;
	inFile >> num2;
	inFile >> num3;
	inFile >> num4;
	inFile >> num5;

	cout << "\nThe first number is " << num1;

	cout << "\nThe second number is " << num2;

	cout << "\nThe third number is " << num3;

	cout << "\nThe fourth number is " << num4;

	cout << "\nThe fifth number is " << num5;

	num1 = num1 + num2 + num3 + num4 + num5;

	cout << "\nThe sum of all five numbers is " << num1;


	cout << endl;

	inFile.close(); //closes file



	return 0;
}