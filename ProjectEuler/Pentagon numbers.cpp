

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool isPentagonal(int num);

int main()
{
	int num1, num2;
	for(int x = 1; x <= 3000; x++)
	{
		for(int y = x+1; y <= 3000; y++)
		{
			num1 = x * (3 * x - 1) / 2;
			num2 = y * (3 * y - 1) / 2;
			if(isPentagonal(num1) && isPentagonal(num2))
			{
				if(isPentagonal(num2 - num1) && isPentagonal(num1 + num2))
				{
					cout << x << " " << y << endl;
					cout << num2 - num1;
				}
			}
		}
	}
	
}



bool isPentagonal(int num)
{
	double pentag = (sqrt(1.0 + 24.0 * num) + 1.0 ) / 6.0;
	
	//cout << pentag;
	return( pentag == (int) pentag);
}
