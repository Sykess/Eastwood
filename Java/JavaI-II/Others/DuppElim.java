/*
 Program Name: DuppElim.java
 Author: Nathan Caron
 Date: 10/2/14
 Purpose: Enter ints 10-100 and display non duplicates
 Work in progress...
*/

import java.util.Scanner;
import java.util.Arrays;


public class DuppElim
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int[] array = new int[5];

		for(int counter = 0; counter < array.length; counter++)
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

			Arrays.sort(array);
			int location = Arrays.binarySearch(array, userInput);
			System.out.printf("location is:  %d", location);
			if(location >= 0)
				System.out.println("alreaddy there");
			else
				array[counter] = userInput;
		}
		for(int display = 0; display < array.length; display++)
		{
			if(array[display] > 10)
				System.out.printf("%d   ", array[display]);
		}
		System.out.println();



		System.out.println();

	}
}