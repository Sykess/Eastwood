

// Problem 58
#include <iostream>
using namespace std;



bool isPrime(int num);


int main()
{
	int primes = 3;
	int side = 2;
	int num = 9;
	
	while((double)primes / (2 * side + 1) > 0.10)
	{
		side+= 2;
		for(int i = 0; i < 4; i++)
		{
			num += side;
			if(isPrime(num))
				primes++;
		}
	}
	cout << side + 1;
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





