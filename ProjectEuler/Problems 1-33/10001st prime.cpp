
// problem 7
#include <iostream>
using namespace std;

bool isPrime(int num);

int main()
{
	int prime = 0;
	int x = 1;
	while(prime != 10001)
	{
		x++;
		if(isPrime(x))
			prime++;
	}
	
	cout << x;
	
	return 0;
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
