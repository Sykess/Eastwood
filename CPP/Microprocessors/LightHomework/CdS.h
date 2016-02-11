/*
***************************************
   Your Name
   ENT234
   MM/DD/YYYY
   
   Cadmium Sulfide Cell
   Light Sensor Library
***************************************
*/
#ifndef CDS_H
#define CDS_H

#define MAX_LIGHT  511

class Light {
  public:
  Light();
  int rawLight(int channel);
  float rawLightVoltage(int channel);
  float percentLight(int channel);
};

#endif
