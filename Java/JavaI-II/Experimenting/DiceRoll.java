

import java.util.Random;


public class DiceRoll
{
	private static final Random randomNumbers = new Random();
	private static final int MAX = 36000000;

	public static void main(String[] args)
	{
		int[] total = new int[13];
		int roll = 0;

		for(int x = 0; x < MAX; x++)
		{
			roll = rollDice();
			total[roll]++;
		}

		System.out.println("Roll:	Frequency:");

		for(int x = 2; x < total.length; x++)
			System.out.printf("%d\t%,d%n", x, total[x]);

	}

	public static int rollDice()
	{
		int die1 = 1 + randomNumbers.nextInt(6);
		int die2 = 1 + randomNumbers.nextInt(6);

		return die1 + die2;
	}


}