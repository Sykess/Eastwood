


public class EnhancedFor
{
	public static void main(String[] args)
	{
		double finish;

		for(String x : args)
			finish += Double.parseDouble(x);

		System.out.print(finish);

	}


}