/* Nathan Caron
   3/9/2015
   
   Compute square roots using Chebyshev Polynomial
   algorithm, and then again with built in sqrt function,
   and time each of them.
*/


#include "mySqrt.h"

void setup() 
{
  float computed;
  unsigned long tBefore, tAfter;
  Serial.begin(9600);
  
  tBefore = micros();
  computed = mySqrt(COMPUTE);
  tAfter = micros();
  Serial.print("Square root of .8888 using Cheby: ");
  // Display with 10 digits past decimal point:
  Serial.println(computed, 10);
  Serial.print("This method took: ");
  Serial.print(tAfter - tBefore);
  Serial.println(" microseconds.\n");
  
  tBefore = micros();
  computed = sqrt(COMPUTE);
  tAfter = micros();
  Serial.print("Square root of .8888 using sqrt: ");
  Serial.println(computed, 10);
  Serial.print("This method took: ");
  Serial.print(tAfter - tBefore);
  Serial.println(" microseconds.");
}

void loop() {}


