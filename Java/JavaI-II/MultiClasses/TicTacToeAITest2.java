/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment
 Date:
 Purpose:
*/

import java.util.Scanner;


public class TicTacToeAITest2
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		TicTacToeAI2 game = new TicTacToeAI2();
		boolean validMove;
		int player, move;

		System.out.print("Move numbers:\n");
		game.displayMoves();


		do
		{
			System.out.print("Go first or second? (1 or 2): ");
			player = input.nextInt();
		}while(player != 1 && player != 2);

		game.choosePlayer(player);

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
				System.out.printf("\nEnter the move number: ");
				move = input.nextInt();
				while(move < 1 || move > 9)
				{
					System.out.print("Incorrect entry, enter move(1-9): ");
					move = input.nextInt();
				}

				validMove = game.makeMove(move);
				if(!validMove)
					System.out.println("Space is already filled!");

			}while(!validMove);

			if(game.checkWin())
				break;
			if(game.noMoves())
				break;

			if(player == 1)
				game.aiMoveO();
		}

		game.displayBoard();
		if(game.getWinner() == "Tie")
			System.out.print("\nWe have a tie!\n");
		else
			System.out.print("\n" +game.getWinner() + " is the winner!\n");

	}
}