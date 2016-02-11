
#include <iostream>
using namespace std;



int main()
{
	bool cont = true;
	int num = 2000;
	
	while(cont)
	{
		num++;
		for(int x = 1; x <= 20; x++)
		{
			if(num % x != 0)
				break;
			if(x == 20)
				cont = false;
		}	
	}
	
	cout  << num;
	
	return 0;
}
