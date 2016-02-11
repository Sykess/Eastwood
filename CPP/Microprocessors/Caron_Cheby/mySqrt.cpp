#include "mySqrt.h"
#include "Arduino.h"

float mySqrt(float f)
{
  return P0 + (P1 * f) - (P2 * (f * f))
         + (P3 * (f * f * f)) - (P4 * (f * f * f * f));
}



