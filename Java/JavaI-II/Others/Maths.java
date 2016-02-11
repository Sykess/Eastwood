

public class Maths
{
	public static void main(String[] args)
	{
		double amount = 0; // amount on deposit at the end of each year
		double principal = 1000.0; //initial amount before interest
		double rate = 0.05; // interest rate initialized at lowest rate

		//Display headers
		System.out.printf("%s%n" , "\n10 Year Growth by Interest Rate");
		System.out.printf("%s%12s%12s%12s%12s%12s%12s%n",
			"Year", "Rate 5%", "Rate 6%", "Rate 7%", "Rate 8%",
			"Rate 9%", "Rate 10%");
		System.out.printf("%s%s%n", "--------------------------------------",
			"--------------------------------------");

		// To count through each year
		for (int year = 1; year <= 10; year++)
		{
			// To count through each interest rate
			for (int count = 0; count <= 5; count++)
			{
				// Calculate interest for lowest rate and display year
			   	if(rate == 0.05)
				{
					amount = principal * Math.pow(1.0 + rate, year);
					// Display the year and amount
					System.out.printf("%4d%, 12.2f", year, amount);
					rate += 0.01;
				}
				//Calculate interest for the remaining rates don't display year
				else
				{
					// Calculate and display amount at remaining rates
					amount = principal * Math.pow(1.0 + rate, year);
					System.out.printf("%, 12.2f", amount);
					rate += 0.01; // Increment rate
				}
			}
			System.out.printf("%n"); //Move to next line of report
			rate = 0.05; //Reset interest rate to 5%
		}
	}
}