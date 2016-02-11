/*
 Program Name: GuessMe.java
 Author: Nathan Caron
 Date: 9/22/14
 Purpose: Have user guess number between 1-1000.
*/

import java.util.Scanner;
import java.security.SecureRandom;

public class guessmetry
{
	private static final SecureRandom randomNumbers = new SecureRandom();

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int goAgain = 0;
		int guess;
		int higher = 0;


		do{
			System.out.println("Hello, I'm going to think of a number 1-1000 "
							   +"and you're going to guess! Ready?");
			int random = generateNumber();

			System.out.println("I've got my number, what's your first guess? ");
			guess = input.nextInt();

			int counter = 0;

			while(guess != random)
			{
				if(guess > random)
				System.out.println("Too high, try again!");
				else
				System.out.println("Too low, try again!");

				guess = input.nextInt();
				counter++;
			}
			if(counter <= 10)
			System.out.println("Aha, you know the secret!");
			else
			System.out.println("You should be able to do better!");

			System.out.println("1 to play again, any other key to exit: ");
			goAgain = input.nextInt();

		}while(goAgain == 1);

	}



	public static int generateNumber()
	{
		int random = 1 + randomNumbers.nextInt(1000);
		return random;
	}

}