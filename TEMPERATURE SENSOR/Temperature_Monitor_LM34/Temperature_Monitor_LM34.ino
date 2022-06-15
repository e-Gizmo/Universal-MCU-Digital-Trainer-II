/////////////////////////////////////
// Temperature Monitor using LM34  //
//                                 //
// This sample program allows the  //
// MCU to read an analog reading   //
// of a sensor specifically the    //
// LM34 which is a temperature     //
// sensor that reads Fahrenheit.   //
//                                 //
// Codes by:                       //
// eGizmo Mechatronix Central      //
// Taft, Manila, Philippines       //
// http://www.egizmo.com           //
// April 16, 2013                  //
/////////////////////////////////////
 
// Activates liquid crystal library:
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
 
void setup()
{
  Serial.begin(9600); // Serial communication for checking
  lcd.begin(16,2);    // Sets LCD rows and columns
  lcd.setCursor(0,0);
  lcd.print("  TEMPERATURE");
  lcd.setCursor(0,1);
  lcd.print("    MONITOR");
  delay(1800);
  lcd.clear();
}
 
void loop()
{
  // Stores the sensor reading to the variable 
  //int FAHRENHEIT = analogRead(A5);
  int RAW_VOLTAGE = analogRead(A5);
  float MILLI_VOLTS = (RAW_VOLTAGE/1024.0)*5000;
  float FAHRENHEIT = MILLI_VOLTS/10;
 
  // Formula for converting Fahrenheit to Celsius:
  float CELSIUS = (FAHRENHEIT - 32) * (5.0/9.0);
  
  delay(1900);
  lcd.setCursor(0,0);
  lcd.print("Fahrenheit:"); 
  lcd.print(FAHRENHEIT);
  lcd.setCursor(0,1);
  lcd.print("Celsius:"); 
  lcd.print(CELSIUS);
 
  // Optional serial monitor:
  Serial.println("Fahrenheit:");
  Serial.println(FAHRENHEIT);
  Serial.println("Celsius:");
  Serial.println(CELSIUS);
  
  // NOTE:
  // Sometimes the sensor is not calibrated therefore
  // one must make a way to calibrate the sensor.
  // For more information, see the data sheets of the LM34
}
