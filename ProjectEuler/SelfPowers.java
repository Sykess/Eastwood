
import java.math.BigInteger;
import static java.lang.Math.pow;


public class SelfPowers
{
	public static void main(String[] args)
	{
		//int x = 5;
		BigInteger num = new BigInteger("1");
		BigInteger sum = new BigInteger("0");
		//System.out.println(num);

		for(int x = 1; x <= 1000; x++)
		{
			num = num.valueOf(x);
			num = num.pow(x);
			sum = sum.add(num);

			//num = num.add(BigInteger.ONE);
			//System.out.println(x);
		}
		System.out.println(sum);

	}
}