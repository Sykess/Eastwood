/*
 Program Name: CaronNateDE.java
 Author: Nathan Caron
 Assignment #2
 Date: 9/21/14
 Purpose: Have user enter a binary number and convert it to decimal.
*/

import java.util.Scanner;

public class Binary
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int bin = 0; // binary number to be converted
		int dup = 0; // duplicate needed for validation purposes
		int dec = 0; // variable for decimal equivalent
		int mult = 1; // multiplier for exponents of 2

		while(bin == 0)
		{
			System.out.print("Enter a binary number: ");
			bin = input.nextInt();

			if(bin == 0)
			break; // if user enters 0 it is valid binary number, so break
				   // out of while loop
			if(bin < 0) // makes sure bin is not negative
			bin = 0; // since

			dup = bin; // set our duplicate to replicate bin so we can
					   // check each digit while maintaining bin
			while(dup > 0)// once dup reaches 0 we've checked all digits
			{
				if(dup % 10 > 1)// checks if rightmost digit is 0 or 1
				{
					bin = 0; // if it isn't 0 or 1, set bin to 0 to stay
						     // in while bin = 0 loop and ask for new input
					dup = 0; // also if it isn't 0 or 1, we don't need
					 		 // to check dup anymore
				}
				else
					dup /= 10; // if it is 0 or 1, drop it and check next digit
			}
		}

		dup = bin; // reset dup to bin again so we can display both
				   // binary and decimal equivalent

		while(bin > 0)
		{
			dec = dec + bin % 10 * mult; // takes decimal number and adds
										 // either the 0 or 1 x mult
			bin /= 10; // take off the rightmost digit since
					   // we already accounted for it
			mult *= 2; // mult starts as 1 for 2 to the 0, then for every
					   // digit moving right to left the number is
					   // multiplied by 2 to represent 2 to the nth power
		}
		System.out.printf("Your binary number %d converts to %d in decimal.",
			dup, dec);
	}
}