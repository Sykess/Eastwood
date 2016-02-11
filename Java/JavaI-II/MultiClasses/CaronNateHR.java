/*
 Program Name: CaronNateHR.java
 Author: Nathan Caron
 Assignment # 7
 Date: 10/29/2014
 Purpose: Test out HeartRates class
*/

import java.util.Scanner;

public class CaronNateHR
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String first, last;  // name variables
		int month, day, year; // variable for birthday

		System.out.print("Enter your first name: ");
		first = input.nextLine(); // use line since some names have spaces

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
		// don't validate for which month because might not be set yet
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

		// test mutators
		mine.setFirstName("Bob");
		mine.setLastName("Jones");
		mine.setMonth(9);
		mine.setDay(21);
		mine.setYear(1987);

		// test accessors
		System.out.printf("\nFirst name: %s\nLast name: %s\nDOB: %02d/%02d/"
						 +"%04d\nMax Heart rate: %d\nTarget Range: %.0f-%.0f\n",
						 mine.getFirstName(), mine.getLastName(),
						 mine.getMonth(), mine.getDay(), mine.getYear(),
						 mine.maxHeartRate(), mine.targetHeartMin(),
						 mine.targetHeartMax());
	}
}