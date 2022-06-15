////////////////////////////////////
// LCD Display #1 (MCU TRAINER)   //
//                                //
// This sample program enables    //
// the user to use simple         //
// display and positioning.       //
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
 
 
 
void setup()
{
  lcd.begin(16,2);
  // Sets lcd number of rows and columns
}
 
// About set cursor:
// lcd.setCursor(row,column)
// NOTE: The rows and columns accepts only
// integers.
 
void loop()
{
  lcd.setCursor(5,0);                           // Sets lcd cursor
  lcd.print("WELCOME");                         // 1st line message 
  lcd.setCursor(3,1);                           // Sets lcd cursor to second line
  lcd.print("to e-Gizmo");                      // 2nd line message
  
}
