#include <iostream>
using namespace std;

int getDivSum(int num);
bool array[1000000] = {false};

int main()
{
	int chain = 0;
	int temp1 = 0, temp2 = 0;
	int highestChain = 0;
	bool found = false;
	
	for(int i = 12496; i < 15000; i++)
	{
		chain = 1;
		if(array[i])
			continue;
		found = false;
		temp1 = getDivSum(i);
		if(temp1 >= 1000000)
			continue;;

		array[temp1] = true;
		
		while(temp1 != i && chain < 30 && temp1 != 1 && temp1 < 1000000)
		{
			temp1 = getDivSum(temp1);

			if(temp1 >= 1000000)
				break;
			array[temp1] = true;
			chain++;
			if(temp1 == i)
				found = true;
		}
		if(chain > highestChain && found)
		{
			highestChain = chain;
			temp2 = i;
		}
		
	}
	cout << temp2 << "  " << highestChain;
	
}

int getDivSum(int num)
{
	int sum = 0;
	for(int i = 1; i <= num / 2; i++)
	{
		if(num % i == 0)
			sum += i;
	}
	return sum;
}
