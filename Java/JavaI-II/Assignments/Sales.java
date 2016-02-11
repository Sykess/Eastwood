/*
 Program Name: Sales.java
 Author: Nathan Caron
 Date Modified: 10/12/2014
 Purpose: Take in sales slips and output totals.
*/

import java.util.Scanner;

public class Sales
{
	public static void main(String[] args)
	{
		double[][] sales = new double [5][4];

		Scanner input = new Scanner(System.in);

		System.out.print("Enter a slip? (1 for yes 2 for no) ");
		int choice = input.nextInt();

		while(choice < 1 || choice > 2)
		{
			System.out.print("Invalid choice, 1 for yes, 2 for no: ");
			choice = input.nextInt();
		}

		while(choice == 1)
		{
			enterSales(sales);
			System.out.print("Enter another slip? (1-yes, 2-no) ");
			choice = input.nextInt();

			while(choice < 1 || choice > 2)
			{
				System.out.print("Invalid choice, 1 for yes, 2 for no: ");
				choice = input.nextInt();
			}
		}

		System.out.printf("%nSalesperson #:%10s%13s%13s%13s%13s%n",
						  "1","2","3","4","Total:");
		for(int row = 0; row < sales.length; row++)
		{
			System.out.printf("Product #%d:", row + 1);

			double totalProd = 0;
			for(int col = 0; col < sales[row].length; col++)
			{
				System.out.printf("%5s %7.2f", "$", sales[row][col]);
				totalProd+= sales[row][col];

				if(col == sales[row].length -1)
					System.out.printf("%5s %7.2f", "$", totalProd);

			}
			System.out.println();
		}

		System.out.print("Total:     ");
		for(int col = 0; col < sales[col].length; col++)
		{
			double totalPerson = 0;
			for(int row = 0; row < sales.length; row++)
			{
				totalPerson += sales[row][col];
			}

			System.out.printf("%5s %7.2f", "$", totalPerson);
		}
		System.out.println();
	}
//////////////////////////////////////////////////////////////////////////
	public static void enterSales(double[][] sales)
	{
		Scanner input = new Scanner(System.in);

		System.out.print("Enter the salesperson number: ");
		int salesNum = input.nextInt();
		while(salesNum < 1 || salesNum > 4)
		{
			System.out.print("Invalid entry, enter salesperson #(1-4): ");
			salesNum = input.nextInt();
		}

		System.out.print("Enter product number: ");
		int productNum = input.nextInt();
		while(productNum < 1 || productNum > 5)
		{
			System.out.print("Invalid product number, enter 1-5: ");
			productNum = input.nextInt();
		}

		System.out.print("Enter dollar value earned for that product: ");
		double total = input.nextDouble();
		while(total < 0)
		{
			System.out.print("Invalid dollar amount, enter correct amount: ");
			total = input.nextDouble();
		}

		sales[productNum -1][salesNum -1] += total;
	}

}