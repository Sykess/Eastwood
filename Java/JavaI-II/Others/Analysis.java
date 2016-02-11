/*
 Program Name: Analysis.java
 Editor: Nathan Caron
 Date: 9/21/14
 Purpose: Analysis of examination results using nested control statements.
*/
import java.util.Scanner;

public class Analysis
{
	public static void main(String[] args)
	{
		// create Scanner to obtain input from command window
		Scanner input = new Scanner(System.in);

		// initializing variables in declarations
		int passes = 0;
		int failures = 0;
		int studentCounter = 1;
		int result = 0;

		// proess 10 students using counter-controlled loop
		while(studentCounter <= 10)
		{
			int validate = 0; // initialize validate here so every loop
							  // it resets to 0
			// prompt user for input and obtain value from user
			while(validate != 1)
			{
				System.out.print("Enter result (1 = pass, 2 = fail); ");
				result = input.nextInt();
				if(result == 1) // result must be 1 or 2 to get
							    // out of validate loop
					validate = 1;
				if(result == 2)
					validate = 1;
				if(validate != 1) // if it's invalid let user know
					System.out.println("Invalid response! ");
			}


			// if...else is nested in the while statement
			if(result == 1)
				passes = passes + 1;
			else
				failures = failures + 1;

			// increment studentCounter so loop eventually terminates
			studentCounter = studentCounter + 1;
		}

		// termination phase; prepare and display results
		System.out.printf("Passed: %d%nFailed: %d%n", passes, failures);

		// determine whether more than 8 students passed
		if(passes > 8)
			System.out.println("Bonus to instructor!");
	}
}