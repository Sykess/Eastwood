
#include<iostream>
#include<cstring>
#include<math.h>
#include "Stack.h"
using namespace std;

bool isValid(char);


int main()
{
	char ch;
	Stack stack(6);
	int num1, num2, key = 0;
	data d, d1;
	bool cont = true;
	double num3, num4;
	
	double temp[10];
	double tempNum = 0;
	int pos = 0;
	
	bool powLeft = true;
	double powerLeft = 0;
	int powerRight = 0;
	
	cout << "Enter expression to evaluate or a # to quit: ";
	
	string trying;
	
	do
	{
		//ch = cin.get();
		
		
		
		
		while(!isValid(ch) && ch != 10)
		{
			cout << ch << "is invalid!\n";
			ch = cin.get();
		}
		
		switch(ch)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '=':
			case '#':
			case ' ': 
				for(int x = 0; x < 10; x++)
				{
					if(powerLeft >= 0)
						tempNum += temp[x] * pow(10, powerLeft);
					if(powerRight > 0)
						tempNum += temp[x] / pow(10, powerRight);	
				}
				break;
			case '.':
				powLeft = false;
				break;
			default:
				temp[pos] = ch-48;
				if(powLeft)
					powerLeft++;
				else
					powerRight++;
				break;
				
		};
		cout << "tempNum is: " << tempNum;
		//cout << "size of temp is"<< temp.size();
		
		/*
		switch(ch)
		{
			case 43:  // +
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.num;
					num1 = d.num;
					d.num = num1 + num2;
					stack.push(key, d);
				}
				break;
			case 45:  // -
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.num;
					num1 = d.num;
					d.num = num1 - num2;
					stack.push(key, d);
				}
				break;
			case 42:  // *
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.num;
					num1 = d.num;
					d.num = num1 * num2;
					stack.push(key, d);
				}
				break;
			case 47:  // /
				if(!(stack.pop(key, d1) && stack.pop(key, d)))
				{
					cont = false;
					cout << "Underfill.\n";
				}
				else
				{
					num2 = d1.num;
					num1 = d.num;
					if(num2 != 0)
						d.num = num1 / num2;
					else
					{
						cout << "Cannot divide by 0!";
						cont = false;
						break;
					}
					stack.push(key, d);
				}
				break;
			case 61:  // =
				if(stack.pop(key, d) && !stack.pop(key, d1))
					cout << d.num;
				else
					cout << "Stack empty!";
				cout << "\nEnter expression to evaluate or a # to quit: ";
				break;
			case 35:  // #
			case 32: // space
			case 10:
				break;
			default:
				d.num = ch-48;
				if(!stack.push(key, d))
				{
					cont = false;
					cout << "Overfill.\n";
				}
				break;
			
		};
		*/
		
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
