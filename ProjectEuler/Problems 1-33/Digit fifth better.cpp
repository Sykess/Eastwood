
//problem 30
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int main()
{
	int sum, num, total = 0;
	
	for(int x = 10; x < 200000; x++) // started with 350k but through trial and error went with 200k
	{
		sum = 0;
		num = x;
		
		do
		{
			sum += pow(num % 10, 5); //raise each digit to 5th power and add to sum
			num /= 10;
		}while(num > 0);
		
		if(x == sum)
			total += x;
	}
	cout  << total;
}
