/*
 Program Name: Palindrome.cpp
 Author: Nathan Caron
 Assignment #9
 Date: 5/7/14
 Purpose: Test if a string is a palindrome.
*/

#include <iostream>
#include <string>

using namespace std;

bool isPal(const string &pal, int first, int last);

int main()
{
	string pal;
	char choice;
	do
	{
		//wasn't sure to indent here or not, last
		// program you marked indent after my do
		cout << "\nEnter a string and see if it's a palindrome: ";
		getline(cin, pal);
	
		if(isPal(pal, 0, pal.length() -1))
		cout << "It IS a palindrome!";
		else
		cout << "It is NOT a palindrome!";
	
		cout << "\nWould you like to enter another? (Y or N)";
		cin >> choice;
		while(toupper(choice) != 'Y' && toupper(choice) != 'N')
		{
			cout << "\nEnter Y or N! ";
			cin >> choice;
		}
		cin.ignore();
	}while(toupper(choice) != 'N');
	
	return 0;
}

bool isPal(const string &pal, int first, int last)
{
	if(last <= first)
		return true;
	
	if(!isalpha(pal[first]))
	return isPal(pal, first +1, last);
	
	if(!isalpha(pal[last]))
	return isPal(pal, first, last - 1);
	
	if(toupper(pal[first]) == toupper(pal[last]))
	return isPal(pal, first + 1, last - 1);
	
	return false;
}
