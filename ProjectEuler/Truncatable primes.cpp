


#include <iostream>
#include <limits>
using namespace std;


bool isPrime(int num);

int main()
{
	int num;
	int div, prime, total = 0;
	
	
	
	for(int x = 10; x < 750000; x++)
	{
		if(isPrime(x))
		{
			num = x;
			div = 10;
			prime = 1;
			while(num / div > 0 && prime == 1)
			{
				if(!isPrime(num % div) || !isPrime(num / div))
					prime = 0;
				div *= 10;
			}
			if(prime == 1)
				total += x;
		}
	}
	cout << total;
	
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
