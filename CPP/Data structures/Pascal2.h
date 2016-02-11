/*
 Program Name: Pascal.h
 Author: Nathan Caron
 Assignment #1
 Date: 1/30/15
 Purpose: Class to create array containing pascal's triangle and display it.
*/

#include <iostream>
#pragma comment(lib, "th32.lib")
#define VC_EXTRALEAN
#include <windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <shlwapi.h>
using namespace std;


class pascal2
{
	private:
		int SIZE;
		int * pasTri;
		int oldPos;
		int newPos;
	public:
		pascal2(int n);
		void propagate();
		void display();
		void display2();
		void displayInverted();
		void placeCursor(const int x, const int y);

		~pascal2();
};


////////////////////////////////////////////////////////////////////////

pascal2::pascal2(int n)
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
void pascal2::placeCursor(const int x, const int y)
{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
		COORD PlaceCursorHere;
		PlaceCursorHere.X = x;
		PlaceCursorHere.Y = y;			
	
		SetConsoleCursorPosition(hConsole, PlaceCursorHere);
		return;
}

////////////////////////////////////////////////////////////////////////

void pascal2::propagate()
{
	do{
		// added this since only allowed to hardcode first 3 numbers in array.
		if(newPos == 3) 
		{
			pasTri[newPos] = 1;
			newPos++;
		}
		
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
void pascal2::display2()
{
	int x = 0;
	int counter = 1;
	int tracker = 2;
	int spaces = 0;
	int newRow = 0;
	
	while(x < SIZE)
	{
		PlaceCursor(25,25); printf(pasTri[x]);
		cout << " ";
		x++;
		
		if(x == counter)
		{
			cout << "\n";
			newRow++;
			spaces++;
			counter+= tracker;
			tracker++;
		}
	}
}

////////////////////////////////////////////////////////////////////////

void pascal2::display()
{
	int x = 0;
	int counter = 1;
	int tracker = 2; // tracks how many numbers in given row
	int spaces = 0; // placeholder for elements of formatter array
	int newRow = 1; 
	int formatter[17] = {38,37,36,35,34,32,31,29,27,25,21,19,17,15,13,9,5};
	
	while(x < SIZE)
	{

		if(newRow == 1)
		{
			for(int x = 0; x < formatter[spaces]; x++)
				cout << " ";
				
			newRow--;
		}
		
		cout << pasTri[x] << " ";
		x++;
		
		if(x == counter)
		{
			cout << "\n";
			newRow++;
			spaces++;
			counter+= tracker;
			tracker++;
		}
	}
}
////////////////////////////////////////////////////////////////////////

void pascal2::displayInverted()
{
	int formatter[17] = {5,9,13,15,17,19,21,25,27,29,31,32,34,35,36,37,38};
	int x = 152;
	int tracker = 16;
	int counter = 135;
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
		
		cout << pasTri[x] << " ";
		x--;
		
		if(x == counter)
		{
			cout << "\n";
			newRow++;
			spaces++;
			counter-= tracker;
			tracker--;
		}	
	}
}


////////////////////////////////////////////////////////////////////////

pascal::~pascal2(){ delete[] pasTri; }


