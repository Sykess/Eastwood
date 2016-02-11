
#include <iostream>
using namespace std;

bool isPrime(int num);

int main()
{
	unsigned long long sum = 0;
	for(int x = 2; x < 2000000; x++)
	{
		if(isPrime(x))
			sum+= x;
	}
	cout << sum;
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
