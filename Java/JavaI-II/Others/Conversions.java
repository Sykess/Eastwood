/*
Program Name: Conversions.java
Author: Nathan Caron
Date modified: 9/24/2014
*/

public class Conversions
{
	public static void main(String[] args)
	{
		int bin, oct, hex;

		System.out.printf("%6s%6s%6s%10s", "Decimal:", "Binary:", "Octal", "Hexadecimal:");

		for(int dec = 1; dec <= 32; dec++)
		{
			bin = toBin(dec);

			oct = toOct(dec);

			System.out.printf("%n%6d%6d%6d", dec, bin, oct);

		}


	}

	public static int toBin(int x)
	{
		int bin = 0;

		if(x == 256)
		{
			bin = 100000000;
			return bin;
		}

		if(x >= 128)
		{
			x -= 128;
			bin += 10000000;
		}

		if(x >= 64)
		{
			x -= 64;
			bin += 1000000;
		}

		if(x >= 32)
		{
			x -= 32;
			bin += 100000;
		}

		if(x >= 16)
		{
			x -= 16;
			bin += 10000;
		}
		if(x >= 8)
		{
			x -= 8;
			bin += 1000;
		}

		if(x >= 4)
		{
			x -= 4;
			bin += 100;
		}

		if(x >= 2)
		{
			x -= 2;
			bin += 10;
		}

		if(x >= 1)
			bin += 1;

		return bin;
	}

	public static int toOct(int x)
	{
		int oct = 0;

		if(x >= 64)
		{
			oct = x % 8;
			x /= 8;
		}

		if(x > 8)
		{
			oct += (x % 8 * 10);
			x /= 8;
		}

		if(x > 0)
			oct += (x % 8 * 100);
		return oct;
	}

	public static void toHex(int x)
	{


	}
}