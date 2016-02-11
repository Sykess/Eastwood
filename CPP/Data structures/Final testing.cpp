

#include <iostream>
using namespace std;


void Func(int n);
void Quiz(int n);

int main()
{
	//Func(73);
	Quiz(2);
}


void Func(int n)
{
	if(n > 0)
	{
		Func(n/5);
		cout << n % 5;
	}
}

void Quiz(int n)
{
	if(n > 0)
	{
		cout << 0;
		Quiz(n-1);
		cout << 1;
		Quiz(n-1);
	}
}
