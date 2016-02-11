/*
 Program Name: Palindrome.java
 Author: Nathan Caron
 Date: 9/13/14
 Purpose: Take a 5 digit integer from user
 	      and determine if it's a palindrome.
*/

import java.util.Scanner;

public class Palindrome
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);

		int pal = 0;

		System.out.print("Enter a 5 digit integer or -1 to quit: ");
		pal = input.nextInt();

		while( pal != -1)
		{

			while(pal < 10000 || pal > 99999)
			{
				System.out.print("Invalid entry, try again: ");
				pal = input.nextInt();
			}

			if(pal % 10 == pal / 10000)
			{
				if(pal % 100 / 10 == pal / 1000 % 10)
					System.out.println("Entry is a Palindrome! ");
				else
					System.out.println("Entry is NOT a Palindrome! ");
			}
			else
				System.out.println("Entry is NOT a Palindrome! ");

			System.out.print("Enter another 5 digit integer or -1 to quit: ");
			pal = input.nextInt();

		}


	}



}