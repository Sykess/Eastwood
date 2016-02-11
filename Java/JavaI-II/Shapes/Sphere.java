


public class Sphere extends ThreeDimensionalShape
{
	private double radius;

	public Sphere(double radius)
	{
		if(radius <= 0)
			throw new IllegalArgumentException(
				"Radius must be > 0");
		this.radius = radius;
	}

	public double getRadius(){ return radius; }

	public void setRadius(double radius)
	{
		if(radius <= 0)
			throw new IllegalArgumentException(
				"Radius must be > 0");
		this.radius = radius;
	}

	@Override
	public double getArea()
	{
		return 4 * Math.PI * radius * radius;
	}

	@Override
	public double getVolume()
	{
		return 4 / 3 * Math.PI * radius * radius * radius;
	}

	@Override
	public String toString()
	{
		return String.format("Sphere%nRadius: %.2f%nArea: %.2f%nVolume: %.2f",
							 getRadius(), getArea(), getVolume());
	}

}