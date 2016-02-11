/*
 Program Name: RMV.cpp
 Author: Nathan Caron
 Assignment #4
 Date: 3/6/15
 Purpose: Simulate lines at the RMV.
*/

#include <stdlib.h>
#include <time.h>
#include "Queue.h"

//Function prototype
void display();

//Global Constants
const int EXPRESS = 5; //lines[0]
const int ENFORCEMENT = 20; //lines[1]
const int PERMIT = 30; //lines[2]
const int FULL_SERVICE = 10; //lines[3]
Queue lines[4];

int main()
{
	
	int times[4] = {EXPRESS, ENFORCEMENT, PERMIT, FULL_SERVICE};
	int custNum = 1,  classification; 
	data d;
	
	// needed otherwise same random numbers always generated
	srand(time(0)); 
	
	
	for(int time = 0;time <= 450; time+= 5)
	{
		if(time <= 420) 
		{
			classification = rand()%5;
			
			if(classification >= 0 && classification < 4)
			{
				d.custNum = custNum;
				d.time = time;
				lines[classification].enQueue(d);
				custNum++;
			}
		}
		
		for(int x = 0; x < 4; x++)
		{
			lines[x].vwQueue(d);
			if(time - d.time >= times[x])
				lines[x].deQueue(d);
		}
		
		display();
			
		for(int x = 0; x < 100000000; x++); // dummy loop for display
	
		system("cls");
	}
}
/////////////////////////////////////////////////////////////////
void display()
{
	cout << "Line:\t\t\t Customer Number:\n";
	cout << "===========================================";
	cout << "\nExpress line:\t\t ";
	lines[0].display();
	cout << "\nEnforcement line:\t ";
	lines[1].display();
	cout << "\nPermit line:\t\t ";
	lines[2].display();
	cout << "\nFull Service line:\t ";
	lines[3].display();
}





