



public class Cube extends ThreeDimensionalShape
{
	private double side;

	public Cube(double side)
	{
		if(side <= 0)
			throw new IllegalArgumentException(
				"Side must be > 0");
		this.side = side;
	}

	public double getSide(){ return side; }
	public void setSide(double side)
	{
		if(side <= 0)
			throw new IllegalArgumentException(
				"Side must be > 0");
		this.side = side;
	}

	@Override
	public double getArea()
	{
		return 6 * side * side;
	}

	@Override
	public double getVolume()
	{
		return side * side * side;
	}

	@Override
	public String toString()
	{
		return String.format("Cube%nSide: %.2f%nArea: %.2f%nVolume: %.2f",
							 getSide(), getArea(), getVolume());
	}


}