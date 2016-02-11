import java.util.Random;
import java.security.SecureRandom;

public class KnightsTourRandom
{
	private static int[][] board = new int[8][8];
	private static final Random randomNumbers = new Random();
	public static int currentRow = 0;
	public static int currentCol = 0;
	private static int[] horizontal = {2,1,-1,-2,-2,-1,1,2};
	private static int[] vertical = {-1,-2,-2,-1,1,2,2,1};

	public static void main(String[] args)
	{
		boolean success = false;
		boolean game = false;
		int emptySpaces = 0;
		int fullGames = 0;

		while(!success)
		{
			playGame();
			emptySpaces = 0;

			for(int[] x : board)
				for(int y : x)
					if(y == 0)
						emptySpaces++;
			if(emptySpaces == 0)
				success = true;
			fullGames++;
		}

		displayBoard();
		System.out.printf("%d games to get there!", fullGames);

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
		currentRow = randomNumbers.nextInt(8);
		currentCol = randomNumbers.nextInt(8);
		board[currentRow][currentCol] = 1;

		while(knight)
		{
			counter++;
			knight = possibleMoves(counter);
		}

	}


////////////////////////////////////////////////////////////////

	public static boolean possibleMoves(int counter)
	{

		boolean valid = false;
		int countdown = 0;

		int move = randomNumbers.nextInt(8);

		while(!valid)
		{

			if(currentRow + horizontal[move] >= 0 && currentRow + horizontal[move] < 8)
				if(currentCol + vertical[move] >= 0 && currentCol + vertical[move] < 8)
					if(board[currentRow + horizontal[move]][currentCol + vertical[move]] == 0)
						valid = true;
			if(!valid)
			{
				if(move >= 7)
					move = 0;
				else
					move++;
			}
			countdown++;
			if(countdown > 7) // if countdown hits 8 there are no possible moves
				return false;
		}

		currentRow += horizontal[move];
		currentCol += vertical[move];
		board[currentRow][currentCol] = counter;
		return true;
	}

}//end class