/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment
 Date:
 Purpose:
*/

import java.security.SecureRandom;

public class TicTacToeAI3
{
	private enum Status{X, O, EMPTY};
	private Status[][] board = new Status[3][3];
	private Status player, ai, winner;
	private SecureRandom randomNumbers = new SecureRandom();

	public TicTacToeAI3()
	{
		for(int x = 0; x <= 2; x++)
		{
			for(int y = 0; y <= 2; y++)
				board[x][y] = Status.EMPTY;
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
	public void determineWinner(Status x)
	{
		if(x == Status.X)
			winner = Status.X;
		if(x == Status.O)
			winner = Status.O;
		if(x == Status.EMPTY)
			winner = Status.EMPTY;
	}
////////////////////////////////////////////////////
	public String getWinner()
	{
		if(winner == Status.X)
			return "X";
		if(winner == Status.O)
			return "O";
		return "Tie";
	}

////////////////////////////////////////////////////
	public boolean checkWin()
	{
		for(int x = 0; x < 3; x++)
		{
			// row win
			if(board[x][0] == board[x][1] && board[x][1] == board[x][2]
			   && board[x][0] != Status.EMPTY)
			{
				determineWinner(board[x][0]);
				return true;
			}
			// col win
			if(board[0][x] == board[1][x] && board[1][x] == board[2][x]
			   && board[0][x] != Status.EMPTY)
			{
				determineWinner(board[0][x]);
				return true;
			}
		}
		//diag wins
		if(board[0][0] == board[1][1] && board[1][1] == board[2][2]
		   && board[0][0] != Status.EMPTY)
		{
			determineWinner(board[0][0]);
			return true;
		}
		if(board[0][2] == board[1][1] && board[1][1] == board[2][0]
		   && board[0][2] != Status.EMPTY)
		{
			determineWinner(board[0][2]);
			return true;
		}
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
	public void choosePlayer(int x)
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
	public void displayMoves()
	{
		int move = 1;
		for(int x = 0; x <= 2; x++)
		{
			for(int y = 0; y <= 2; y++)
			{
				System.out.printf(" %d ", move);
				if(y < 2)
					System.out.print(" | ");
				move++;
			}
			if(x < 2)
				System.out.print("\n----------------\n");
		}
		System.out.println();
	}


////////////////////////////////////////////////////
	public boolean makeMove(int move)
	{
		int row = 0;
		int col = 0;

		if(move == 1)
		{
			row = 0;
			col = 0;
		}
		if(move == 2)
		{
			row = 0;
			col = 1;
		}
		if(move == 3)
		{
			row = 0;
			col = 2;
		}
		if(move == 4)
		{
			row = 1;
			col = 0;
		}
		if(move == 5)
		{
			row = 1;
			col = 1;
		}
		if(move == 6)
		{
			row = 1;
			col = 2;
		}
		if(move == 7)
		{
			row = 2;
			col = 0;
		}
		if(move == 8)
		{
			row = 2;
			col = 1;
		}
		if(move == 9)
		{
			row = 2;
			col = 2;
		}

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
	public void aiMoveHeur()
	{
		int score1 = 0;
		int score2 = 0;
		int bestCol = 0;
		int bestRow = 0;
		int bestScore = 0;


		for(int row = 0; row < 3; row++)
		{
			for(int col = 0; col < 3; col++)
			{
				if(board[row][col] != Status.EMPTY)
					continue;
				for(int curRow = 0; curRow < 3; curRow++)
				{
					if(board[curRow][col] == ai)
						score1 += 10;
					if(board[curRow][col] == player)
						score1 += 8;
				}
				for(int curCol = 0; curCol < 3; curCol++)
				{
					if(board[row][curCol] == ai)
						score2 += 10;
					if(board[row][curCol] == player)
						score2 += 8;
				}
				if(score1 > bestScore)
				{
					bestScore = score1;
					bestRow = row;
					bestCol = col;
				}

				if(score2 > bestScore)
				{
					bestScore = score2;
					bestRow = row;
					bestCol = col;
				}
				score1 = 0;
				score2 = 0;
			} // end col
		}


		board[bestRow][bestCol] = ai;

	} // end method

////////////////////////////////////////////////////
	public void aiMoveX()
	{
		int moveX = randomNumbers.nextInt(3);
		int moveY = randomNumbers.nextInt(3);
		boolean isValid = false;


		//check for chances to win
		for(int x = 0; x < 3; x++)
		{
			if(board[x][0] == ai && board[x][1] == ai)
			{
				if(board[x][2] == Status.EMPTY)
				{
					board[x][2] = ai;
					return;
				}
			}
			if(board[x][1] == ai && board[x][2] == ai)
			{
				if(board[x][0] == Status.EMPTY)
				{
					board[x][0] = ai;
					return;
				}
			}
			if(board[x][0] == ai && board[x][2] == ai)
			{
				if(board[x][1] == Status.EMPTY)
				{
					board[x][1] = ai;
					return;
				}
			}
			if(board[0][x] == ai && board[1][x] == ai)
			{
				if(board[2][x] == Status.EMPTY)
				{
					board[2][x] = ai;
					return;
				}
			}
			if(board[0][x] == ai && board[2][x] == ai)
			{
				if(board[1][x] == Status.EMPTY)
				{
					board[1][x] = ai;
					return;
				}
			}
			if(board[1][x] == ai && board[2][x] == ai)
			{
				if(board[0][x] == Status.EMPTY)
				{
					board[0][x] = ai;
					return;
				}
			}
		}
		// Check diagonals for chances to win
		if(board[1][1] == ai && board[0][0] == ai)
		{
			if(board[2][2] == Status.EMPTY)
			{
				board[2][2] = ai;
				return;
			}
		}
		if(board[0][0] == ai && board[2][2] == ai)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = ai;
				return;
			}
		}
		if(board[1][1] == ai && board[2][2] == ai)
		{
			if(board[0][0] == Status.EMPTY)
			{
				board[0][0] = ai;
				return;
			}
		}
		// Check columns and Rows for danger
		for(int x = 0; x < 3; x++)
		{
			if(board[x][0] == player && board[x][1] == player)
			{
				if(board[x][2] == Status.EMPTY)
				{
					board[x][2] = ai;
					return;
				}
			}
			if(board[x][1] == player && board[x][2] == player)
			{
				if(board[x][0] == Status.EMPTY)
				{
					board[x][0] = ai;
					return;
				}
			}
			if(board[x][0] == player && board[x][2] == player)
			{
				if(board[x][1] == Status.EMPTY)
				{
					board[x][1] = ai;
					return;
				}
			}
			if(board[0][x] == player && board[1][x] == player)
			{
				if(board[2][x] == Status.EMPTY)
				{
					board[2][x] = ai;
					return;
				}
			}
			if(board[0][x] == player && board[2][x] == player)
			{
				if(board[1][x] == Status.EMPTY)
				{
					board[1][x] = ai;
					return;
				}
			}
			if(board[1][x] == player && board[2][x] == player)
			{
				if(board[0][x] == Status.EMPTY)
				{
					board[0][x] = ai;
					return;
				}
			}
		}
		// Check diagonals for danger
		if(board[1][1] == player && board[0][0] == player)
		{
			if(board[2][2] == Status.EMPTY)
			{
				board[2][2] = ai;
				return;
			}
		}
		if(board[0][0] == player && board[2][2] == player)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = ai;
				return;
			}
		}
		if(board[1][1] == player && board[2][2] == player)
		{
			if(board[0][0] == Status.EMPTY)
			{
				board[0][0] = ai;
				return;
			}
		}
		if(board[0][2] == player && board[1][1] == player)
		{
			if(board[2][0] == Status.EMPTY)
			{
				board[2][0] = ai;
				return;
			}
		}
		if(board[1][1] == player && board[2][0] == player)
		{
			if(board[0][2] == Status.EMPTY)
			{
				board[0][2] = ai;
				return;
			}
		}
		if(board[0][2] == player && board[2][0] == player)
		{
			if(board[1][1] == Status.EMPTY)
			{
				board[1][1] = ai;
				return;
			}
		}
		// No wins or losses this turn, moving on
		while(!noMoves())
		{
			if(board[moveX][moveY] == Status.EMPTY)
			{
				board[moveX][moveY] = ai;
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