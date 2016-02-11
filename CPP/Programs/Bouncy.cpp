#include <iostream>
using namespace std;

bool isBouncy(int n);

int main()
{
	int i = 100, bouncy = 0;
	double average = 0;

	
	while(average < 99)
	{
		if(isBouncy(i))
			bouncy++;
		average = (double)bouncy / (double)i * 100;
		i++;
	}
	cout << i;
	
}

bool isBouncy(int n)
{
	int temp = n % 10;
	bool descend = false;
	n /= 10;

	while(temp == n % 10)
	{
		n /= 10;
		if(n == 0)
			return false;
	}
	if(temp < n % 10)
		descend = true;
	while(n > 0)
	{
		if(descend)
		{
			if(temp > n % 10)
				return true;
		}
		else
		{
			if(temp < n % 10)
				return true;
		}
		temp = n % 10;
		n /= 10;
	}
	
	return false;	
}
