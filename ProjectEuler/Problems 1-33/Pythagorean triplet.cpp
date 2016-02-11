
#include <iostream>
using namespace std;



int main()
{
	int answer;
	
	for(int x = 0; x < 500; x++)
	{
		for(int y = 0; y < 500; y++)
		{
			for(int z = 0; z < 500; z++)
			{
				if(x * x + y * y == z * z)
					if(x + y + z == 1000)
						answer = x * y * z;
			}
		}
	}
	cout << answer;
}


