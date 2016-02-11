

// problem 30
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int main()
{
	int finalSum = 0;
	
	for(int x = 2; x < 200000; x++)
	{
		int tempSum = 0;
		int number = x;
		
		while(number > 0)
		{
			int digit = number % 10;
			number /= 10;
			
			int temp = digit;
			for(int y = 1; y < 5; y++)
				temp *= digit;
			tempSum += temp;
		}
		if(tempSum == x)
			finalSum += x;
	}
	cout << finalSum;
}
