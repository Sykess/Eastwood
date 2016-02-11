



import java.util.Scanner;


public class TryingPN
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		char letters[][] = { {'0','0','0'},{'1','1','1'},{'A','B','C'},{'D','E','F'},
							 {'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},
							 {'T','U','V'},{'W','X','Y'} };
		char[] word = new char[7];

		int[] number = {7,4,3,7,7,6,5};

		for(int a = 0; a < 3; a++)
		{
			word[0] = letters[number[0]][a];
			for(int b = 0; b < 3; b++)
			{
				word[1] = letters[number[1]][b];
				for(int c = 0; c < 3; c++)
				{
					word[2] = letters[number[2]][c];
					for(int d = 0; d < 3; d++)
					{
						word[3] = letters[number[3]][d];
						for(int e = 0; e < 3; e++)
						{
							word[4] = letters[number[4]][e];
							for(int f = 0; f < 3; f++)
							{
								word[5] = letters[number[5]][f];
								for(int g = 0; g < 3; g++)
								{
									word[6] = letters[number[6]][g];
									System.out.println(word);
								}
							}
						}
					}
				}
			}
		}

	}



}