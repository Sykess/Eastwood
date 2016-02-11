


import java.util.Scanner;
import java.io.FileReader;
import java.io.File;

public class CaronNateEH
{
	public static void main(String[] args)
	{
		String[][] array = new String[52][2];
		int counter = 0;
		int x = 0;
		int y = 0;
		String strFile = "states.dat";
		Scanner inFile = null;
		try{

			inFile = new Scanner(new FileReader("states.dat"));

			while(inFile.hasNext())
			{
				inFile.useDelimiter(":");

				array[x][y] = inFile.next();

				if(counter == 1)
				{
					x++;
					y--;
					counter--;
				}
				else
				{
					y++;
					counter++;
				}
			}

			inFile.close();

		}catch(Exception e)
		{
			System.err.println("Error: " + e.getMessage());
		}finally
		{
			inFile.close();
		}
	}


}