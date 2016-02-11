
#include <iostream>
using namespace std;

void blah(int);

int main()
{
	blah(3);
	cout << "\n" << __func__;
	
	
}

void blah(int a)
{
	cout << __FUNCTION__;
}
