/*
 Program Name: TurtleGraphics.java
 Author: Nathan Caron
 Date: 10/13/14
 Purpose:
*/

import java.util.Scanner;

public class TurtleGraphics
{

	private static boolean pen = false;
	private static Scanner input = new Scanner(System.in);
	private static int direction = 0; //0 right, 1 down, 2 left, 3 up
	private static int posRow = 0;
	private static int posCol = 0;
	private static int[][] floor = new int[20][20];

	public static void main(String[] args)
	{
		int choice;

		do
		{
			displayMenu();
			choice = input.nextInt();
			while(choice < 1 || choice > 9)
			{
				System.out.println("Invalid entry!");
				displayMenu();
				choice = input.nextInt();
			}

			processChoice(choice);
			System.out.println();

		}while(choice != 9);
	}
///////////////////////////////////////////////////////////
	public static void processChoice(int choice)
	{
		switch(choice)
		{
			case 1: pen = false;
				break;
			case 2: pen = true;
				break;
			case 3: if(direction == 3)
						direction = 0;
					else
						direction++;
				break;
			case 4: if(direction == 0)
						direction = 3;
					else
						direction--;
				break;
			case 5: moveForeward();
				break;
			case 6: displayFloor();
				break;
			case 7: for(int row = 0; row < floor.length; row++)
					{
						for(int col = 0; col < floor[row].length; col++)
							floor[row][col] = 0;
					}
				break;
			case 8: System.out.println("Your turtle is at: "+ posRow+"  "+posCol);
			default:
				break;

		}

	}
///////////////////////////////////////////////////////////
	public static void moveForeward()
	{
		System.out.print("Move foreward how many spaces?");
		int spaces = input.nextInt();
		int move = 0;

		while(spaces < 1 || spaces > 19)
		{
			System.out.print("Invalid choice, 1-19: ");
			spaces = input.nextInt();
		}

		switch(direction)
		{
			case 0: // move right
				move = posCol + spaces;
				if(move > 20)
					move = 20;
				if(pen)
				{
					for(int x = posCol; x < move; x++)
						floor[posRow][x] = 1;
				}
				posCol = move -1;
				break;
			case 1: // move down
				move = posRow + spaces;
				if(move > 20)
					move = 20;
				if(pen)
				{
					for(int x = posRow; x < move; x++)
						floor[x][posCol] = 1;
				}
				posRow = move -1;
				break;
			case 2: // move left
				move = posCol - (spaces - 1);
				if(move < 0)
					move = 0;
				if(pen)
				{
					for(int x = move; x <= posCol; x++)
						floor[posRow][x] = 1;
				}
				posCol = move;
				break;
			case 3: // move up
				move = posRow - (spaces - 1);
				if(move < 0)
					move = 0;
				if(pen)
				{
					for(int x = move; x < posRow; x++)
						floor[x][posCol] = 1;
				}
				posRow = move;
		}

	}
///////////////////////////////////////////////////////////
	public static void displayFloor()
	{
		for(int row = 0; row < floor.length; row++)
		{
			for(int col = 0; col < floor[row].length; col++)
			{
				if(floor[row][col] == 0)
					System.out.print(" ");
				else
					System.out.print("*");
			}
			System.out.println();
		}

	}
///////////////////////////////////////////////////////////
	public static void displayMenu()
	{
		System.out.println("Command:	Meaning:");
		System.out.println("1			Pen up");
		System.out.println("2			Pen Down");
		System.out.println("3			Turn right");
		System.out.println("4			Turn left");
		System.out.println("5			Move foreward");
		System.out.println("6			Display floor");
		System.out.println("7			Clear floor");
		System.out.println("9			Current position");
		System.out.println("9			Exit program");
		System.out.print("Enter your choice: ");
	}
///////////////////////////////////////////////////////////
}