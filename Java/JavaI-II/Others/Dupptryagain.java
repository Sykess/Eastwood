/*
 Program Name: DuppElim.java
 Author: Nathan Caron
 Date: 10/2/14
 Purpose: Enter ints 10-100 and display non duplicates
 Work in progress...
*/

import java.util.Scanner;
import java.util.ArrayList;

public class Dupptryagain
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
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
				array.add(userInput);

			System.out.print("Unique values thus far: ");
			for(int x : array)
				System.out.printf(" %d ", x);
			System.out.printf("%n%n");
		}
	}
}