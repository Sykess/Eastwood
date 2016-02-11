
//problem 32
#include <iostream>
#include <math.h>
#include <iomanip>
#include "Sll.h"
using namespace std;

bool isPandigital(int x, int y);

int main()
{
	Sll list;
	int sum = 0;
	for(int x = 1; x < 50; x++)
	{
		for(int y = 150; y < 2000; y++)
		{
			if(isPandigital(x, y))
			{
				if(list.addItem(x * y))
				{
					sum+= x * y;
					cout << x << " " << y << endl;
				}
			}
		}
	}
	//list.display();
	cout << sum;
	
}

bool isPandigital(int x, int y)
{
	int array[10];
	for(int n = 0; n < 10; n++)
	{
		array[n] = 0;
	}
	int product = x * y;
	
	while(x > 0)
	{
		array[x % 10]++;
		x /= 10;
	}
	while(y > 0)
	{
		array[y % 10]++;
		y /= 10;
	}
	while(product > 0)
	{
		array[product % 10]++;
		product /= 10;
	}
	if(array[0] > 0)
		return false;
	for(int n = 1; n < 10; n++)
	{
		if(array[n] != 1)
			return false;
	}
	return true;
}
