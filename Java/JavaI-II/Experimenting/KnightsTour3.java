

public class KnightsTour3
{
	private static int[][] board = new int[8][8];
	public static int currentRow = 0;
	public static int currentCol = 0;
	private static int[] horizontal = {2,1,-1,-2,-2,-1,1,2};
	private static int[] vertical = {-1,-2,-2,-1,1,2,2,1};
	private static int[][] heur = { {2,3,4,4,4,4,3,2},{3,4,6,6,6,6,4,3},
									{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
									{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
									{3,4,6,6,6,6,4,3},{2,3,4,4,4,4,3,2} };

	public static void main(String[] args)
	{
		int fail = 0;

		for(int row = 7; row >= 0; row--)
		{
			for(int col = 7; col >= 0; col--)
			{
				currentRow = row;
				currentCol = col;

				playGame();
				fail = 0;
				for(int[] x : board)
					for(int y : x)
						if(y == 0)
							fail++;

				if(fail == 0)
					System.out.print("Success at starting Row "+row+" and starting Col "+col+"\n");
			}
		}


		for(int[] x : board) //working way to display 2D arrays
			for(int y : x)
				if(y == 0)
					System.out.print("");
	}
////////////////////////////////////////////////////////////////

	public static void displayHeur()
	{
		for(int x = 0; x < board.length; x++)
		{
			for(int y = 0; y < board[x].length; y++)
			{
				System.out.print("\t"+heur[x][y]);
			}
			System.out.printf("\n\n");
		}
		System.out.println();
	}

////////////////////////////////////////////////////////////////

	public static void displayBoard()
	{
		for(int x = 0; x < board.length; x++)
		{
			for(int y = 0; y < board[x].length; y++)
			{
				System.out.print("\t"+board[x][y]);
			}
			System.out.printf("\n\n");
		}
		System.out.println();
	}

////////////////////////////////////////////////////////////////

	public static void clearBoard()
	{
		for(int row = 0; row < board.length; row++)
		{
			for(int col = 0; col < board[row].length; col++)
			{
				board[row][col] = 0;
			}
		}
	}
////////////////////////////////////////////////////////////////

	public static void playGame()
	{
		boolean knight = true;
		int counter = 1;
		clearBoard();
		board[currentRow][currentCol] = 1;
		checkHeur();


		while(knight)
		{
			counter++;
			knight = possibleMoves(counter);
			checkHeur();
		}

	}


////////////////////////////////////////////////////////////////

	public static void checkHeur()
	{
		int heurcount = 0;
		for(int row = 0; row < board.length; row++)
		{
			for(int col = 0; col < board[row].length; col++)
			{
				heurcount = 0;
				for(int move = 0; move < 8; move++)
				{
					if(row + horizontal[move] >= 0 && row + horizontal[move] < 8)
						if(col + vertical[move] >= 0 && col + vertical[move] < 8)
							if(board[row][col] == 0)
								heurcount++;
				}
				heur[row][col] = heurcount;
			}
		}
	}

////////////////////////////////////////////////////////////////
	public static boolean possibleMoves(int counter)
	{

		boolean[] valid = new boolean[8];
		int moveNumber = 9;
		int curHeur = 9;
		int latestHeur = 0;


		for(int move = 0; move < 8; move++)
		{

			if(currentRow + horizontal[move] >= 0 && currentRow + horizontal[move] < 8)
				if(currentCol + vertical[move] >= 0 && currentCol + vertical[move] < 8)
					if(board[currentRow + horizontal[move]][currentCol + vertical[move]] == 0)
						valid[move] = true;
		}


		for(int x = 0; x < 8; x++)
		{

			if(valid[x])
			{
				latestHeur = heur[currentRow + horizontal[x]][currentCol + vertical[x]];
				if(latestHeur < curHeur)
				{
					curHeur = latestHeur;
					moveNumber = x;
				}
				/* Using this to check a move ahead actually produces less successes.
				if(latestHeur == curHeur)
				{
					moveNumber = compareMoves(moveNumber, x);
				}*/
			}
		}
		if(moveNumber > 7)
			return false;
		else
		{
			currentRow += horizontal[moveNumber];
			currentCol += vertical[moveNumber];
			board[currentRow][currentCol] = counter;
			return true;
		}
	}

////////////////////////////////////////////////////////////////////

	public static int compareMoves(int oldMove, int newMove)
	{
		boolean[] validOld = new boolean[8];
		boolean[] validNew = new boolean[8];
		int rowOld = currentRow + horizontal[oldMove];
		int rowNew = currentRow + horizontal[newMove];
		int colOld = currentCol + vertical[oldMove];
		int colNew = currentCol + vertical[newMove];
		int oldHeur = 9;
		int latestOld = 0;
		int newHeur = 9;
		int latestNew = 0;
		int moveNumberOld = 0;
		int moveNumberNew = 0;

		for(int move = 0; move < 8; move++)
		{
			if(rowOld + horizontal[move] >= 0 && rowOld + horizontal[move] < 8)
				if(colOld + vertical[move] >= 0 && colOld + vertical[move] < 8)
					if(board[rowOld + horizontal[move]][colOld + vertical[move]] == 0)
						validOld[move] = true;

			if(rowNew + horizontal[move] >= 0 && rowNew + horizontal[move] < 8)
				if(colNew + vertical[move] >= 0 && colNew + vertical[move] < 8)
					if(board[rowNew + horizontal[move]][colNew + vertical[move]] == 0)
						validNew[move] = true;
		}

		for(int x = 0; x < 8; x++)
		{
			if(validOld[x])
			{
				latestOld = heur[rowOld + horizontal[x]][colOld + vertical[x]];
				if(latestOld < oldHeur)
				{
					oldHeur = latestOld;
					moveNumberOld = x;
				}
			}
			if(validNew[x])
			{
				latestNew = heur[rowNew + horizontal[x]][colNew + vertical[x]];
				if(latestNew < oldHeur)
				{
					newHeur = latestOld;
					moveNumberNew = x;
				}
			}
		}//end for
		if(oldHeur < newHeur)
			return oldMove;
		else
			return newMove;
	}

}//end class