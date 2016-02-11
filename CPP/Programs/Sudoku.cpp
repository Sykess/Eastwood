
#include <iostream>
#include <fstream>
using namespace std;


bool solve(int game[][9], int row, int column);
bool isValid(int game[][9], int row, int column, int num);
void display(int game[][9]);
int fileSolve();

int main()
{
	fstream file("sudoku.txt", ios::in);
	int game[9][9] = { {0, 0, 3,  0, 2, 0,  6, 0, 0},
				       {9, 0, 0,  3, 0, 5,  0, 0, 1},
				       {0, 0, 1,  8, 0, 6,  4, 0, 0},
				       
				       {0, 0, 8,  1, 0, 2,  9, 0, 0},
				       {7, 0, 0,  0, 0, 0,  0, 0, 8},
				       {0, 0, 6,  7, 0, 8,  2, 0, 0},
				       
				       {0, 0, 2,  6, 0, 9,  5, 0, 0},
				       {8, 0, 0,  2, 0, 3,  0, 0, 9},
				       {0, 0, 5,  0, 1, 0,  3, 0, 0}};
	
	//solve(game, 0, 0);
	cout << fileSolve();
	
	
	
	return 0;
}

int fileSolve()
{
	fstream file("sudoku.txt", ios::in);
	
	int game[9][9] = {0};
	int totalGames = 0;
	int totalScore = 0;
	//char c;
	int c;
	int dummy;
	
	while(totalGames < 50)
	{
		//get first 7 characters
		for(int i = 0; i < 7; i++)
			file.get();
		//get those weird spaces after grid number
		if(totalGames >= 1)
			file.get();
		
		for(int r = 0; r < 9; r++)
		{
			for(int c = 0; c < 9; c++)
			{
				game[r][c] = file.get() - 48;
				//if array took that weird space get next number
				if(game[r][c] < 0)
					game[r][c] = file.get() - 48;
			}
		}
		solve(game, 0, 0);
		
		//display(game);
		
		totalScore += (game[0][0] * 100);
		totalScore += (game[0][1] * 10);
		totalScore += (game[0][2]);
		totalGames++;	
	}
	file.close();
	return totalScore;
}

void display(int game[][9])
{
	for(int r = 0; r < 9; r++)
	{
		for(int c = 0; c < 9; c++)
		{
			std::cout << game[r][c] << " ";
			if( (c+1) % 3 == 0)
				std::cout << "  ";
		}
		std::cout << std::endl;
		if( (r+1) % 3 == 0)
			std::cout << "\n\n";
	}
	
}


bool solve(int game[][9], int row, int column)
{
	if(row >= 9)
		return true;
	
	if(game[row][column])
	{
		if(column >= 8)
		{
			if(solve(game, row + 1, 0))
				return true;
		}
		else
		{
			if(solve(game, row, column + 1))
				return true;
		}
		return false;
	}
	
	for(int num = 1; num < 10; num++)
	{
		if(isValid(game, row, column, num))
		{
			game[row][column] = num;
			if(column >= 8)
			{
				if(solve(game, row + 1, 0))
					return true;
			}
			else
			{
				if(solve(game, row, column + 1))
					return true;
			}
			game[row][column] = 0;
			
		}
	}
	return false;
}

bool isValid(int game[][9], int row, int column, int num)
{
	int secRow = 3 * (row / 3);
	int secCol = 3 * (column / 3);
	int row1 = (row + 2) % 3;
	int row2 = (row + 4) % 3;
	int col1 = (column + 2) % 3;
	int col2 = (column + 4) % 3;
	
	for(int i = 0; i < 9; i++)
	{
		if(game[row][i] == num)
			return false;
		if(game[i][column] == num)
			return false;
	}
	
	if(game[row1+secRow][col1+secCol] == num)
		return false;
	if(game[row2+secRow][col1+secCol] == num)
		return false;
	if(game[row1+secRow][col2+secCol] == num)
		return false;
	if(game[row2+secRow][col2+secCol] == num)
		return false;
	return true;
}




