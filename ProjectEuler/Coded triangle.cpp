

#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;

void loadNames();
void loadTri();

// names[1785]; is last name

string names[2000];
int triVals[20];

int main()
{
	loadNames();
	loadTri();
	
	int count;
	int triangleWords = 0;
	
	
	for(int x = 0; x < 1786; x++)
	{
		count = 0;
		for(int y = 0; y < names[x].size(); y++)
		{
			count += names[x][y] - 64;
		}
		for(int z = 0; z < 20; z++)
		{
			if(triVals[z] == count)
			{
				triangleWords++;
				cout  << "Tri num: " << names[x] << endl;
			}
		}
	}
	cout << triangleWords;
	
	
}

void loadTri()
{
	for(int x = 0; x < 20; x++)
	{
		triVals[x] = (x+1) * (x+2) / 2;
	}
}


void loadNames()
{
	ifstream file;
	file.open("words.txt");
	int pos = 0;
	
	stringstream ss;
	ss << file.rdbuf();
	string str = ss.str();
	file.close();
	
	for(int x = 0; x < str.size(); x++)
	{
		if(str[x] != '"')
		{
			if(str[x] != ',')
				names[pos].append(1, str[x]);
			else
				pos++;
		}
	}
}


