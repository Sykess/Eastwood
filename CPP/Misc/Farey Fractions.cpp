

#include <iostream>
#include <iomanip>

using namespace std;

void printFarey(int x);

int main()
{
	printFarey(3);
}


void printFarey(int x)
{
	int a = 0, b = 1, c = 1, d = x, position = 0;
	int k, newA, newB;
	int numer[30], denom[30];
	for(int i = 0; i < 30; i++)
		numer[i] = denom[i] = 0;
	
	numer[position] = a, denom[position] = b;
	position++;
	numer[position] = c, denom[position] = d;
	
	while(!(numer[position] == 1 && denom[position] == 1))
	{
		position++;
		k = (int)((x + b) / d);
		newA = c, newB = d;
		c = k * c - a;
		d = k * d - b;
		numer[position] = c;
		denom[position] = d;
		a = newA, b = newB;
	}
	//cout << numer[0] << " " << numer[1] << " " << numer[2];
	for(int i = 0; !(numer[i] == 1 && denom[i] == 1);i++)
	{
		cout << setw(2) << numer[i];
	}
	cout << setw(2) << 1 << endl;
	for(int i = 0;!(numer[i] == 1 && denom[i] == 1);i++)
	{
		cout << setw(2) << denom[i];
	}
	cout << setw(2) << 1 << endl;
}



