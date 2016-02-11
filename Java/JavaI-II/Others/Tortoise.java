/*
 Program Name: TortoiseAndHare.java
 Author: Nathan Caron
 Date: 10/4/2014
 Purpose:  1 - H  2 - T  3 - OUCH
*/

import java.util.Scanner;
import java.security.SecureRandom;
import java.util.Arrays;

public class Tortoise
{
	private static final SecureRandom randomNumbers = new SecureRandom();

	public static void main(String[] args)
	{
		int[] race = new int[70];

		Scanner input = new Scanner(System.in);

		int hare = 0;
		int tort = 0;

		boolean results = true;

		while(results)
		{
			tort += moveT();
			if(tort < 0)
				tort = 0;
			hare += moveH();
			if(hare < 0)
				hare = 0;
			if(hare >= 69)
				hare = 69;
			if(tort >= 69)
				tort = 69;

			display(race, tort, hare);
			results = results(race);
			input.nextLine(); // next line so you can keep hitting enter
							  // so you can watch the race line by line
		}
		if(race[69] == 1)
			System.out.println("Hare wins!");
		else if(race[69] == 2)
			System.out.println("Tortoise wins!");
		else
			System.out.println("Tie!");
	}
/////////////////////////////////////////////////////////
	public static int moveT()
	{
		int moveT = randomNumbers.nextInt(10);

		switch(moveT)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
				moveT = 3;
				break;
			case 5:
			case 6:
				moveT = -6;
				break;
			case 7:
			case 8:
			case 9:
				moveT = 1;
				break;
		}
		return moveT;
	}
/////////////////////////////////////////////////////////
	public static int moveH()
	{
		int moveH = randomNumbers.nextInt(10);
		switch(moveH)
		{
			case 0:
			case 1:
				moveH = 0;
				break;
			case 2:
			case 3:
				moveH = 9;
				break;
			case 4:
				moveH = -12;
				break;
			case 5:
			case 6:
			case 7:
				moveH = 1;
				break;
			case 8:
			case 9:
				moveH = -2;
				break;
		}
		return moveH;
	}
/////////////////////////////////////////////////////////
	public static void display(int[] race, int t, int h)
	{
		Arrays.fill(race, 0);
		if(t == h)
			race[t] = 3;
		else
		{
			race[t] = 2;
			race[h] = 1;
		}
		for(int x = 0; x < race.length; x++)
		{
			if(race[x] == 0)
				System.out.print(" ");
			if(race[x] == 1)
				System.out.print("H");
			if(race[x] == 2)
				System.out.print("T");
			if(race[x] == 3)
				System.out.print("OUCH");
		}
		System.out.println();
	}
/////////////////////////////////////////////////////////
	public static boolean results(int[] race)
	{
		if(race[69] != 0)
			return false;

		return true;
	}

}