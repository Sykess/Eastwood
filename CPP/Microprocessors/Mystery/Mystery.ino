/* Nathan Caron
   2/18/2015
   
   This program is calculating squares.  It doesn't
   display it, but xs actually represents 1^2 first,
   then 2^2, then 3^2, and so on.  The variable arg
   is used to control the while loop, and it keeps the
   squared numbers from reaching whatever arg is set to.
   In the case of 200, the largest square that can be
   made (with ints) is 196, which is 14^2.  The 14 that
   is displayed on the screen represents the largest
   int possible with its square being less than arg.  The
   actual expression displaying (delta/2) - 1 represents
   the iterations delta went through the while loop, and
   subtracts 1 (since xs has to be incremented above arg
   to break out of the loop, we want 1 less iteration).
   Note xs actually ends up equaling 225 in this program.

*/

void setup() {
  int arg = 200;
  int xs = 1, delta = 3;
  
  while (xs < arg)
  {
    xs = xs + delta;
    delta = delta + 2;
  }
  
  Serial.begin(9600);
  Serial.println((delta/2)-1);
}

void loop() {
  
}
