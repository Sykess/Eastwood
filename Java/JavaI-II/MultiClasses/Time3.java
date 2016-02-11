// Fig. 8.5: Time2.java
// Time2 class declaration with overloaded constructors.

public class Time3
{

   private int timeSecs;

   // Time3 no-argument constructor:
   // initializes each instance variable to zero
   public Time3()
   {
      this(0, 0, 0); // invoke constructor with three arguments
   }

   // Time3 constructor: hour supplied, minute and second defaulted to 0
   public Time3(int hour)
   {
      this(hour, 0, 0); // invoke constructor with three arguments
   }

   // Time3 constructor: hour and minute supplied, second defaulted to 0
   public Time3(int hour, int minute)
   {
      this(hour, minute, 0); // invoke constructor with three arguments
   }

   // Time3 constructor: hour, minute and second supplied
   public Time3(int hour, int minute, int second)
   {
      if (hour < 0 || hour >= 24)
         throw new IllegalArgumentException("hour must be 0-23");

      if (minute < 0 || minute >= 60)
         throw new IllegalArgumentException("minute must be 0-59");

      if (second < 0 || second >= 60)
         throw new IllegalArgumentException("second must be 0-59");

      timeSecs += hour * 3600;  // 3600 seconds in each hour
      timeSecs += minute * 60; // 60 seconds in each minute
      timeSecs += second;
   }

   // Time3 constructor: another Time3 object supplied
   public Time3(Time3 time)
   {
      // invoke constructor with three arguments
      this(time.getHour(), time.getMinute(), time.getSecond());
   }

   // Set Methods
   // set a new time value using universal time;
   // validate the data
   public void setTime(int hour, int minute, int second)
   {
      if (hour < 0 || hour >= 24)
         throw new IllegalArgumentException("hour must be 0-23");

      if (minute < 0 || minute >= 60)
         throw new IllegalArgumentException("minute must be 0-59");

      if (second < 0 || second >= 60)
         throw new IllegalArgumentException("second must be 0-59");

      timeSecs += hour * 3600; // 3600 seconds in each hour
      timeSecs += minute * 60; // 60 seconds in each minute
      timeSecs += second;
   }

   // validate and set hour
   public void setHour(int hour)
   {
      if (hour < 0 || hour >= 24)
         throw new IllegalArgumentException("hour must be 0-23");

      timeSecs %= 3600;
      timeSecs += hour * 3600;
   }

   // validate and set minute
   public void setMinute(int minute)
   {
      if (minute < 0 || minute >= 60)
         throw new IllegalArgumentException("minute must be 0-59");

      timeSecs -= timeSecs % 3600 / 60 * 60;
      timeSecs += minute * 60;
   }

   // validate and set second
   public void setSecond(int second)
   {
      if (second < 0 || second >= 60)
         throw new IllegalArgumentException("second must be 0-59");

      timeSecs -= timeSecs % 3600 % 60;
      timeSecs += second;
   }

   // Get Methods
   // get hour value
   public int getHour()
   {
      return timeSecs / 3600;
   }

   // get minute value
   public int getMinute()
   {
      return timeSecs % 3600 / 60;
   }

   // get second value
   public int getSecond()
   {
      return timeSecs % 3600 % 60;
   }

   // convert to String in universal-time format (HH:MM:SS)
   public String toUniversalString()
   {
      return String.format(
         "%02d:%02d:%02d", getHour(), getMinute(), getSecond());
   }

   // convert to String in standard-time format (H:MM:SS AM or PM)
   public String toString()
   {
      return String.format("%d:%02d:%02d %s",
         ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12),
         getMinute(), getSecond(), (getHour() < 12 ? "AM" : "PM"));
   }
} // end class Time2

