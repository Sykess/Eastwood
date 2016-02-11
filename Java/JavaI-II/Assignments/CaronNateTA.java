
import java.util.Scanner;

// A at 65, add 32 for lowercase
public class CaronNateTA
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String s1;
		char[] chars;// = new char[s1.length()];
		char[] alphabet = new char[26];
		int pos = 0;
		int amt = 0;

		System.out.println("Enter a string and the amount each letter occurs "
						+"wil be displayed: ");
		s1 = input.nextLine();

		chars = new char[s1.length()];

		s1.getChars(0, s1.length(), chars, 0);


		for(int x = 65; x < 91; x++)
		{
			alphabet[pos] = (char)x;
			pos++;
		}
		pos = 0;

		for(int x = 65; x < 91; x++)
		{
			amt = 0;
			for(char character : chars)
			{
				if(character == (char)x || character == (char)x+32)
					amt++;
			}
			System.out.printf("%s's:   %d%n", Character.toLowerCase(alphabet[pos]), amt);
			pos++;
		}
	}
}