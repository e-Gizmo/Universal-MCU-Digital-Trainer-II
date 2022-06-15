/////////////////////////////////////////
// Unipolar Stepper Motor              //
// with Rotary encoder                 //
// (eGizmo Universal MCU Trainer)      //
//                                     //
// This sample program makes use       //
// of a unipolar stepper motor         //
// with rotary encoder wherein         //
// the encoder acts us a knob          //
// for adjusting the speed of rotation //
// of the stepper motor.               //
//                                     //
// Codes by:                           //
// eGizmo Mechatronix Central          //
// Taft, Manila, Philippines           //
// http://www.egizmo.com               //
// April 13, 2013                      //
/////////////////////////////////////////
 
// Activates LCD Library
#include<LiquidCrystal.h>
#define e_A 5               // Connect A of rotary encoder to pin 5
#define e_B 6               // Connect B of rotary encoder to pin 6
#define e_switch 7          // Connect switch of rotary encoder to pin 7
 
int e_Position = 0;
int e_Speed = 0;
boolean e_ALast = LOW;      // Remembers the previous pin state
 
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
  Serial.begin(9600);
  for(int pin = 8; pin<=11; pin++)
  {
    pinMode(pin,OUTPUT);             // Pins for stepper motor driver
  }
  pinMode(e_switch,OUTPUT);
  pinMode(e_A,INPUT);
  pinMode(e_B,INPUT);
  digitalWrite(e_switch,HIGH);
  digitalWrite(e_A,HIGH);
  digitalWrite(e_B,HIGH); 
  lcd.begin(16,2);
}
 
void loop()
{
  int rotate = digitalRead(e_switch);         // Reads rotary encoder state
  if(rotate==0)                               // Is rotary encoder button pressed?
  {
    lcd.setCursor(0,0);
    lcd.print("clockwise     ");                  
    lcd.setCursor(7,1);
    lcd.print("<--speed");
    lcd.setCursor(0,1);
    lcd.print(e_Speed);
    lcd.print("  ");
    CW();                                     // Rotates clockwise
  }
 
  else                                        // If not,
  {
    lcd.setCursor(0,0);
    lcd.print("ctr.");
    lcd.setCursor(4,0);
    lcd.print("clockwise");
    lcd.setCursor(7,1);
    lcd.print("<--speed");
    lcd.setCursor(0,1);
    lcd.print(e_Speed);
    lcd.print("  ");
    CCW();                                    // Rotates counter clockwise
  }
}
 
 
void CCW()
{
 
  boolean encoderA = digitalRead(e_A);
  if ((e_ALast == HIGH) && (encoderA == LOW))
  {
    if (digitalRead(e_B) == LOW)
    {
      e_Position--;
    }
    else
    {
      e_Position++;
    }
  }
  e_ALast = encoderA;
 
  e_Speed = 30-e_Position;
  
  if(e_Speed==0)
  {
    e_Position = 0;
  }
 
  // The following codes vary for certain stepper motors
  // depending on their data pins.
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(e_Position);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(e_Position);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(e_Position);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(e_Position);
}
 
void CW()
{
 
  boolean encoderA = digitalRead(e_A);
 
  if ((e_ALast == HIGH) && (encoderA == LOW))
  {
    if (digitalRead(e_B) == LOW)
    {
      e_Position++;
    }
    else
    {
      e_Position--;
    }
  }
  e_ALast = encoderA;
 
  e_Speed = 30-e_Position;
  
    if(e_Speed==0)
  {
    e_Position = 0;
  }
  
  // The following codes vary for certain stepper motors
  // depending on their data pins.
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  delay(e_Position);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(e_Position);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  delay(e_Position);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  delay(e_Position);
}
