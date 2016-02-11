
import java.lang.Math;


public class Circle extends TwoDimensionalShape
{
	private double radius;

	public Circle(double radius)
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

	public double getArea()
	{
		return Math.PI * radius * radius;
	}

	@Override
	public String toString()
	{
		return String.format("Circle%nRadius: %.2f%nArea: %.2f",
			getRadius(), getArea() );
	}

}