/*
 Program Name: CaronNatePN.java
 Author: Nathan Caron
 Assignment #6
 Date: 10/15/2014
 Purpose: Display prime numbers between 2 and 999.
*/

import java.util.Arrays;

public class CaronNatePN
{
	public static void main(String[] args)
	{
		final int MAX = 1000; // make MAX a constant
		boolean[] isPrime = new boolean[MAX];
		int total = 0; // used to control display

		Arrays.fill(isPrime, true);

		// go only until i*i < MAX because any number(MAX) divisible
		// by a number greater than its square root is also
		// divisible by a number smaller than its square root
		for(int i = 2; i * i < MAX ; i++)
		{
			if(isPrime[i])
			{
				for(int mult = i; i * mult < MAX; mult++)
					isPrime[mult * i] = false;
			}
		}
		System.out.println("The prime numbers between 2 and 999 are:\n ");

		for(int i = 2; i < MAX; i++)
		{
			if(isPrime[i]) // if it's true at that index, that index is prime
			{
				total += 1;
				System.out.printf("%d\t", i);

				if(total %8== 0) // start new line every 8 numbers
					System.out.printf("%n%n");
			}
		}
	}// end main
}