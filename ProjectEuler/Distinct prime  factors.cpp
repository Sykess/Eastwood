// problem 47
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include "Sll.h"

using namespace std;

int primeFactors(int num);
bool isPrime(int num);

Sll list;

int main()
{
	for(int x = 100; x < 1000000; x++)
	{
		if(isPrime(x))
			continue;
		if(primeFactors(x) == 4)
			if(primeFactors(x+1) == 4)
				if(primeFactors(x+2) == 4)
					if(primeFactors(x+3) == 4)
					{
						cout << x;
						break;
					}
	}
	
}

bool isPrime(int num)
{
	if(num == 1)
		return false;
	for(int x = 2; x <= num / x; x++)
	{
		if(num % x == 0 )
			return false;
	}
	return  true;
}     

int primeFactors(int num)
{
	list.makeEmpty();
	
	for(int x = 2; x <= num / x; x++)
	{
		while(num % x == 0)
		{
			list.addItem(x);
			num /= x;
		}
	}
	if(num > 1)
		list.addItem(num);
	return list.total();
}
