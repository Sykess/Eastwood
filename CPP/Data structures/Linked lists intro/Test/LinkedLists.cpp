/*
 Program Name: LinkedLists.cpp
 Author: Nathan Caron
 Assignment #2
 Date: 2/13/2015
 Purpose: Test out linked lists from file.
*/

#include<fstream>
#include "SllFunc.h"
#include "UsllFunc.h"

//Functions
bool loadLists();
void displayMenu();

//Global Constants
Sll sorted;
Usll unsorted;

int main()
{
	int choice, del;
	
	do
	{
		displayMenu();
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "Incorrect entry, try again: ";
			cin >> choice;
		}
		
		switch(choice)
		{
			case 1:
				if(!loadLists())
					return -1; // can't open file so exit
				break;
			case 2:
				cout << "\nSorted list containing " << sorted.getLength()
					 << " elements:\n";
				sorted.display();
				cout << "\nUnsorted list containing "
					 << unsorted.getLength() << " elements:\n";
				unsorted.display();
				cout << endl;
				break;
			case 3:
				cout << "Enter number to delete: ";
				cin >> del;
				if(!sorted.deleteItem(del))
					cout << "Number not found in sorted list\n";
				if(!unsorted.deleteItem(del))
					cout << "Number not found in unsorted list\n";
				break;
			case 4:
				unsorted.makeEmpty();
				break;
			case 5:
				sorted.makeEmpty();
				break;				
		}
	}while(choice != 6);
}
/////////////////////////////////////////////////////////////
void displayMenu()
{
	cout << "\nMenu\n";
	cout << "=============\n";
	cout << "1) Load both lists\n";
	cout << "2) Display both lists and the quantity of elements\n";
	cout << "3) Delete item from both lists\n";
	cout << "4) Empty unsorted linked list\n";
	cout << "5) Empty sorted linked list\n";
	cout << "6) Exit program\n";
}
/////////////////////////////////////////////////////////////
bool loadLists()
{
	fstream file;
	int numbers;
	
	file.open("Numbers.dat");
	if(!file)
	{
		cout << "Failed to open file \"Numbers.dat\"\n";
		return false;
	}
	
	//sorted.makeEmpty();
	//unsorted.makeEmpty();

	while(!file.eof())
	{
		file >> numbers;
		sorted.addItem(numbers);
		unsorted.addItem(numbers);	
	}
	file.close();
	return true;
}


