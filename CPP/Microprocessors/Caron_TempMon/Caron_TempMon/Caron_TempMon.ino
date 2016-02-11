/* 
  Nathan Caron
  ENT234
  3/2/2015

  Monitor temperature and only display it when it is within
  the range of 80F +/- 1.  Otherwise print that Temperature
  is out-of-range.  Delay readings by .5 second.
*/



void setup() 
{
  Serial.begin(9600);
  Serial.println("Nathan Caron: Temperature Monitor");
}

void loop() 
{
  float tempF, tempC,  theTemperature;
  // create static so only assigns it 0 once, this variable
  // is so out of range display only occurs once between valid displays
  static int displayOut = 0;
  
  // read input on analog pin 0.  Using mV instead of V.
  theTemperature = ((float) 5000 * (float) analogRead(A0)/(float) 1024.0);
  
  //Calculate temperature in Celsius
  tempC = (theTemperature-(float) 500.0)/(float) 10.0;
  
  tempF = tempC * 1.8 + 32;
  
  if(tempF >= 60 && tempF <= 90)
  {
    Serial.print("Temperature is: ");
    Serial.print(tempF);
    Serial.print(" F. / ");
    Serial.print(tempC);
    Serial.println(" C.");
    delay(500);
    // set to 0 so if error occurs after this it will display
    displayOut = 0; 
  }
  else
  {
    if(displayOut == 0)
    {
      Serial.println("Temperature is out-of-range");
      displayOut++;
    }
    delay(1000);
  }
}



