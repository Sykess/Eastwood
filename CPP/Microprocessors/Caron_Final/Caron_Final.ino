/*

   Nathan Caron
   5/6/2015
   
   Program that takes a string and converts it to be displayed on a 
   5 by 7 led display, and displays one letter at a time, shifting
   it to the left and shifting in the next letter, and cycles through
   string endlessly.
   
*/

#define NUM_ROWS 7
#define NUM_COLS 5
#define ROW_DELAY 3

#include "ledfonts_5x7.h"

//These are the pins I will use to drive the rows of the 5X7 LED array
//They are listed in the array from the top row down
byte row_array[] = {A0,A1,A2,A3,A4,A5,7};
//These are the pins I will use to drive the columns of the 5X7 LED array
//They are listed in the array from the left-most column to the right
byte col_array[] = {8,3,4,5,6};

//initialize to fill all LEDs
byte led_buf[7] = {0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};

//string to be scrolled
String str = "ENT234PWND~!";
//byte array to hold letters
byte disp[12][7];

int currentLetter = 0, currentShift = 0;

byte theRow=0;

void Paint()
{
  //This whole ISR takes just 33.6 uS to execute
  digitalWrite(row_array[theRow],HIGH);
  theRow++;
  if(theRow>=7)
    theRow=0;

  digitalWrite(col_array[0],led_buf[theRow]&0x10);
  digitalWrite(col_array[1],led_buf[theRow]&0x08);
  digitalWrite(col_array[2],led_buf[theRow]&0x04);
  digitalWrite(col_array[3],led_buf[theRow]&0x02);
  digitalWrite(col_array[4],led_buf[theRow]&0x01);

  digitalWrite(row_array[theRow],LOW);
}

void setup() 
{
  pinMode(13,OUTPUT);

  //Setup the row pins (all are outputs)  
  for(int i=0;i<NUM_ROWS;i++)
  {
    pinMode(row_array[i],OUTPUT);
    digitalWrite(row_array[i],HIGH);
  }

  //Setup the row pins (all are outputs)
  for(int i=0;i<NUM_COLS;i++)
  {
    pinMode(col_array[i],OUTPUT);
    digitalWrite(col_array[i],HIGH);
  }
  
  //setup the 2d byte array with letters from ledfonts
  for(int i = 0; i < str.length(); i++)
  {
    // subtract 32 from ascii value to get which letter in ledfonts
    // corresponds, then multiply by 8 since 8 rows in each letter,
    // and add j for which column its on
    for(int j = 0; j < 7; j++)
      disp[i][j] = charmap[(str[i] - 32) * 8 + j];
  }

  attachInterrupt(0,Paint,RISING);

  //generate tone causes interrupt to paint led_buf to display
  tone(9,350);
}

void loop() 
{
  shift();
  //control how quickly the letters scroll
  delay(300);
}

void shift()
{
  //shift every row one to the left
  for(int i = 0; i < 7; i++)
  {
    led_buf[i] = (led_buf[i] << 1);  
  }
  currentShift++;
  
  //first 2 shifts after each letter are blank, so just return
  if(currentShift < 2)
    return;
  
  //checks which stage of shift its on, based on currentShift,
  //to know which column of each row to load onto screen
  switch(currentShift)
  {
    //checks 1st column on display
    case 3: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x10)
                led_buf[i] |= 0x01;
            break;
    //checks 2nd column on display
    case 4: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x08)
                led_buf[i] |= 0x01;
            break;
    //checks 3rd column on display
    case 5: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x04)
                led_buf[i] |= 0x01;
            break;
    //checks 4th column on display
    case 6: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x02)
                led_buf[i] |= 0x01;
            break;
    //checks final column on display
    case 7: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x01)
                led_buf[i] |= 0x01;
            break;
  };
  //after 7 shifts have happened(5 columns and 2 whitespace)
  if(currentShift >= 7)
  {
    //reset shift
    currentShift = 0;
    //if ran out of letters, start back at beginning
    //otherwise increment letter
    if(currentLetter >= str.length() - 1)
      currentLetter = 0;
    else
      currentLetter++;
  }
}
