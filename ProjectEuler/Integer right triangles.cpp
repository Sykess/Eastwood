

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>

using namespace std;

int thirdSide(int a, int b);

int main()
{
	int c = 0;
	int p[1000];
	int max = 0;
	int valueP = 0; // p = perimeter
	for(int x = 0; x < 1000; x++)
		p[x] = 0;
		
	for(int a = 1; a < 500; a++)
	{
		for(int b = a; b < 500; b++)
		{
			c = thirdSide(a, b);
			if(c != 0 && a+b+c < 1000)
			{
				p[a+b+c]++;
				//cout << a << " " << b << " " << c << endl;
			}
		}
	}
	for(int x = 0; x < 1000; x++)
	{
		if(p[x] > max)
		{
			max = p[x];
			valueP = x;
		}
	}
	cout << valueP;
}

int thirdSide(int a, int b)
{
	double side = sqrt(a * a + b * b);
	if(side == (int) side)
		return (int)side;
	return 0;
}



