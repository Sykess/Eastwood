
// problem 46: Goldbach's other conjecture.

/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool isPrime(int num);
bool isConjecture(int num);

int main()
{
	int temp, squareNum;
	int firstNon = 0;
	for(int x = 3; x < 10000; x+= 2)
	{
		squareNum = 1;
		if(!isPrime(x))
		{
			if(!isConjecture(x))
				if(firstNon < x && firstNon == 0)
					firstNon = x;
		}
		
	}
	cout <<  firstNon;
}

bool isConjecture(int num)
{
	int squareNum;
	for(int y = 3; y < num - 1; y++)
	{
		squareNum = 1;
		if(isPrime(y))
		{
			while(2 * squareNum * squareNum < num)
			{
				if(y + 2 * squareNum * squareNum == num)
					return true;
				squareNum++;
			}
		}
	}
	return false;
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
