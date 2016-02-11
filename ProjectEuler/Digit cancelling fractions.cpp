

#include <iostream>
using namespace std;



int main()
{
	double a, b;
	double denom = 1;
	double numer = 1;
	
	
	for(double x = 10; x <= 50; x++)
	{
		for(double y = 50; y <= 99; y++)
		{
			if((int)y % 10 == 0)
				continue;
			if((int) x / 10 == (int) x % 10 || (int) y / 10 == (int) y % 10)
				continue;
			a = (int)x % 10;
			b = (int)y / 10;
			//cout << a << " " << b << endl;
			//cout << x << " " << y << endl;
			if(a == b)
			{
				a = (int)x / 10;
				b = (int)y % 10;
				if(a / b == x / y)
				{
					cout << x << " " << y << endl;
					numer *= x;
					denom *= y;
				}
			}
			a = (int) x / 10;
			b = (int) y % 10;
			if(a == b)
			{
				a = (int)x % 10;
				b = (int)y / 10;
				if(a / b == x / y)
				{
					cout << x << " " << y << endl;
					numer *= x;
					denom *= y;
				}
			}
		}
	}
	for(int x = (int) denom / 2; x >= 2; x--)
	{
		if((int)numer % x == 0 && (int)denom % x == 0)
		{
			numer /= x;
			denom /= x;
		}
	}
	cout << numer << " / " << denom;
}
