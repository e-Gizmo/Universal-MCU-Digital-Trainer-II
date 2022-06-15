/////////////////////////////////////
// Analog voltage source w/ LCD    //
// eGizmo Universal MCU Trainer    //
//                                 //
// Reads analog voltage from       //
// three voltage sources provided  //
// in the trainer. Max of 5V       //
//                                 //
// Simply connect VR1, VR2 and VR3 //
// to A0, A1 and A2 respectively   //
//                                 //
// See circuit diagram on the same //
// folder for other connections    //
//                                 //
// Codes by:                       //
// eGizmo Mechatronix Central      //
// Taft, Manila, Philippines       //
// http://www.egizmo.com           //
/////////////////////////////////////
 
#include<LiquidCrystal.h>
 
LiquidCrystal lcd(13,12,7,6,5,4);
// LCD Pins Connection: 
// NOTE: The reference for this connections is 
// according to JP1 of the MCU Trainer. This is 
// different when using a separate LCD display
//
// LCD RS (Pin 1) to Arduino pin 13
// LCD R/W (Pin2) to GND
// LCD EN (Pin 3) to Arduino pin 12
// LCD D4 (Pin 8) to Arduino pin 4
// LCD D5 (Pin 9) to Arduino pin 5
// LCD D6 (Pin 10) to Arduino pin 6
// LCD D7 (Pin 11) to Arduino pin 7
 
#define D 50
// Delay for voltage reading. Maintain a low value so that
// voltage can be controlled easier.
#define BUZZER 9
// Connect buzzer to digital pin 9
 
void setup() 
{  
  Serial.begin(9600); // Begin serial communication (optional)
  lcd.begin(16,2);
}
 
void loop() {
 
  int VR1 = analogRead(A0);
  int VR2 = analogRead(A1);
  int VR3 = analogRead(A2);
  
  float VP1 = VR1 * (5.0 / 1023.0); // Formula for voltage reading 1
  float VP2 = VR2 * (5.0 / 1023.0); // Formula for voltage reading 2
  float VP3 = VR3 * (5.0 / 1023.0); // Formula for voltage reading 3
  
  // Optional serial reading:
  Serial.print(VP1); Serial.print(" ");   Serial.print(VP2); Serial.print(" ");   Serial.print(VP3); Serial.print(" "); 
  Serial.print("\n");
  
  lcd.setCursor(0,1);
  lcd.print(VP1);  
  lcd.setCursor(5,1);
  lcd.print(VP2); 
  lcd.setCursor(10,1);
  lcd.print(VP3); 
  lcd.setCursor(0,0);
  lcd.print("Voltage Monitor");
  
  // Optional 5v indicator. If necessary, connect buzzer to
  // pin 9 of the MCU
  if(VP1==5)
  {
    tone(BUZZER,1000,100);
  }
  if(VP2==5)
  {
    tone(BUZZER,1000,100);
  }
  if(VP3==5)
  {
    tone(BUZZER,1000,100);
  }
  
  delay(D);
}
