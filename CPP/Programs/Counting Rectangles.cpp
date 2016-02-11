#include <iostream>
using namespace std;

int numOfRects(int x, int y);

int main()
{
	int currRects = 0, area = 0;
	int distanceCurr(0), distanceClosest(100000);
	
	double i = 1.41, j = 1.4;
	if(i == j)
		cout << "They're equal";
	else
		cout << "They're not equal";
	
	for(int x = 1; x < 200; x++)
	{
		for(int y = x; y < 200; y++)
		{
			currRects = numOfRects(x, y);
			
			if(currRects > 1900000 && currRects < 2000000)
			{
				distanceCurr = 2000000 - currRects;
				if(distanceCurr < distanceClosest)
				{
					distanceClosest = distanceCurr;
					area = x * y;
					cout << "x: " << x << " y: " << y << endl;
					cout << "Area: " << area << " Rects: " << currRects << endl;
					break;
				}
			}
			/*if(currRects > 2000000 && currRects < 2100000)
			{
				distanceCurr = currRects - 2000000;
				if(distanceCurr < distanceClosest)
				{
					distanceClosest = distanceCurr;
					area = x * y;
				}
				//break;
			}*/
			if(currRects > 2000000)
				break;
		}
		if(currRects > 2100000)
			break;
	}
	cout << area;
}

int numOfRects(int x, int y)
{
	int rects = 0;
	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < y; j++)
		{
			rects += (x - i) * (y - j);
		}
	}
	return rects;
}
