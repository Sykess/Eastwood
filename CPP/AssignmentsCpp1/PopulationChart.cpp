// Program Name: PopulationChart.cpp
// Author: Nathan Caron
// Assignment #4
// Date: 11/01/06
// Purpose: Reads populations from a file and converts it to *'s

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream inFile;
	int year = 1900, population;

	inFile.open("people.dat");
	if(inFile.fail()) //makes sure file exists
		return -1;

	cout << "\nPrairieville Population Growth"
	     << "\n(each * represents 1,000 people)\n";

	while(!inFile.eof())
	{
		inFile >> population;

		if(population > 0) //makes sure population exists to display that year and
						   //keeps the empty line at end of file from creating a year
		cout << endl << year << " ";

		population /= 1000;

		while (population >= 1) //adds a * for every 1000 people
		{
			cout << "*";
			population--;
		}

		year += 20;
	}

	inFile.close();

	cout << endl << endl;

	return 0;
}