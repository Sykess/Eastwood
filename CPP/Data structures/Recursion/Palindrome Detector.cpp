/*
 Program Name: Palindrome Detector.cpp
 Author: Nathan Caron
 Assignment #6
 Date: 4/17/14
 Purpose: Test if a string is a palindrome.
*/

#include <iostream>
#include <cstring>

using namespace std;

bool isPal(char *array, int start, int end);

int main()
{
	char array[256];
	char ch;
	
	do
	{
		cout << "Enter a string to see if it's a palindrome: ";
		cin.getline(array, 256);
		
		if(isPal(array, 0, strlen(array) - 1))
			cout << "The string: \"" << array << "\" is a Palindrome.";
		else
			cout << "The string: \"" << array << "\" is not a Palindrome.";
			
		cout << "\n\nEnter another string? (Y or N): ";
		cin >> ch;
		while(toupper(ch) != 'Y' && toupper(ch) != 'N')
		{
			cout << "Invalid entry, Y for yes, N for no: ";
			cin >> ch;
		}
		
		cin.ignore();
	}while(toupper(ch) == 'Y');
	
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////
bool isPal(char *array, int start, int end)
{	
	if(isdigit(array[start]) || isdigit(array[end]))
		return false;
		
	if(start >= end)
		return true;
		
	if(!isalpha(array[start]))
		return isPal(array, ++start, end);
		
	if(!isalpha(array[end]))
		return isPal(array, start, --end);
		
	if(toupper(array[start]) == toupper(array[end]))
		return isPal(array, ++start, --end);
		
	return false;
}
