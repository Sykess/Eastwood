/* Nathan Caron
   2/23/2015
   
   Note: I can't get the micros to work properly.  The way
   it's written now, if you take the first big block of code
   in setup and switch it with the second, it gives very
   contradictory output (says the int_Sqrt function took 
   negative microseconds).  
   I've also tried taking out flushes,adding flushes,
   nothing I do can seem to keep consistant output.
   
   I also tried using 2 variables, an int for first and a 
   double for second, and did tBefore then next line did
   first = int_Sqrt(20000); then next line set tAfter, and
   tAfter - tBefore came out to 4.  I did the same thing for
   the sqrt(20000) and tAfter - tBefore came out to 4 at first
   then after playing with the code for a bit it came out to 0.
   I don't get it.
*/
int int_Sqrt(int n);

void setup() 
{
  unsigned long tBefore, tAfter;
  int testing;
  int arg = 20000;
  double test;
  
  Serial.begin(9600);
  
  //Serial.print("Square root of 20,000: ");
  tBefore = micros();
  //Serial.println(int_Sqrt(20000));
  testing = int_Sqrt(arg);
  tAfter = micros();
  Serial.print("tBefore: ");
  Serial.println(tBefore);
  Serial.print("tAfter: ");
  Serial.println(tAfter);
  Serial.print("Difference using int_Sqrt function: ");
  Serial.print(tAfter - tBefore);
  Serial.println(" microseconds.");
  
  //Serial.print("Square root of 20,000: ");
  tBefore = micros();
  //Serial.println(sqrt(20000));
  test = sqrt(arg);
  tAfter = micros();
  Serial.print("tBefore: ");
  Serial.println(tBefore);
  Serial.print("tAfter: ");
  Serial.println(tAfter);
  Serial.print("Difference using sqrt(x): ");
  Serial.println(tAfter - tBefore);
  Serial.println(" microseconds.");
}

void loop() {}

int int_Sqrt(int n)
{
  int xs = 1, delta = 3;
  
  while(xs < n)
  {
    xs += delta;
    delta += 2;
  }
  return delta / 2 - 1;
}
