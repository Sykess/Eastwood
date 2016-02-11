/***************************************
   Thomas P. Sullivan
   ENT234
   2/27/2015
   
   Print the temperature in C and F
   (when in range)
***************************************/
//Read TMP36 and display only when within range
#include "tmp36.h"

//Setup that which needs it
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println();
  Serial.println();
  Serial.println("Your first and last name: Temperature Monitor");
}

//Forever
void loop() {
  float theTemperatureC;
  float theTemperatureF;

  // read the input on analog pin 0: notice that we are making this millivolts
  //by multiplying by 5000 instead of 5
  theTemperatureC = getTempInDegC(0);
  theTemperatureF = C2F(theTemperatureC);

  if(inRange(theTemperatureF))
  {
    // print out the temperature in degrees C
    Serial.print("The Temperature is ");
    Serial.print(theTemperatureC);
    Serial.print("C or ");
    Serial.print(theTemperatureF);
    Serial.println("F");
  }
  else
  {
    Serial.println("Temperature is Out-of-Range");
    while(!inRange(theTemperatureF))
    {
        theTemperatureC = getTempInDegC(0);
        theTemperatureF = C2F(theTemperatureC);
    }
  }
  // print out the temperature in degrees F
  Serial.println();

  delay(500);        // delay in between reads
}

