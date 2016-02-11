// Fig. 8.6: Time2Test.java
// Overloaded constructors used to initialize Time2 objects.

public class Time3Test
{
   public static void main(String[] args)
   {
      Time3 t1 = new Time3(); // 00:00:00
      Time3 t2 = new Time3(2); // 02:00:00
      Time3 t3 = new Time3(21, 34); // 21:34:00
      Time3 t4 = new Time3(12, 25, 42); // 12:25:42
      Time3 t5 = new Time3(t4); // 12:25:42



      System.out.println("Constructed with:");
      displayTime("t1: all default arguments", t1);
      displayTime("t2: hour specified; default minute and second", t2);
      displayTime("t3: hour and minute specified; default second", t3);
      displayTime("t4: hour, minute and second specified", t4);
      displayTime("t5: Time2 object t4 specified", t5);


      t4.setSecond(58);
      t4.setMinute(33);
      t4.setHour(16);

	  System.out.print("Get hour t4:   " + t4.getHour()+"\n");
      System.out.print("Get minute t4: " + t4.getMinute()+"\n");
      System.out.print("Get second t4: " + t4.getSecond()+"\n");

      // attempt to initialize t6 with invalid values
      try
      {
         Time3 t6 = new Time3(27, 74, 99); // invalid values
      }
      catch (IllegalArgumentException e)
      {
         System.out.printf("%nException while initializing t6: %s%n",
            e.getMessage());
      }
   }

   // displays a Time2 object in 24-hour and 12-hour formats
   private static void displayTime(String header, Time3 t)
   {
      System.out.printf("%s%n   %s%n   %s%n",
         header, t.toUniversalString(), t.toString());
   }
} // end class Time2Test


/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
