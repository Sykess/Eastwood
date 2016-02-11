/*
 Program Name: ships.cpp
 Author: Nathan Caron
 Assignment #8
 Date: 5/1/14
 Purpose: Demonstrate class inheritance.
*/

#include <iostream>
#include <string>
#include "ships.h"

using namespace std;


int main()
{
	const int NUM_SHIPS = 3;
	
	Ship *ships[NUM_SHIPS] = 
	{
		new Ship("Titanic", "1912"),
		new CruiseShip("SS Disney", "2008", 5000),
		new CargoShip("SS Car-go", "1999", 856)
	};
	
	
	for(int x = 0; x < 3; x++)
	{
		cout << "\nShip # " << x + 1 << endl;
		ships[x]->print();
		cout << endl;
	}
	
	
	for(int x=0; x < NUM_SHIPS; x++)
	delete ships[x];
	
	return 0;
}


