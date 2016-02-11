/*
Program Name: PracticeAlgebra.java
Author: Nathan Caron
Modified: 9/24/2014

*/

import javax.swing.JOptionPane;
import java.lang.Math;
import java.util.Scanner;
import java.security.SecureRandom;

public class PracticeAlgebra
{
	private static final SecureRandom randomNumbers = new SecureRandom();
	public static void main(String[] args)
	{

		Scanner input = new Scanner(System.in);
		int keepgo = 5;
		problem();

		do{
			String choice = JOptionPane.showInputDialog("6X + 32 = ?");
			double answer = Double.parseDouble(choice);
			double correct = -32;
			correct/= 5;

			String message = String.format("Nope, it's %f, better luck next time!", correct);
			if(answer == correct)
			JOptionPane.showMessageDialog(null, "Correct!");
			else
			JOptionPane.showMessageDialog(null, message);
			choice = JOptionPane.showInputDialog("Done? 1 for no");
			int blah = Integer.parseInt(choice);
			keepgo = blah;

		}while(keepgo== 1);
	}

	public static void problem()
	{
		JOptionPane.showMessageDialog(null, "1: Multiplication\n2: Division \n 3 Add/Subtract");
		String choice = JOptionPane.showInputDialog("1: Multiplication\n2: Division \n 3 Add/Subtract\nWhat type of problem do you want?");
		int blah = Integer.parseInt(choice);

	}

	public static void create()
	{
		int digits = 2 + randomNumbers.nextInt(5);
		int x = 1 + randomNumbers.nextInt(9);
		int y = randomNumbers.nextInt(10);



	}

}