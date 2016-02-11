/******************************************************************************
program:	KnightTour.cpp
author:		A.Hayden
date:		04/17/15
assignment:	#6-1
purpose:	Knight's tour program using recursion with back-tracking
******************************************************************************/

#include <iostream>
using namespace std;



////////////////// FUNCTION PROTOTYPES/////////////////////////////////////////

bool knight(int **board, int xSize, int ySize, int x, int y, int move);
bool valid(int **board, int xSize, int ySize, int x, int y);
void display(int **board, int xSize, int ySize);

///////////////////////////////////////////////////////////////////////////////

int main()
{
	int xStart, yStart, xSize, ySize;
	
	cout << "\nEnter your the width of your board: ";
	cin >> xSize;
	cout << "\nEnter your the height of your board: ";
	cin >> ySize;
	
	cout << "\nEnter your starting 'x' position: ";
	cin >> xStart;
	cout << "\nEnter your starting 'y' position: ";
	cin >> yStart;
	
	int **board;
	board = new int *[xSize];
	for(int y = 0; y < ySize; y++)
	        board[y] = new int [ySize];
	    
	for(int i = 0; i < xSize; i++)
		for(int j = 0; j < ySize; j++)
			board[i][j] = 0;
	
	if(knight(board, xSize, ySize, xStart, yStart, 1))
	    display(board, xSize, ySize);
    else 
		cout << "\nUnable to find solution.";
	
	cout << endl << endl;
	system("pause");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

bool knight(int **board, int xSize, int ySize, int x, int y, int move)
{
	if(!valid(board,xSize, ySize, x, y))
		return false;
	//cout << valid(board,xSize, ySize, x, y);
	board[x][y] = move;
	if(move == xSize * ySize)	// base case knight's tour complete
		return true;
		
/*	int moves[2][8] = {{2, 1, -1, -2, -2, -1, 1, 2},
				 	   {1, 2, 2, 1, -1, -2, -2, -1}};*/
				  
	if(knight(board, xSize, ySize, x +2, y +1, move + 1)) // L U U
		return true;
	if(knight(board, xSize, ySize, x + 1, y + 2, move + 1)) // R U U
		return true;
	if(knight(board, xSize, ySize, x -1, y +2, move + 1)) // R R U
		return true;
	if(knight(board, xSize, ySize, x -2, y + 1, move + 1)) // R R D
		return true;
	if(knight(board, xSize, ySize, x -2, y -1, move + 1)) // R D D 
		return true;
	if(knight(board, xSize, ySize, x - 1, y- 2, move + 1)) // L D D
		return true;
	if(knight(board, xSize, ySize, x +1, y -2, move + 1)) // L L D
		return true;
	if(knight(board, xSize, ySize, x +2, y - 1, move + 1)) // L L U
		return true;
	board[x][y] = 0;
	//cout << endl;

	return false;	
}

///////////////////////////////////////////////////////////////////////////////

bool valid(int **board, int xSize, int ySize, int x, int y)
{
	if((x < 0) || (y < 0) || (x >= xSize) || (y >= ySize))
		return false;
	if((board[x][y] != 0))
			return false;
	return true;
}

///////////////////////////////////////////////////////////////////////////////

void display(int **board, int xSize, int ySize)
{
	for(int xcor = 0; xcor < xSize; xcor++)
	{
		
		for(int ycor = 0; ycor < ySize; ycor++)
		{
			cout << board[xcor][ycor] << "\t";
		}
		cout << endl << endl;
	}
	for(int z = 0; z < 200000000; z++);
}
