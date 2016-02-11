/*
 Program Name: CaronNateHR.java
 Author: Nathan Caron
 Assignment
 Date: 10/29/2014
 Purpose: Test out HeartRates class
*/

import java.util.Scanner;

public class testHR
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String first, last;
		int month, day, year; // variable for birthday

		System.out.print("Enter your first name: ");
		first = input.nextLine();

		System.out.print("Enter your last name: ");
		last = input.nextLine();

		System.out.print("Enter the numerical month of your birthday: ");
		month = input.nextInt();
		while(month < 1 || month > 12)
		{
			System.out.print("Invalid entry. Enter month 1-12: ");
			month = input.nextInt();
		}

		System.out.print("Enter the day of your birthday: ");
		day = input.nextInt();
		while(day < 1 || day > 31)
		{
			System.out.print("Invalid entry. Enter day 1-31: ");
			day = input.nextInt();
		}

		System.out.print("Enter the year you were born: ");
		year = input.nextInt();
		while(year < 1900 || year > 2014)
		{
			System.out.print("Invalid entry. Enter the correct year: ");
			year = input.nextInt();
		}

		HeartRates mine = new HeartRates(first, last, month, day, year);

		mine.displayInfo();
	}
}