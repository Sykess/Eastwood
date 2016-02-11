/*
 Program Name: ships.h
 Author: Nathan Caron
 Assignment #8
 Date: 5/1/14
 Purpose: Demonstrate class inheritance.
*/

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

//BASE CLASS
class Ship
{
	private:
		string name;
		string year;
	public:
		Ship();
		Ship(string, string);
		bool setName(string);
		bool setYear(string);
		string getName();
		string getYear();
		virtual void print();
};

Ship::Ship()
{
	name = "";
	year = "";
}

Ship::Ship(string n, string y)
{
	name = n;
	year = y;
}

bool Ship::setName(string n)
{
	name = n;
	return true;
}

bool Ship::setYear(string y)
{
	year = y;
	return true;
}

string Ship::getName() { return name; }

string Ship::getYear() { return year; }

void Ship::print()
{
	cout << "\nThe name of the ship is "
		 << name << " and the year it was built was "
		 << year << endl;
}

///////////////////////////////////////////////////////
//Derived class 1
class CruiseShip : public Ship
{
	private:
		int maxPassengers;
	public:
		CruiseShip();
		CruiseShip(string, string, int);
		bool setPass(int);
		int getPass();
		void print();
};

CruiseShip::CruiseShip() : Ship() { maxPassengers = 0; }

CruiseShip::CruiseShip(string n, string y, int max)
					: Ship(n, y)
{
	maxPassengers = max;
}

bool CruiseShip::setPass(int m)
{
	if(m < 0)
		return false;
	maxPassengers = m;
	return true;
}

int CruiseShip::getPass() { return maxPassengers; }

void CruiseShip::print()
{
	cout << "\nThe Cruise Ship's name is " << getName()
		 << " and the max passengers is " << maxPassengers
		 << endl;
}

/////////////////////////////////////////////////////////////
//Derived class 2

class CargoShip : public Ship
{
	private:
		int capacity;
	public:
		CargoShip();
		CargoShip(string, string, int);
		bool setCapacity(int);
		int getCapacity();
		void print();
};

CargoShip::CargoShip() : Ship() { capacity = 0; }

CargoShip::CargoShip(string n, string y, int cap)
			      : Ship(n, y)
{
	capacity = cap;
}

bool CargoShip::setCapacity(int cap)
{
	if(cap < 0)
		return false;
	capacity = cap;
	return true;
}

int CargoShip::getCapacity() { return capacity; }

void CargoShip::print()
{
	cout << "\nThe Cargo Ship's name is " << getName()
		 << " and the capacity in tonnage is "
		 << capacity << endl;
}
