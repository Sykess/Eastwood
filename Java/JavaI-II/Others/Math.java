


import java.util.Scanner; // needed to get user input

public class Math
{
	public static void main(String[] args)
	{
		Scanner input = new Scanner(System.in); // needed for user input

		int number; // create number for user's input
		int output1, output2, output3, output4; // create output variables

		System.out.print("Enter exactly 5 numbers: ");
		number = input.nextInt(); //read number from user

		output1 = number % 10; // gives us digit in 1's position
		number /= 10; // drops last number off of user input
		output2 = number % 10; // gives us digit in current 1's position
							   // which is user's 10's position
		number /= 10;
		output3 = number % 10; // gives us user's 100's position
		number /= 10;
		output4 = number % 10; // gives us user's 1000's position
		number /= 10;
		//what is remaining in number now is the first output

		// Prints users number with exactly 3 spaces between each digit
		// if user enters more than 5 digits, the first number will have
		System.out.printf("%d   %d   %d   %d   %d%n", number, output4,
		                  output3, output2, output1);

	}
}