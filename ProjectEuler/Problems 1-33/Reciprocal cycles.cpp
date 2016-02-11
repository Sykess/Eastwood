

#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	int sequenceL = 0;
	int num = 0;
	int remainders[100];
	for(int x = 0; x < 100; x++)
		remainders[x] = 0;
	
	for(int x = 999; x > 1; x--)
	{
		if(sequenceL >= x)
			break;
		
		//int remainders[x];
		int value = 1;
		int position = 0;
		//cout << remainders[value];
		while(remainders[value] == 0 && value != 0)
		{
			remainders[value] = position;
			value *= 10;
			value %= x;
			position++;
			cout << position << endl;
		}
		
		if(position - remainders[value] > sequenceL)
		{
			sequenceL = position - remainders[value];
			num = x;
		}
		
	}
	cout << num << endl << sequenceL;
	

	
}


