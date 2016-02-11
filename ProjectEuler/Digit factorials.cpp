

#include <iostream>
using namespace std;

double factorial(double x);

int main()
{
	//cout << factorial(3);
	double num, sum, total = 0;
	
	/*
	for(double x = 10; x <= 5000000000; x++)
	{
		num = x;
		sum = 0;
		while(num > 0)
		{
			sum += factorial((int)num % 10);
			num = (int)num / 10;
		}
		if(sum == x)
			total += x;
	}
	cout << total;*/
	cout << factorial(20);
}

double factorial(double x)
{
	if(x == 0)
		return 1;
	
	double y = x * factorial(x - 1);
	cout << y << endl;
	return y;
	//return (x * factorial(x- 1));
}
