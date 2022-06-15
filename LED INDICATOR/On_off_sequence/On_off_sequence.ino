////////////////////////////////////////////////
// LED MONITOR                                //
// FOR eGizmo UNIVERSAL MCU TRAINER           //
//                                            //
// This serves as a sample program for        //
// an LED monitor showing a on off sequence.  //
//                                            // 
// See manual for pin assignments and sample  //
// circuit diagram                            //
//                                            //
// Codes by:                                  //
// eGizmo Mechatronix Central                 //
// Taft, Manila, Philippines                  //
// http://www.egizmo.com                      //
// April 11, 2013                             //
////////////////////////////////////////////////
 
int DEL1 = 100;  // Adjust this delay for separating functions
int DEL2 = 100;  // Adjust this delay for individual delay of turning on/off the LEDs
int LED_NUMBER[] = {0,1,2,3,4,5,6,7};
 
void setup()
{
  for(int i =0; i<=7; i++)
  {
  pinMode(LED_NUMBER[i],OUTPUT); // Sets all the LED pins as OUTPUT
  }
}
 
void loop()
{
  ASCENDONOFF();
  delay(DEL1);
  DESCENDONOFF();
  delay(DEL1);
}
  
  
 
// Turns on and off the LEDs in ascending order
void ASCENDONOFF()
{
    for(int i=0; i<=7; i++)
  {
    digitalWrite(LED_NUMBER[i],HIGH); // Turns on the LEDs
    delay(DEL2);
    digitalWrite(LED_NUMBER[i],LOW);  // Turns off the LEDs
    delay(DEL2);
  }
 
  
}
 
// Turns on and off the LEDs in descending order
void DESCENDONOFF()
{
    for(int i=7; i>=0; i--)
  {
    digitalWrite(LED_NUMBER[i],HIGH); // Turns on the LEDs
    delay(DEL2);
    digitalWrite(LED_NUMBER[i],LOW);  // Turns off the LEDs
    delay(DEL2);
  }
}
