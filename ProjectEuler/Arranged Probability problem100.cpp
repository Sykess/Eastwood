
#include <iostream>
using namespace std;


int main()
{
	unsigned long long b = 15;
	unsigned long long n = 21;
	unsigned long long target = 1000000000000;
	
	while(n < target)
	{
		unsigned long long btemp = 3 * b + 2 * n - 2;
		unsigned long long ntemp = 4 * b + 3 * n - 3;
		
		b = btemp;
		n = ntemp;
	}
	cout << "B is: " << b << "\nN is: " << n;
}
