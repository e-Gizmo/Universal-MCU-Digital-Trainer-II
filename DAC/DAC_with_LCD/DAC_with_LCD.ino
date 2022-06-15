////////////////////////////////////
// Digital To Analog Converter    //
// MCU Trainer using MAX5382      //
//                                //
// This program allows the user   //
// to convert a digital input     //
// from the MCU to I2c device     //
// then converts it into an       //
// analog reading.                //
//                                //
// Pin assignments:               //
// SCL to Pin A5                  //
// SDA to Pin A4                  //
// Analog output of DAC to A0     //
//                                //
// Codes by:                      //
// eGizmo Mechatronix Central     //
// Taft, Manila, Philippines      //
// http://www.egizmo.com          //
// April 18, 2013                 //
////////////////////////////////////
 
// NOTE:
// If you are having problem finding the 
// address of your I2c device. Uncomment
// the following codes for I2c library and
// comment the wire codes using /* */
// then upload. You should see the address
// of your device by using the I2c.scan() function.
 
/*
/////////////////////// I2c ////////////////////////
#include <I2C.h>
#define MAX5382 0x30 // I2c device address
 
void setup()
{
  I2c.begin();
  Serial.begin(9600);
}
 
void loop()
{
 I2c.scan();
}
////////////////////////////////////////////////////
*/
  
//////////////////////// WIRE //////////////////////
#include <Wire.h>
#include <LiquidCrystal.h>
#define MAX5382 0x30 // I2c device address
 
LiquidCrystal lcd(13,12,7,6,5,4);
// LCD Pins Connection: 
// NOTE: The reference for this connections is 
// according to JP1 of the MCU Trainer. This is 
// different when using a separate LCD display
//
// LCD RS (Pin 1) to Arduino pin 13
// LCD R/W (Pin2) to GND
// LCD EN (Pin 3) to Arduino pin 12
// LCD D4 (Pin 8) to Arduino pin 8
// LCD D5 (Pin 9) to Arduino pin 9
// LCD D6 (Pin 10) to Arduino pin 10
// LCD D7 (Pin 11) to Arduino pin 11
 
int intensity = 0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("     eGizmo   ");
  lcd.setCursor(0,1);
  lcd.print("      DAC    ");
  delay(2000);
  lcd.clear();
}
 
void loop()
{  
  
  for(intensity = 256; intensity>=0; intensity--)
  {
  // The intensity is just an assumption of the 
  // LED's brightness
  Wire.beginTransmission(MAX5382);
  Wire.write(intensity);
  Wire.endTransmission();
 
  int wireReading = analogRead(A0);
  float voltage = wireReading * (5.0 / 1023.0);
  // Standard code for reading voltage through
  // the analog pin of arduino.
  
  lcd.setCursor(0,0);
  lcd.print("Voltage:");
  lcd.setCursor(12,0);
  lcd.print(voltage);
  
  lcd.setCursor(0,1);
  lcd.print("Intensity:");
  lcd.setCursor(13,1);
  lcd.print(intensity);
  delay(50);  // Set delay for fading effect
  }
  
}
//////////////////////////////////////////////////////
