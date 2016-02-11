

public class command
{
	public static void main(String[]args)
	{
		if(args[0])
		{
			int length = Integer.parseInt(args[0]);
			int[] array = new int[length];
		}
		else
		{
			int[] array = new int[10];
		}

		System.out.printf("%s%8s%n", "Index", "Value");

		for(int counter = 0; counter < array.length; counter++)
			System.out.printf("%5d%8d%n", counter, array[counter]);


	}

}