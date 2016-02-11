/*
 Program Name: DupElim.java
 Author: Nathan Caron
 Date: 10/2/14
 Purpose: Enter ints 10-100 and display non duplicates
*/

import java.util.Scanner;
import java.util.Arrays;


public class DupElim
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int[] array = new int[5]; // create array of 5 for worst case

		for(int counter = 0; counter < 5; counter++)
		{
			System.out.print("Enter integer between 10-100 inclusively: ");

			array[counter] = input.nextInt();

			// directions say numbers 10-100 inclusive, so the
			// following while loop validates input
			while(array[counter] < 10 || array[counter] > 100)
			{
				System.out.print("Incorrect value, try again: ");
				array[counter] = input.nextInt();
			}


			for(int x = 0; x < counter; x++)
			{
				if(array[counter] == array[x])
					array[counter] = 0;
			}



			System.out.print("Unique value(s): ");
			for(int x = 0; x <= counter; x++)
			{
				// if statement only prints number if its > 10, and I
				// set all duplicates to 0 so they won't be displayed twice
				if(array[x] >= 10)
					System.out.printf("%d  ", array[x]);
			}
			System.out.println(); // blank line after unique numbers printed
		}
	} // end method
} // end class