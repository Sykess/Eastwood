
/*
 Program Name: CaronNateTW.java
 Author: Nathan Caron
 Assignment # 3
 Date: 2/24/2015
 Purpose: Convert phone numbers to real words.
*/


import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.io.IOException;
import java.io.PrintStream;
import java.io.File;
import java.io.FileReader;


public class CaronNateTW
{

	private static Scanner readFile;
	private static String[] realWords = new String[10];
	private static int pos = 0;
	private static char letters[][] = { {'0','0','0'},{'1','1','1'},{'A','B','C'},
										{'D','E','F'},{'G','H','I'},{'J','K','L'},
										{'M','N','O'},{'P','R','S'},{'T','U','V'},
										{'W','X','Y'} };


	public static void main(String[] args) throws Exception
	{
		Scanner input = new Scanner(System.in);
		File file = new File("PhoneWords.txt");
		PrintStream ps = new PrintStream(file);
		int[] number = new int[7];
		String numberStr;

		System.out.print("Enter phone number in format xxx-xxxx: \n(note that "
						+"although 0's and 1's are legal digits after \nthe first "
						+"number, they will prevent words from being found)  ");
		numberStr = input.next();

		while(!validateNumber(numberStr))
		{
			System.out.print("\nInvalid format, try again: ");
			numberStr = input.next();
		}

		for(int x = 0; x < numberStr.length(); x++)
		{
			if(x != 3) // position 3 is the dash
				number[pos++] = Character.digit(numberStr.charAt(x), 10);
		}
		pos = 0;  // reuse pos here and in compareWords function


		System.out.println("\nComputing possible real words and then writing to file "
						  +"PhoneWords.txt\nThis may take a minute or two...");

		calcWords(number);

		for(String s : realWords)
		{
			if(s != null)
				ps.println(s);
		}

		if(realWords[0] == null)
			System.out.println("No real word matches found.");
		else
			System.out.println("Matches were found and printed to file.");

		if(ps != null)
			ps.close();

	}
/////////////////////////////////////////////////////////////////////////
	public static boolean validateNumber(String num)
	{
		return num.matches("[1-9]\\d{2}-\\d{4}");
	}
/////////////////////////////////////////////////////////////////////////

	public static void compareWords(char[] word)
	{
		String str = new String(word);

		try
		{
			readFile = new Scanner(Paths.get("enable1.txt"));
		}
		catch(IOException e)
		{
			System.out.println("Error, file enable1.txt not found!");
			System.exit(1);
		}

		while(readFile.hasNext())
		{
			if(readFile.next().equalsIgnoreCase(str))
			{
				realWords[pos] = str;
				pos++;
			}
		}
		readFile.close();
	}

/////////////////////////////////////////////////////////////////////////

	public static void calcWords(int[] num)
	{
		char[] word = new char[7];

		for(int a = 0; a < 3; a++)
		{
			word[0] = letters[num[0]][a];
			for(int b = 0; b < 3; b++)
			{
				word[1] = letters[num[1]][b];
				for(int c = 0; c < 3; c++)
				{
					word[2] = letters[num[2]][c];
					for(int d = 0; d < 3; d++)
					{
						word[3] = letters[num[3]][d];
						for(int e = 0; e < 3; e++)
						{
							word[4] = letters[num[4]][e];
							for(int f = 0; f < 3; f++)
							{
								word[5] = letters[num[5]][f];
								for(int g = 0; g < 3; g++)
								{
									word[6] = letters[num[6]][g];
									compareWords(word);
								}
							}
						}
					}
				}
			}
		}
	}
/////////////////////////////////////////////////////////////////////////

}