



public class Tetrahedron extends ThreeDimensionalShape
{
	private double side;

	public Tetrahedron(double side)
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
		return Math.sqrt(3) * side * side;
	}

	@Override
	public double getVolume()
	{
		return Math.pow(side, 3) / (6 * Math.sqrt(2));
	}

	@Override
	public String toString()
	{
		return String.format("Tetrahedron%nSide: %.2f%nArea: %.2f%n%s%.2f",
							 getSide(), getArea(), "Volume: ", getVolume());
	}

}