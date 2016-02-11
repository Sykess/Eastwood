
import java.util.Scanner;

public class Reverse
{

	public static void main(String[] args)
	{
		int frontNum;

		Scanner input = new Scanner(System.in);
		System.out.println("Enter an integer and I will reverse the digits: ");
		frontNum = input.nextInt();
		System.out.printf("%n%n%s%d%n", "The reverse of your number is ",
			reverseNum(frontNum));
	}


	public static int reverseNum(int forwardNum)
	{
		int backNum = 0;

		while(forwardNum > 0)
		{
			backNum *= 10;
			backNum += forwardNum % 10;
			forwardNum /= 10;
		}
		return backNum;
	}

}