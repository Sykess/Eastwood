/*
 Program Name: Knights tour.cpp
 Author: Nathan Caron
 Assignment #6
 Date: 4/17/14
 Purpose: Solve the knight's tour on a user specified sized board using recursion.
*/

#include <iostream>
#include <iomanip>
using namespace std;

bool tour(int ** board, int x_coord, int y_coord, int xsize, int ysize, int moveNum);
bool valid(int ** board, int x, int y, int xsize, int ysize);
void display(int ** board, int x, int y);
void getData(int &x, int &y, int &startX, int &startY);

// set global since only needed in tour and do not want it to initialize every call
// also, this order solves 8x8 much quicker than the order we came up with in class
int moves[2][8] = {{2, 1, -1, -2, -2, -1, 1, 2},
				   {1, 2, 2, 1, -1, -2, -2, -1}};

int main()
{
	int x, y, startX, startY;
	int ** board;
	
	// used function to get data because main was getting messy
	getData(x, y, startX, startY);
	
	board = new int*[y];
	for(int i = 0; i < y; i++)
		board[i] = new int[x];
	
	// initialize board
	for(int i = 0; i < y; i++)
		for(int j = 0; j < x; j++)
			board[i][j] = 0;
	
	cout << "\nThinking...\n";
	if(tour(board, startX, startY, x, y, 1))
	{
		cout << "Completed Knight's Tour:\n";
		display(board, x, y);
	}
	else
		cout << "Tour could not be completed.\n";
	

	for(int i = 0; i < y; i++)
		delete[] board[i];
	delete[] board;
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////
void getData(int &x, int &y, int &startX, int &startY)
{
	cout << "Some information is needed to solve the Knight's Tour...";
	cout << "\nEnter rows for board: ";
	cin >> y;
	while(y < 1 || y > 12)
	{
		cout << "Invalid amount, must be between 1 and 12: ";
		cin >> y;
	}
	
	cout << "Enter columns for board: ";
	cin >> x;
	while(x < 1 || x > 12)
	{
		cout << "Invalid amount, must be between 1 and 12: ";
		cin >> x;
	}
	
	cout << "Enter starting coordinate for x: ";
	cin >> startX;
	while(startX < 0 || startX >= x)
	{
		cout << "Invalid starting point, must be between 0 and "
			 << x - 1 << ": ";
		cin >> startX;
	}
	
	cout << "Enter starting coordinate for y: ";
	cin >> startY;
	while(startY < 0 || startY >= y)
	{
		cout << "Invalid starting point, must be between 0 and "
			 << y - 1 << ": ";
		cin >> startY;
	}
	
}
///////////////////////////////////////////////////////////////////////////////////
void display(int ** board, int x, int y)
{
	for(int i = 0; i < y; i++)
	{
		for(int j = 0; j < x; j++)
			cout << setw(4) << board[i][j];
		cout << endl;
	}	
}
///////////////////////////////////////////////////////////////////////////////////
bool tour(int ** board, int x_coord, int y_coord, int xsize, int ysize, int moveNum)
{
	if(!valid(board, x_coord, y_coord, xsize, ysize))
		return false;
	board[y_coord][x_coord] = moveNum;
	
	if(moveNum == xsize * ysize)
		return true;
	
	//index through the 8 possible moves using the moves array
	for(int i = 0; i < 8; i++)
	{
		if(tour(board, x_coord + moves[0][i], y_coord + moves[1][i],
				xsize, ysize, moveNum + 1))
			return true;
	}
	
	board[y_coord][x_coord] = 0;
	return false;
}
///////////////////////////////////////////////////////////////////////////////////
bool valid(int ** board, int x, int y, int xsize, int ysize)
{
	if(x < 0 || y < 0 || y >= ysize || x >= xsize)
		return false;
	if(board[y][x] != 0)
		return false;
	return true;
}
