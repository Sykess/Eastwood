




public class Square extends TwoDimensionalShape
{
	private double side;

	public Square(double side)
	{

		if(side <= 0)
			throw new IllegalArgumentException(
				"Side must be > 0");
		this.side = side;
	}

	public void setSide(double side)
	{
		this.side = side;
	}

	public double getSide()
	{
		return side;
	}

	public double getArea()
	{
		return side * side;
	}

	@Override
	public String toString()
	{
		return String.format("Square%nSide: %.2f%nArea: %.2f",
			getSide(), getArea() );

	}


}