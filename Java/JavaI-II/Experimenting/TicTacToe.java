/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment
 Date:
 Purpose:
*/



public class TicTacToe
{
	private enum Status{X, O, EMPTY};
	private Status[][] board = new Status[3][3];
	private Status player = Status.X;

	public TicTacToe()
	{
		for(int x = 0; x <= 2; x++)
		{
			for(int y = 0; y <= 2; y++)
				board[x][y] = Status.EMPTY;
		}

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
	public int getPlayer()
	{
		if(player == Status.X)
			return 1;
		else
			return 2;
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
	public void changePlayer()
	{
		if(player == Status.X)
			player = Status.O;
		else
			player = Status.X;
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