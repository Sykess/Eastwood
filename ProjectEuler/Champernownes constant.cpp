

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <math.h>

using namespace std;



int main()
{
	char buffer[256];
	string str;
	int total = 1;
	
	for(int x = 1; x < 200000; x++)
	{
		str.append(itoa(x, buffer, 10));
	}
	buffer[0] = str[0];
	buffer[1] = str[9];
	buffer[2] = str[99];
	buffer[3] = str[999];
	buffer[4] = str[9999];
	buffer[5] = str[99999];
	buffer[6] = str[999999];
	buffer[7] = '\0';
	int numbers = atoi(buffer);
	
	while(numbers > 0)
	{
		total *= numbers % 10;
		numbers /= 10;
	}
	cout << total;
}




