////////////////////////////////////////////////
// LED MONITOR                                //
// FOR eGizmo UNIVERSAL MCU TRAINER           //
//                                            //
// This serves as a sample program for        //
// an LED monitor showing a running light     //
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
int LED_NUMBER[] = {0,1,2,3,4,5,6,7,8,9};
 
void setup()
{
  for(int i =0; i<=9; i++)
  {
  pinMode(LED_NUMBER[i],OUTPUT); // Sets all the LED pins as OUTPUT
  }
}
 
void loop()
{
  ASCENDON();
  delay(DEL1);
  ASCENDOFF();
  delay(DEL1);
  DESCENDON();
  delay(DEL1);
  DESCENDOFF();
  delay(DEL1);
}
  
  
// Turns on the LEDs in ascending order
void ASCENDON()
{
    for(int i=0; i<=9; i++)
  {
    digitalWrite(LED_NUMBER[i],HIGH); // Turns on the LEDs
    delay(DEL2);
  }
}
 
// Turns off the LEDs in ascending order
void ASCENDOFF()
{
    for(int i=0; i<=9; i++)
  {
    digitalWrite(LED_NUMBER[i],LOW); // Turns off the LEDs
    delay(DEL2);
  }
}
 
// Turns on the LEDs in descending order
void DESCENDON()
{
    for(int i=9; i>=0; i--)
  {
    digitalWrite(LED_NUMBER[i],HIGH); // Turns on the LEDs
    delay(DEL2);
  }
}
 
// Turns off the LEDs in descending order
void DESCENDOFF()
{
    for(int i=9; i>=0; i--)
  {
    digitalWrite(LED_NUMBER[i],LOW); // Turns off the LEDs
    delay(DEL2);
  }
}
