/*
 Program Name: Date.java
 Author: Nathan Caron
 Assignment -
 Date: 10/27/2014
 Purpose: Create a class to store and display dates.
*/



public class Date
{
	private int month, day, year;

	// Constructor
	public Date(int month, int day, int year)
	{
		if(year > 0 && year < 2100)
			this.year = year;
		//validate day correlates with month
		if(month >= 1 && month <= 12)
		{
			this.month = month;

			if(month == 1 || month == 3 || month == 5 || month == 7 ||
			month == 8 || month == 10 || month == 12)
			{
				if(day >= 1 && day <= 31)
					this.day = day;
			}
			else if(month == 4 || month == 6 || month == 9 || month == 11)
			{
				if(day >= 1 && day <= 30)
					this.day = day;
			}
			else if(month == 2)
			{
				if(year % 4 == 0)
				{
					if(day >= 1 && day <= 29)
						this.day = day;
				}
				else
				{
					if(day >= 1 && day <= 28)
						this.day = day;
				}
			}
		}
	}

	// Accessors
	public int getMonth(){  return month;  }
	public int getDay(){  return day;  }
	public int getYear(){  return year;  }

	// Mutators
	public void setMonth(int month)
	{
		if(month >= 1 && month <= 12)
			this.month = month;
		else
			this.month = 0;
	}

	public void setDay(int day)
	{
		if(month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12)
		{
			if(day >= 1 && day <= 31)
				this.day = day;
		}
		else if(month == 4 || month == 6 || month == 9 || month == 11)
		{
			if(day >= 1 && day <= 30)
				this.day = day;
		}
		else if(month == 2)
		{
			if(year % 4 == 0)
			{
				if(day >= 1 && day <= 29)
					this.day = day;
			}
			else
			{
				if(day >= 1 && day <= 28)
					this.day = day;
			}
		}
		else // if the day is not valid
			this.day = 0;
	}

	public void setYear(int year)
	{
		if(year > 0 && year < 2100)
			this.year = year;
		else
			this.year = 0;
	}

	public void displayDate()
	{
		if(month > 0 && day > 0 && year > 0)
			System.out.printf("%02d/%02d/%d", month, day, year);
		else
			System.out.print("Invalid date");
	}

}