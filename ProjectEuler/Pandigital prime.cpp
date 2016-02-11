

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool isPand(string s);
bool isPrime(int num);

int main()
{
	int largest = 0;
	char buff[256];
	string str;
	
	for(int x = 10000000; x > 0; x--)
	{
		if(isPrime(x))
		{
			str = itoa(x, buff, 10);
			if(isPand(str))
			{
				if(x > largest)
				{
					largest = x;
					break;
				}
			}
		}
	}
	cout << largest;
	
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

bool isPand(string s)
{
	char buff[15];
	int isPand[10];
	for(int x = 0; x < 10; x++)
	{
		isPand[x] = 0;
	}
	
	for(int x = 0; x < s.size(); x++)
	{
		buff[x] = s[x];
		if(x+1 == s.size())
			buff[x+1] = '\0';
	}
	long pand = atoi(buff);
	
	while(pand > 0)
	{
		isPand[pand % 10]++;
		pand /= 10;
	}
	for(int x = 1; x < s.size(); x++)
	{
		if(isPand[x] != 1)
			return false;
	}
	for(int x = s.size()+1; x < 10; x++)
	{
		if(isPand[x] > 0)
			return false;
	}
	if(isPand[0] != 0)
		return false;
	return true;

}
