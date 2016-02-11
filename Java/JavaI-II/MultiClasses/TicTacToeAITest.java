/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment
 Date:
 Purpose:
*/

import java.util.Scanner;


public class TicTacToeAITest
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		TicTacToeAI game = new TicTacToeAI();
		int coordX;
		int coordY;
		boolean validMove;
		int player;

		do
		{
			System.out.print("Go first or second? (1 or 2): ");
			player = input.nextInt();
		}while(player != 1 && player != 2);

		if(player == 1)
			game.changePlayer();

		while(!game.checkWin())
		{
			if(player == 2)
				game.aiMoveX();

			if(game.checkWin())
				break;
			if(game.noMoves())
				break;
			game.displayBoard();
			do
			{
				System.out.printf("\nEnter the Row(1-3): ");
				coordX = input.nextInt();
				while(coordX < 1 || coordX > 3)
				{
					System.out.print("Incorrect entry, enter Row(1-3): ");
					coordX = input.nextInt();
				}
				System.out.printf("Enter the Column(1-3): ");
				coordY = input.nextInt();
				while(coordY < 1 || coordY > 3)
				{
					System.out.print("Incorrect entry, enter Column(1-3): ");
					coordY = input.nextInt();
				}

				validMove = game.makeMove(coordX - 1, coordY - 1 );
				if(!validMove)
					System.out.println("Space is already filled!");

			}while(!validMove);

			if(player == 1)
				game.aiMoveO();
		}

		game.displayBoard();
		if(game.checkWin())
			System.out.printf("\nGame Over!\n");
		else
			System.out.print("\nWe have a tie! \n");

	}
}