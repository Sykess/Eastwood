

import java.math.BigInteger;
import java.lang.StringBuffer;



public class LychrelNumbers
{
	public static void main(String[] args)
	{
		int result = 0;

		for(int i = 10; i < 10000; i++)
			if(isLych(i))
				result++;
		System.out.println(result);
	}
	public static boolean isLych(int num)
	{
		BigInteger orig = new BigInteger(Integer.toString(num));
		BigInteger temp;
		String reverse;
		reverse = new StringBuffer(orig.toString()).reverse().toString();
		temp = new BigInteger(reverse);

		for(int i = 0; i < 50; i++)
		{
			orig = orig.add(temp);
			reverse = new StringBuffer(orig.toString()).reverse().toString();
			temp = new BigInteger(reverse);
			if(orig.equals(temp))
				return false;
		}
		return true;
	}

}