/*
 Program Name: Bicycle.java
 Author: Nathan Caron
 Assignment #10
 Date: 11/19/2014
 Purpose: Calculate carbon footprint of bicycles.
*/



public class Bicycle implements CarbonFootprint
{
	private double milesMonthly;

	public Bicycle(double miles)
	{
		if(miles < 0)
			throw new IllegalArgumentException(
				"Can not ride negative hours");
		milesMonthly = miles;
	}

	public void setMiles(double miles)
	{
		if(miles < 0)
			throw new IllegalArgumentException(
				"Can not ride negative hours");
		milesMonthly = miles;
	}

	public double getMiles(){ return milesMonthly; }

	@Override
	public double getCarbonFootprint()
	{
		// bicycles do not emit CO2 so return 0
		return 0;
	}
}