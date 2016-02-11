/******************************************************************************
program:	Dll.cpp
author:		A.Hayden
date:		4/8/15
assignment:	#5
purpose:	DataBase with Double Linked Lists
******************************************************************************/

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "DLL.h"


int main()
{
	char choice;
	int part;
	Dll list;
	data d;
	
	string token;
	fstream file;
	string filename;
	do
	{
    	cout << "\nWhat File would you like to open?: ";
    	cin >> filename;
    	file.open(filename.c_str());
    	if(!file)
    	         cout << "Error opening file: " << filename 
                      << ". Please Try Again" << endl;
    }while(!file);
	
    cout << "\n+-------------------------------------------------------+"
		 << "\n|\t\t\t     MENU\t\t\t|"
		 << "\n|\ta. Add New Record                               |"
		 << "\n|\tb. Delete Record (by part-record number)        |"
		 << "\n|\tc. Modify Record                                |"
		 << "\n|\td. List All Records by Inventory Number         |"
		 << "\n|\te. List All Records by Cost                     |"
		 << "\n|\tf. Quit and SAVE                                |"
		 << "\n+-------------------------------------------------------+"
		 << endl;
	char temp[35];
	int x, y;
	do
	{
		while(getline(file, token))
		{
			x = y = 0;
			for(int i = 0; i < 4; i++)
			{
			
				while(token[x] != ';' && token[x] != '\0')
				{
					temp[y] = token[x];
					x++;
					y++;
				}
				temp[y] = '\0';
				if(i == 0)
					part = atoi(temp);
				if(i == 1)
					strcpy(d.toolname, temp);
				if(i == 2)
					d.quantity = atoi(temp);
				if(i == 3)
					d.cost = atof(temp);
				y = 0;
				x++;
			}
			list.add(part, d);
			//file >> part >> d.toolname >> d.quantity >> d.cost;
			//list.add(part, d);
		}
		file.close();
		cout << "\nEnter Your Selection: ";
		cin >> choice;
		
		switch(choice)
		{
			case 'A':
			case 'a':
				{
					cout << "\nEnter New Part #: ";
					cin >> part;
					cout << "Enter Description: ";
					cin.ignore();
					cin.getline(d.toolname, 35);
					cout << "Enter Quantity: ";
					cin >> d.quantity;
					cout << "Enter Cost: ";
					cin >> d.cost;
					list.add(part, d);
				}
				break;
			
			case 'B':
			case 'b':
				cout << "What would you like to remove?: ";
				cin >> part;
				if(list.remove(part, d))
					cout << "Item Deleted.";
				else
					cout << "Item Number Not Found. Try Again." << endl;
				break;
				
			case 'C':
			case 'c':
				{
					cout << "\nWhat record would you like to modify?: ";
					cin >> part;
					list.find(part, d);
					if(list.find(part, d))
					{
						cout << "\nEnter New Part #: ";
						cin >> part;
						cout << "Enter Description: ";
						cin >> d.toolname;
						cout << "Enter Quantity: ";
						cin >> d.quantity;
						cout << "Enter Cost: ";
						cin >> d.cost;
						list.add(part, d);
					}
					else
						cout << "\n<ERROR>. Part Number Not Found.";
				}
				break;
				
			case 'D':
			case 'd':
				if(list.isEmpty())
					cout << "Inventory Empty.";
				else
					list.display(cout);
				break;
				
			case 'E':
			case 'e': list.displayCost();
				break;
			
			case 'F':
			case 'f':
				file.open(filename.c_str());
                list.display(file);
                file.close();
				return 0;
				break;
			
			default:
				cout << "\nSorry Invalid Selection. Try again: ";
				cin >> choice;
			
		}
	
	}while((choice != 'f') || (choice != 'F'));
	
	
	return 0;
}
