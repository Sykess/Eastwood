/*
 Program Name: Database.cpp
 Author: Nathan Caron
 Assignment # 5
 Date: 4/9/2015
 Purpose: Load inventory from a file and load into doubly linked list.
 		  Note, I tested out a new trick I found to prevent the program
 		  from crashing when a user enters something other than a number
 		  when the program is expecting an int.  It uses limits, and that is
 		  why in all my int validations I have cin.clear() and cin.ignore(...)
 		  as well as cin.fail() in select places.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <limits>
using namespace std;
#include "Dll.h"

// Function prototypes
bool loadFromFile(string fileName);
void saveToFile(string fileName);
void displayMenu();
void modifyRecord();
void addRecord();
void displayPrice();

// Set list as global so don't have to pass it to functions
Dll list;


int main()
{
	int choice, temp;
	data d;
	char fileName[50];

	
	cout << "Enter file name to load: ";
	cin.getline(fileName, 50);

	if(!loadFromFile(fileName))
		return 0;
	
	do
	{
		displayMenu();
		cin >> choice;
		// used limits to prevents program breaking if user enters non-ints
		while(cin.fail() || choice < 1 || choice > 6)
		{
			cin.clear();
   		    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid choice, enter choice 1-6: ";
			cin >> choice;
		}
		
		switch(choice)
		{
			case 1: addRecord();
					break;
			case 2: cout << "Enter part number to delete record: ";
					cin >> temp;
					while(!list.deleteItem(temp, d) && temp != -1)
					{
						cin.clear();
   					    cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout << "Invalid part number.  Enter part number "
							 << "or -1 to cancel: ";
						cin >> temp;
					}
					if(temp != -1)
						cout << "Successfully deleted!\n";
					break;
			case 3: modifyRecord();
					break;
			case 4: if(list.isEmpty())
						cout << "Inventory is empty!\n";
					else
					{
						cout << endl << setw(10) << "Part#:" << setw(35) <<"Item name:"
							 << setw(10) << "Quantity:" << setw(12) << "Cost:\n\n";
						list.display();
					}
					break;
			case 5: if(list.isEmpty())
						cout << "Inventory is empty!\n";
					else
						displayPrice();
					break;
			case 6: saveToFile(fileName);
					break;
		};
		
	}while(choice != 6);

	return 0;
}
/////////////////////////////////////////////////////////////////////////////
void displayMenu()
{
	cout << "Menu:\n"
		 << "============================\n"
		 << "1: Add new record\n"
		 << "2: Delete record\n"
		 << "3: Modify record\n"
		 << "4: List all records by part number\n"
		 << "5: List all records by cost\n"
		 << "6: Save and quit\n"
		 << "Enter choice: ";
}
/////////////////////////////////////////////////////////////////////////////
void addRecord()
{
	int key;
	data d;
	string name;
	
	cout << "Enter part number: ";
	cin >> key;
	while(cin.fail() || list.find(key, d) || key < 0)
	{
		cin.clear();
   		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid or there is already an item with that part number."
			 << "\nEnter a new one or -1 to cancel: ";
		cin >> key;
		if(key == -1)
			return;
	}
	
	cout << "Enter product name: ";
	cin.ignore();
	cin.getline(d.toolName, 35);
	
	cout << "Enter quantity: ";
	cin >> d.quantity;
	while(cin.fail() || d.quantity < 0)
	{
		cin.clear();
   	    cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Quantity must be at least 0, enter quantity: ";
		cin >> d.quantity;
	}
	cout << "Enter cost of " << d.toolName << " : ";
	cin >> d.cost;
	while(cin.fail() || d.cost <= 0)
	{
		cin.clear();
   		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid price.  Enter cost greater than 0: ";
		cin >> d.cost;
	}
	if(list.add(key, d))
		cout << "Successfully entered!\n";
	
}
/////////////////////////////////////////////////////////////////////////////
void displayPrice()
{
	int qty = list.quantity();
	int tempPos = 0;
	double temp1, temp2;
	data d;
	int array[qty];
	
	list.getKeys(array);
	
	// sort keys by cost
	for(int x = 0; x < qty - 1; x++)
	{
		list.find(array[x], d);
		temp1 = d.cost;
		list.find(array[x+1], d);
		temp2 = d.cost;
		if(temp1 > temp2)
		{
			tempPos = array[x];
			array[x] = array[x+1];
			array[x+1] = tempPos;
			
			// send it 2 back if x is greater than 0, to go up the list
			// until the cost being moved is > the one before it
			if(x > 0)
				x-=2;
			else
				x--;
		}
	}
	
	//display
	cout << endl << setw(10) << "Part#:" << setw(35) <<"Item name:"
		 << setw(10) << "Quantity:" << setw(12) << setprecision(2) 
		 << fixed << "Cost:\n\n";
	for(int x = 0; x < qty; x++)
	{
		list.find(array[x], d);
		cout << setw(10) << array[x] << setw(35) << d.toolName << setw(10)
			 << d.quantity << setw(10) <<  d.cost << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////
void modifyRecord()
{
	int key, temp, choice;
	data d, dNew;
	
	cout << "Enter part number to modify: ";
	cin >> key;
	while(!list.find(key, d))
	{
		cout << "Part number not found, try again or -1 to cancel: ";
		cin >> key;
		if(key == -1)
			return;
	}
	list.deleteItem(key, d);
	// since find requires type data passed in, need a 2nd data variable to
	// prevent the data from being overwritten when sent into find
	dNew = d; 
	
	do
	{
		cout << "Modify menu: "
			 << "\n1: Change key"
			 << "\n2: Change name"
			 << "\n3: Change quantity"
			 << "\n4: Change price"
			 << "\n5: Finished"
			 << "\nEnter choice: ";
		cin >> choice;
		while(cin.fail() || choice < 1 || choice > 5)
		{
			cin.clear();
   		    cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid choice, enter choice 1-5: ";
			cin >> choice;
		}
		
		switch(choice)
		{
			case 1:	cout << "Current key: " << key
					     << "\nEnter new key: ";
					cin >> temp;
					while(cin.fail() || list.find(temp, d) || temp < 0)
					{
						cin.clear();
   	  				    cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout << "Part number taken or invalid choice."
							 << "\nEnter new  part number: ";
						cin >> temp;
					}
					key = temp;
					break;
			case 2: cout << "Current name: " << dNew.toolName
						 << "\nEnter new name: ";
					cin.ignore();
					cin.getline(dNew.toolName, 35);
					break;
			case 3: cout << "Current quantity: " << dNew.quantity
					     << "\nEnter new quantity: ";
					cin >> dNew.quantity;
					while(cin.fail() || dNew.quantity < 0)
					{
						cin.clear();
   	  				    cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout << "Quantity must be at least 0."
							 << "\nEnter new quantity: ";
						cin >> dNew.quantity;
					}
					break;
			case 4: cout << "Current price: " << dNew.cost
					     << "\nEnter new cost: ";
					cin >> dNew.cost;
					while(cin.fail() || dNew.cost <= 0)
					{
						cin.clear();
   	 			        cin.ignore(numeric_limits<streamsize>::max(),'\n');
						cout << "Invalid price, must be over 0."
						 	 << "\nEnter new cost: ";
						cin >> dNew.cost;
					}
					break;
			case 5: if(list.add(key, dNew))
						cout << "Successfully modified!\n";
					else
						cout << "Error, could not modify.\n";
					break;
		}
		
	}while(choice != 5);
}
/////////////////////////////////////////////////////////////////////////////
bool loadFromFile(string fileName)
{
	ifstream file;
	char temporary[35];
	string line, token;
	int key, temp = 1; 
	data d;
	
	file.open(fileName.c_str(), ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
			istringstream iss(line);
			while(getline(iss, token, ';')) // tokenize each line
			{
				for(int x = 0; x < token.size(); x++)
				{
					temporary[x] = token[x];
					if(x+1 == token.size())
						temporary[x+1] = '\0';
				}
				// since there are 4 fields per line, temp keeps track
				// of which field we're on to know where to put it
				switch(temp)
				{
					case 1: key = atoi(temporary);
						    temp++;
						    break;
					case 2: strcpy(d.toolName, temporary);
							temp++;
							break;
					case 3: d.quantity = atoi(temporary);
							temp++;
							break;
					case 4: d.cost = atof(temporary);
							temp = 1;
							break;
				};
			}
			list.add(key, d);
		}
	}
	else
	{
		cout << "Could not open file!";
		return false;
	}
	file.close();
	return true;
}
/////////////////////////////////////////////////////////////////////////////
void saveToFile(string fileName)
{
	streambuf *orig, *toFile;
	ofstream file;
	file.open(fileName.c_str() , ios::out);
	
	orig = cout.rdbuf(); // hold cout to screen
	
	if(file.is_open())
	{
		toFile = file.rdbuf();
		cout.rdbuf(toFile); // set cout to file
		// created displayFormatted() to write to file with same formatting
		// that it started with
		list.displayFormatted();
		cout.rdbuf(orig); // reset cout back to screen
		cout << "Successfully saved!\n";
	}
	else
		cout << "Could not open file!";
	file.close();
}
