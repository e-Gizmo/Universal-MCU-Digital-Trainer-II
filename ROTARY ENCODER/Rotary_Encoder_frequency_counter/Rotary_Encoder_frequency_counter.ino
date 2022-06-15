////////////////////////////////////////
// Rotary Encoder + LCD Display       //
// with Frequency display             //
// eGizmo Universal MCU Trainer       //
//                                    //
// This sample program makes use      //
// of a rotary encoder with a buzzer  //
// that outputs the frequency         //
// received by changing encoder       //
// position.                          //
//                                    //
// Codes by:                          //
// eGizmo Mechatronix Central         //
// Taft, Manila, Philippines          //
// http://www.egizmo.com              //
// April 13, 2013                     //
////////////////////////////////////////
 
 
// Activate liquid crystal library
#include<LiquidCrystal.h> 
#define e_A 5       // Connect A of rotary encoder to pin 5
#define e_B 6       // Connect B of rotary encoder to pin 6
#define SWITCH 7    // Connect S3 of rotary encoder to pin 7
 
int encoderPos = 0; // Sets initial position of encoder
 
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
 
boolean e_ALast = LOW;
 
void setup()
{
  pinMode(e_A, INPUT);
  pinMode(e_B, INPUT);
  pinMode(SWITCH, INPUT);
  digitalWrite(e_A, HIGH);
  digitalWrite(e_B, HIGH);
  lcd.begin(16,2);
  lcd.print("Rotary Encoder"); // Welcome Message
}
 
void loop()
{
  boolean encoderA = digitalRead(e_A);
 
  if ((e_ALast == HIGH) && (encoderA == LOW))
  {
    if (digitalRead(e_B) == LOW)
    {
      encoderPos--;    // Encoder position decreases when encoder is rotated CW
    }
    else
    {
      encoderPos++;    // Encoder position increases when encoder is rotated CCW
    }
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("POS:");
    lcd.setCursor(5,0);
    lcd.print(encoderPos);
    
    int buzzertone = encoderPos+100;
    tone(9,buzzertone,100);
    
    lcd.setCursor(0,1);
    lcd.print("FREQ:");
    lcd.setCursor(6,1);
    lcd.print(buzzertone);
  }
 
  e_ALast = encoderA;
  
}
