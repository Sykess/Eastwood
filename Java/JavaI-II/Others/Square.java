import java.util.Scanner;

public class Square
{
   // obtain value from user
   public static void main(String args[])
   {
      Scanner input = new Scanner(System.in);

      System.out.print("Enter square size: ");
      int size = input.nextInt();
      
      squareOfAsterisks(size);
   } 

   // draw a square of asterisks
   public static void squareOfAsterisks(int side)
   {
      for (int row = 1; row <= side; row++)
      {
         for (int column = 1; column <= side; column++)
            System.out.print("*");

         System.out.println();
      } 
   } 
} // end class