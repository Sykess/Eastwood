/**************************************************************************************************
program:      ComparingInts.java
author:       Daniel Clukey
date:         9/11/14
assignment:   discussion assignment 2
purpose:      To allow the user to input 2 integers then tell which one is larger.
**************************************************************************************************/

//For scanner to get user input.
import java.util.Scanner;

public class ComparingInts
{
	public static void main(String[] args)
	{
		//Declares scanner for input.
		Scanner input = new Scanner(System.in);

		//Declare variables
		int num1, num2;

		//Tell the user what the program does then nextline(\n).
		System.out.println("Enter two numbers into this program to tell which one is larger.\n");

		//Ask for user input for number 1 (num1).
		System.out.print("Enter the first integer. ");

		//Receive user input for number 1 (num1).
		num1 = input.nextInt();

		//Nextline(%n) then ask for user input for number 2 (num2).
		System.out.print("\nEnter the second integer. ");

		//Receive user input for number 2 (num2).
		num2 = input.nextInt();

		//Relational operator, if this (num1) is greater than (>) this (num2)
		if (num1 > num2)
		{
			//then print nextline(%n) "num1(the value stored in num1) is larger." nextline(%n).
			System.out.printf("%n%d is larger. %n", num1);
		}
		//if statement contained in brackets for readability.


        //Relational operator, if this (num2) is greater than (>) this (num1)
		if (num2 > num1)
		{
			//then print nextline(%n) "num2(the value stored in num2) is larger." nextline(%n).
			System.out.printf("%n%d is larger. %n", num2);
		}
		//if statement contained in brackets for readability.


		//Relational operator, if this (num1) is equal to (==) this (num2)
		if (num1 == num2)
		{
			//then nextline(\n) then print "The numbers are equal." then nextline(println).
			System.out.println("\nThe numbers are equal.");
		}
		//if statement contained in brackets for readability.
	}
}