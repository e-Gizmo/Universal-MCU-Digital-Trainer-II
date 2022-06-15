////////////////////////////////////
// LCD Display #2 (MCU TRAINER)   //
//                                //
// This sample program enables    //
// the user to use the auto       //
// scroll function of the lcd     //
// display.                       //
//                                //
// Codes by:                      //
// eGizmo Mechatronix Central     //
// Taft, Manila, Philippines      //
// http://www.egizmo.com          //
////////////////////////////////////
 
#include <LiquidCrystal.h>  
// Includes liquid crystal library
 
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
 
char characters[] = {'A','R','D','U','I','N','O'}; 
// An array for defining the characters of your message
int SPEED = 200;  
// Adjsutable speed
 
void setup()
{
  lcd.begin(16,2);
  // Sets lcd number of rows and columns
}
 
void loop()
{
  lcd.setCursor(0,0);                           // Sets lcd cursor
  for(int letter = 0; letter<=6; letter++)
  {
    lcd.print(characters[letter]);             // Prints out the letters one by one
    delay(SPEED);                                // How quick the letters will show up
  }
 
  lcd.setCursor(16,1);                         // Sets lcd crusor to next line
  lcd.autoscroll();                            // Enables autoscroll
 
 
  for(int letter = 0; letter<=6; letter++)
  {
    lcd.print(characters[letter]);             // Prints out the letters one by one
    delay(SPEED);                                // How quick the letters will show up
  }
  
}
