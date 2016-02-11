

#include <iostream>
using namespace std;

bool isPal(int num);

int main()
{
	int largest = 0;
	
	for(int x = 100; x < 1000; x++)
	{
		for(int y = 100; y < 1000; y++)
		{
			if(isPal(x * y))
				if(x * y > largest)
					largest = x * y;
		}
	}
	
	cout << largest;
	
	return 0;
}

bool isPal(int num)
{
	int temp = num;
	int newNum = 0, degree = 1;
	while(temp / 10 > 0 || temp % 10 > 0)
	{
		newNum *= 10;
		newNum += temp % 10;
		temp /= 10;
	}
	if(num == newNum)
		return true;
	return false;
}
