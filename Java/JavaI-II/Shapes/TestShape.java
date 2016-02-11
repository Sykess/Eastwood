


public class TestShape
{
	public static void main(String[] args)
	{

		Shape[] shapes = new Shape[6];

		shapes[0] = new Square(5);
		shapes[1] = new Circle(7);
		shapes[2] = new Triangle(4, 8);
		shapes[3] = new Cube(5);
		shapes[4] = new Sphere(9);
		shapes[5] = new Tetrahedron(7);

		System.out.println("\n\n***************\n\n");
		for(Shape current : shapes)
		{
			System.out.printf("Shape: %s%n", current.getClass().getName());


			if(current instanceof TwoDimensionalShape)
			{
				System.out.printf("Area: %.2f%n", current.getArea());
			}
			else
			{
				ThreeDimensionalShape curshape = (ThreeDimensionalShape) current;

				System.out.printf("Area: %.2f%n", curshape.getArea());
				System.out.printf("Volume: %.2f%n", curshape.getVolume());
			}
			System.out.println();
		}
	}
}