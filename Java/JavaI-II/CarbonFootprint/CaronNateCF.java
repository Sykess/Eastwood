/*
 Program Name: CaronNateCF.java
 Author: Nathan Caron
 Assignment #10
 Date: 11/19/2014
 Purpose: Test the CarbonFootprint interface.
*/


import java.util.ArrayList;

public class CaronNateCF
{
	public static void main(String[] args)
	{
		ArrayList<CarbonFootprint> list = new ArrayList<CarbonFootprint>();

		// car thats drives 921 miles per month and gets 29 miles per gallon.
		list.add(new Car(500, 29));
		// building that uses 50 kWh electricity & 40 therms of gas per month.
		list.add(new Building(45, 40, 0));
		// bicycle that drives 112 miles per month.
		list.add(new Bicycle(112));

		for(int x = 0; x < list.size(); x++)
		{
			System.out.printf("The carbon footprint of the %s is: %.2f KG%s%n",
				list.get(x).getClass().getName(),
				list.get(x).getCarbonFootprint(), " per year.");
		}
	}
}