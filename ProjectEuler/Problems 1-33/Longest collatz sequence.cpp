
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;



int main()
{
	unsigned  long long n;
	int chains, longestChain, longestNum;
	
	for(int x = 1; x <= 1000000; x++)
	{
		n = x;
		chains = 0;
		while(n != 1)
		{
			if(n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
			chains++;
		}
		if(longestChain < chains)
		{
			longestChain = chains;
			longestNum = x;
		}
	}
	cout << longestNum <<  endl << longestChain;
}


