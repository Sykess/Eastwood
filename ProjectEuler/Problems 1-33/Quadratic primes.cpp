
#include <iostream>
using namespace std;


bool isPrime(int num);


int main()
{
	bool prime;
	int num, primecount = 0;
	int tempNum;
	int maxA, maxB;
	for(int a = -999; a < 1000; a++)
	{
		for(int b = -999; b < 1000; b++)
		{
			prime = true;
			num = 0;
			while(prime)
			{
				tempNum = num * num + a * num + b;
				if(tempNum < 0)
					tempNum *= -1;
				if(isPrime(tempNum))
				{
					num++;
				}
				else
					prime = false;
				if(num > primecount)
				{
					primecount = num;
					maxA = a;
					maxB = b;
				}
			}
		}
	}
	cout << primecount << " " << maxA << " " << maxB;
	
	
}


bool isPrime(int num)
{
	for(int x = 2; x <= num / x; x++)
	{
		if(num % x == 0 )
			return false;
	}
	return  true;
}
