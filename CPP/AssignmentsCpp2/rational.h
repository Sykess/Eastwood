/*
 Program Name: Rational.h
 Author: Nathan Caron
 Assignment #6
 Date: 4/9/14
 Purpose: Do fraction work arithmetic 
 in a class object.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class rational
{
	private:
		int fracs[2][3];
		
	public:
		void reduce(int &n, int &d);
		//constructors
		rational();
		rational(int, int, int, int);
		//mutators
		bool loadFracOne(int, int);
		bool loadFracTwo(int, int);
		bool add();
		bool subtract();
		bool multiply();
		bool divide();
		//accessors
		void displayFractions();
		void displayDecimal();
		//destructor
		~rational();
};
/////////////////////////////////////////////////////////////////////
void rational::reduce(int &n, int &d)
{
	
	if(n * d > 0)
	{
	for(int x = n * d; x > 1; x--)
	{
		if((n % x == 0) && (d % x == 0))
		{
			n /= x;
			d /= x;
		}
	}
	
	}
	//for negative numbers
	if(n * d < 0)
	{
	for(int x = n * d; x < -1; x++)
	{
		if((n % x == 0) && (d % x == 0))
		{
			n /= x;
			d /= x;
		}
	}
	}

}
/////////////////////////////////////////////////////////////////////
void rational::displayFractions()
{
	cout << "\nFraction 1: " << fracs[0][0] << "/" << fracs[1][0]
		 <<"\nFraction 2: " << fracs[0][1] << "/" << fracs[1][1]
		 <<"\nFraction 3: " << fracs[0][2] << "/" << fracs[1][2];
	
}
//////////////////////////////////////////////////////////////////////
void rational::displayDecimal()
{
	double num;
	double den;
	num = fracs[0][0];
	den = fracs[1][0];
	cout << "\nFraction 1 in floating point format is: " 
	 << (num / den);
	num = fracs[0][1];
	den = fracs[1][1];
	cout << "\nFraction 2 in floating point format is: "
	 << (num / den);
	num = fracs[0][2];
	den = fracs[1][2];
	cout << "\nFraction 3 in floating point format is: "
	 << (num / den);
}
/////////////////////////////////////////////////////////////////////
rational::rational()
{
	fracs[0][0] = 0;
	fracs[1][0] = 1;
	fracs[0][1] = 0;
	fracs[1][1] = 1;
	fracs[0][2] = 0;
	fracs[1][2] = 1;
}
/////////////////////////////////////////////////////////////////////
rational::rational(int n1, int d1, int n2, int d2)
{
	fracs[0][0] = n1;
	fracs[1][0] = d1;
	fracs[0][1] = n2;
	fracs[1][1] = d2;
}
/////////////////////////////////////////////////////////////////////
bool rational::loadFracOne(int n, int d)
{
	fracs[0][0] = n;
	fracs[1][0] = d;
	//if num and den both negative, -/- = +, so...
	if(fracs[0][0] < 0 && fracs[1][0] < 0)
	{
	fracs[0][0] *= -1;
	fracs[1][0] *= -1;
	}
	reduce(fracs[0][0], fracs[1][0]);
}
/////////////////////////////////////////////////////////////////////
bool rational::loadFracTwo(int n, int d)
{
	fracs[0][1] = n;
	fracs[1][1] = d;
	if(fracs[0][1] < 0 && fracs[1][1] < 0)
	{
	fracs[0][1] *= -1;
	fracs[1][1] *= -1;
	}
	reduce(fracs[0][1], fracs[1][1]);
}
/////////////////////////////////////////////////////////////////////
bool rational::add()
{
	int n1, n2, d1;
	//get like denominators
	n1 = fracs[0][0] * fracs[1][1];
	d1 = fracs[1][0] * fracs[1][1];
	n2 = fracs[0][1] * fracs[1][0];
	fracs[0][2] = n1 + n2;
	fracs[1][2] = d1;
	reduce(fracs[0][2], fracs[1][2]);
}
//////////////////////////////////////////////////////////////////////
bool rational::subtract()
{
	int n1, n2, d1;
	
	n1 = fracs[0][0] * fracs[1][1];
	d1 = fracs[1][0] * fracs[1][1];
	n2 = fracs[0][1] * fracs[1][0];
	fracs[0][2] = n1 - n2;
	fracs[1][2] = d1;
	reduce(fracs[0][2], fracs[1][2]);
}
//////////////////////////////////////////////////////////////////////
bool rational::multiply()
{
	fracs[0][2] = fracs[0][0] * fracs[0][1];
	fracs[1][2] = fracs[1][0] * fracs[1][1];
	reduce(fracs[0][2], fracs[1][2]);
}
//////////////////////////////////////////////////////////////////////
bool rational::divide()
{
	if(fracs[0][1] == 0)
	cout << "\nCannot be divided! ";
	else{
	fracs[0][2] = fracs[0][0] * fracs[1][1];
	fracs[1][2] = fracs[1][0] * fracs[0][1];
	}
	reduce(fracs[0][2], fracs[1][2]);
}
//////////////////////////////////////////////////////////////////////
rational::~rational()
{
}
