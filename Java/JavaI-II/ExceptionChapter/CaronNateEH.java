/*
 Program Name: CaronNateEH.java
 Author: Nathan Caron
 Assignment #11
 Date: 11/26/2014
 Purpose: Demonstrate exception handling with files.
*/

import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.FileReader;


public class CaronNateEH
{
	// Instance variable
	public static String[][] array = new String[52][2];


	public static void main(String[] args)
	{
		String file, state;
		int age, zipCode = 0, position = -1;
		boolean continueLoop = true;
		Scanner input = new Scanner(System.in);

		try
		{
			System.out.print("Enter your age to participate in survey: ");
			age = input.nextInt();
		}
		catch(InputMismatchException e)
		{
			System.err.print("We understand you do not want to participate"
				+" in our survey\nThanks for your time!\n");
			return;
		}


		while(continueLoop)
		{
			try
			{
				System.out.print("Enter the name of the file containing "
					+"standardized, two character abbreviations for each "
					+"state, along with the names of the states: ");
				file = input.next();
				convertFileToArray(file);
				continueLoop = false; // will break loop if no exceptions
			}
			catch(Exception e)
			{
				System.err.print("The file was not able to be opened.\n");
			}
		}

		System.out.print("Enter the 2 character abbreviation of your state:");

		do{
			state = input.next();

			for(int x = 0; x < array.length; x++)
			{
				// check first column of array for state abbreviation
				if(array[x][0].equalsIgnoreCase(state))
					position = x;
			}
			if(position < 0)
				System.out.print("Incorrect entry, try again: ");
		}while(position < 0);

		// Reuse continueLoop by setting to true here.
		continueLoop = true;

		while(continueLoop)
		{
			try
			{
				System.out.print("Enter 5 digit zip code: ");
				String zip = input.next();
				if(zip.length() == 5)
				{
					// if zip isn't an integer, will throw exception
					zipCode = Integer.parseInt(zip);
				}
				else // if not 5 characters long, throw exception
					throw new Exception();
				continueLoop = false;
			}
			catch(NumberFormatException e)
			{
				System.err.println("Zip code must be numbers. ");
			}
			catch(Exception e)
			{
				System.err.println("Zip code must be 5 digits long. ");
			}
		}

		System.out.printf("Customer's Age: %d%nState: %s%nZip Code: %05d%n%s%n",
			age, array[position][1], zipCode, "Thank you for participating "
			+"in our survey!");


	}
////////////////////////////////////////////////////////////
	public static void convertFileToArray(String file) throws Exception
	{
		int counter = 0;
		int x = 0;
		int y = 0;
		Scanner inFile = null;

		try
		{
			inFile = new Scanner(new FileReader(file));

			while(inFile.hasNext())
			{
				// use a delimiter to separate at newlines and :
				inFile.useDelimiter(":|\r?\n|\r");

				// counter will alternate between 0 and 1, so all
				// state abbreviations will be in the 1st column
				// and all state names will be in the 2nd column
				if(counter == 1)
				{
					array[x][y] = inFile.next();
					x++;
					y--;
					counter--;
				}
				else
				{
					array[x][y] = inFile.next();
					y++;
					counter++;
				}
			}
		}
		catch(Exception e)
		{
			throw e;
		}
		// finally so file will close no matter what
		finally
		{
			inFile.close();
		}
	}

}