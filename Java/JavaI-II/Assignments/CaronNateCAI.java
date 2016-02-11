/*
 Program Name: CaronNateCAI.java
 Author: Nathan Caron
 Assignment #5
 Date: 10/5/2014
 Purpose: Randomly generate positive single digit multiplication questions
 		  and if the user gets it wrong, allow them to keep trying.
*/

import java.security.SecureRandom; // needed to generate random numbers
import java.util.Scanner;


public class CaronNateCAI
{
	// accessible to all methods
	private static final SecureRandom randomNumbers = new SecureRandom();

	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int correctAnswer = generateQuestion();
		System.out.print("(-1 at any time to quit): ");
		int userAnswer = input.nextInt();

		while(userAnswer != -1)
		{
			boolean rightOrWrong = false; // initialize to false here so every
										  // loop it resets to false for
										  // the incorrect answer loop

			while(userAnswer != correctAnswer)
			{
				display(rightOrWrong);
				userAnswer = input.nextInt();

				if(userAnswer == -1)
				return; // use return instead of break for full exit
			}

			rightOrWrong = true; // once out of loop must be correct
			display(rightOrWrong);

			correctAnswer = generateQuestion();
			userAnswer = input.nextInt();
		}
	}
///////////////////////////////////////////////////////////////////////
	public static void display(boolean x)
	{
		int choice = 1 + randomNumbers.nextInt(4); // chooses 1-4
		if(!x) // if  the answer is wrong
		{
			switch(choice)
			{
				case 1: System.out.print("No. Please try again. ");
				break;
				case 2: System.out.print("Wrong. Try once more. ");
				break;
				case 3: System.out.print("Don't give up! ");
				break;
				case 4: System.out.print("No. Keep trying. ");
				break;
			}
		}
		else // if the answer's not wrong then it must be right
		{
			switch(choice)
			{
				case 1: System.out.println("Very good! ");
				break;
				case 2: System.out.println("Excellent! ");
				break;
				case 3: System.out.println("Nice work! ");
				break;
				case 4: System.out.println("Keep up the good work! ");
				break;
			}
		}
	}
///////////////////////////////////////////////////////////////////////
	public static int generateQuestion()
	{
		int x = 1 + randomNumbers.nextInt(9); // creates 1-9
		int y = 1 + randomNumbers.nextInt(9);
		System.out.printf("How much is %d times %d? ", x, y);

		return(x * y); // return answer
	}
} // end class