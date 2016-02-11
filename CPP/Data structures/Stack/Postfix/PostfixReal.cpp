/*
 Program Name: PostfixReal.cpp
 Author: Nathan Caron
 Assignment #3
 Date: 2/25/2015
 Purpose: Allow user to enter real numbers in postfix notation.
*/


#include<iostream>
#include<sstream>
#include<cstring>
#include "Stack.h"
using namespace std;

bool isValid(char);


int main()
{
	char ch;
	double realNum, num1, num2;
	Stack stack(6);
	int key = 0; // dummy key
	data d, d1;
	bool cont = true; // for errors
	string input;
	
	cout << "Enter expression to evaluate or a # to quit"
	     << "\nNote: You must separate numbers and operators"
		 << "\nby either a space or a newline.  ";
	do
	{
		cin >> input;
		
		while(!isValid(input[0]) && input[0] != 10)
		{
			cout << input << "is invalid!\n";
			cin >> input;
		}
		
		switch(input[0])
		{
			case '-':
				if(isdigit(input[1])) //allows negative numbers
				{
					stringstream convert(input);
					if(!(convert >> realNum))
						realNum = 0;
					ch = '0';
				break;
				}
			case '+':
			case ' ':
			case '*':
			case '/':
			case '=':
			case '#':
				ch = input[0];
				break;
			default:
				stringstream convert(input);
				if(!(convert >> realNum))
					realNum = 0;
				ch = '0';
				break;
		};
		
		switch(ch)
		{
			case '+':  // +
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.real;
					num1 = d.real;
					d.real = num1 + num2;
					stack.push(key, d);
				}
				break;
			case '-':  // -
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.real;
					num1 = d.real;
					d.real = num1 - num2;
					stack.push(key, d);
				}
				break;
			case '*':  // *
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.real;
					num1 = d.real;
					d.real = num1 * num2;
					stack.push(key, d);
				}
				break;
			case '/':  // /
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.real;
					num1 = d.real;
					if(num2 != 0)
						d.real = num1 / num2;
					else
					{
						cout << "Cannot divide by 0!";
						cont = false;
						break;
					}
					stack.push(key, d);
				}
				break;
			case '=':  // =
				if(stack.pop(key, d) && !stack.pop(key, d1))
					cout << d.real;
				else
					cout << "Stack empty!";
				cout << "\nEnter expression to evaluate or a # to quit: ";
				break;
			case '#':  // #
			case ' ': // space
			case 10: // newline
				break;
			default:
				d.real = realNum;
				if(!stack.push(key, d))
				{
					cont = false;
					cout << "Overfill.\n";
				}
				break;
			
		};
		
	}while(ch != '#' && cont);
	
}


bool isValid(char ch)
{
	if(ch == 43 || ch == 45 || ch == 42 || ch == 47 || ch == 126 || ch == 35 || ch == 32 || ch == 61 || ch == 46) // valid symbols
		return true;
	else if(ch >= 48 && ch <= 57) // valid numbers
		return true;
	else
		return false;
}


