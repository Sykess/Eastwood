
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double factorial(double num);

int main()
{
	
	cout << factorial(100);
	
}


double factorial(double num)
{
	if(num == 1)
		return num;
	num *= factorial(num - 1);
}

