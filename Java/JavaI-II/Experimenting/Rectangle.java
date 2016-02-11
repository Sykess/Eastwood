
public class Rectangle
{
     private double length;
     private double width;



public Rectangle()
{
     this.length = 1.0;
     this.width = 1.0;
}


public double getLength()
{
     return this.length;
}
public double getWidth()
{
     return this.width;
}


public void setLength(double length)
{
     if((length >= 1.0) && (length <= 10.0))
     this.length = length;
}
public void setWidth(double width)
{
     if((width >= 1.0) && (width <= 10.0))
     this.width = width;
}


public double perimeter()
{
     return (2 * (this.length + this.width));
}
public double area()
{
     return this.getLength() * this.getWidth();
}
public String toString()
{
     return "Length; " + this.length + "\tWidth:" + this.width;
}

}