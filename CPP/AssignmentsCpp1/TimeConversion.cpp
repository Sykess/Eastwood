// Program Name: TimeConversion.cpp
// Author: Nathan Caron
// Assignment #3
// Date: 10/20/06
// Purpose:  Calculate seconds to days, hours, minutes, and seconds

#include <iostream>
using namespace std;

int main()
{
	int seconds, minutes, hours, days;

	cout << "\nEnter a value of seconds and I will convert it to ";
	cout << "\nits equivalent days, hours, minutes, and seconds";
	cout << "\nin the format days : hours : minutes : seconds : ";

	cin >> seconds;

	if(seconds >= 86400)
		days = seconds / 86400;
	else
		days = 0;
	cout << endl << (days < 10 ? "0" : ""); //adds a 0 if necessary 
	cout << days << " : ";					//to keep DD format
	seconds = seconds % 86400; //finds remaining seconds
	

	if(seconds >= 3600)
		hours = seconds / 3600;
	else
		hours = 0;
	cout << (hours < 10 ? "0" : "");
	cout << hours << " : ";
	seconds = seconds % 3600;


	if(seconds >= 60)
		minutes = seconds / 60;
	else
		minutes = 0;
	cout << (minutes < 10 ? "0" : "");
	cout << minutes << " : ";
	seconds = seconds % 60;


	cout << (seconds < 10 ? "0" : "");
	cout << seconds;


	cout << endl << endl;

	return 0;

}