////////////////////////////////////////////////
// 4x3 Switch Matrix + LCD Display + Buzzer   //
// eGizmo Universal MCU Trainer               //
//                                            //
// This sample program makes use              //
// of a 4x3 Switch Matrix as keypad           //
// and LCD Display as read out                //
// device. Together, this program             //
// makes a dialer.                            //
//                                            //
// Codes by:                                  //
// eGizmo Mechatronix Central                 //
// Taft, Manila, Philippines                  //
// http://www.egizmo.com                      //
// April 12, 2013                             //
////////////////////////////////////////////////
 
// Activates LCD Library
#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,14,15,16,17);
// LCD Pins Connection: 
// NOTE: The reference for this connections is 
// according to JP1 of the MCU Trainer. This is 
// different when using a separate LCD display
//
// LCD RS (Pin 1) to Arduino pin 13
// LCD R/W (Pin2) to GND
// LCD EN (Pin 3) to Arduino pin 12
// LCD D4 (Pin 8) to Arduino pin 14
// LCD D5 (Pin 9) to Arduino pin 15
// LCD D6 (Pin 10) to Arduino pin 16
// LCD D7 (Pin 11) to Arduino pin 17
 
const int numRows = 4;       // number of rows in the keypad
const int numCols = 3;       // number of columns
const int debounceTime = 20; // number of milliseconds for switch to be stable
 
// keymap defines the character returned when the corresponding key is pressed
const char keymap[numRows][numCols] = {
  { '1', '2', '3'   } ,
  { '4', '5', '6'   } ,
  { '7', '8', '9'   } ,
  { '*', '0', '#'   }
};
 
// this array determines the pins used for rows and columns
const int rowPins[numRows] = { 7, 2, 3, 6 }; // Rows 0 through 3
const int colPins[numCols] = { 5, 8, 4 };    // Columns 0 through 2
 
// Optional buzzer:
const int BUZZER = 9;
const int DUR = 100; // Duration for each dial
 
void setup()
{
  // Serial.begin(9600); // Begins serial communication
  lcd.begin(16,2);    // Sets LCD rows and columns
  for (int row = 0; row < numRows; row++)
  {
    pinMode(rowPins[row],INPUT);       // Set row pins as input
    digitalWrite(rowPins[row],HIGH);   
  }
  for (int column = 0; column < numCols; column++)
  {
    pinMode(colPins[column],OUTPUT);     // Set column pins as outputs 
    // for writing
    digitalWrite(colPins[column],HIGH);
  }
  pinMode(BUZZER,OUTPUT);
}
 
void loop()
{ 
  char key = getKey();
  if( key != 0) 
  {
    // Serial.println(key);
    lcd.print(key);
 
    if(key==keymap[0][0])
    {
      tone(BUZZER,100,DUR);
    }
    if(key==keymap[0][1])
    {
      tone(BUZZER,150,DUR);
    }
    if(key==keymap[0][2])
    {
      tone(BUZZER,200,DUR);
    }
 
 
    if(key==keymap[1][0])
    {
      tone(BUZZER,250,DUR);
    }
    if(key==keymap[1][1])
    {
      tone(BUZZER,300,DUR);
    }
    if(key==keymap[1][2])
    {
      tone(BUZZER,350,DUR);
    }
 
 
    if(key==keymap[2][0])
    {
      tone(BUZZER,400,DUR);
    }
    if(key==keymap[2][1])
    {
      tone(BUZZER,450,DUR);
    }
    if(key==keymap[2][2])
    {
      tone(BUZZER,500,DUR);
    }
 
 
    if(key==keymap[3][0])
    {
      tone(BUZZER,550,DUR);
    }
    if(key==keymap[3][1])
    {
      tone(BUZZER,600,DUR);
    }
    if(key==keymap[3][2])
    {
      tone(BUZZER,650,DUR);
    }
  }
 
}
 
// Function for getting which key is pressed
char getKey()
{
  char key = 0;                                  // 0 indicates no key pressed
  for(int column = 0; column < numCols; column++)
  {
    digitalWrite(colPins[column],LOW);         
    for(int row = 0; row < numRows; row++)     
    {
      if(digitalRead(rowPins[row]) == LOW)     
      {
        delay(debounceTime);                     // Debounce
        while(digitalRead(rowPins[row]) == LOW);                    
        key = keymap[row][column];               // Stores value of key pressed
      }
    }
    digitalWrite(colPins[column],HIGH);    
  }
  return key;  // Returns key value
}
