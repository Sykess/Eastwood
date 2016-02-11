

#include <iostream>
#include <iomanip>
using namespace std;

void swap(int x, int y, int array[]);

int main()
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int count = 1;
	int max = 1000000;
	
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
	}
	for(int x = 0; x < 10; x++)
		cout << array[x];
	
}

void swap(int x, int y, int array[])
{
	int z = array[x];
	array[x] = array[y];
	array[y] = z;
}
