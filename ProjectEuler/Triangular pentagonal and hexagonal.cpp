

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool isPentagonal(int num);
bool isHexagonal(int num);
bool isTriangular(int num);

int main()
{
	int hex, tri, pen;
	
	//note all hex numbers are also tri numbers, so only need to generate hex and check
	//if they are pentagonal.  The other functions I created are unneeded
	for(int x = 145; x < 50000; x++)
	{
		hex = x * (2 * x - 1);
		if(isPentagonal(hex))
			cout << hex;
	}
	
}



bool isPentagonal(int num)
{
	//use quadratic equation to get this formula
	double pentag = (sqrt(1.0 + 24.0 * num) + 1.0 ) / 6.0;
	
	//cout << pentag;
	return( pentag == (int) pentag);
}

bool isTriangular(int num)
{
	double tri = (sqrt(1 + 8.0 * num) - 1) / 2;
	return( tri == (int) tri);
}

bool isHexagonal(int num)
{
	double hex = (sqrt(1 + 8.0 * num) + 1) / 4;
	return( hex == (int) hex);
}
