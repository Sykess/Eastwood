

#include <iostream>
using namespace std;

const int XSIZE = 6;
const int YSIZE = 6;

bool valid(int maze[XSIZE][YSIZE], int x, int y);
bool rat(int maze[XSIZE][YSIZE], int x, int y, int move);
void display(int maze[XSIZE][YSIZE]);

int main()
{
	int maze[XSIZE][YSIZE] = {{1, 1, 1, 9, 1, 1},
							  {1, 0, 0, 0, 0, 1},
							  {1, 0, 0, 0, 0, 1},
							  {1, 1, 0, 0, 0, 1},
							  {1, 0, 0, 0, 0, 0},
							  {1, 1, 1, 0, 0, 0}};
	cout << rat(maze, 3, 2, 2);
	
	
	
}

bool rat(int maze[XSIZE][YSIZE], int x, int y, int move)
{
	if(maze[x][y] == 9)
		return true;
	if(!valid(maze, x, y))
		return false;
	maze[x][y] = move;
	
	for(int z = 0; z < 1000000000; z++);
	
	system("CLS");
	display(maze);
	
	if(rat(maze, x-1, y, ++move))
		return true;
	else
		rat(maze, x-1, y, --move);
		
	if(rat(maze, x+1, y, ++move))
		return true;
	else
		rat(maze, x+1, y, --move);
		
	if(rat(maze, x, y-1, ++move))
		return true;
	else
		rat(maze, x, y - 1, --move);
		
	if(rat(maze, x, y+1, ++move))
		return true;
	else
		rat(maze, x, y+1, --move);
	maze[x][y] = 0;
	return false;
}

void display(int maze[XSIZE][YSIZE])
{
	for(int x = 0;  x < XSIZE; x++)
	{
		for(int y = 0; y < YSIZE; y++)
		{
			cout << maze[x][y] << " ";
		}
		cout << endl;
	}
}

bool valid(int maze[XSIZE][YSIZE], int x, int y)
{
	if((x < 0) || y < 0 || y == YSIZE || (x == XSIZE))
		return false;
	if((maze[x][y] != 0) )
		return false;
	return true;
}
