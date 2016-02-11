/*
 Program Name: TicTacToe.java
 Author: Nathan Caron
 Assignment # 8
 Date: 11/5/2014
 Purpose: Create a game of tic tac toe with AI.
*/

import java.util.Scanner;


public class CaronNateTTT
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		TTTAI game = new TTTAI();
		boolean validMove;
		int player, move;

		System.out.print("Move numbers:\n");
		game.displayMoves();


		do
		{
			System.out.print("Go first or second? (1 or 2): ");
			player = input.nextInt();
		}while(player != 1 && player != 2);

		game.choosePlayer(player); // choose if player is X or O

		while(!game.checkWin())
		{
			if(player == 2)// if player is 2nd let AI move now
				game.aiMove();

			if(game.checkWin())// check if game is over after AI move
				break;
			if(game.noMoves()) // check if board still has empy spaces
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

				validMove = game.makeMove(move); // false if space not open
				if(!validMove)
					System.out.println("Space is already filled!");

			}while(!validMove); // breaks loop once valid move is made
								// if there are no moves it wont get this far

			if(game.checkWin()) // check again in case player is X
				break;
			if(game.noMoves())
				break;

			if(player == 1)
				game.aiMove();
		}

		game.displayBoard(); // display final board
		if(game.getWinner() == "Tie")
			System.out.print("\nWe have a tie!\n");
		else
			System.out.print("\n" +game.getWinner() + " is the winner!\n");
	}
}