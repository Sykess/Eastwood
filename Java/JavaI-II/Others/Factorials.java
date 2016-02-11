/*
 Program Name: Factorials.java
 Author: Nathan Caron
 Date: 9/21/14
 Purpose: Display even factorials 1-20.
*/

public class Factorials
{
	public static void main(String[] args)
	{
		long fact = 1;

		System.out.printf("%-6s%-30s%n", "N:", "|  N! (or N Factorial) :");
		System.out.println("==============================");
		for(int x = 2; x <= 20; x+= 2)
		{
			fact *= x; // fact is multiplied by x, which each loop will
					   // combine for a total of all the numbers 1
					   // through x
			fact *= (x - 1); // since we're only displaying the even numbers
							 // our for loop goes by 2's, but those odd
							 // numbers still need to be multiplied into
							 // fact to get the correct result, so every
							 // iteration we also multiply fact by x - 1
			System.out.printf("%-6d%-3s%,-30d%n", x, "|  ", fact);
			// If you try to go any higher you will not get the correct answer
			// because it will be too large for the long and will overflow
			// long's range is -9,223,372,036,854,775,808 to
			// +9,223,372,036,854,775,807
		}
	}
}