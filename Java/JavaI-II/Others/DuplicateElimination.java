/*
 Program Name: DuplicateElimination.java
 Author: Nathan Caron
 Date: 10/4/14
 Purpose: Enter ints 10-100 and display non duplicates
*/

import java.util.Scanner;
import java.util.ArrayList;

public class DuplicateElimination
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		// use ArrayList type array so we can tell if there are duplicates
		// and so it always keeps the array size as small as possible
		ArrayList<Integer> array = new ArrayList<Integer>();

		for(int counter = 0; counter < 5; counter++)
		{
			System.out.print("Enter integer between 10-100 inclusively: ");

			int userInput = input.nextInt();

			// directions say numbers 10-100 inclusive, so the
			// following while loop validates input
			while(userInput < 10 || userInput > 100)
			{
				System.out.print("Incorrect value, try again: ");
				userInput = input.nextInt();
			}

			if(!array.contains(userInput))
				array.add(userInput); // only add user's number to array
									  // if its a unique value

			System.out.print("Unique values thus far: ");
			for(int x : array)
				System.out.printf(" %d ", x); // display all elements of array
			System.out.printf("%n%n");
		}
	} // end main
}