/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment
 Date:
 Purpose:
*/

import java.util.Scanner;


public class TicTacTest
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		TicTacToe game = new TicTacToe();
		int coordX;
		int coordY;
		boolean validMove;

		while(!game.checkWin())
		{
			if(game.noMoves())
					break;

			game.displayBoard();
			do
			{


				System.out.printf("\nEnter the Row(1-3) for player %d : ",
								  game.getPlayer());
				coordX = input.nextInt();
				while(coordX < 1 || coordX > 3)
				{
					System.out.print("Incorrect entry, enter Row(1-3): ");
					coordX = input.nextInt();
				}
				System.out.printf("Enter the Column(1-3) for player %d : ",
								  game.getPlayer());
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

			game.changePlayer();
		}

		game.displayBoard();
		if(game.checkWin())
			System.out.printf("\nCongratulations player %d for winning!\n",
					      game.getPlayer());
		else
			System.out.print("\nWe have a tie! \n");

	}
}