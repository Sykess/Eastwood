/*
 Program Name: CaronNateDS.java
 Author: Nathan Caron
 Assignment #2
 Date: 9/14/14
 Purpose: Take a 5 digit integer from user and display
 	      it back with 3 spaces between each digit.
*/


import java.util.Scanner; // needed to get user input

public class CaronNateDS
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in); // needed for user input

		int number; // create number for user's input
		int output1, output10, output100, output1000; // create output variables

		System.out.print("Enter exactly 5 numbers: ");
		number = input.nextInt(); //read number from user

		output1 = number % 10; // gives us digit in 1's position
		number /= 10; // drops last number off of user input
		output10 = number % 10; // gives us digit in current 1's position,
						   	    // which is user's 10's position
		number /= 10;
		output100 = number % 10; // gives us user's 100's position
		number /= 10;
		output1000 = number % 10; // gives us user's 1000's position
		number /= 10;
		//what is remaining in number now is the first output

		System.out.printf("%d   %d   %d   %d   %d%n", number, output1000,
		                  output100, output10, output1);
		/* Prints users number with exactly 3 spaces between each digit
		   if user enters more than 5 digits, the first number will have
		   all digits above the 1000's position.  If they enter less than
		   5 digits, 0's will fill the extra spaces. IE 345 would be 00345. */


	} // end method main
} // end class CaronNateDS