/* 
   Nathan Caron
   ENT 234
   4/27/2015
   
   Question 4 on the test, to solve the sum of 1-100.
   I may have gotten a little carried away, my initial 
   solution was so quick that I got creative.
*/

#include "CountingSums.h"

void disp(String s, int sum, unsigned long time);


void setup() 
{
  Serial.begin(9600);
  
  unsigned long tI, tF;
  int sum;
  
  tI = micros();
  sum = sumOfCounting(N);
  tF = micros();
  disp("sumOfCounting: ", sum, tF-tI);
  
  tI = micros();
  sum = sumAnotherWay(N);
  tF = micros();
  disp("sumAnotherWay: ", sum, tF-tI);
  
  tI = micros();
  sum = sumWithRecursion(N, 0, 0);
  tF = micros();
  disp("sumWithRecursion: ", sum, tF-tI);
  
  tI = micros();
  sum = sumOverlyComplicated(N);
  tF = micros();
  disp("sumOverlyComplicated: ", sum, tF-tI);
  
  tI = micros();
  sum = pairs(N);
  tF = micros();
  disp("pairs: ", sum, tF-tI);
  
  tI = micros();
  sum = pairsFormula(N);
  tF = micros();
  disp("pairsFormula: ", sum, tF-tI);

}


//I tried to move display function to .cpp, compiler
//threw a tantrum, so now its here.
void disp(String s, int sum, unsigned long time)
{
  Serial.print("The sum using ");
  Serial.print(s);
  Serial.print(sum);
  Serial.print(" and took: ");
  Serial.print(time);
  Serial.println(" Micro seconds");
}

void loop() {}
