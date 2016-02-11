/*
 Program Name: TortoiseAndHare.java
 Author: Nathan Caron
 Date: 10/4/2014
 Purpose:
*/

import java.security.SecureRandom;
import java.util.ArrayList;

public class TortoiseAndHare
{
	private static final SecureRandom randomNumbers = new SecureRandom();

	public static void main(String[]args)
	{
		ArrayList<String> raceTrack = new ArrayList<String>(70);
		boolean race = true;
		String hare = "H";
		String tortoise = "T";



		for(String item : raceTrack)
			System.out.printf(" %s", item);

		raceTrack.add("OUCH");

		int counter = 0;

		for(int x = 1; x < 70; x++)
			raceTrack.add(" ");

		System.out.println("And they're off!");

		while(counter < 5)
		{
			move(raceTrack);
			display(raceTrack);

			checkRace(raceTrack);
			counter++;
		}


	}
	public static void move(ArrayList<String> race)
	{
		int moveT = randomNumbers.nextInt(10);
		int moveH = randomNumbers.nextInt(10);

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

		int currentPosition = race.indexOf("H");
		if(currentPosition < 0)
			currentPosition = race.indexOf("OUCH");
		currentPosition += moveH;
		if(currentPosition < 0)
			currentPosition = 0;
		if(race.get(currentPosition) == "T"  || race.get(currentPosition) =="OUCH")
			race.remove(currentPosition);
		race.add(currentPosition, "H");

		currentPosition = race.indexOf("T");
		if(currentPosition < 0)
			currentPosition = race.indexOf("OUCH");
		if(currentPosition < 0)
			currentPosition = race.indexOf("H");
		currentPosition += moveT;
		if(currentPosition < 0)
			currentPosition = 0;
		if(race.get(currentPosition) == "T")
			race.remove(currentPosition);

		if(race.get(currentPosition) == "H")
		{
			race.remove(currentPosition);
			race.add(currentPosition, "OUCH");
		}
		else
			race.add(currentPosition, "T");

	}



	public static void display(ArrayList<String> race)
	{
		for(String item : race)
			System.out.printf("%s", item);
	}



	public static void checkRace(ArrayList<String> track)
	{

	}



}