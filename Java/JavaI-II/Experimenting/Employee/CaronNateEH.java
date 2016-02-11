/*
 Program Name: CaronNateEH.java
 Author: Nathan Caron
 Assignment # 9
 Date: 11/12/2014
 Purpose: Create a superclass for Employees.
*/


public class CaronNateEH
{
	private final String firstName, lastName, socialSecurityNumber;

	public CaronNateEH(String first, String last, String ssn)
	{
		firstName = first;
		lastName = last;
		socialSecurityNumber = ssn;
	}

	public String getFirstName(){ return firstName; }
	public String getLastName(){ return lastName; }
	public String getSocialSecurityNumber(){ return socialSecurityNumber; }

	@Override
	public String toString()
	{
		return String.format("%s: %s %s%n%s: %s", "employee", getFirstName(),
							 getLastName(), "Social Security Number",
							 socialSecurityNumber);
	}

}