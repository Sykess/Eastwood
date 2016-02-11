

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

bool isPrime(int num);

int main()
{
	int num1, num2, num3;
	int array1[10], array2[10], array3[10];
	int same = 0;
	
	for(int x = 1000; x <= 3340; x++)
	{
		if(isPrime(x))
		{
			num2 = x + 3330;
			if(isPrime(num2))
			{
				num3 = num2 + 3330;
				if(isPrime(num3))
				{
					num1 = x;
					for(int y = 0; y < 10; y++)
						array1[y] = array2[y] = array3[y] = 0;
					while(num1 > 0)
					{
						array1[num1 % 10]++;
						num1 /= 10;
					}
					while(num2 > 0)
					{
						array2[num2 % 10]++;
						num2 /= 10;
					}
					while(num3 > 0)
					{
						array3[num3 % 10]++;
						num3 /= 10;
					}
					same = 0;
					for(int y = 0; y < 10; y++)
					{
						if(array1[y] == array2[y])
							if(array2[y] == array3[y])
								same++;
					}
					if(same == 10)
						cout << x << x+3330 << x+6660 << endl;
				}
			}
		}
	}
	
	
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


