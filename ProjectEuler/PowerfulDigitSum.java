
import java.math.BigInteger;
import static java.lang.Math.pow;



public class PowerfulDigitSum
{
	public static void main(String[] args)
	{
		long starttime = System.nanoTime();
		//BigInteger num = new BigInteger("0");
		int highest = 0, current = 0;
		String temp;

		for(int a = 80; a < 100; a++)
		{
			for(int b = 80; b < 100; b++)
			{
				current = 0;
				temp = Integer.toString(a);
				BigInteger num = new BigInteger(temp);
				//num = num.valueOf(a);
				num = num.pow(b);
				while(!num.equals(BigInteger.ZERO))
				{
					current += num.mod(BigInteger.TEN).intValue();
					num = num.divide(BigInteger.TEN);
				}
				if(current > highest)
					highest = current;
			}
		}

		System.out.println(highest);

		long endtime = System.nanoTime();
		double totaltime = endtime-starttime;

		System.out.println("total time: " + totaltime/1000000 + "ms");
	}
}