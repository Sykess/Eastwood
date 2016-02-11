/*
 Program Name: Palindrome.java
 Author: Nathan Caron
 Date: 9/13/14
 Purpose: Take a 5 digit integer from user
 	      and determine if it's a palindrome.
*/

import java.util.Scanner;

public class Palindromee
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int pal;

		System.out.print("Enter a 5 digit integer: ");
		pal = input.nextInt();

		while(pal < 10000)
		{
			System.out.print("Invalid entry, try again: ");
			pal = input.nextInt();
		}

		if(pal % 10 == pal / 10000)
			if(pal % 100 / 10 == pal / 1000 % 10)
			System.out.print("Entry is a Palindrome! ");

			else
				System.out.print("Entry is NOT a Palindrome! ");


	}



}