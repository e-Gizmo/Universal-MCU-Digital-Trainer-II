/////////////////////////////////////////////////////////////
// Digital MCU Trainer (BUZZER 2)                          //
//                                                         //
// This sample program enables a programmable              //
// tone for a buzzer with optional delay etc.              //
//                                                         //
// Simply connect a wire from the headers of the buzzer    //
// component of the trainer to any digital I/O             //
// header located on the trainer. But for this example,    //
// connect a wire from the buzzer to pin 9 of the          //
// MCU extension pins.                                     //
//                                                         //
// Codes by:                                               //
// eGizmo Mechatronix Central                              //
// Taft, Manila, Philippines                               //
// http://www.egizmo.com                                   //
// April 10, 2013                                          //
/////////////////////////////////////////////////////////////
 
 
#include "pitches.h"
#define BUZZER 9
// Always use a PWM pin for the tone or analog write function
 
void setup() 
{
}
 
void loop() 
{
  //////////////////////////////////////////////////////
  // Note: This set makes use of the for loop.        //
  // It is wherein                                    //
  // for(initial,range,increment){                    //
  // Command here                                     //
  // }                                                //
  // tone(pin number, frequency)                      //
  // delay(time)                                      //
  //////////////////////////////////////////////////////
  
  
  for(int i=0;i<=560;i++)
  {
  tone(BUZZER,i); 
  // Sets pin 9 with a frequency of i which is from 0 to 560. 
  // This makes a police alarm like sound.
  delay(10); 
  }
  
}
