

public class KnightsTour
{
	private static int[][] board = new int[8][8];
	private static int currentRow = 0;
	private static int currentCol = 0;
	private static int[][] heur = { {2,3,4,4,4,4,3,2},{3,4,6,6,6,6,4,3},
									{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
									{4,6,8,8,8,8,6,4},{4,6,8,8,8,8,6,4},
									{3,4,6,6,6,6,4,3},{2,3,4,4,4,4,3,2} };

	public static void main(String[] args)
	{
		int counter = 0;
		boolean knight = true;

		while(knight)
		{
			counter++;
			knight = possibleMoves(counter);
		}
		for(int x = 0; x < board.length; x++)
		{
			for(int y = 0; y < board[x].length; y++)
			{
				System.out.print(" "+board[x][y]);
			}
			System.out.println();
		}


	}

	public static boolean possibleMoves(int counter)
	{
		int horizontal = 0;
		int vertical = 0;

		for(int move = 0; move < 8; move++)
		{

			switch(move)
			{
				case 0: horizontal = 2;
						vertical = -1;
						break;
				case 1:	horizontal = 1;
						vertical = -2;
						break;
				case 2: horizontal = -1;
						vertical = -2;
						break;
				case 3: horizontal = -2;
						vertical = -1;
						break;
				case 4: horizontal = -2;
						vertical = 1;
						break;
				case 5: horizontal = -1;
						vertical = 2;
						break;
				case 6: horizontal = 1;
						vertical = 2;
						break;
				case 7: horizontal = 2;
						vertical = 1;
						break;
			}
			if(currentRow + horizontal >= 0 && currentRow + horizontal < 8)
				if(currentCol + vertical >= 0 && currentCol + vertical < 8)
				{
					currentRow += horizontal;
					currentCol += vertical;
					if(board[currentRow][currentCol] == 0)
					{
						board[currentRow][currentCol] = counter;
						return true;
					}
					else
					{
						currentRow -= horizontal;
						currentCol -= vertical;
					}
				}

		}//end for
		return false;
	}

}