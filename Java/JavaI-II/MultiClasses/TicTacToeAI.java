/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment
 Date:
 Purpose:
*/

import java.security.SecureRandom;

public class TicTacToeAI
{
	private enum Status{X, O, EMPTY};
	private Status[][] board = new Status[3][3];
	private int[] moveList = new int[9];
	private Status player = Status.O;
	private Status ai;
	private SecureRandom randomNumbers = new SecureRandom();
	private int counter = 0;
	private int counter2 = 0;

	public TicTacToeAI()
	{
		for(int x = 0; x <= 2; x++)
		{
			for(int y = 0; y <= 2; y++)
				board[x][y] = Status.EMPTY;
		}
		for(int x = 0; x < 9; x++)
		{
			moveList[x] = ++counter;
		}
	}
////////////////////////////////////////////////////
	public void changePlayer()
	{
		if(player == Status.O)
			player = Status.X;
		else
			player = Status.O;
	}

////////////////////////////////////////////////////
	public boolean checkWin()
	{
		for(int x = 0; x < 3; x++)
		{
			// row win
			if(board[x][0] == board[x][1] && board[x][1] == board[x][2]
			   && board[x][0] != Status.EMPTY)
				return true;
			// col win
			if(board[0][x] == board[1][x] && board[1][x] == board[2][x]
			   && board[0][x] != Status.EMPTY)
				return true;
		}
		//diag wins
		if(board[0][0] == board[1][1] && board[1][1] == board[2][2]
		   && board[0][0] != Status.EMPTY)
			return true;
		if(board[0][2] == board[1][1] && board[1][1] == board[2][0]
		   && board[0][2] != Status.EMPTY)
			return true;
		return false;
	}
////////////////////////////////////////////////////
	public boolean noMoves()
	{
		for(int x = 0; x <= 2; x++)
		{
			for(int y = 0; y <= 2; y++)
			{
				if(board[x][y] == Status.EMPTY)
					return false;
			}
		}
		return true;
	}

////////////////////////////////////////////////////
	public void chooseOrder(int x)
	{
		if(x == 1)
		{
			player = Status.X;
			ai = Status.O;
		}
		if(x == 2)
		{
			player = Status.O;
			ai = Status.X;
		}
	}
////////////////////////////////////////////////////
	public boolean makeMove(int row, int col)
	{
		if(board[row][col] == Status.EMPTY)
		{
			board[row][col] = player;
			return true;
		}
		else
		{
			return false;
		}
	}
////////////////////////////////////////////////////
	public void aiMoveX()
	{
		int moveX = randomNumbers.nextInt(3);
		int moveY = randomNumbers.nextInt(3);
		boolean isValid = false;


		//check for chances to win
		for(int x = 0; x < 3; x++)
		{
			if(board[x][0] == Status.X && board[x][1] == Status.X)
			{
				if(board[x][2] == Status.EMPTY)
				{
					board[x][2] = Status.X;
					return;
				}
			}
			if(board[x][1] == Status.X && board[x][2] == Status.X)
			{
				if(board[x][0] == Status.EMPTY)
				{
					board[x][0] = Status.X;
					return;
				}
			}
			if(board[x][0] == Status.X && board[x][2] == Status.X)
			{
				if(board[x][1] == Status.EMPTY)
				{
					board[x][1] = Status.X;
					return;
				}
			}
			if(board[0][x] == Status.X && board[1][x] == Status.X)
			{
				if(board[2][x] == Status.EMPTY)
				{
					board[2][x] = Status.X;
					return;
				}
			}
			if(board[0][x] == Status.X && board[2][x] == Status.X)
			{
				if(board[1][x] == Status.EMPTY)
				{
					board[1][x] = Status.X;
					return;
				}
			}
			if(board[1][x] == Status.X && board[2][x] == Status.X)
			{
				if(board[0][x] == Status.EMPTY)
				{
					board[0][x] = Status.X;
					return;
				}
			}
		}
		// Check diagonals for chances to win
		if(board[1][1] == Status.X && board[0][0] == Status.X)
		{
			if(board[2][2] == Status.EMPTY)
			{
				board[2][2] = Status.X;
				return;
			}
		}
		if(board[0][0] == Status.X && board[2][2] == Status.X)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = Status.X;
				return;
			}
		}
		if(board[1][1] == Status.X && board[2][2] == Status.X)
		{
			if(board[0][0] == Status.EMPTY)
			{
				board[0][0] = Status.X;
				return;
			}
		}
		// Check columns and Rows for danger
		for(int x = 0; x < 3; x++)
		{
			if(board[x][0] == Status.O && board[x][1] == Status.O)
			{
				if(board[x][2] == Status.EMPTY)
				{
					board[x][2] = Status.X;
					return;
				}
			}
			if(board[x][1] == Status.O && board[x][2] == Status.O)
			{
				if(board[x][0] == Status.EMPTY)
				{
					board[x][0] = Status.X;
					return;
				}
			}
			if(board[x][0] == Status.O && board[x][2] == Status.O)
			{
				if(board[x][1] == Status.EMPTY)
				{
					board[x][1] = Status.X;
					return;
				}
			}
			if(board[0][x] == Status.O && board[1][x] == Status.O)
			{
				if(board[2][x] == Status.EMPTY)
				{
					board[2][x] = Status.X;
					return;
				}
			}
			if(board[0][x] == Status.O && board[2][x] == Status.O)
			{
				if(board[1][x] == Status.EMPTY)
				{
					board[1][x] = Status.X;
					return;
				}
			}
			if(board[1][x] == Status.O && board[2][x] == Status.O)
			{
				if(board[0][x] == Status.EMPTY)
				{
					board[0][x] = Status.X;
					return;
				}
			}
		}
		// Check diagonals for danger
		if(board[1][1] == Status.O && board[0][0] == Status.O)
		{
			if(board[2][2] == Status.EMPTY)
			{
				board[2][2] = Status.X;
				return;
			}
		}
		if(board[0][0] == Status.O && board[2][2] == Status.O)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = Status.X;
				return;
			}
		}
		if(board[1][1] == Status.O && board[2][2] == Status.O)
		{
			if(board[0][0] == Status.EMPTY)
			{
				board[0][0] = Status.X;
				return;
			}
		}
		if(board[0][2] == Status.O && board[1][1] == Status.O)
		{
			if(board[2][0] == Status.EMPTY)
			{
				board[2][0] = Status.X;
				return;
			}
		}
		if(board[1][1] == Status.O && board[2][0] == Status.O)
		{
			if(board[0][2] == Status.EMPTY)
			{
				board[0][2] = Status.X;
				return;
			}
		}
		if(board[0][2] == Status.O && board[2][0] == Status.O)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = Status.X;
				return;
			}
		}
		// No wins or losses this turn, moving on
		while(!noMoves())
		{
			if(board[moveX][moveY] == Status.EMPTY)
			{
				board[moveX][moveY] = Status.X;
				return;
			}
			moveX = randomNumbers.nextInt(3);
			moveY = randomNumbers.nextInt(3);
		}

	}


