/*
 Program Name: CaronNateBS.java
 Author: Nathan Caron
 Assignment #6
 Date: 4/7/2015
 Purpose: Sorts an array using the "bucket sort" method.
*/



public class CaronNateBS
{

	public static void main(String[] args)
	{
		int[] array = {1356, 152, 151, 155, 1350, 200000000, 151, 45, 1355, 669575, 9392, 11, 11};

		sort(array);

		for(int x : array)
			System.out.println(x);

	}

	public static int places(int[] array)
	{
		int maxValue = 0;
		int places = 1;

		for(int x = 0; x < array.length; x++)
		{
			if(array[x] > maxValue)
				maxValue = array[x];
		}

		while(maxValue / 10 > 0)
		{
			places++;
			maxValue /= 10;
		}
		// returns how many digits are in the maximum value
		return places;
	}

	public static void sort(int[] array)
	{
		int places = places(array);
		int[][] bucket = new int[10][array.length];
		int counter = 0, position = 0, currentPlace = 1;
		// position tracks number in current position
		// currentPlace holds information for 1's 10's 100's etc

		for(int x = 0; x < places; x++)
		{
			for(int y = 0; y < array.length; y++)
			{
				// divides number by place position and then modulus it
				// so when getting positions such as 10's the original
				// number is not lost
				position = array[y] / currentPlace % 10;

				// finds next open position
				while(bucket[position][counter] > 0)
					counter++;

				bucket[position][counter] = array[y];
				counter = 0;
			}

			for(int a = 0; a < bucket.length; a++)
			{
				for(int b = 0; b < bucket[a].length; b++)
				{
					// Goes through 0's then 1's and so on and fills
					// numbers  greater than 0 back into the array
					if(bucket[a][b] > 0)
					{
						array[counter] = bucket[a][b];
						counter++;
						bucket[a][b] = 0;
					}
				}
			}
			counter = 0; // reset counter for next iteration
			currentPlace *= 10;
		}
	}


}