/*
Program name: Airline.java
Date Modified: 10/8/2014
Creator: Nathan Caron
Purpose: Assign seats for first class and economy.
*/

import java.util.Scanner;

public class Airline
{
	public static void main(String[] args)
	{
		boolean[] seats = new boolean[10];
		Scanner input = new Scanner(System.in);
		int seat = -1;
		int again;

		do
		{
			System.out.print("Please enter 1 for first class or 2 for economy: ");

			int grade = input.nextInt();

			while(grade != 1 && grade != 2)
			{
				System.out.print("Invalid entry, please type 1 or 2: ");
				grade = input.nextInt();
			}

			if(grade == 1)
				seat = firstClass(seats);
			if(grade == 2)
				seat = economy(seats);
			while(seat < 0)
			{
				if(grade == 1)
				{
					System.out.print("First class is full, would you mind economy? (1 for yes, 2 for no) ");
					grade = input.nextInt();

					while(grade != 1 && grade != 2)
					{
						System.out.print("Incorrect response, 1 for yes, 2 for no: ");
						grade = input.nextInt();
					}
					if(grade == 1)
					{
						seat = economy(seats);
						if(seat < 0)
							System.out.print("Sorry full, next flight leaves in 3 hours!");
					}
					else
						System.out.print("Next flight leaves in 3 hours!");
					grade = 1;
				}
				if(grade == 2)
				{
					System.out.print("Economy is full, would you mind First class? (1 for yes, 2 for no) ");
						grade = input.nextInt();

						while(grade != 1 && grade != 2)
						{
							System.out.print("Incorrect response, 1 for yes, 2 for no: ");
							grade = input.nextInt();
						}
						if(grade == 1)
						{
							seat = firstClass(seats);
							if(seat < 0)
								System.out.print("Sorry full, next flight leaves in 3 hours!");
						}
						else
							System.out.print("Next flight leaves in 3 hours!");
				}
				if(seat == -1)
					seat = 11;
			}

			if(seat < 11 && seat > 5)
				System.out.printf("Boarding pass: seat %d, class: Economy.%n%n", seat);
			if(seat < 6 && seat >= 0)
				System.out.printf("Boarding pass: seat %d, class: First class.%n%n", seat);
			System.out.print("Would you like to book another ticket? (1 for yes, 2 for no) ");
			again = input.nextInt();


		}while(again == 1);


	}

	public static int economy(boolean[] seats)
	{
		int empty = -1;

		for(int x = 5; x < seats.length; x++)
		{
			if(!seats[x])
			{
				empty = x;
				seats[x] = true;
				return empty;
			}
		}
		return empty;
	}

	public static int firstClass(boolean[] seats)
	{
		int empty = -1;

		for(int x = 0; x < seats.length / 2; x++)
		{
			if(!seats[x])
			{
				empty = x;
				seats[x] = true;
				return empty;
			}
		}
		return empty;
	}

}