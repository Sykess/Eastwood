#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int array[] = {1,2,1,1,4,1,1,6,1,1,8,1,1,10,1,1,12,1,1,14,1,1,16,1,1,18,1,1,20,
				   1,1,22,1,1,24,1,1,26,1,1,28,1,1,30,1,1,32,1,1,34,1,1,36,1,1,38,
				   1,1,40,1,1,42,1,1,44,1,1,46,1,1,48,1,1,50,1,1,52,1,1,54,1,1,56,
				   1,1,58,1,1,60,1,1,62,1,1,64,1,1,66,1,1,68,1,1,70,1,1,72,1,1,74};
	std::cout << "Size is: " << sizeof(array) / sizeof(int) << std::endl;
	unsigned long long numer, denom, temp;
	numer = 1;
	denom = array[98];
	
	for(int x = 98; x >= 0; x--)
	{
		numer += (array[x-1] * denom);
		temp = numer;
		numer = denom;
		denom = temp;
	}
	temp = numer;
	numer = denom;
	denom = temp;
	numer += 2 * denom;
	std::cout << "Numerator: " << numer << "\nDenominator: " << denom;
	
	return 0;
}
