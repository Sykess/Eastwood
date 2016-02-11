

public class KnightsTour2
{
	private static int[][] board = new int[8][8];
	private static int currentRow = 1;
	private static int currentCol = 4;
	private static int[] horizontal = {2,1,-1,-2,-2,-1,1,2};
	private static int[] vertical = {-1,-2,-2,-1,1,2,2,1};
	private static int[][] heur = { {2,3,4,4,4,4,3,2},{3,4,6,6,6,6,4,3},
									{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
									{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
									{3,4,6,6,6,6,4,3},{2,3,4,4,4,4,3,2} };

	public static void main(String[] args)
	{
		int counter = 1;
		boolean knight = true;


		board[currentRow][currentCol] = 1;

				for(int x = 0; x < board.length; x++)
				{
					for(int y = 0; y < board[x].length; y++)
					{
						System.out.print("\t"+heur[x][y]);
					}
					System.out.printf("\n\n");
				}
		System.out.println();
		while(knight)
		{
			counter++;
			knight = possibleMoves(counter);
			checkHeur();

		}
		for(int x = 0; x < board.length; x++)
		{
			for(int y = 0; y < board[x].length; y++)
			{
				System.out.print("\t"+board[x][y]);
			}
			System.out.printf("\n\n");
		}
		System.out.println();

		for(int[] x : board)
			for(int y : x)
				if(y == 0)
					System.out.print("fail");
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


		for(int move = 0; move < 8; move++)
		{

			if(currentRow + horizontal[move] >= 0 && currentRow + horizontal[move] < 8)
				if(currentCol + vertical[move] >= 0 && currentCol + vertical[move] < 8)
					if(board[currentRow + horizontal[move]][currentCol + vertical[move]] == 0)
						valid[move] = true;
		}//end for


		for(int x = 0; x < 8; x++)
		{

			if(valid[x])
			{
				if(heur[currentRow + horizontal[x]][currentCol + vertical[x]] < curHeur)
				{
					curHeur = heur[currentRow + horizontal[x]][currentCol + vertical[x]];
					moveNumber = x;
				}

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

}