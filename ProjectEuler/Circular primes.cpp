

#include <iostream>

using namespace std;

bool isPrime(int num);

int main()
{
	int num, temp, circPrimes = 4, digits;
	int movingNum;
	
	for(int x = 10; x < 1000000; x++)
	{
		if(isPrime(x))
		{
			num = x;
			digits = 1;
			temp = 1;
			while(num > 0)
			{
				digits*= 10;
				num /= 10;
			}
			digits /= 10;
			
			num = x;
			do
			{
				movingNum = num % 10;
				num /= 10;
				num += movingNum * digits;

				if(!isPrime(num))
					temp = 0;
			}while(num != x);
			
			if(temp == 1)
				circPrimes++;
		}
	}
	cout << circPrimes;
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
