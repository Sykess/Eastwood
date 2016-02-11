
#include <iostream>
using namespace std;



int main()
{
	int  squares = 0, natural = 0;
	
	for(int x = 1; x <= 100; x++)
	{
		squares += x * x;
		natural += x;
	}
	natural *= natural;
	cout <<  natural - squares;
	return 0;
}
