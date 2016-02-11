
import java.util.Scanner;


public class zipCode
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in);
		String zip;
		int zipNum;
		boolean continueLoop = true;

		while(continueLoop)
		{
			try
			{
				System.out.print("Enter 5 digit zip code: ");
				zip = input.next();
				if(zip.length() == 5)
				{
					zipNum = Integer.parseInt(zip);
				}
				else
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


	}



}