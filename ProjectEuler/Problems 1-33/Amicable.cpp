

//problem 21, sum of all amicable numbers under 1000 
//amicable - d(a) = b and d(b) = a while a != b, d = proper divisors

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include "Sll.h"
using namespace std;

int sum(int num);

int main()
{
	Sll list;
	int total = 0;
	int fullSum = 0;
	
	for(int x = 1; x < 10000; x++)
	{
		total = sum(x);
		if(sum(total) == x)
		{
			if(!list.addItem(x))
				fullSum += (x + total);
			list.addItem(total);
		}
	}
	
	cout << fullSum;
	
}

int sum(int num)
{
	int sum = 0;
	for(int x = 1; x <= num / 2; x++)
	{
		if(num % x == 0)
			sum += x;
	}
	return sum;
}

