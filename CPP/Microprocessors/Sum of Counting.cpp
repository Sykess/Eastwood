

#include <iostream>
using namespace std;

int sumOfCounting(int num);
int sumAnotherWay(int num);
int sumWithRecursion(int num, int index, int total);
int sumOverlyComplicated(int num);
int complicatedOdd(int num);
int complicatedEven(int num);
int pairs(int num);


int main()
{
	cout << sumOfCounting(100);
	cout << endl << sumAnotherWay(100);
	cout << endl << sumWithRecursion(100, 0, 0);
	cout << endl << sumOverlyComplicated(100);
	cout << endl << pairs(100);
	
}

int sumOfCounting(int num)
{
	int total = 0;
	for(int x = 1; x <= num; x++)
		total += x;
	return total;
}

int pairs(int num)
{
	int high = num;
	int total = 0;
	
	for(int low = 1; high > low; high--, low++)
		total += high + low;

	return total;
}

int sumAnotherWay(int num)
{
	int index = 0, total = 0;
	while(index < num)
	{
		index++;
		total += index;
	}
	return total;
}

int sumWithRecursion(int num, int index, int total)
{
	if(num < index)
		return total;
	return sumWithRecursion(num, index + 1, total += index);
}

int sumOverlyComplicated(int num)
{
	if(num % 2 == 0)
		complicatedEven(num);
	else
		complicatedOdd(num);
}

int complicatedEven(int num)
{
	int total = 0;
		
	for(int x = 2; x <= num; x+= 2)
		total += x;
		
	if(num % 2 == 0)
		total += complicatedOdd(num);
		
	return total;
}

int complicatedOdd(int num)
{
	int total = 0;
	
	for(int x = 1; x <= num; x+= 2)
		total += x;
	
	if(num % 2 != 0)
		total += complicatedEven(num);
	
	return total;
}

