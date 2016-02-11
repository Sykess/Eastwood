/*
 Program Name: Rethrowing.java
 Author: Nathan Caron
 Assignment: N/A
 Date: 11/24/2014
 Purpose: Demonstrate rethrowing an exception.
*/



public class Rethrowing
{
	public static void main(String[] args)
	{
		try
		{
			someMethod();
		}
		catch(Exception e)
		{
			System.err.println("Caught in main stack trace:");
			// Catch the twice rethrown exception and print stack trace.
			e.printStackTrace();
		}

		System.out.println("Program still makes it here since exceptions "
						   +"were all handled.");
	}
/////////////////////////////////////////////////////////
	public static void someMethod() throws Exception
	{
		try
		{
			someMethod2();
		}
		catch(Exception e)
		{
			System.err.println("someMethod, thrown second");
			// Rethrow exception from someMethod2
			throw e;
		}
	}
/////////////////////////////////////////////////////////
	public static void someMethod2() throws Exception
	{
		try
		{
			// Initial exception throw
			throw new Exception();
		}
		catch(Exception e)
		{
			System.err.println("someMethod2, thrown first");
			// Rethrow for further testing
			throw e;
		}
	}
}