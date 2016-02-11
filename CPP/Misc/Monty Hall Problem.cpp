
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define ULL unsigned long long
#define K double


void showDoors(int val);

int main()
{
	int car, choice, shown, wins = 0, losses = 0;
	// needed otherwise same random numbers always generated
	srand(time(0)); 
	int doors[3];
	char yorn;
	
	K num = 4.2;
	cout << num;
	
	do
	{

		car = rand() % 3;
		for(int x = 0; x < 3; x++)
			doors[x] = 0;
		doors[car] = 1;
		
		showDoors(0);
		
		cin >> choice;
		while(choice < 1 || choice > 3)
		{
			cout << "Invalid entry, 1-3: ";
			cin >> choice;
		}
		choice--;
		
		for(int x = 0; x < 3; x++)
		{
			if(x == choice)
				continue;
			if(x == car)
				continue;
			showDoors(x+1);
			shown = x;
				break;
		}
		
		cout << "Would you like to switch you choice? (Y or N) ";
		cin >> yorn;
		if(toupper(yorn) == 'Y')
		{
			if(shown == 0)
				if(choice == 1)
					choice = 2;
				else
					choice = 1;
			else if(shown == 1)
				if(choice == 0)
					choice = 2;
				else
					choice = 0;
			else if(shown == 2)
				if(choice == 0)
					choice = 1;
				else
					choice = 0;
		}
		showDoors(car + 4);
		if(choice == car)
		{
			wins++;
			cout << "You win!\n";
		}
		else
		{
			losses++;
			cout << "You lose!\n";
		}
		cout << "\nPlay again? (Y or N)";
		cin >> yorn;
		system("CLS");
	}while(toupper(yorn) == 'Y');
	cout << "Wins: " << wins << "\nLosses: " << losses;
	
}

void showDoors(int val)
{
	if(val == 0)
	{
		cout << "Choose out of 3 doors:"
			 << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n|    o |  |    o |  |    o |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|"
			 << "\nWhich door do you want? ";
	}
	if(val == 1)
	{
		cout << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n| GOAT |  |    o |  |    o |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|\n";
	}
	if(val == 2)
	{
		cout << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n|    o |  | GOAT |  |    o |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|\n";
	}
	if(val == 3)
	{
		cout << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n|    o |  |    o |  | GOAT |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|\n";
	}
	if(val == 4)
	{
		cout << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n| CAR  |  | GOAT |  | GOAT |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|\n";
	}
	if(val == 5)
	{
		cout << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n| GOAT |  | CAR  |  | GOAT |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|\n";
	}
	if(val == 6)
	{
		cout << "\n Door 1    Door 2    Door 3"
			 << "\n ______    ______    ______"
			 << "\n|      |  |      |  |      |"
			 << "\n|      |  |      |  |      |"
			 << "\n| GOAT |  | GOAT |  | CAR  |"
			 << "\n|      |  |      |  |      |"
			 << "\n|______|  |______|  |______|\n";
	}
}


