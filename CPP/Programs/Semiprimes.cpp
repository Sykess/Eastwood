
#include <iostream>
#include <vector>
using namespace std;

int factors(int num);

int main()
{
	int total(1);
	int old = 0;
	int neww;


	
	for(int i = 4; i < 10000000; i++)
	{
		neww = factors(i);
		if(old == neww)
			total++;
		old = neww;
	}
	cout << total;
	
}


int factors(int num)
{
	//vector<int> fac;
	int fact = 2;
	
	for(int x = 2; x <= num / 2; x++)
	{
		if(num % x == 0)
		{
			fact++;
			//fac.push_back(x);
			
			//num /= x;
		}
	}
	//if(num > 1)
		//fact++;
		//fac.push_back(num);
		
	return fact;
	
}
