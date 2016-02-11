/*




*/



public class Date
{
	private int month, day, year;

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

	public int getMonth(){  return month;  }
	public void setMonth(int month){ this.month = month; }

	public int getDay(){  return day;  }
	public void setDay(int day){  this.day = day;  }

	public int getYear(){  return year;  }
	public void setYear(int year){ this.year = year; }

	public void displayDate()
	{
		if(month > 0 && day > 0 && year > 0)
			System.out.printf("%d/%d/%d", month, day, year);
		else
			System.out.print("Invalid date");
	}

}