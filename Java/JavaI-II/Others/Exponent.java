/*
 Program Name: Exponent.java
 Author: Nathan Caron
 Date: 10/2/2014
 Purpose: Calculate a user's integer to the power of the user's exponent.
*/

import java.util.Scanner;

public class Exponent
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int again;

		do
		{
			System.out.print("Enter the base and exponent, "
							 +"separated by a space: ");
			int base = input.nextInt();    // making 2 inputs this way allows
			int exponent = input.nextInt();// user to enter a space between
										   // inputs or even hit enter between
										   // inputs and they will work
			int end = integerPower(base, exponent); // call method integerPower

			System.out.printf("%d to the power of %d = %d%n", base,
							  exponent, end); // display user's input back
							  				  // with the answer

			System.out	.print("Would you like to enter another? 1 for yes, "
							 +"0 for no: ");
			again = input.nextInt();

			while(again < 0 || again > 1) // validates user input a 0 or 1
			{
				System.out.print("Incorrect response, type 1 or 0: ");
				again = input.nextInt();
			}

		}while(again == 1);
	}
//////////////////////////////////////////////////////////////////////////////
	public static int integerPower(int b, int e)// b for base e for exponent
	{
		int total = 1; // start at 1 because anything to the 0 power is 1

		for(int x = 0; x < e; x++)
		{
			total *= b	;
		}
		return total;
	}
}