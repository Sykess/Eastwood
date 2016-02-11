void setup() 
{
  Serial.begin(9600);
  
}

void loop() 
{
  

}

float mySqrt(float f)
{
  return 0.2549729994354 + ((1.172251620351 * f))
         - (0.6720680317089 * (f * f))
         + (0.3075057498669 * (f * f * f))
         - (0.0626624251406 * (f * f * f * f));
}
