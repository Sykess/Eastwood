#include <iostream>
#include <fstream>
using namespace std;

void importArray();

int array[80][80] = {0};

int main()
{
    importArray();
	
	
	//build bottom and right rows
	for(int i = 78; i >= 0; i--)
	{
		array[79][i] += array[79][i+1];
		array[i][79] += array[i+1][79];
	}
	for(int x = 78; x >= 0; x--)
	{
		for(int y = 78; y >= 0; y--)
		{
			if(x == 0 && y == 0)
			{
				array[y][x] += array[0][1];
				break;
			}
			array[y][x] += (array[y][x+1] < array[y+1][x] ? array[y][x+1] : array[y+1][x]);
			
		}
	}
    
    cout << array[0][0];
    
    return 0;
}

void importArray()
{
	fstream file("matrix.txt", ios::in);
    int x = 0, y = 0;
    char dummy;
    while(file.good())
    {
    	file >> array[y][x];
    	file >> dummy;
    	if(x >= 79)
    	{
    		x = 0;
    		y++;
		}
		else
			x++;
    }
    file.close();
}



