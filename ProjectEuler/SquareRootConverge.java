
import java.math.BigInteger;
import java.math.*;
import static java.lang.Math.pow;



public class SquareRootConverge
{
	public static void main(String[] args)
	{
		BigInteger numer = new BigInteger("3");
		BigInteger denom = new BigInteger("2");
		BigInteger two = new BigInteger("2");
		int result = 0;

		for(int i = 1; i < 1000; i++)
		{
			numer = numer.add(denom.multiply(two));
			denom = numer.subtract(denom);
			BigInteger tempNum = numer;
			BigInteger tempDen = denom;


			while(!tempDen.equals(BigInteger.ZERO))
			{
				tempNum = tempNum.divide(BigInteger.TEN);
				tempDen = tempDen.divide(BigInteger.TEN);
			}
			if(!tempNum.equals(BigInteger.ZERO))
				result++;
		}

		System.out.println(result);

	}
}