/*
 Program Name: Car.java
 Author: Nathan Caron
 Assignment #10
 Date: 11/19/2014
 Purpose: Calculate carbon footprint of cars.
*/



public class Car implements CarbonFootprint
{
	private double monthlyMiles, milesPerGallon;

	public Car(double monthlyMiles, double MPG)
	{
		if(monthlyMiles < 0)
			throw new IllegalArgumentException(
				"Miles per month can not be negative.");
		if(MPG <= 0)
			throw new IllegalArgumentException(
				"Miles per gallon can not be negative or 0.");
		this.monthlyMiles = monthlyMiles;
		milesPerGallon = MPG;
	}

	public void setMonthlyMiles(double miles)
	{
		if(miles < 0)
			throw new IllegalArgumentException(
				"Miles per month can not be negative.");
		monthlyMiles = miles;
	}

	public void setMilesPerGallon(double MPG)
	{
		if(MPG <= 0)
			throw new IllegalArgumentException(
				"Miles per gallon can not be negative or 0.");
		milesPerGallon = MPG;
	}

	public double getMonthlyMiles(){ return monthlyMiles; }
	public double getMilesPerGallon(){ return milesPerGallon; }

	public double getYearlyGallons()
	{
		// multiply by 12 to get yearly miles then divide by MPG
		return 12 * getMonthlyMiles() / getMilesPerGallon();
	}

	@Override
	public double getCarbonFootprint()
	{
		// multiply gallons yearly by 8.91 kg per gallon
		return 8.91 * getYearlyGallons();
	}

}