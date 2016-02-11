/*




*/



public class Date2
{
	private int month, day, year;


	public Date(int month, int day, int year)
	{
		if(month > 0 && month < 13)
			this.month = month;
		if(day > 0 && day < 32)
			this.day = day;
		if(year > 0 && year < 2100)
			this.year = year;
	}

	public int getMonth(){  return month;  }
	public void setMonth(int month){ this.month = month; }

	public int getDay(){  return day;  }
	public void setDay(int day){  this.day = day;  }

	public int getYear(){  return year;  }
	public void setYear(int year){ this.year = year; }

	public void displayDate()
	{
		System.out.printf("%d/%d/%d", month, day, year);
	}

}