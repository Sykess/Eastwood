/*
 Program Name: CommissionEmployee.java
 Author: Nathan Caron
 Assignment # 9
 Date: 11/12/2014
 Purpose: Create a subclass of Employee.
*/

public class CommissionEmployee extends CaronNateEH
{
	private double grossSales, commissionRate;

	public CommissionEmployee(String first, String last, String ssn,
							  double grossSales, double commissionRate)
	{
		super(first, last, ssn);

		if(grossSales < 0)
			throw new IllegalArgumentException("Gross sales must be >= 0");
		if(commissionRate <= 0 || commissionRate >= 1)
			throw new IllegalArgumentException("Commission rate must be > 0"
											   +"and < 1");

		this.grossSales = grossSales;
		this.commissionRate = commissionRate;
	}

	public void setGrossSales(double grossSales)
	{
		if(grossSales < 0)
			throw new IllegalArgumentException("Gross sales must be >= 0");

		this.grossSales = grossSales;
	}

	public void setCommissionRate(double commissionRate)
	{
		if(commissionRate <= 0 || commissionRate >= 1)
			throw new IllegalArgumentException("Commission rate must be > 0"
											   +" and < 1");

		this.commissionRate = commissionRate;
	}

	public double getGrossSales(){ return grossSales; }
	public double getCommissionRate(){ return commissionRate; }

	public double earnings(){ return getCommissionRate() * getGrossSales(); }

	@Override
	public String toString()
	{
		return String.format("%s %s%n%s: %.2f%n%s: %.2f", "Commission ",
							 super.toString(), "Gross Sales", getGrossSales(),
							 "Commission Rate", getCommissionRate());
	}

}