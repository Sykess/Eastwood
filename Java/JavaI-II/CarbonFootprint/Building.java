/*
 Program Name: Building.java
 Author: Nathan Caron
 Assignment #10
 Date: 11/19/2014
 Purpose: Calculate carbon footprint of buildings.
*/



public class Building implements CarbonFootprint
{
	// Useage variables
	private double monthlyElectricity, monthlyGas, monthlyOil;

	public Building(double electricity, double gas, double oil)
	{
		if(electricity < 0)
			throw new IllegalArgumentException(
				"Electricity can not be negative");
		if(gas < 0)
			throw new IllegalArgumentException(
				"Natural gas can not be negative");
		if(oil < 0)
			throw new IllegalArgumentException(
				"Heating oil can not be negative");

		// average monthly electricity measured in kWh
		monthlyElectricity = electricity;
		// average monthly gas measured in therms
		monthlyGas = gas;
		// average monthly oil measured in gallons
		monthlyOil = oil;
	}

	public void setElectricity(double electricity)
	{
		if(electricity < 0)
			throw new IllegalArgumentException(
				"Electricity can not be negative");
		monthlyElectricity = electricity;
	}

	public void setGas(double gas)
	{
		if(gas < 0)
			throw new IllegalArgumentException(
				"Gas can not be negative");
		monthlyGas = gas;
	}

	public void setOil(double oil)
	{
		if(oil < 0)
			throw new IllegalArgumentException(
				"Heating oil can not be negative");
		monthlyOil = oil;
	}

	public double getElectricity(){ return monthlyElectricity; }
	public double getGas(){ return monthlyGas; }
	public double getOil(){ return monthlyOil; }

	public double getYearlyElectricity()
	{
		// 12 months times monthly electricity times .554 kg co2 per kWh
		return 12 * getElectricity() * .554;
	}

	public double getYearlyGas()
	{
		// 12 months times monthly gas times 5 kg co2 per therm
		return 12 * getGas() * 5;
	}

	public double getYearlyOil()
	{
		// 12 months times monthly oil times 10.15 kg co2 per gallon
		return 12 * getOil() * 10.15;
	}


	@Override
	public double getCarbonFootprint()
	{
		// returns annual total KG of co2 for the house
		return getYearlyElectricity() + getYearlyGas() + getYearlyOil();
	}
}