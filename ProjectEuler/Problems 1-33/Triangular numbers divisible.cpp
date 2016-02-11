
#include <iostream>
#include <math.h>
using namespace std;



int main()
{
	int divisors;
	int triangleNumber = 0;
	
	
	for(int x = 1; x <= 20000; x++)
	{
		triangleNumber+= x;
		divisors = 0;
		for(int y = 1; y <= sqrt(triangleNumber); y++)
		{
			if(triangleNumber % y == 0)
				divisors+= 2;
		}
		if(sqrt(triangleNumber) * sqrt(triangleNumber) == triangleNumber)
			divisors--;
			
		if(divisors > 500)
		{
			cout << triangleNumber;
			break;
		}
	}
	
}


