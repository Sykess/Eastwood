
#include "CdS.h"

#define LIGHT_CHANNEL 0
/*
***************************************
   Thomas P. Sullivan
   ENT234
   3/23/2015
   
   Cadmium Sulfide Cell
   Light Sensor Library
***************************************
*/

Light lightSensor;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Raw Light Value: ");
  Serial.print(lightSensor.rawLight(LIGHT_CHANNEL));
  Serial.print(" Raw Light Volts: ");
  Serial.print(lightSensor.rawLightVoltage(LIGHT_CHANNEL));
  Serial.print(" Percent Light Value: ");
  Serial.print(lightSensor.percentLight(LIGHT_CHANNEL));
  Serial.println();
  delay(500);
}
