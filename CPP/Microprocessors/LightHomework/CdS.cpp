/*
***************************************
   Nathan Caron
   ENT234
   03/30/2015
   
   Cadmium Sulfide Cell
   Light Sensor Library
***************************************
*/
#include "CdS.h"
#include "Arduino.h"

Light::Light(){}

int Light::rawLight(int channel)
{
  // constrain the reading from the input channel from 0-1023
  // to 0-511 using the constrain function by sending the reading
  // in as x, the min value as 0, and the max value.  Putting
  // that into the return statement prevents creating extra variables.
  return constrain(analogRead(channel), 0, 511);
}

float Light::rawLightVoltage(int channel)
{
  // Using algebra shows that V = 5 * AD / 511.  So return the raw light
  // value (obtained by calling rawLight()) * 2.5 / 511.0 to avoid creating
  // an extra variable.  Will return 0-2.5
  return rawLight(channel) * 2.5 / 511.0;
}

float Light::percentLight(int channel)
{
  // Divide the raw light value (obtained from rawLight()) by 511 and multiply
  // that by 100 to give the percent.  Once again, return the result directly
  // instead of creating a new variable.
  return rawLight(channel) / 511.0 * 100;
}


