/*
 Program Name: testDate.java
 Author: Nathan Caron
 Assignment -
 Date: 10/27/2014
 Purpose: Test out the Date class.
*/


public class testDate
{
	public static void main(String[] args)
	{
		Date myDate = new Date(2, 29, 2001);
		Date myDate2 = new Date(2, 29, 2000);

		myDate.displayDate();
		System.out.println();
		myDate2.displayDate();
		System.out.println();
	}
}