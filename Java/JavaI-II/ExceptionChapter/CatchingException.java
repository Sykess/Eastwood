import java.io.IOException;

public class CatchingException
{
   // execute 
   public static void main(String[] args)
   {
      try
      {
         throw new ExceptionA();
      }
      catch (Exception exception)
      {
         System.out.println(exception);
      }

      try
      {
         throw new ExceptionB();
      }
      catch (Exception exception)
      {
         System.out.println(exception);
      }

      try
      {
         throw new NullPointerException();
      }
      catch (Exception exception)
      {
         System.out.println(exception);
      }

      try
      {
         throw new IOException();
      }
      catch (Exception exception)
      {
         System.out.println(exception);
      }
   }
} // end class