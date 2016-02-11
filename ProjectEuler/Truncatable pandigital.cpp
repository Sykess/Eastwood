

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;


bool isPand(string s);

int main()
{
	
	char buff[256];
	string str;
	int n;
	int pand[10];
	int highest = 0;
	
	for(int x = 1; x <= 10000; x++)
	{
		n = 1;
		str = itoa(x, buff, 10);
		
		while(str.size() < 9)
		{
			n++;
			str.append(itoa(x * n, buff, 10));
		}
		if(str.size() == 9)
		{
			
			if(isPand(str))
			{
				for(int y = 0; y < str.size(); y++)
				{
					buff[y] = str[y];
					if(y+1 == str.size())
						buff[y+1] = '\0';
				}
			
				if(atoi(buff) > highest)
				{
					highest = atoi(buff);
					cout << "x is: " << x << " n is: " << n << endl;
				}
			}
		}
		
	}
	cout << highest;
}

bool isPand(string s)
{
	char buff[15];
	int isPand[10];
	for(int x = 0; x < 10; x++)
	{
		isPand[x] = 0;
	}
	
	for(int x = 0; x < s.size(); x++)
	{
		buff[x] = s[x];
		if(x+1 == s.size())
			buff[x+1] = '\0';
	}
	long pand = atoi(buff);
	
	while(pand > 0)
	{
		isPand[pand % 10]++;
		pand /= 10;
	}
	for(int x = 1; x < 10; x++)
	{
		if(isPand[x] != 1)
			return false;
	}
	if(isPand[0] != 0)
		return false;
	return true;

}


