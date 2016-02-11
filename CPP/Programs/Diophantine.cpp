
#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	unsigned long long x, y;
	int max(0), final(0);
	
	for(unsigned long long d = 661; d <= 662; d++)
	{
		if((int)sqrt(d) == (double)sqrt(d))
			continue;
		x = 2;
		y = 1;
		while((x * x - y * y * d) != 1)
		{
			if(x * x > y * y * d)
				y++;
			else
				x++;
		}
		if(x > max)
		{
			max = x;
			cout << x << endl;
			final = d;
		}
		
		
	}
	cout << final;
	
	
	
}
