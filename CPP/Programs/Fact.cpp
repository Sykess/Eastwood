
#include <iostream>
using namespace std;

#define MAX 65

int factorial(int n);
bool duplicate(int * arr, int n, int c);
void resetArr(int * arr);

int main()
{
	int fact[10];
	int dup[MAX];
	int chains = 0, temp, newNum, total(0);
	
	for(int i = 0; i < 10; i++)
		fact[i] = factorial(i);
	
	for(int i = 1; i < 1000000; i++)
	{
		resetArr(dup);
		dup[0] = i;
		newNum = i;
		
		chains = 0;
		do{
		
			temp = newNum;
			newNum = 0;
			while(temp > 0)
			{
				newNum += fact[temp % 10];
				temp /= 10;
			}
			chains++;
		}while(duplicate(dup, newNum, chains));
		if(chains == 60)
			total++;
	}
	
	cout << total;
	
	return 0;
}

//checks for duplicate and if not adds num to array
bool duplicate(int * arr, int num, int c)
{
	for(int i = 0; i < c; i++)
		if(arr[i] == num)
			return false;
			
	arr[c] = num;
	return true;
}

void resetArr(int * arr)
{
	for(int i = 0; i < MAX; i++)
		arr[i] = 0;
}

int factorial(int n)
{
	int temp;
	
	if(n <= 1)
		return 1;
		
	temp = n * factorial(n - 1);
	
	return temp;
}