////////////////////////////////////////////////////
	public void aiMoveO()
	{
		int moveX = randomNumbers.nextInt(3);
		int moveY = randomNumbers.nextInt(3);
		boolean isValid = false;


		//check for chances to win
		for(int x = 0; x < 3; x++)
		{
			if(board[x][0] == Status.O && board[x][1] == Status.O)
			{
				if(board[x][2] == Status.EMPTY)
				{
					board[x][2] = Status.O;
					return;
				}
			}
			if(board[x][1] == Status.O && board[x][2] == Status.O)
			{
				if(board[x][0] == Status.EMPTY)
				{
					board[x][0] = Status.O;
					return;
				}
			}
			if(board[x][0] == Status.O && board[x][2] == Status.O)
			{
				if(board[x][1] == Status.EMPTY)
				{
					board[x][1] = Status.O;
					return;
				}
			}
			if(board[0][x] == Status.O && board[1][x] == Status.O)
			{
				if(board[2][x] == Status.EMPTY)
				{
					board[2][x] = Status.O;
					return;
				}
			}
			if(board[0][x] == Status.O && board[2][x] == Status.O)
			{
				if(board[1][x] == Status.EMPTY)
				{
					board[1][x] = Status.O;
					return;
				}
			}
			if(board[1][x] == Status.O && board[2][x] == Status.O)
			{
				if(board[0][x] == Status.EMPTY)
				{
					board[0][x] = Status.O;
					return;
				}
			}
		}
		// Check diagonals for chances to win
		if(board[1][1] == Status.O && board[0][0] == Status.O)
		{
			if(board[2][2] == Status.EMPTY)
			{
				board[2][2] = Status.O;
				return;
			}
		}
		if(board[0][0] == Status.O && board[2][2] == Status.O)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = Status.O;
				return;
			}
		}
		if(board[1][1] == Status.O && board[2][2] == Status.O)
		{
			if(board[0][0] == Status.EMPTY)
			{
				board[0][0] = Status.O;
				return;
			}
		}
		// Check columns and Rows for danger
		for(int x = 0; x < 3; x++)
		{
			if(board[x][0] == Status.X && board[x][1] == Status.X)
			{
				if(board[x][2] == Status.EMPTY)
				{
					board[x][2] = Status.O;
					return;
				}
			}
			if(board[x][1] == Status.X && board[x][2] == Status.X)
			{
				if(board[x][0] == Status.EMPTY)
				{
					board[x][0] = Status.O;
					return;
				}
			}
			if(board[x][0] == Status.X && board[x][2] == Status.X)
			{
				if(board[x][1] == Status.EMPTY)
				{
					board[x][1] = Status.O;
					return;
				}
			}
			if(board[0][x] == Status.X && board[1][x] == Status.X)
			{
				if(board[2][x] == Status.EMPTY)
				{
					board[2][x] = Status.O;
					return;
				}
			}
			if(board[0][x] == Status.X && board[2][x] == Status.X)
			{
				if(board[1][x] == Status.EMPTY)
				{
					board[1][x] = Status.O;
					return;
				}
			}
			if(board[1][x] == Status.X && board[2][x] == Status.X)
			{
				if(board[0][x] == Status.EMPTY)
				{
					board[0][x] = Status.O;
					return;
				}
			}
		}
		// Check diagonals for danger
		if(board[1][1] == Status.X && board[0][0] == Status.X)
		{
			if(board[2][2] == Status.EMPTY)
			{
				board[2][2] = Status.O;
				return;
			}
		}
		if(board[0][0] == Status.X && board[2][2] == Status.X)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = Status.O;
				return;
			}
		}
		if(board[1][1] == Status.X && board[2][2] == Status.X)
		{
			if(board[0][0] == Status.EMPTY)
			{
				board[0][0] = Status.O;
				return;
			}
		}
		if(board[0][2] == Status.X && board[1][1] == Status.X)
		{
			if(board[2][0] == Status.EMPTY)
			{
				board[2][0] = Status.O;
				return;
			}
		}
		if(board[1][1] == Status.X && board[2][0] == Status.X)
		{
			if(board[0][2] == Status.EMPTY)
			{
				board[0][2] = Status.O;
				return;
			}
		}
		if(board[0][2] == Status.X && board[2][0] == Status.X)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = Status.O;
				return;
			}
		}
		// No wins or losses this turn, choose at random
		while(!noMoves())
		{
			if(board[moveX][moveY] == Status.EMPTY)
			{
				board[moveX][moveY] = Status.O;
				return;
			}
			moveX = randomNumbers.nextInt(3);
			moveY = randomNumbers.nextInt(3);
		}

	}
////////////////////////////////////////////////////
	public void displayBoard()
	{
		for(int x = 0; x <= 2; x++)
		{
			for(int y = 0; y <= 2; y++)
			{
				if(board[x][y] == Status.EMPTY)
					System.out.print("   ");
				if(board[x][y] == Status.X)
					System.out.print(" X ");
				if(board[x][y] == Status.O)
					System.out.print(" O ");
				if(y < 2)
					System.out.print(" | ");
			}
			if(x < 2)
				System.out.print("\n----------------\n");
		}
	}
}// end class