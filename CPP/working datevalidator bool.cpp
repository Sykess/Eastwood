/*
 Program Name: CourseGrade.cpp
 Author: Nathan Caron
 Assignment #5
 Date: 3/26/14
 Purpose: 
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct inventory
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

int main()
{
	inventory item;
	cout << "Enter date format mm/dd/yyyy: \n";
	cin.getline(item.date_added, 30, '\n');
	if (validDate(item.date_added) == 1)
	cout << item.date_added[0] << item.date_added[1] << item.date_added[2] << item.date_added[3] 
	<< item.date_added[4] << item.date_added[5] << item.date_added[6] << item.date_added[7]
	<< item.date_added[8] << item.date_added[9];
	else
	cout << "wrong";
	
	
	
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



