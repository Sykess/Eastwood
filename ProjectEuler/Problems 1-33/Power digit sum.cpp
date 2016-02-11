
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

///////////////////// Resorted to java for this

int main()
{
	double num= pow(2, 1000);
	//double num = 235;
	printf("%f", num);
	
	double added = 0;
	
	while(num > 0)
	{
		added += (unsigned long  long int) num % 10;
		num /= 10;
	}
	cout << endl << added;
	
}


