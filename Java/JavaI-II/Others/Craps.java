/*
 Program Name: Craps.java
 Author: Nathan Caron
 Date: 9/22/14
 Purpose: Play Craps!
*/

import java.security.SecureRandom;
import java.util.Scanner;

public class Craps
{
	private static final SecureRandom randomNumbers = new SecureRandom();
	private enum Status { CONTINUE, WON, LOST };

	private static final int SNAKE_EYES = 2;
	private static final int TREY = 3;
	private static final int SEVEN = 7;
	private static final int YO_LEVEN = 11;
	private static final int BOX_CARS = 12;

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int myPoint = 0;
		int bankBalance = 1000;
		int wager;
		Status gameStatus;

		do{

			System.out.printf("You have $%d, how much would you like "
								+"to wager? (-1 to quit)", bankBalance);
			wager = input.nextInt();

			if(wager == -1)
				break;

			while(wager > bankBalance || wager <= 0)
			{
				if(wager == 0)
					System.out.print("You have to wager something! ");
				else
					System.out.printf("You don't have that amount to wager!"
								  +" Enter a valid amount 1-%d!",
								  bankBalance);
				wager = input.nextInt();
			}

			if(wager == bankBalance)
				System.out.println("\nWow you're risking it all!\n");
			else
				chatter();

			int sumOfDice = rollDice();

			switch(sumOfDice)
			{
				case SEVEN:
				case YO_LEVEN:
					gameStatus = Status.WON;
					break;
				case SNAKE_EYES:
				case TREY:
				case BOX_CARS:
					gameStatus = Status.LOST;
					break;
				default:
					gameStatus = Status.CONTINUE;
					myPoint = sumOfDice;
					System.out.printf("Point is %d%n", myPoint);
					break;
			}

			while(gameStatus == Status.CONTINUE)
			{
				sumOfDice = rollDice();

				if(sumOfDice == myPoint)
					gameStatus = Status.WON;
				else
					if(sumOfDice == SEVEN)
						gameStatus = Status.LOST;
			}

			if(gameStatus == Status.WON)
			{
				System.out.printf("Player wins!%nYou won $%d%n", wager);
				bankBalance += wager;
			}
			else
			{
				System.out.printf("Player loses!%nYou lost $%d%n", wager);
				bankBalance -= wager;
			}

			if(bankBalance == 0)
				System.out.println("Sorry. You busted!");

		}while(bankBalance != 0);

		System.out.println("Thanks for playing, come again! ");
	}
/////////////////////////////////////////////////////////////////////////
	public static void chatter()
	{
		int option = randomNumbers.nextInt(3);

		switch(option)
		{
			case 0:
				System.out.println("\nOh, you're going for broke, huh?\n");
				break;
			case 1:
				System.out.println("\nAw c'mon, take a chance!\n");
				break;
			case 2:
				System.out.println("\nYou're up big. Now's the time to "
									+"cash in your chips!\n");
				break;
		}
	}
/////////////////////////////////////////////////////////////////////////
	public static int rollDice()
	{
		int die1 = 1 + randomNumbers.nextInt(6);
		int die2 = 1 + randomNumbers.nextInt(6);

		int sum = die1 + die2;

		System.out.printf("Player rolled %d + %d = %d%n",
			die1, die2, sum);
		return sum;
	}
}