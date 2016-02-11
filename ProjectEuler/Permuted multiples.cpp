

#include <iostream>

using namespace std;

bool permuted(int x);

int main()
{
	for(int x = 1; x < 10000000; x++)
	{
		if(permuted(x))
		{
			cout << x;
			break;
		}
	}
	
	return 0;
}

bool permuted(int x)
{
	int temp, orig;
	int array1[10], array2[10];
	for(int a = 0; a < 10; a++)
		array1[a] = array2[a] = 0;
	orig = x;
	temp = 2 * x;
	while(temp > 0)
	{
		array2[temp % 10]++;
		temp /= 10;
	}
	while(orig > 0)
	{
		array1[orig % 10]++;
		orig /= 10;
	}
	for(int a = 0; a < 10; a++)
	{
		if(array1[a] != array2[a])
			return false;
		array2[a] = 0;
	}
	temp = 3 * x;
	while(temp > 0)
	{
		array2[temp % 10]++;
		temp /= 10;
	}
	for(int a = 0; a < 10; a++)
	{
		if(array1[a] != array2[a])
			return false;
		array2[a] = 0;
	}
	temp = 4 * x;
	while(temp > 0)
	{
		array2[temp % 10]++;
		temp /= 10;
	}
	for(int a = 0; a < 10; a++)
	{
		if(array1[a] != array2[a])
			return false;
		array2[a] = 0;
	}
	temp = 5 * x;
	while(temp > 0)
	{
		array2[temp % 10]++;
		temp /= 10;
	}
	temp = 6 * x;
	for(int a = 0; a < 10; a++)
	{
		if(array1[a] != array2[a])
			return false;
	}
	return true;
}

