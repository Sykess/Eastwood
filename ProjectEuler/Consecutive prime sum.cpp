

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

bool isPrime(int num);

int main()
{
	int sum = 0;
	int maxPrime = 0;
	int x = 7; // found this start by trial and error
	
	while(sum < 1000000)
	{
		if(isPrime(x))
		{
			sum+= x;
		}
		if(sum < 1000000)
		if(isPrime(sum))
			if(maxPrime < sum)
				maxPrime = sum;
		x++;
	}
	
	cout << maxPrime;
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
