
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

String str = "Jake has a choad";
byte disp[16][7];

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
  
  //setup the 2d byte array
  for(int i = 0; i < str.length(); i++)
  {
    for(int j = 0; j < 7; j++)
      disp[i][j] = charmap[(str[i] - 32) * 8 + j];
  }

  attachInterrupt(0,Paint,RISING);

  tone(9,250);
}

void loop() 
{
  shift();
  delay(200);
}

void shift()
{
  for(int i = 0; i < 7; i++)
  {
    led_buf[i] = (led_buf[i] << 1);  
  }
  currentShift++;
  if(currentShift < 2)
    return;
  
  switch(currentShift)
  {
    case 3: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x10)
                led_buf[i] |= 0x01;
            break;
    case 4: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x08)
                led_buf[i] |= 0x01;
            break;
    case 5: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x04)
                led_buf[i] |= 0x01;
            break;
    case 6: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x02)
                led_buf[i] |= 0x01;
            break;
    case 7: for(int i = 0; i < 7; i++)
              if(disp[currentLetter][i] & 0x01)
                led_buf[i] |= 0x01;
            break;
  };
  if(currentShift >= 7)
  {
    currentShift = 0;
    if(currentLetter >= str.length() - 1)
      currentLetter = 0;
    else
      currentLetter++;
  }
}


