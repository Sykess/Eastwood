// Program Name: DataSizes.cpp
// Author: Nathan Caron
// Assignment #2
// Date: 9/22/06
// Purpose: Calculate how many bytes char, int, float, and double use

#include <iostream>
using namespace std;

int main()
{

	cout << "\nThe size of an integer is " << sizeof(int) << " bytes.";
	cout << "\nThe size of a float is " << sizeof(float) << " bytes.";
	cout << "\nThe size of a char is " << sizeof(char) << " byte.";
	cout << "\nThe size of a double is " << sizeof(double) << " bytes.";

	cout << endl << endl;

	return 0;
}
