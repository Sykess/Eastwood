
import java.math.BigInteger;
import static java.lang.Math.pow;

public class PowerDigitSum
{
	public static void main(String[] args)
	{
		int added = 0;
		int power = 1000;

		BigInteger num = new BigInteger("2");
		BigInteger sum = new BigInteger("0");
		//num2 = num.pow(power);

		num = num.pow(1000);

		while(num.signum() == 1)
		{
			sum = sum.add(num.mod(BigInteger.TEN));
			num = num.divide(BigInteger.TEN);
		}
		System.out.println(sum);

	}

}