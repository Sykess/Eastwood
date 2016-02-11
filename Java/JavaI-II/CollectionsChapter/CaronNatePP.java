
/*
 Program Name: CaronNatePP.java
 Author: Nathan Caron
 Assignment # 4
 Date: 3/3/2015
 Purpose: Determine if number is prime, and if not, print its prime factors.
*/


import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.HashSet;


public class CaronNatePP
{

	public static void main(String[] args)
	{
		long number;
		Scanner input = new Scanner(System.in);
		boolean cont = true;

		while(cont)
		{
			System.out.print("Enter a number to see if it's prime: ");
			number = input.nextLong();
			while(number <= 1)
			{
				System.out.print("Number must be positive and greater than 1: ");
				number = input.nextLong();
			}

			if(isPrime(number))
				System.out.printf("%n%d is prime.%n", number);
			else
			{
				System.out.printf("%n%d is not prime.  It's prime factors are: ", number);
				printFactors(number);
			}

			System.out.print("\nEnter another number? 1 for yes, 2 for no: ");
			int Nnumber = input.nextInt();
			while(Nnumber != 1 && Nnumber != 2)
			{
				System.out.print("Invalid entry, 1 for yes, 2 for no: ");
				Nnumber = input.nextInt();
			}
			if(number == 2)
				cont = false;
		}

	}
/////////////////////////////////////////////////////////////////////////////
	public static boolean isPrime(long num)
	{
		for(int x = 3; x < num; x++)
		{
			if(num % x == 0 || num % 2 == 0)
				return false;
		}
		return true;
	}
/////////////////////////////////////////////////////////////////////////////
	public static void printFactors(long num)
	{
		List<Long> factors = new ArrayList<>();

		for(long x = 2; x <= num / x; x++)
		{
			while(num % x == 0)
			{
				factors.add(x);
				num /= x;
			}
		}
		if(num > 1) // since I used num / x as condition
			factors.add(num);

		Set<Long> set = new HashSet<>(factors);

		for(long x : set)
			System.out.printf("%d ", x);
		System.out.println();
	}
}