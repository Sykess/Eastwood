
#include <iostream>
using namespace std;

int array[10000000] = {0};

int main()
{
	const int max = 10000000;
	int temp;
	int total = 1;
	
	for(int i = 2; i <= max/2; i++)
	{
		temp = i;
		while(temp < max)
		{
			array[temp]++;
			temp += i;
		}
	}
	for(int i = 4; i < max - 1; i++)
	{
		if(array[i] == array[i+1])
			total++;
	}
	
	cout << total;
	
}
