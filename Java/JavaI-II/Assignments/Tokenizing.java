

import java.util.Scanner;
import java.util.StringTokenizer;

public class Tokenizing
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);

		System.out.print("Enter a line of text then hit enter: ");
		String line = scanner.nextLine();
		StringBuilder buffer;

		String[] token = line.split(" ");

		System.out.println("The words starting with \"b\" are:");

		for(String x : token)
		{
			buffer = new StringBuilder(x);

			if(buffer.charAt(0) == 'b')
				System.out.printf("%s ", buffer);
		}
		System.out.println();
		System.out.println();
	}
}