/*
 Program Name: Inventory.cpp
 Author: Nathan Caron
 Assignment #5
 Date: 3/26/14
 Purpose: Store inventory date in a structor to a file,
 and be able to add, change, and view items.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

struct item
{
	char desc[50];
	int qty_on_hand;
	double whole_sale_cost;
	double retail_cost;
	char date_added[11];
};

void addItem(fstream &file);
void display(fstream &file);
void changeItem(fstream &file);
bool validDate(char date[]);
void displayMenu();

int main()
{
	char choice;
	

	do
	{
		displayMenu();
		cin >> choice;
	while (toupper(choice) < 'A' || toupper(choice) > 'D') 
     {
        cout << "Incorrect entry, please make a choice "
             << "in the range of A through D:";
        cin >> choice;
   	 }
   	 fstream file("Inventory.dat", ios::in | ios::out  | ios::app | ios::binary);
   	 
   	 //I put fail check here because if I put it at start and file wasn't created
   	 //yet, program would close instead of creating it.
   	if(file.fail())
	{
		cout << "ERROR, Cannot open file, closing.\n";
		return 0;
	}
	
   	 switch(choice)
   	 {
   	 	case 'a':
   	 	case 'A': addItem(file);
   	 		
   	 	break;
   	 	
   		case 'b':
   		case 'B': display(file);
   			
   		break;
   		
   		case 'c':
   		case 'C': changeItem(file);
   			
   		break;
   		
   	 	
   	 }
   	 file.close();
	
}while (toupper(choice) != 'D');

	return 0;
}


bool validDate(char date[])
{
	char temp[5];
	int mm, dd, yyyy;
	
	if(strlen(date) != 10)
		return false;
	
	temp[0] = date[0];
	temp[1] = date[1];
	temp[3] = '\0';
	mm = atoi(temp);
	
	temp[0] = date[3];
	temp[1] = date[4];
	temp[3] = '\0';
	dd = atoi(temp);
	
	if((mm > 12) || (mm < 1))
		return false;
		
	switch(mm)
	{
		case 2: if((dd < 0) || (dd > 29))
			return false;
		break;
		
		case 4:
		case 6:
		case 9:
		case 11: if((dd < 0) || (dd > 30))
			return false;
		break;
		default: if((dd < 0) || (dd > 31))
			return false;
	}
	
	temp[0] = date[6];
	temp[1] = date[7];
	temp[2] = date[8];
	temp[3] = date[9];
	temp[5] = '\0';
	
	yyyy = atoi(temp);
	
	if((yyyy < 1900) || (yyyy > 2100))
		return false;
	return true;
}



void addItem(fstream &file)
{
	item record;
	
	fstream inventory("Inventory.dat", ios::out | ios::app | ios::binary);
	
	cout << "Enter the item's Description: ";
	cin.ignore();
	cin.getline(record.desc, 50);
	do{
	cout << "Enter the quantity on hand: ";
	cin >> record.qty_on_hand;
	}while(record.qty_on_hand < 0);
	do{
	cout << "Enter the whole sale cost: ";
	cin >> record.whole_sale_cost;
	}while(record.whole_sale_cost < 0);
	do{
	cout << "Enter the retail cost: ";
	cin >> record.retail_cost;
	}while(record.retail_cost < 0);
	do{
	cout << "Enter the date added in format mm/dd/yyyy: ";
	cin >> record.date_added;
	}while(validDate(record.date_added) != true);
	
	file.write(reinterpret_cast<char *>(&record), sizeof(record));	
	inventory.close();
	
}


void changeItem(fstream &file)
{
	item record;
	int recNum;
	
	fstream inventory;
	cout << "Which record number would you like to change? ";
	cin >> recNum;
	recNum -= 1;  // For some reason need to subrtract 1 to get right spot.

	inventory.open("Inventory.dat",  ios::out | ios::in | ios::binary);
	inventory.seekp(recNum * sizeof(record), ios::beg);

    
	cout << "Enter the item's Description: ";
	cin.ignore();
	cin.getline(record.desc, 50);
	do{
	cout << "Enter the quantity on hand: ";
	cin >> record.qty_on_hand;
	}while(record.qty_on_hand < 0);
	do{
	cout << "Enter the whole sale cost: ";
	cin >> record.whole_sale_cost;
	}while(record.whole_sale_cost < 0);
	do{
	cout << "Enter the retail cost: ";
	cin >> record.retail_cost;
	}while(record.retail_cost < 0);
	do{
	cout << "Enter the date added in format mm/dd/yyyy: ";
	cin >> record.date_added;
	}while(validDate(record.date_added) != true);
	
	file.write(reinterpret_cast<char *>(&record), sizeof(record));	
	inventory.write(reinterpret_cast<char *>(&record), sizeof(record));	
	inventory.close();

}

void display(fstream &file)
{
	item record;
	int recNum;
	fstream inventory;
	
	cout << "Which record number would you like to view? ";
	cin >> recNum;
	recNum -= 1;  // For some reason need to subrtract 1 to get right spot.
	
	inventory.open("Inventory.dat", ios::in | ios::binary);
    inventory.seekg(recNum * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast<char *>(&record),
    sizeof(record));
 	
	
		cout << "Item description: ";
		cout << record.desc << endl;
		cout << "Quantity on hand: ";
		cout << record.qty_on_hand << endl;
		cout << "Wholesale cost: ";
		cout << record.whole_sale_cost << endl;
		cout << "Retail cost: ";
		cout << record.retail_cost << endl;
		cout << "Date added to inventory: ";
		cout << record.date_added << endl;
		
	inventory.close();
}


void displayMenu()
{
    cout << "\nMenu" << "\n";
    cout << "=====================\n";
    cout << "\t a) Add new record\n";
    cout << "\t b) Display any record in file\n";
    cout << "\t c) Change any record in file\n";
    cout << "\t d) Exit program\n";
    cout << "Enter your choice: ";
}
