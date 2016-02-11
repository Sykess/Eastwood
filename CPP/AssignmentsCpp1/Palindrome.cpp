// Program Name: Palindrome.cpp
// Author: Nathan Caron
// Assignment #6
// Date: 11/29/06
// Purpose: Test if a string is a palindrome or not.

#include <iostream>
using namespace std;

//global constants
const int MAX = 100;

bool String(char str[MAX]);
bool palindrome(const char origpal[MAX]);
int getLength(char str[MAX]);

int main()
{
	char palin[MAX] = "";
	int check;

	do{
	

	cout << "Enter a string, and I will tell you if its a palindrome: ";


	if(String(palin))
	{
		if(palindrome(palin))
			cout << "The string you entered was a palindrome";
		else
			cout << "The string you entered was not a palindrome";


	}
	else
		cout << "You entered an invalid string";



	cout << "\n\nPress 1 to exit, any other number to enter another string";
	cin >> check;

	cout << endl << endl;


	}while(check != 1);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

bool String(char str[MAX])
{
	char ch;
	int x = 0;

	while((ch = cin.get()) != '\n')
	{
		if(x != (MAX - 1))
			str[x++] = ch;
		else
			return false;
	}
	str[x] = '\0';


	return true;
}

//////////////////////////////////////////////////////////////////////////////////

int getLength(char str[MAX])
{
	int size = 0;
	
	for(;(str[size] != '\0')&&(size < MAX);size++);
	if(size != MAX)
		return size;
	return 1;
}

//////////////////////////////////////////////////////////////////////////////////

bool palindrome(const char origpal[MAX])
{

	cout << origpal;

	char duppal[MAX];
	int size = 0;
	int y=0;
	int end = 0, start = 0;

	for(int x=0; (x < origpal[x]); x++)
	{
		if((origpal[x] >= 65) && (origpal[x] <= 90))
			duppal[y] = origpal[x];
		if((origpal[x] >= 97) && (origpal[x] <= 122))
			duppal[y] = origpal[x] - 32;
		y++;
	}

	end = getLength(duppal);

	
	cout << duppal << end;

	

	for(;start<=end;)
	{
		if(start != end)
			return false;
		start + 1, end - 1;
	}
	

	return true;
}