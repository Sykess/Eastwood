

#include <iostream>
#include <iomanip>
#include "Sll.h"
using namespace std;

#define MAX 6965
#define LIMIT 28123

void loadAbundant();


Sll list;
int abundant[MAX];

int main()
{
	loadAbundant();
	int sum = 0;
	bool writtenAbundant[LIMIT];
	
	
	for(int x = 0; x < MAX; x++)
	{
		for(int y = 0; y < MAX; y++)
		{
			if(abundant[x] + abundant[y] <= LIMIT)
			{
				writtenAbundant[abundant[x] + abundant[y]] = true;
			}
			else
				break;
		}
	}
	
	for(int x = 1; x <= LIMIT; x++)
	{
		if(!writtenAbundant[x])
			sum+= x;
	}
	cout << sum;
	
}

void loadAbundant()
{
	int index = 0;
	for(int x = 1; x <= LIMIT; x++)
	{
		int sum = 0;
		for(int y = 1; y <= x / 2; y++)
		{
			if(x % y == 0)
				sum+= y;
		}
		if(sum > x)
			abundant[index++] = x;
	}
}
