

import java.util.Scanner;

public class testRectangle
{

public static void main (String[] args)
{
     Scanner userInput = new Scanner (System.in);
     Rectangle s = new Rectangle();

     System.out.print("Please enter a length:  ");
     s.setLength(userInput.nextDouble());

     System.out.print("Enter a width:  ");
     s.setWidth(userInput.nextDouble());

    System.out.println("The rectangle with the attributes: \n" + s);
    System.out.println("Has a perimeter of:  " + s.perimeter() + " and area is: " + s.area());
}

}