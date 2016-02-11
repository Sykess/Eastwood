

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;


void swap(int x, int y, int array[]);

int main()
{
	int array[] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};
	int div[] = {2, 3, 5, 7, 11, 13, 17};
	
	int count = 1;
	int temp = 0;
	int max = 3265920; // max combos since can't start with 0, 9 * 9! to obtain
	//int max = 3628800; max starting with 0 (swith 0 and 1 in array) 10! to obtain
	unsigned long long total = 0;
	bool good = true;
	
	while(count < max)
	{
		int n = 10; // elements
		int x = n - 1;
		while(array[x - 1] >= array[x])
			x--;
		
		int y = n;
		while(array[y - 1] <= array[x - 1])
			y--;
			
		swap(x - 1, y - 1, array);
		x++;
		y = n;
		while(x < y)
		{
			swap(x - 1, y - 1, array);
			x++;
			y--;
		}
		count++;
		good = true;
		for(int z = 0; z < 7; z++)
		{
			temp = 0;
			temp = array[z+3];
			temp+= array[z+2] * 10;
			temp+= array[z+1] * 100;
			if(temp % div[z] != 0)
				good = false;		
		}
		if(good)
		{
			total += array[9];
			total += array[8] * 10;
			total += array[7] * 100;
			total += array[6] * 1000;
			total += array[5] * 10000;
			total += (unsigned long long)array[4] * 100000;
			total += (unsigned long long)array[3] * 1000000;
			total += (unsigned long long)array[2] * 10000000;
			total += (unsigned long long)array[1] * 100000000;
			total += (unsigned long long)array[0] * 1000000000;
		}
	}
	cout << total;
	
}

void swap(int x, int y, int array[])
{
	int z = array[x];
	array[x] = array[y];
	array[y] = z;
}


