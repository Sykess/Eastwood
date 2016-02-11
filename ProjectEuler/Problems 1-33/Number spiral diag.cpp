

// Problem 28
#include <iostream>
using namespace std;

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

int array[1001][1001];

int main()
{
	unsigned long long summ = 0;
	int holder = 1; // which  number we're at, ie 1-2-3 etc
	int steps = 1; // how many steps
	int direction = 1;
	int twoHolder = 1;
	int row = 500, col = 500;
	array[row][col] = 1;
	
	while(holder <= 1002001)
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
	for(int x = 0; x <= 1000; x++)
	{
		summ += array[x][x];
	}

	for(int x = 1000, y = 0; x >= 0; x--, y++)
	{
		summ += array[x][y];
	}
	cout << summ - 1; // -1 because middle 1 is counted twice
}



