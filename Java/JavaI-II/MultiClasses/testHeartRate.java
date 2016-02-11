d/*
 Program Name:
 Author: Nathan Caron
 Assignment
 Date: 10/29/2014
 Purpose: Test out HeartRates class
*/


import java.util.Scanner;

public class testHeartRate
{
	public static Scanner input = new Scanner(System.in);
	private static final int MONTH = 0;
	private static final int DAY = 1;
	private static final int YEAR = 2;

	public static void main(String[] args)
	{

		String lastName, firstName;
		int month, day, year;
		int[] bDay = new int[3];
		int choice = 0;

		firstName = enterName("first");
		lastName = enterName("last");
		birthDay(bDay);

		HeartRates mine = new HeartRates(firstName, lastName, bDay[MONTH],
										 bDay[DAY], bDay[YEAR]);

		mine.displayInfo();
		do
		{
			menu();
			choice = input.nextInt();
			switch(choice)
			{
				case 1: firstName = enterName("first");
						mine.setFirstName(firstName);
						break;
				case 2: lastName = enterName("last");
						mine.setLastName(lastName);
						break;
				case 3: birthDay(bDay);
						mine.setMonth(bDay[MONTH]);
						mine.setDay(bDay[DAY]);
						mine.setYear(bDay[YEAR]);
						break;
				case 5: mine.displayInfo();
						break;
			}
		}while(choice != 6);

	}

	public static void birthDay(int[] bDay)
	{
		System.out.print("Enter the numerical month of your birthday: ");
		bDay[MONTH] = input.nextInt();
		while(bDay[MONTH] < 1 || bDay[MONTH] > 12)
		{
			System.out.print("Enter month 1-12: ");
			bDay[MONTH] = input.nextInt();
		}

		System.out.print("Enter the day of your birthday: ");
		bDay[DAY] = input.nextInt();
		while(bDay[DAY] < 1 || bDay[DAY] > 31)
		{
			System.out.print("Enter day 1-31: ");
			bDay[DAY] = input.nextInt();
		}

		System.out.print("Enter the year you were born: ");
		bDay[YEAR] = input.nextInt();
		while(bDay[YEAR] < 1900 || bDay[YEAR] > 2014)
		{
			System.out.print("Enter the correct year: ");
			bDay[YEAR] = input.nextInt();
		}
	}

	public static String enterName(String s)
	{
		System.out.printf("Enter your %s name:", s);
		s = input.nextLine();
		return s;
	}

	public static void menu()
	{
		System.out.println("\n1 - Change first name");
		System.out.println("2 - Change last name");
		System.out.println("3 - Change Birthdate");
		System.out.println("4 - Change today's date");
		System.out.println("5 - Display Data");
		System.out.print("6 - Quit : ");
	}
}