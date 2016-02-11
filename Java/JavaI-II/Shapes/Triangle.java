



public class Triangle extends TwoDimensionalShape
{
	private double base, height;

	public Triangle(double base, double height)
	{
		if(base <= 0)
			throw new IllegalArgumentException(
				"Base must be > 0");
		if(height <= 0)
			throw new IllegalArgumentException(
				"Height must be > 0");
		this.base = base;
		this.height = height;
	}

	public double getBase(){ return base; }
	public double getHeight(){ return height; }

	public void setBase(double base)
	{
		if(base <= 0)
			throw new IllegalArgumentException(
				"Base must be > 0");
		this.base = base;
	}

	public void setHeight(double height)
	{
		if(height <= 0)
			throw new IllegalArgumentException(
				"Height must be > 0");
		this.height = height;
	}

	@Override
	public double getArea(){ return base * height / 2; }

	@Override
	public String toString()
	{
		return String.format("Triangle%nBase: %.2f%nHeight: %.2f%nArea: %.2f",
			getBase(), getHeight(), getArea() );
	}

}