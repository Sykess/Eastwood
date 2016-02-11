
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double factorial(double num);
double combinSel(double n, double r);

int main()
{
	
	//cout << setprecision(15) << combinSel(23, 10);
	int total = 0;
	
	for(int n = 5; n <= 100; n++)
	{
		for(int r = 1; r < n - 1; r++)
		{
			if(combinSel(n, r) > 1000000)
				total++;
		}
	}
	cout << total;
}

double combinSel(double n, double r)
{
	return factorial(n) / (factorial(r) * factorial(n - r));
}

double factorial(double num)
{
	if(num == 1)
		return num;
	return num *= factorial(num - 1);
}

