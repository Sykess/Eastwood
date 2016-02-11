/* 
   Nathan Caron
   4/22/2015
   
   Use an interrupt that increments a global variable to control the LED on the
   Arduino to blink once every 1/2 second.
   
   One thing I notice is that when I time the blinks with my stopwatch, there are roughly
   30 blinks in 29.8 seconds, probably either due to propagation delay or the delay from
   code being run.
*/

#define OFF 100
#define ON 50

//I used an unsigned long long variable since the number being increased by 100 per second
//will grow rapidly, using an unsigned long long  will allow the program to run for a long time.
unsigned long long global = 0;

void myHandler(){ global++; }

//set pin 13 to output, attach an interrupt, and then generate a tone of frequency 100 Hz on pin 9.
void setup() 
{
  pinMode(13, OUTPUT);
  attachInterrupt(0,myHandler,RISING);
  tone(9,100);
}

void loop() 
{
  //check if divisible by 100 first since numbers divisible by 100 are also divisible by 50
  //if it is divisible by 100, turn LED off, since 50 will happen first to turn the LED on
  if(global % OFF == 0)
    digitalWrite(13, LOW);
  //use else if so that if it is not divisible by 100, but is by 50, then turn LED on
  else if(global % ON == 0)
    digitalWrite(13, HIGH);
}
