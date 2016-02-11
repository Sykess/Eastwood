/*
 Program Name: Pascal.h
 Author: Nathan Caron
 Assignment #1
 Date: 1/30/15
 Purpose: Class to create array containing pascal's triangle and display it.
*/

#include <iostream>
using namespace std;


class pascal
{
	private:
		int SIZE;
		int * pasTri;
		int oldPos;
		int newPos;
	public:
		pascal(int n);
		void propagate();
		void display();
		void displayInverted();
		~pascal();
};

////////////////////////////////////////////////////////////////////////

pascal::pascal(int n)
{
	SIZE = n;
	oldPos = 1;
	newPos = 3;
	pasTri = new int[SIZE];
	for(int x = 0; x < 3; x++)
	*(pasTri + x) = 1;
	for(int x = 3; x < SIZE; x++)
	*(pasTri + x) = 0;
}

////////////////////////////////////////////////////////////////////////

void pascal::propagate()
{
	do{
		// added this since only allowed to hardcode first 3 numbers in array.
		if(newPos == 3) 
			pasTri[newPos++] = 1;
		
		pasTri[newPos] = pasTri[oldPos] + pasTri[oldPos + 1];
		newPos++;
		oldPos++;
		
		if(pasTri[oldPos] == 1 && pasTri[oldPos + 1] == 1)
		{
			oldPos++;
			pasTri[newPos] = 1;
			if(newPos + 1 < SIZE)
			{
				pasTri[newPos + 1] = 1;
				newPos+= 2;
			}
		}
	}while(newPos + 1 < SIZE);
}

////////////////////////////////////////////////////////////////////////

void pascal::display()
{
	int x = 0;
	int counter = 1;
	int tracker = 2; // tracks how many numbers in given row
	int spaces = 0; // placeholder for elements of formatter array
	int newRow = 1; 
	// with trial and error I found out how many spaces for each row:
	int formatter[17] = {38,37,36,35,34,32,31,29,27,25,21,19,17,15,13,9,5};
	
	while(x < SIZE)
	{

		if(newRow == 1)
		{
			for(int x = 0; x < formatter[spaces]; x++)
				cout << " ";
			newRow--;
		}
		
		cout << pasTri[x++] << " ";
		
		if(x == counter)
		{
			cout << "\n";
			newRow++;
			spaces++;
			counter+= tracker++;
		}
	}
}
////////////////////////////////////////////////////////////////////////

void pascal::displayInverted()
{
	int formatter[17] = {5,9,13,15,17,19,21,25,27,29,31,32,34,35,36,37,38};
	int x = 152; // 152 instead of 153 due to how arrays work
	int tracker = 16; // amount of numbers in 2nd row
	int counter = 135;// array position after 1st row
	int newRow = 1;
	int spaces = 0;
	
	while(x >= 0)
	{
		if(newRow == 1)
		{
			for(int x = 0; x < formatter[spaces]; x++)
				cout << " ";
			newRow--;
		}
		
		cout << pasTri[x--] << " ";
		
		
		if(x == counter)
		{
			cout << "\n";
			newRow++;
			spaces++;
			counter-= tracker--;
			
		}	
	}
}


////////////////////////////////////////////////////////////////////////

pascal::~pascal(){ delete[] pasTri; }


