#include <iostream>
using namespace std;


void setArray();
bool isRight(int a, int b, int c);

int array[1500000] = {0};

int main()
{
//	setArray();
cout << "hi";
		for(int a = 3; a < 3000; a++)
	{
		for(int b = 4; b < 3000; b++)
		{
			for(int c = 5; c < 3000; c++)
			{
				//if(isRight(a, b, c))
					//array[a+b+c]++;
				if(a > 1000)
					cout << "hi";
			}
		}
	}
	
	
	return 0;
}
/*
void setArray()
{
	for(int a = 3; a < 300000; a++)
	{
		for(int b = 4; b < 300000; b++)
		{
			for(int c = 5; c < 300000; c++)
			{
				//if(isRight(a, b, c))
					//array[a+b+c]++;
				if(a > 1000)
					cout << "hi";
			}
		}
	}
}



bool isRight(int a, int b, int c)
{
	if( (a * a + b * b) == c * c )
		return true;
	return false;
}*/
