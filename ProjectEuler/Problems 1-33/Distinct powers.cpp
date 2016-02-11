
#include <iostream>
#include <math.h>
#include <iomanip>
#include "Sll.h"
using namespace std;


int main()
{
	Sll list;
	double result;
	
	for(int x = 2; x <= 100; x++)
	{
		for(int  y = 2; y <= 100; y++)
		{
			result = pow(x,y);
			if(!list.findItem(result))
				list.addItem(result);
		}
	}
	cout << list.total();
	
}
