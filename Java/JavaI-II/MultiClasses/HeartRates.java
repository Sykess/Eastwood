/*
 Program Name: HeartRates.java
 Author: Nathan Caron
 Assignment # 7
 Date: 10/29/2014
 Purpose: Calculate heart rate maximum and target range.
*/


import java.time.LocalDate;


public class HeartRates
{
	private LocalDate today = LocalDate.now(); // used for current date
	private String firstName, lastName;
	private int month, day, year; // birthday variables
	private int currentMonth = today.getMonthValue();
	private int currentDay = today.getDayOfMonth();
	private int currentYear = today.getYear();

	public HeartRates(String fn, String ln, int month, int day, int year)
	{
		firstName = fn;
		lastName = ln;
		this.month = month;
		this.day = day;
		this.year = year;
	}


	// Mutators:
	public void setLastName(String lastName){ this.lastName = lastName; }
	public void setFirstName(String firstName){ this.firstName = firstName; }
	public void setMonth(int month)
	{
		if(month >= 1 && month <= 12)
			this.month = month;
	}
	public void setDay(int day)
	{
		// generic validate incase day is set before month
		if(day >= 1 && day <= 31)
			this.day = day;
	}
	public void setYear(int year)
	{
		if(year >= 1900 && year <= 2014)
			this.year = year;
	}
	public void setCurrentMonth(int month)
	{
		if(month >= 1 && month <= 12)
			currentMonth = month;
	}
	public void setCurrentDay(int day)
	{
		if(day >= 1 && day <= 31)
			currentDay = day;
	}
	public void setCurrentYear(int year)
	{
		if(year >= 1900 && year <= 2014)
			currentYear = year;
	}

	// Accessors
	public String getLastName(){ return lastName; }
	public String getFirstName(){ return firstName; }
	public int getMonth(){ return month; }
	public int getDay(){ return day; }
	public int getYear(){ return year; }
	public int getCurrentMonth(){ return currentMonth; }
	public int getCurrentDay(){ return currentDay; }
	public int getCurrentYear(){ return currentYear; }

	public int getAge()
	{
		if(currentMonth > month)
			return currentYear - year;
		else if(currentMonth == month)
			if(currentDay >= day)
				return currentYear - year;
		//if neither return has hit then deduct this year:
		return currentYear - year - 1;
	}

	public int maxHeartRate()
	{
		return 220 - getAge();
	}

	public double targetHeartMin()
	{
		return .5 * maxHeartRate();
	}
	public double targetHeartMax()
	{
		return .85 * maxHeartRate();
	}

	public void displayInfo()
	{
		System.out.printf("%nFirst name: %s%nLast name: %s%nAge: %d%n"
						+"Max Heart Rate: %d%nTarget range: %.0f-%.0f",
						firstName,  lastName,+getAge(), maxHeartRate(),
						targetHeartMin(), targetHeartMax() );
		// display doubles with .0f so that it rounds to nearest whole number
		System.out.println(); // blank line for readability
	}

}