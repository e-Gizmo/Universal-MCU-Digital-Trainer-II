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
#define MAX5382 0x30 // I2c device address
 
int intensity = 0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
 
}
 
void loop()
{  
  
  for(intensity = 256; intensity>=0; intensity--)
  {
  Wire.beginTransmission(MAX5382);
  Wire.write(intensity);
  Wire.endTransmission();
 
  int wireReading = analogRead(A0);
  float voltage = wireReading * (5.0 / 1023.0);
  // Standard code for reading voltage through
  // the analog pin of arduino.
  Serial.println(voltage);
  Serial.println(intensity);
  delay(50);
  }
  
}
//////////////////////////////////////////////////////
