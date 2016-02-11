/*
Read TMP36 and display with float
*/

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {

  // read the input on analog pin 0: notice that we are making this millivolts
  //by multiplying by 5000 instead of 5
  float theTemperature = ((float) 5000 * (float) analogRead(A0)/(float) 1024.0);

  //Calculate the temperature
  theTemperature = (theTemperature-(float) 500.0)/(float) 10.0;

  // print out the temperature in degrees C
  Serial.println(theTemperature);
  delay(1000);        // delay in between reads
}
