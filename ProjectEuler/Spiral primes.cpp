

// Problem 58
#include <iostream>
using namespace std;

#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4
//#define LENGTH 22101

bool isPrime(int num);
int LENGTH = 23001;
unsigned long array[23001][23001];

int main()
{
	unsigned long long summ = 0;
	int primes = 0;
	int holder = 1; // which  number we're at, ie 1-2-3 etc
	int steps = 1; // how many steps
	int direction = 1;
	int twoHolder = 1;
	int row = LENGTH / 2;
	int col = LENGTH / 2;
	array[row][col] = 1;
	
	while(holder <= LENGTH * LENGTH)
	{
		//cout << holder << endl;
		for(int x = 0; x < steps; x++)
		{
			holder++;
			switch(direction)
			{	
				case RIGHT:
					col++;
					array[row][col] = holder;
					break;
				case DOWN:
					row++;
					array[row][col] = holder;
					break;
				case LEFT:
					col--;
					array[row][col] = holder;
					break;
				case UP:
					row--;
					array[row][col] = holder;
					break;
			};
		}//end steps loop
		if(twoHolder == 2) // every 2 directions steps increases
		{
			steps++;
			twoHolder = 0;
		}
		twoHolder++;
		if(direction == 4)
			direction = 1;
		else
			direction++;
	}
	/*	
	for(int x = 0; x <= 1000; x++)
	{
		summ += array[x][x];
	}

	for(int x = 1000, y = 0; x >= 0; x--, y++)
	{
		summ += array[x][y];
	}
	cout << summ - 1; // -1 because middle 1 is counted twice
	*/
	/*
	for(int x = 0; x < LENGTH; x++)
		for(int y = 0; y < LENGTH; y++)
			cout << array[x][y] << endl;
	*/
	
	for(int x = 0; x <= LENGTH - 1; x++)
		if(isPrime(array[x][x]))
			primes++;
	
	for(int x = LENGTH - 1, y = 0; x >= 0; x--, y++)
		if(isPrime(array[x][y]))
			primes++;
	
	double percent = (double)primes / (2 * LENGTH - 1);
	cout << percent;
	
}


bool isPrime(int num)
{
	if(num == 1 || num == 2 || num < 1)
		return false;
	for(int x = 2; x <= num / x; x++)
	{
		if(num % x == 0 )
			return false;
	}
	return  true;
}      





