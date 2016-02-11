

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;




bool isPrime(int num);
void getDigitPatterns(int (*val5)[5], int (*val6)[6]);



int main()
{
	int (*val5)[5], (*val6)[6];
	getDigitPatterns(val5, val6);
	
	cout << *val5[1][1];
}

void getDigitPatterns(int (*val5)[5], int (*val6)[6])
{	
	int retval6[][6] = 
		 {{1, 1, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 1},
		  {1, 0, 0, 1, 0, 1}, {1, 0, 0, 0, 1, 1},
	 	  {0, 1, 1, 0, 0, 1}, {0, 1, 0, 1, 0, 1},
	 	  {0, 1, 0, 0, 1, 1}, {0, 0, 1, 1, 0, 1},
	 	  {0, 0, 1, 0, 1, 1}, {0, 0, 0, 1, 1, 1}};
	
	int retval5[4][5] = 
	 {{1, 0, 0, 0, 1}, {0, 1, 0, 0, 1},
 	  {0, 0, 1, 0, 1}, {0, 0, 0, 1, 1}};
 	int (* val)[5] = retval5;
 	int (* val2)[6] = retval6;
 	val5 = val;
 	val6 = val2;
}

bool isPrime(int num)
{
	if(num == 1)
		return false;
	for(int x = 2; x <= num / x; x++)
	{
		if(num % x == 0 )
			return false;
	}
	return  true;
}      
