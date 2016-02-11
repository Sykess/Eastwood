/*
 Program Name: NumArray.h
 Author: Nathan Caron
 Assignment #7
 Date: 4/16/14
 Purpose: Dynamically create array of numbers and show high/low/ave.
*/

#include <iostream>
using namespace std;

class numArray
{
	private:
		double *nList;
		int qty;
	public:
		numArray(int n = 0);
		bool setNum(int n);
		bool getNum(int n);
		double getHigh();
		double getLow();
		double getAve();
		~numArray();
};

////////////////////////////////////////////////////////////////////////

numArray::numArray(int n)
{
	qty = n;
	nList = new double[qty];
	
	for(int x = 0; x < qty; x++)
	*(nList + x) = 0;
}

////////////////////////////////////////////////////////////////////////

bool numArray::setNum(int n)
{
	double x;
	
	do{
		cout << "\nEnter number to put in position " << n+1 << " : ";
		cin >> x;
		if(!x)
		cout << "\nInvalid entry ";
	}while(!x);
	
	*(nList + n) = x;
}

////////////////////////////////////////////////////////////////////////

bool numArray::getNum(int n)
{
	cout << "\nThe number in position " << n+1 << " is "
	     << *(nList + n);
}

////////////////////////////////////////////////////////////////////////

double numArray::getHigh()
{
	double high;
	high = *(nList);
	for(int x = 0; x < qty; x++)
	{
		if(*(nList + x) > high)
		high = *(nList + x);
	}
	return high;	
}

////////////////////////////////////////////////////////////////////////

double numArray::getLow()
{
	double low;
	low = *(nList);
	
	for(int x = 0; x < qty; x++)
	{
		if(*(nList + x) < low)
		low = *(nList + x);
	}
	return low;
}

////////////////////////////////////////////////////////////////////////

double numArray::getAve()
{
	double ave = 0;
	
	for(int x = 0; x < qty; x++)
	{
		ave += *(nList + x);
	}
	ave /= qty;
	return ave;
}

////////////////////////////////////////////////////////////////////////

numArray::~numArray(){ delete [] nList; }


